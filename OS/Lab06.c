#include <sys/types.h>	//open所需头文件
#include <sys/stat.h>	//open所需头文件
#include <fcntl.h>		//open所需头文件
#include <unistd.h>		//read|write|lseek所需头文件
#include <stdio.h>
#include <stdlib.h>


int getFunction(){
    puts("0、退出");
    puts("1、创建新文件");
    puts("2、写文件");
    puts("3、读文件");
    puts("4、修改文件权限");
    puts("5、查看当前文件权限并退出");
    char ch[2];
    scanf("%s",ch);
    while (ch[0]<'0'||ch[0]>'5'){
        puts("输入错误，请重新输入");
        scanf("%s",ch);
    }
}

int getfile(int flags,mode_t mode){
    char a[256];
    puts("请输入（或拖入）文件名或路径：");
    for(;;){
        gets(a);
        int ret=open(a,flags,mode);
        if (ret==-1){
            puts("文件路径错误");
        }
        else {
            return ret;
        }
    };
}

int func1(){
    
}
int func2(){
    
}
int func3(){
    
}
int func4(){
    
}
int func5(){
    
}

int main(){
    for (;;){
        switch (getFunction()){
            case 0:
                return 0;
            case 1:
                func1();
                break;
            case 2:
                func2();
                break;
            case 3:
                func3();
                break;
            case 4:
                func4();
                break;
            case 5:
                func5();
                return 0;
        }
    }
}

/*****************
参考资料：
https://www.linuxidc.com/Linux/2016-11/137612.htm

https://blog.csdn.net/ljianhui/article/details/10055665

https://blog.csdn.net/shanshanpt/article/details/39852249
*****************/