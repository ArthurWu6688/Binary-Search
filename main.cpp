#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;
typedef struct{
    ElemType *elem;//����ָ��
    int TableLen;//���涯̬�������Ԫ�صĸ���
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
//�������д洢���Ǻ�������ڵ�ַ��Ҳ��һ��ָ�룬�Ǻ���ָ������
//left��right��ָ�������е���������Ԫ��
//qsort�涨���leftָ��ָ���ֵ����rightָ��ָ���ֵ��������ֵ����֮���ظ�ֵ����ȷ���0
int compare(const void* left,const void* right){
    return *(ElemType *)left-*(ElemType *)right;//��С��������
    //return *(ElemType *)right-*(ElemType *)left; �Ӵ�С����
}

int main(){
    SStable ST;
    ST_init(ST,10);
    qsort(ST.elem,ST.TableLen,sizeof(ElemType),compare);//����
    ST_print(ST);

    ElemType key;
    printf("������Ҫ���ҵ���ֵ:");
    scanf("%d",&key);
    int pos=binary_search(ST,key);
    if(pos!=-1){
        printf("�ҵ��ˣ��±���%d\n",pos);
    }else{
        printf("û�ҵ�\n");
    }
    return 0;
}