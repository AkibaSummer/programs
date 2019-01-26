#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ElemType int
#define true 1
#define false 0
#define maxnum 100

int comptimes,assitimes;

void swap(ElemType *a,ElemType *b){
    assitimes+=3;
    ElemType c=*a;
    *a=*b;
    *b=c;
}

//直接插入排序
void InsertSort1(ElemType A[],int n){
    int i,j;
    for (i=2;i<=n;i++){
        if (++comptimes,A[i]<A[i-1]){
            A[0]=A[i];
            ++assitimes;
            for (j=i-1;++comptimes,A[0]<A[j];--j){
                A[j+1]=A[j];
                ++assitimes;
            }
            A[j+1]=A[0];
            ++assitimes;
        }
    }
}

//折半插入排序
void InsertSort2(ElemType A[],int n){
    int i,j,low,high,mid;
    for (i=2;i<=n;i++){
        A[0]=A[i];
        ++assitimes;
        low=1,high=i-1;
        while(low<=high){
            mid=(low+high)/2;
            if (++comptimes,A[mid]>A[0])high=mid-1;
            else low=mid+1;
        }
        for (j=i-1;j>=high+1;--j){
            A[j+1]=A[j];
            ++assitimes;
        }
        A[high+1]=A[0];
        ++assitimes;
    }
}

//希尔排序
void ShellSort(ElemType A[],int n){
    int dk,i,j;
    for (dk=n/2;dk>=1;dk/=2)
        for (i=dk+1;i<=n;i++)
            if (++comptimes,A[i]<A[i-dk]){
                A[0]=A[i];
                ++assitimes;
                for (j=i-dk;++comptimes,j>0&&A[0]<A[j];j-=dk){
                    A[j+dk]=A[j];
                    ++assitimes;
                }
                A[j+dk]=A[0];
                ++assitimes;
            }
}

//冒泡排序
void BubbleSort(ElemType A[],int n){
    int i,j;
    int flag;
    for (i=0;i<n-1;i++){
        flag=false;
        for (j=n-1;j>i;j--)
            if(++comptimes,A[j-1]>A[j]){
                swap(A+j-1,A+j);
                flag=true;
            }
            if (flag=false)
                return;
    }
}

//快速排序
int Partition(ElemType A[],int low,int high){
    ElemType pivot=A[low];
    ++assitimes;
    while(low<high){
        while(++comptimes,low<high&&A[high]>=pivot)--high;
        A[low]=A[high];
        ++assitimes;
        while(++comptimes,low<high&&A[low]<=pivot)++low;
        A[high]=A[low];
        ++assitimes;
    }
    A[low]=pivot;
    ++assitimes;
    return low;
}
void QuickSort(ElemType A[],int low,int high){
    if (low<high){
        int pivotpos=Partition(A,low,high);
        QuickSort(A,low,pivotpos-1);
        QuickSort(A,pivotpos+1,high);
    }
}

//简单选择排序
void SelectSort(ElemType A[],int n){
    int i,j,min;
    for (i=0;i<n-1;i++){
        min=i;
        for (j=i+1;j<n;j++)
            if (++comptimes,A[j]<A[min])min=j;
        if (min!=i)swap(A+i,A+min);
    }
}

//堆排序
void AdjustDown(ElemType A[],int k,int len){
    A[0]=A[k];
    ++assitimes;
    int i;
    for (i=2*k;i<=len;i*=2){
        if (++comptimes,i<len&&A[i]<A[i+1])i++;
        if (++comptimes,A[0]>=A[1])break;
        else{
            A[k]=A[i];
            ++assitimes;
            k=i;
        }
    }
    A[k]=A[0];
    ++assitimes;
}
void BuildMaxHeap(ElemType A[],int len){
    for (int i=len/2;i>0;i--)
        AdjustDown(A,i,len);
}
void HeapSort(ElemType A[],int len){
    BuildMaxHeap(A,len);
    int i;
    for (i=len;i>1;i--){
        swap(A+i,A+1);
        AdjustDown(A,1,i-1);
    }
}

//归并排序 
void Merge(ElemType A[],int low,int mid,int high){
    ElemType *B=(ElemType*)malloc((high+1)*sizeof(ElemType));
    for (int k=low;k<=high;k++){
        B[k]=A[k];
        ++assitimes;
    }
    int i,j,k;
    for (i=low,j=mid+1,k=i;i<=mid&&j<=high;k++){
        if (++comptimes,B[i]<=B[j])A[k]=B[i++];
        else A[k]=B[j++];
        ++assitimes;
    }
    while(i<mid) {
        A[k++]=B[i++];
        ++assitimes;
    }
    while(j<=high) {
        A[k++]=B[j++];
        ++assitimes;
    }
}
void MergeSort(ElemType A[],int low,int high){
    if (low<high){
        int mid=(low+high)/2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        Merge(A,low,mid,high);
    }
}

void copyArr(ElemType A[],ElemType B[],int n){
    for (int i=1;i<=n;i++){
        B[i]=A[i];
        ++assitimes;
    }
}

int main(){
    ElemType arr[maxnum+5],sorted[maxnum+5];
    srand(time(0));
    for (int t=1;t<=5;t++){
        printf("第%d次比较：\n",t);
        for (int i=1;i<=maxnum;i++){
            arr[i]=rand()%1000;
        }
        comptimes=assitimes=0;
        copyArr(arr,sorted,maxnum);
        InsertSort1(sorted,maxnum);
        printf("直接插入排序：\n比较次数 %d\n移动次数 %d\n\n",comptimes,assitimes);
        
        comptimes=assitimes=0;
        copyArr(arr,sorted,maxnum);
        InsertSort2(sorted,maxnum);
        printf("折半插入排序：\n比较次数 %d\n移动次数 %d\n\n",comptimes,assitimes);
        
        comptimes=assitimes=0;
        copyArr(arr,sorted,maxnum);
        ShellSort(sorted,maxnum);
        printf("希尔排序：\n比较次数 %d\n移动次数 %d\n\n",comptimes,assitimes);
        
        comptimes=assitimes=0;
        copyArr(arr,sorted,maxnum);
        BubbleSort(sorted,maxnum);
        printf("起泡排序：\n比较次数 %d\n移动次数 %d\n\n",comptimes,assitimes);
        
        comptimes=assitimes=0;
        copyArr(arr,sorted,maxnum);
        QuickSort(sorted,1,maxnum);
        printf("快速排序：\n比较次数 %d\n移动次数 %d\n\n",comptimes,assitimes);
        
        comptimes=assitimes=0;
        copyArr(arr,sorted,maxnum);
        SelectSort(sorted,maxnum);
        printf("简单选择排序：\n比较次数 %d\n移动次数 %d\n\n",comptimes,assitimes);
        
        comptimes=assitimes=0;
        copyArr(arr,sorted,maxnum);
        HeapSort(sorted,maxnum);
        printf("堆排序：\n比较次数 %d\n移动次数 %d\n\n",comptimes,assitimes);
        
        comptimes=assitimes=0;
        copyArr(arr,sorted,maxnum);
        MergeSort(sorted,1,maxnum);
        printf("归并排序：\n比较次数 %d\n移动次数 %d\n\n",comptimes,assitimes);
    }
}











