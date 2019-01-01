#include <sys/types.h>	//open所需头文件
#include <sys/stat.h>	//open所需头文件
#include <fcntl.h>		//open所需头文件
#include <unistd.h>		//read|write|lseek所需头文件
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int getFunction(){
    puts("0、退出");
    puts("1、创建新文件");
    puts("2、写文件");
    puts("3、读文件");
    puts("4、修改文件权限");
    puts("5、查看当前文件权限并退出");
    char ch[10];
    scanf("%s",ch);
    while (ch[0]<'0'||ch[0]>'5'){
        puts("输入错误，请重新输入");
        scanf("%s",ch);
    }
    return ch[0]-'0';
}

int getfile(mode_t flags){
    char a[256];
    printf("请输入（或拖入）文件名或路径：");
    for(;;){
        scanf("%s",a);
        int ret=open(a,flags,0666);
        if (ret==-1){
            puts("发生错误");
        }
        else {
            return ret;
        }
    };
}

int func1(){   
    close(getfile(O_RDWR|O_CREAT|O_EXCL));    
    puts("创建成功！");
}
int func2(){
    int ret=getfile(O_WRONLY);
    char buf[1024];
    memset(buf,0,1024);
    puts("请输入要写入的数据：");  
    scanf("%s",buf);
    int retnum=write(ret,buf,strlen(buf));
    if (retnum==-1)puts("写入发生错误");
    else printf("写入成功，buf=%s\n",buf);
    close(ret);
    return 0;
}
int func3(){
    int ret=getfile(O_RDONLY);
    char buf[1024];
    memset(buf,0,1024);
    int retnum=read(ret,buf,1024);
    if (retnum==-1)puts("读取发生错误");
    else printf("读取成功，buf=%s\n",buf);
    close(ret);
    return 0;
}
int func4(){
    int ret=getfile(O_RDONLY);
    puts("请输入要修改的文件权限：");
    mode_t mode;
    scanf("%o",&mode);
    if (fchmod(ret,mode)==-1)
        puts("修改失败");
    else puts("修改成功");
    close(ret);
    return 0;    
}
int func5(){
    int ret=getfile(O_RDONLY);
    struct stat a;
    if (fstat(ret,&a)<0){
        puts("发生错误");
    }
    else {
        printf("所选文件权限为：%o\n",a.st_mode&07777);
    }
    close(ret);
    return 0;
}

int main(){
    for (;;){
        puts("");
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
                break;
        }
    }
}

/*****************
参考资料：
https://www.linuxidc.com/Linux/2016-11/137612.htm
https://blog.csdn.net/u014647208/article/details/5333731
https://blog.csdn.net/ljianhui/article/details/10055665
https://blog.csdn.net/shanshanpt/article/details/39852249
*****************/