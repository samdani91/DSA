#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int findmax(int arr[],int n);
void countsort(int arr[],int n);

int main(int argc,char *argv[])
{

    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) arr[i]=rand()%n;

    countsort(arr,n);

    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");

    return 0;
}

void countsort(int arr[],int n){
    int max=findmax(arr,n);
    int count[max+1];
    for(int i=0;i<=max;i++) count[i]=0; //initialize the count array with zeroes

    int output[n];

    for(int i=0;i<n;i++) count[arr[i]]++; //frequency array

    for(int i=1;i<=max;i++) count[i]+=count[i-1]; //prefix sum array

    for(int i=n-1;i>=0;i--){
        int index=count[arr[i]]-1;
        output[index]=arr[i];
        count[arr[i]]--;
    }

    for(int i=0;i<n;i++) arr[i]=output[i];


}

int findmax(int arr[],int n){
    int max=0;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return  max;
}