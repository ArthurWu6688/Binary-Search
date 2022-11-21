#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;
typedef struct{
    ElemType *elem;//整形指针
    int TableLen;//储存动态数组里边元素的个数
}SStable;

void ST_init(SStable &ST,int len){
    ST.TableLen=len;
    ST.elem=(ElemType*)malloc(sizeof(ElemType));
    int i;
    srand(time(NULL));
    for(i=0;i<ST.TableLen;++i){
        ST.elem[i]=rand()%100;
    }
}

void ST_print(SStable ST){
    for(int i=0;i<ST.TableLen;++i){
        printf("%3d",ST.elem[i]);
    }
    printf("\n");
}

int binary_search(SStable ST,ElemType key){
    int low=0;
    int high=ST.TableLen-1;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(key>ST.elem[mid]){
            low=mid+1;
        }else if(key<ST.elem[mid]){
            high=mid-1;
        }else{
            return mid;
        }
    }
    return -1;
}
//函数名中存储的是函数的入口地址，也是一个指针，是函数指针类型
//left和right是指向数组中的任意两个元素
//qsort规定如果left指针指向的值大于right指针指向的值，返回正值，反之返回负值，相等返回0
int compare(const void* left,const void* right){
    return *(ElemType *)left-*(ElemType *)right;//从小到大排序
    //return *(ElemType *)right-*(ElemType *)left; 从大到小排序
}

int main(){
    SStable ST;
    ST_init(ST,10);
    qsort(ST.elem,ST.TableLen,sizeof(ElemType),compare);//排序
    ST_print(ST);

    ElemType key;
    printf("请输入要查找的数值:");
    scanf("%d",&key);
    int pos=binary_search(ST,key);
    if(pos!=-1){
        printf("找到了，下标是%d\n",pos);
    }else{
        printf("没找到\n");
    }
    return 0;
}