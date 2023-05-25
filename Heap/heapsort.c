#include<stdio.h>
/*                                  9
                            4               5
                        1       3       2
                        
*/

void heapify(int cbt[],int i);
void swap(int *a,int *b);
void print(int cbt[]);
int extractRoot(int cbt[]);
void Heapsort(int cbt[]);

int size=0;

int main(int argc,char *argv[])
{

    int cbt[10]={3,9,2,1,4,5}; 
    int ins,del;
    for(int i=0;i<10;i++){
        if(cbt[i]!=0) size++;
    }
    
    for(int i=(size/2)-1;i>=0;i--){
        heapify(cbt,i);
    }
    print(cbt);
    Heapsort(cbt);

    return 0;
}
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;

}
void heapify(int cbt[],int i){
    int l,r,largest;
    largest=i;
    l=2*i+1;
    r=2*i+2;

    if(l<size && cbt[l]>cbt[largest]) largest=l;
    if(r<size && cbt[r]>cbt[largest]) largest=r;

    if(largest!=i){
        swap(&cbt[largest],&cbt[i]);
        heapify(cbt,largest);
    }
    
}

int extractRoot(int cbt[]){
    int item = cbt[0];
    swap(&cbt[0],&cbt[size-1]);
    size--;
    heapify(cbt,0);
    return item;
}

void Heapsort(int cbt[]){
    while(size){
        int x = extractRoot(cbt);
        printf("%d ",x);
    }
}

void print(int cbt[]){
    for(int i=0;i<size;i++){
        printf("%d ",cbt[i]);
    }
    printf("\n");
}