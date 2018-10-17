#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
int main(){
    int Pid(0);
    int Pid1(0),Pid2(0);
    Pid = fork();
    if (Pid==-1){
        printf("创建第一个子进程失败\n");
    }
    else if (Pid>0){        
        Pid1=Pid;
        printf("我是父进程，成功创建第一个子进程，其Pid为%d\n",Pid1);
        int *status;
        waitpid(Pid1,status,0);
        if (WIFEXITED(*status)==0)
            printf("我是父进程，子进程1返回成功\n");
        else
            printf("我是父进程，子进程1返回失败\n");
        Pid = fork();
        if (Pid==0){
            //printf("c\n");
            printf("我是成功创建的第二个子进程,我将调用exec函数\n");
        	execl("./Lab01_exec.temp","",0);
                        
        }
    	if (Pid==-1){
            printf("创建第二个子进程失败\n");
        }
        else if (Pid>0){
            Pid2=Pid;
            //printf("a\n");
            printf("我是父进程，成功创建第二个子进程，其Pid为%d\n",Pid2);
            int *status;
            waitpid(Pid2,status,0);
            if (WIFEXITED(*status)==0)
                printf("我是父进程，调用exec函数成功\n");
            else
                printf("我是父进程，调用exec函数失败\n");
        }
    }
    else {
        //printf("b\n");
        printf("我是成功创建的第一个子进程\n");
        return 0;
    }
}