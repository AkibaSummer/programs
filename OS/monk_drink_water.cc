#include <bits/stdc++.h> 
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

class Monk{
    int power,speed,ingenious;
    int thirsty,active;
};

class Bucket{
    int capacity,durable;
    int addedcapacity;
};

map<int,Monk>* monks=new map<int,Monk>;
map<int,Bucket>* buckets=new map<int,Bucket>;

void newmonk(){
    int ppid = getppid();
    int power=rand()%100+1;
    int speed=rand()%100+1;
    int agile=rand()%100+1;
    int maxthirsty=rand()%100+1;
    int active=rand()%100+1;
    int thirsty=rand()%maxthirsty+1;
    cout<<"庙里来了一个新和尚，他的属性值如下:"<<endl;
    cout<<"\t力量值:"<<power<<endl;
    cout<<"\t速度值:"<<speed<<endl;
    cout<<"\t敏捷值:"<<agile<<endl;
    cout<<"\t饥渴值:"<<thirsty<<"/"<<maxthirsty<<endl;
    cout<<"\t活跃值:"<<active<<endl;
	while (true){
        int temp=getppid();
        if (temp!=ppid) {
            cout<<"庙被拆了，啊我死了。"<<endl;
            return ;
        }
    }
    
}



void newbucket(){
    
}



int main(){
    int pid=fork();
    if (pid==0){
        newmonk();
    }
    printf("%d\n",pid);
    srand(time(0));
    usleep(1000000);
    printf("orz\n");
}
