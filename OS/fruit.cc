#include <pthread.h>
#include <unistd.h>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define totalnums 10
#define speed 1000

// 清除屏幕
#define CLEAR() printf("\033[2J")
// 上移光标
#define MOVEUP(x) printf("\033[%dA", (x))
// 下移光标
#define MOVEDOWN(x) printf("\033[%dB", (x))
// 左移光标
#define MOVELEFT(y) printf("\033[%dD", (y))
// 右移光标
#define MOVERIGHT(y) printf("\033[%dC",(y))
// 定位光标
#define MOVETO(x,y) printf("\033[%d;%dH", (x), (y))
// 光标复位
#define RESET_CURSOR() printf("\033[H")
// 隐藏光标
#define HIDE_CURSOR() printf("\033[?25l")
// 显示光标
#define SHOW_CURSOR() printf("\033[?25h")

//pthread_mutex_t writemap;
pthread_mutex_t editmap;
pthread_mutex_t mutex_nums;
pthread_mutex_t mutex_fruits;
pthread_t pro[totalnums],con[totalnums],flushscreen;
queue<pair<int,int>> fruits;
queue<bool*> mutexx;
int fruitnums;
bool stop;
char maps[30][30];
int pronums,connums,eatednums,proednums;

void msleep(unsigned int times){
    usleep(times*speed);
}

void *printMaps(void *arg){			//输出地图
    while(1){
    	//pthread_mutex_lock(&writemap);
        if (stop) break;
        MOVETO(0,0);
        for (int i=0;i<30;i++){
            for (int j=0;j<30;j++){
                if (maps[i][j]=='P')
                    printf("\033[1;34m");
                if (maps[i][j]=='F')
                    printf("\033[1;33m");
                if (maps[i][j]=='C')
                    printf("\033[1;32m");
                printf("%c",maps[i][j]);
                printf("\033[0m");
                printf(" ");
            }
            puts("   ");
        }
        printf("生产者数量：%d   \n",pronums);
        printf("消费者数量：%d   \n",connums);
        printf("未被选中的水果数量：%d   \n",fruits.size());
        printf("未被领取的水果数量：%d   \n",fruitnums);
        printf("已食用的水果总数量：%d   \n",eatednums);
        printf("已生产的水果总数量：%d   \n",proednums);
    }
}

void *producer(void *arg){
    pronums++;
    int x,y;
    bool eated=true;
    while(maps[x=rand()%30][y=rand()%30]!=' ');	//找到一个空位置放入新的生产者
    maps[x][y]='P';
    while(1){
        msleep(rand()%200+300);
        if (rand()%10){			//尝试移动
            pthread_mutex_lock(&editmap);                  
            int tempx,tempy,temp;
            temp=rand()%2;
            tempx=x+temp*(-1+rand()%2*2);
            tempy=y+(1-temp)*(-1+rand()%2*2);
            if (maps[tempx][tempy]==' '){
                maps[x][y]=' ';
                maps[x=tempx][y=tempy]='P';
            }
            pthread_mutex_unlock(&editmap);
        }
        else {					//尝试放水果
            pthread_mutex_lock(&mutex_nums);
            if (fruitnums<=totalnums){
                pthread_mutex_lock(&editmap);                
                int tempx,tempy,temp;
                temp=rand()%2;
                tempx=x+temp*(-1+rand()%2*2);
                tempy=y+(1-temp)*(-1+rand()%2*2);
                if (maps[tempx][tempy]==' '&&eated){
                    pthread_mutex_lock(&mutex_fruits);
                    fruits.push({x,y});
                    mutexx.push(&eated);
                    eated=false;
                    maps[x][y]='F';
                    maps[x=tempx][y=tempy]='P';
                    fruitnums++,proednums++;
                    pthread_mutex_unlock(&mutex_fruits);          
                };
                pthread_mutex_unlock(&editmap);    
            }
            pthread_mutex_unlock(&mutex_nums);
        }
        //pthread_mutex_unlock(&writemap);		//通知线程更新地图  
    }
}

void *consumer(void *arg){
    connums++;
    int x,y;
    int tox,toy;
    bool flag=false;
    bool* wanttoeat;
    while(maps[x=rand()%30][y=rand()%30]!=' ');	//找到一个空位置放入新的消费者
    maps[x][y]='C';
    while(1){
        msleep(rand()%200+300);      
        
        if (flag) {			//向水果方向移动
            if (((x==tox)^(y==toy))&&abs(x+y-tox-toy)==1){	//水果就在旁边
            	pthread_mutex_lock(&editmap);                 
                maps[x][y]=' ';
                maps[x=tox][y=toy]='C';
                flag=false;     
            	pthread_mutex_lock(&mutex_fruits);   
                fruitnums--;
                eatednums++;
                *wanttoeat=true;
            	pthread_mutex_unlock(&mutex_fruits); 
                pthread_mutex_unlock(&editmap);
            }
            else if (x!=tox&&y!=toy){	//x，y均不同，随机选择一个移动
            	pthread_mutex_lock(&editmap); 
                if (rand()%2){  //沿着x移动
                    int tempx=x+(tox>x?1:-1),tempy=y;
                    if (maps[tempx][tempy]==' '){
                        maps[x][y]=' ';
                        maps[x=tempx][y=tempy]='C';
                    }
                    else {		//移动失败，随机移动            
                        int tempx,tempy,temp;
                        temp=rand()%2;
                        tempx=x+temp*(-1+rand()%2*2);
                        tempy=y+(1-temp)*(-1+rand()%2*2);
                        if (maps[tempx][tempy]==' '){
                            maps[x][y]=' ';
                            maps[x=tempx][y=tempy]='C';
                        }
                    }
                }
                else {			//沿着y移动
                    int tempy=y+(toy>y?1:-1),tempx=x;
                    if (maps[tempx][tempy]==' '){
                        maps[x][y]=' ';
                        maps[x=tempx][y=tempy]='C';
                    }
                    else {		//移动失败，随机移动                   
                        int tempx,tempy,temp;
                        temp=rand()%2;
                        tempx=x+temp*(-1+rand()%2*2);
                        tempy=y+(1-temp)*(-1+rand()%2*2);
                        if (maps[tempx][tempy]==' '){
                            maps[x][y]=' ';
                            maps[x=tempx][y=tempy]='C';
                        }                        
                    }
                }
                pthread_mutex_unlock(&editmap);
            }
            else if (x!=tox){	//x不同，尝试移动
            	pthread_mutex_lock(&editmap);                 
                    int tempx=x+(tox>x?1:-1),tempy=y;
                    if (maps[tempx][tempy]==' '){
                        maps[x][y]=' ';
                        maps[x=tempx][y=tempy]='C';
                    }
                    else {		//移动失败，随机移动                
                        int tempx,tempy,temp;
                        temp=rand()%2;
                        tempx=x+temp*(-1+rand()%2*2);
                        tempy=y+(1-temp)*(-1+rand()%2*2);
                        if (maps[tempx][tempy]==' '){
                            maps[x][y]=' ';
                            maps[x=tempx][y=tempy]='C';
                        }
                    }
                pthread_mutex_unlock(&editmap);
            }
            else if (y!=toy){	//y不同，尝试移动
            	pthread_mutex_lock(&editmap);       
                    int tempy=y+(toy>y?1:-1),tempx=x;
                    if (maps[tempx][tempy]==' '){
                        maps[x][y]=' ';
                        maps[x=tempx][y=tempy]='C';
                    }
                    else {		//移动失败，随机移动                 
                        int tempx,tempy,temp;
                        temp=rand()%2;
                        tempx=x+temp*(-1+rand()%2*2);
                        tempy=y+(1-temp)*(-1+rand()%2*2);
                        if (maps[tempx][tempy]==' '){
                            maps[x][y]=' ';
                            maps[x=tempx][y=tempy]='C';
                        }                        
                    }     
                pthread_mutex_unlock(&editmap);           
            }
        }
        else {				//当前没有水果
            pthread_mutex_lock(&mutex_fruits);   
            if (!fruits.empty()){		//尝试发现水果
                flag=true;
                tox=fruits.front().first;
                toy=fruits.front().second;
                wanttoeat=mutexx.front();
                mutexx.pop();
                fruits.pop();
            }
            pthread_mutex_unlock(&mutex_fruits);   
            //随机移动
            pthread_mutex_lock(&editmap);                   
            int tempx,tempy,temp;
            temp=rand()%2;
            tempx=x+temp*(-1+rand()%2*2);
            tempy=y+(1-temp)*(-1+rand()%2*2);
            if (maps[tempx][tempy]==' '){
                maps[x][y]=' ';
                maps[x=tempx][y=tempy]='C';
            }
            pthread_mutex_unlock(&editmap);            
        }
        //pthread_mutex_unlock(&writemap);		//通知线程更新地图        
    }
}

void init(){				//初始化
    HIDE_CURSOR();
    srand(time(0));
    //pthread_mutex_init(&writemap,NULL);
    pthread_mutex_init(&editmap,NULL);
    pthread_mutex_init(&mutex_nums,NULL);
    pthread_mutex_init(&mutex_fruits,NULL);    
	CLEAR();
    for (int i=0;i<30;i++){
        for (int j=0;j<30;j++){
            maps[i][j]=' ';
        }
    }
    for (int i=0;i<30;i++){
        maps[i][0]='#';
        maps[i][29]='#';
        maps[0][i]='#';
        maps[29][i]='#';        
    }
}

void start(){
    pthread_create(&flushscreen, NULL, printMaps, NULL);    
    for (int i=0;i<totalnums;i++){
        msleep(200);
        pthread_create(pro+i, NULL, producer, NULL);
        msleep(200);
        pthread_create(con+i, NULL, consumer, NULL);
    }    
}

void waitForExit(){
    char temp;
    scanf("%c",&temp);
    stop=true;
    pthread_join(flushscreen, NULL);
    MOVETO(0,0);
    SHOW_CURSOR();
    CLEAR();    
}

int main(){
    init();
    start();
    waitForExit();
}
