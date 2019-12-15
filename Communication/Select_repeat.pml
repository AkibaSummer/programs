#define WIN 4 /*定义窗口大小*/
#define MAX 7/*定义发送报文计数最大值*/
#define nak_timeout timeout
chan s_r=[10] of {mtype,byte,byte};/*定义发送端到接收端传输通道*/
chan r_s=[10] of {mtype,byte,byte};/*定义接收端到发送端传输通道*/
mtype={mesg, ack, err, nak};/*定义消息类型*/
proctype udt_sender() /*发送端进程*/
{
byte s,r,Ledge,Redge;/*s 为要发送的报文的序号,r 为确认报文的序号,Ledge 为滑动窗口下限,Redge upper-bound*/
Ledge = 0; /*窗口初始化*/
Redge = WIN;
do
::true;
  progress:s = Ledge; /*将要发送报文指针移到窗口头*/
  progress1:
  if
  :: (s!=Redge) -> /*如果当前没有发送满则可以发送*/
    if
    ::s_r!mesg(0,s)-> /*成功发送正确报文*/
      s = (s+1)%MAX;/*s 后移*/
      if
      ::goto progress1; /*在窗口内连续发送*/
      ::skip/*也可以不发送*/
      fi;
    ::s_r!err(s,0) -> /*发送的报文在传输通道中出错*/
      s = (s+1)%MAX;/*s 后移*/
      if
      ::goto progress1;
      ::skip
      fi;
    ::skip -> /*报文在传输通道中丢失*/
      s = (s+1)%MAX;/*s 后移*/
      if
      ::goto progress1;
      ::skip
      fi;
    fi;
  :: (s==Redge) -> /*已经发送满窗口则取消发送*/
    skip;
  fi;
  
  if
  ::r_s?err(0,r) -> skip /*收到错误报文不工作*/
  ::r_s?ack(r,0) ->/*收到正确应答报文*/
    if
    ::(Redge<Ledge) -> /*如果当前窗口右侧标号较小*/
      if
      ::(r>=Ledge||r<Redge)/*正确确认*/
        Redge = (Redge+r+1+MAX-Ledge)%MAX
        Ledge = (r+1)%MAX; /*移动窗口*/   
        goto progress;
      ::(r<Ledge&&r>=Redge)/*不在窗口内*/
        skip;
      fi;
    ::(Ledge<Redge) -> /*如果当前窗口右侧标号较大*/
      if
      ::(r>=Ledge&&r<Redge)
        Redge = (Redge+r+1+MAX-Ledge)%MAX	        
        Ledge = (r+1)%MAX;
        goto progress;
      ::(r<Ledge||r>=Redge)
        skip;
      fi;
    fi;
  ::r_s?nak(0,r) -> /*接受到nak信号*/
    if
    ::(Redge<Ledge) -> /*如果当前窗口右侧标号较小*/
      if
      ::(r>=Ledge||r<Redge)/*在窗口内*/
        if /*重发报文*/
        ::s_r!mesg(0,r)->skip /*成功发送正确报文*/
        ::s_r!err(r,0) ->skip /*发送的报文在传输通道中出错*/
        ::skip -> /*报文在传输通道中丢失*/
        fi;
      ::(r<Ledge&&r>=Redge)/*不在窗口内*/
        skip;
      fi;
    ::(Redge>Ledge) -> /*如果当前窗口右侧标号较大*/
      ::(r>=Ledge&&r<Redge)
        if /*重发报文*/
        ::s_r!mesg(0,r)->skip /*成功发送正确报文*/
        ::s_r!err(r,0) ->skip /*发送的报文在传输通道中出错*/
        ::skip -> /*报文在传输通道中丢失*/
        fi;
      ::(r<Ledge||r>=Redge)
        skip;
    fi;
  fi;
od
}

proctype udt_receiver()/*接收端进程*/
{
byte Ledge,Redge; /*接送方窗口上下界*/
byte t;/*t 为接收报文的序号*/
byte arrived[WIN];/*接受缓冲区 */
Ledge = 0;
Redge = WIN;
do
::s_r?mesg(0,t) ->/*收到正确报文*/
  if
  ::(Redge>Ledge)->
    if 
    ::(t>=Ledge&&t<Redge)->/*报文在窗口内*/
      arrived[t % WIN]=true;
      do
      ::(arrived[Ledge%WIN]==1)-> /*如果收到窗口第一个元素，滑动窗口*/
        arrived[Ledge%WIN]=false;
        Ledge=(Ledge+1)%MAX;
        Redge=(Redge+1)%MAX;
        printf("Received %d\n",(Ledge -1 +MAX)%MAX);
      ::(arrived[Ledge%WIN]==0)->
        break;
      od;
      if
      ::r_s!ack((Ledge-1+MAX)%MAX,0) /*确认*/
      ::r_s!err(0,Ledge) /*确认*/
      ::skip;
      fi
    ::(t<Ledge||t>=Redge)->/*报文不在窗口内*/
      skip;
    fi;
  ::(Redge<Ledge)->
    if 
    ::(t>=Ledge||t<Redge)->/*报文在窗口内*/
      arrived[t%WIN]=true;
      do
      ::(arrived[Ledge%WIN]==1)-> /*如果收到窗口第一个元素，滑动窗口*/
        arrived[Ledge%WIN]=false;
        Ledge=(Ledge+1)%MAX;
        Redge=(Redge+1)%MAX;
        printf("Received %d\n",(Ledge -1 +MAX)%MAX);
      ::(arrived[Ledge%WIN]==0)->
        break;
      od;
      if
      ::r_s!ack((Ledge-1+MAX)%MAX,0) /*确认*/
      ::r_s!err(0,Ledge) /*确认*/
      ::skip;
      fi
    ::(t<Ledge&&t>=Redge)->/*报文不在窗口内*/
      skip;
    fi;
  fi;
::s_r?err(t,0)->/*收到的报文出错*/
  if
  ::r_s!nak(0,t);/*重发确认*/
  ::r_s!err(0,t); /*发送的确认报文在传输通道中出错*/
  ::skip; /*确认报文在传输通道中丢失*/
  fi;
::timeout->
  if
  ::r_s!ack((Ledge-1+MAX)%MAX,0)/*重发确认*/
  ::r_s!err(0,Ledge) /*发送的确认报文在传输通道中出错*/
  ::skip /*确认报文在传输通道中丢失*/
  ::nak_timeout->
    int i;
    for (i : 1 .. WIN){
      if
      ::(arrived[(i+Ledge-1)%MAX%WIN]==0)
        if 
        ::r_s!nak(0,(i+Ledge-1)%MAX)/*重发nak*/
        ::r_s!err(0,(i+Ledge-1)%MAX) /*发送的nak报文在传输通道中出错*/
        ::skip
        fi;
      fi; 
    }
  fi;
  
od;
}
init
{ /*启动进程*/
run udt_sender();
run udt_receiver();
}