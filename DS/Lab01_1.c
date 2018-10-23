#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define namesize 10
typedef int bool;
const int true=1;
const int false=0;
const double eps=1e-6;

typedef struct city{
    char name[namesize];
    double x,y;
}city;

typedef struct ListNode{
    city data;
    struct ListNode *next;
}ListNode;
ListNode* root=NULL;

void cls(){
    #ifdef linux
        system("clear");
    #endif
    #ifdef __WINDOWS_ 
        system("cls");
    #endif    
}

void output(city a){
    printf("城市 %s 的坐标是 (%.3lf,%.3lf)\n",a.name,a.x,a.y);
}

bool cmp(double a,double b){
    return abs(a-b)<eps;
}

void copyCity(city* to,city* from){
    to->x=from->x;
    to->y=from->y;
    strcpy(to->name,from->name);
}

ListNode* insert(ListNode* root,city data){
    ListNode *temp=(ListNode*)malloc(sizeof(ListNode));
    copyCity(&(temp->data),&data);
    temp->next=root;
    return temp;
}

bool deleteCityByName(ListNode* root,ListNode** pre,char name[]){
    if (root==NULL){
        return false;
	}
    else if (!strcmp(name,root->data.name)){
        (*pre)=root->next;
        free(root);
        return true;
    }
    else return deleteCityByName(root->next,&(root->next),name);
}

bool deleteCityByLocation(ListNode* root,ListNode** pre,double x,double y){
    if (root==NULL){
        return false;
	}
    else if (cmp(root->data.x,x)&&cmp(root->data.y,y)){
        (*pre)=root->next;
        free(root);
        return true;
    }
    else return deleteCityByLocation(root->next,&(root->next),x,y);
}

city* findCityByName(ListNode* root,char name[]){
    if (root==NULL){
        return NULL;
    }
    else if (!strcmp(name,root->data.name)){
        return &(root->data);
    }
    else return findCityByName(root->next,name);
}

city* findCityByLocation(ListNode* root,double x,double y){
    if (root==NULL){
        return NULL;
    }
    else if (cmp(root->data.x,x)&&cmp(root->data.y,y)){
        return &(root->data);
    }
    else return findCityByLocation(root->next,x,y);
}

double sqr(double a){
    return a*a;
}

double distOfCityAndPoint(city a,double x,double y){
    return sqrt(sqr(a.x-x)+sqr(a.y-y));
}

void outputCityNameNearLocation(ListNode *root,double x,double y,double dist){
    int num=0;
    while(root!=NULL){
		if (distOfCityAndPoint(root->data,x,y)<dist){
        	printf("城市 %s 到 (%.3lf,%.3lf) 的距离为 %.3lf\n",root->data.name,x,y,distOfCityAndPoint(root->data,x,y));   
            ++num;
        }
        root=root->next;
    }
    if (num==0){
        printf("没有与点 (%.3lf,%.3lf) 距离在 %.3lf 以内的城市\n",x,y,dist);        
    }
}

int outputAllCity(ListNode* root){
    if (root==NULL)return 0;
    output(root->data);
    return outputAllCity(root->next)+1;
}

void function1(){
    city input;
    printf("请输入城市名（不含空格,不超过10个字符）:");
    scanf("%s",input.name);
    printf("请输入城市坐标（两个数x,y，中间以空格隔开）:");
    scanf("%lf %lf",&input.x,&input.y);
    root=insert(root,input);
    cls();
    printf("插入成功\n");    
}

void function2(){
    char input[namesize];
    printf("请输入想要删除的城市的名字（不含空格,不超过10个字符）:");    
    scanf("%s",input);
    cls();
    if (deleteCityByName(root,&root,input)){
  		printf("成功删除一个名字为 %s 的城市\n",input);
    }
    else{
        printf("未找到名称为 %s 的城市\n",input);
    }    
}

void function3(){
    double x,y;
    printf("请输入想要删除的城市坐标（两个数x,y，中间以空格隔开）:");   
    scanf("%lf %lf",&x,&y);
    cls();
    if (deleteCityByLocation(root,&root,x,y)){
  		printf("成功删除一个坐标为 (%.3lf,%.3lf) 的城市\n",x,y);
    }
    else{
        printf("未找到坐标为 (%.3lf,%.3lf) 的城市\n",x,y);
    }    
}

void function4(){
    char input[namesize];
    printf("请输入想要查找的城市名字（不含空格,不超过10个字符）:");    
    scanf("%s",input);
    city* ret;
    cls();
    if ((ret=findCityByName(root,input))!=NULL){
        output(*ret);
    }
    else{
        printf("未找到名称为 %s 的城市\n",input);
    }    
}

void function5(){
    double x,y;
    printf("请输入想要查找的城市坐标（两个数x,y，中间以空格隔开）:");   
    scanf("%lf %lf",&x,&y);
    city* ret;
    cls();
    if ((ret=findCityByLocation(root,x,y))!=NULL){
        output(*ret);
    }
    else{
        printf("未找到坐标为 (%.3lf,%.3lf) 的城市\n",x,y);
    }        
}

void function6(){
    char input[namesize];
    printf("请输入想要修改的城市的名字（不含空格,不超过10个字符）:");    
    scanf("%s",input);
    city* ret;
    if (ret=findCityByName(root,input)){
        output(*ret);
        printf("您想要将坐标修改为？（两个数x,y，中间以空格隔开）\n"); 
        double x,y;
    	scanf("%lf %lf",&x,&y);
        ret->x=x;
        ret->y=y;
    	cls();
        printf("修改成功!\n");
    }
    else{
    	cls();
        printf("未找到名称为 %s 的城市\n",input);
    }
}

void function7(){
    double x,y;
    printf("请输入想要修改的城市的坐标（两个数x,y，中间以空格隔开）:");   
    scanf("%lf %lf",&x,&y);
    city* ret;
    if (ret=findCityByLocation(root,x,y)){
        output(*ret);
        printf("您想要将名字修改为？（不含空格,不超过10个字符）\n"); 
        char input[namesize];
    	scanf("%s",input);
        strcpy(ret->name,input);
    	cls();
        printf("修改成功!\n");
    }
    else{
    	cls();
        printf("未找到坐标为 (%.3lf,%.3lf) 的城市\n",x,y);
    }    
}

void function8(){
    double x,y,dist;
    printf("请输入指定的坐标（两个数x,y，中间以空格隔开）:");
    scanf("%lf %lf",&x,&y);
    printf("请输入指定的距离:");
    scanf("%lf",&dist);
    cls();
    outputCityNameNearLocation(root,x,y,dist);
}

void function9(){
    cls();
    printf("当前共有 %d 个城市\n",outputAllCity(root));
}

int getFunction(){
    char input[namesize];
    printf("请输入一个数字选择您所想要使用的功能:\n");
    printf("1：插入一个城市；\n");
    printf("2：根据城市名删除城市；\n");
    printf("3：根据城市坐标删除城市；\n");
    printf("4：根据城市名查找城市；\n");
    printf("5：根据城市坐标查找城市；\n");
    printf("6：根据城市名修改坐标；\n");
    printf("7：根据城市坐标修改城市名；\n");    
    printf("8：找出与某一坐标距离在某一值之内的所有城市；\n");
    printf("9：输出当前的所有城市；\n");    
    printf("0：退出程序。\n");
    printf("请输入：");
    scanf("%s",input);
    cls();
    return input[0]-'0';
}

int main(){
    cls();
    printf("欢迎使用城市地理位置查询系统\n");
    for (;;){
        switch(getFunction()){
            case 1:
                function1();
                break;
            case 2:
                function2();
                break;
            case 3:
                function3();
                break;
            case 4:
                function4();
                break;
            case 5:
                function5();
                break;
            case 6:
                function6();                
                break;
            case 7:
                function7();                
                break;
            case 8:
                function8();                
                break;
            case 9:
                function9();                
                break;
            case 0:
                printf("欢迎下次使用，再见。\n");
                return 0;
            default:
                printf("输入错误，请重新输入\n");
        }
        puts("");
    }
    return 0;
}