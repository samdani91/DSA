#include<stdio.h>

void insertion_sort(int arr[],int n){
    int i=1;
    int j,temp;
    for(int i=1;i<n;i++){
        j=i;
        while(j>0 && arr[j]< arr[j-1]){
            temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
        }
    }
}

int main(int argc,char *argv[])
{
    
    int arr[10]={6,3,9,2,5,8,1,7,4,0};
    insertion_sort(arr,10);

    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }


    return 0;
}