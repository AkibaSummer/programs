
void Get_next(SString T,int next[]){
    int j,k;
    j=1;k=0;
    next[1]=0;
    while(j<=T[0]){
        if (k==0||T[j]==T[k]){
            ++j;++k;
            next[j]=k;
        }
        else k=next[k];
    }
}

int get_nextval(SString T,int nextval[]){
    int j,k;
    j=1;nextval[1]=0;k=0;
    while(j<T[0]){
        if (k==0||T[j]==T[k]){
            ++j;++k;
            if (T[j]!=T[k])nextval[j]=k;
            else nextval[j]=nextval[k];
        }
        else j=nextval[j];
    }
}