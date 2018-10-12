#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int ElemType;
typedef int Status;
const unsigned int LIST_INIT_SIZE=1000;
const unsigned int LIST_INCREMENT=1000;
const int SUCCESS = 0;
const int ERROR = -1;
const int OVERFLOW = -2;

typedef struct {
    ElemType  *elem;
    int length;
    int listsize;
} SqList;

Status initSqList(SqList *list,ElemType val[],int length){
    list->elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if (!list->elem) return(OVERFLOW);
    list->length = length;
    list->listsize=LIST_INIT_SIZE;
    for (int i=0;i<length;i++){
        *(list->elem+i)=val[i];
    }
    return SUCCESS;
}

ElemType getElem(SqList *list,int pos){
    if (pos<1)return *(list->elem);
    else if (pos>list->length)return *(list->elem+list->length-1);
    else return *(list->elem+pos-1);
}

Status insertSqList(SqList *list,int pos,ElemType val){
    if (pos<1||pos>list->listsize+1)return ERROR;
    if (list->length>=list->listsize){
        ElemType *newBase=(ElemType*)realloc(list->elem,(list->listsize+LIST_INCREMENT)*sizeof(ElemType));
        if (!newBase)return OVERFLOW;
        list->elem=newBase;
        list->listsize+=LIST_INCREMENT;
    }
    if (pos>list->length){
        *(list->elem+pos-1)=val;
        list->length=pos;
        return SUCCESS;
    }
    else {
        ++list->length;
        for (int i=list->length;i>pos;i--){
            *(list->elem+i)=*(list->elem+i-1);
        }
        *(list->elem+pos-1)=val;
        return SUCCESS;
    }
}

Status deleteSqList(SqList *list,int pos){
    if (pos<1||pos>list->length) return ERROR;
    else {
        --list->length;
        for (int i=pos;i<=list->length;i++){
            *(list->elem+i-1)=*(list->elem+i);
        }
        return SUCCESS;
    }
}

Status mergeSortedSqList(SqList *SqListA,SqList *SqListB,SqList *mergedSqList){
    initSqList(mergedSqList,NULL,0);
    int posA=1,posB=1,posC=1;
    for (int i=1;i<=SqListA->length+SqListB->length;i++){
        if (posA>SqListA->length){
            Status tempStatus;
            if ((tempStatus=insertSqList(mergedSqList,posC++,getElem(SqListB,posB++)))!=SUCCESS)return tempStatus;
        }
        else if (posB>SqListB->length){
            Status tempStatus;
            if ((tempStatus=insertSqList(mergedSqList,posC++,getElem(SqListA,posA++)))!=SUCCESS)return tempStatus;
        }
        else if (getElem(SqListA,posA)>getElem(SqListB,posB)){
            Status tempStatus;
            if ((tempStatus=insertSqList(mergedSqList,posC++,getElem(SqListB,posB++)))!=SUCCESS)return tempStatus;
        }
        else {
            Status tempStatus;
            if ((tempStatus=insertSqList(mergedSqList,posC++,getElem(SqListA,posA++)))!=SUCCESS)return tempStatus;
        }
    }
    return SUCCESS;
}

Status mergeUnSortedSqList(SqList *SqListA,SqList *SqListB,SqList *mergedSqList){
    initSqList(mergedSqList,NULL,0);
    for (int i=1;i<=SqListA->length;i++){
        insertSqList(mergedSqList,mergedSqList->length+1,getElem(SqListA,i));
    }
    for (int i=1;i<=SqListB->length;i++){
        insertSqList(mergedSqList,mergedSqList->length+1,getElem(SqListB,i));
    }
    for (int i=1;i<=mergedSqList->length;i++){
        for (int j=i+1;j<=mergedSqList->length;j++){
            if (getElem(mergedSqList,i)==getElem(mergedSqList,j)) deleteSqList(mergedSqList,j--);
        }
    }
    return SUCCESS;
}

int main(){
    SqList a,b,c;
    int val1[3]={1,2,3},val2[4]={2,3,4,5};
    initSqList(&a,val1,3);
    initSqList(&b,val2,4);
    mergeSortedSqList(&a,&b,&c);
    for (int i=0;i<c.length;i++){
        printf("%d ",*(c.elem+i));
    }
    printf("\n");
    mergeUnSortedSqList(&a,&b,&c);
    for (int i=0;i<c.length;i++){
        printf("%d ",*(c.elem+i));
    }
    printf("\n");
}
