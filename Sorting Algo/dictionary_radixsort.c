#include<stdio.h>
#include<string.h>

int maxlength(char str[][100],int n);
void radixsort(char str[][100],int n);
void countingsort(char str[][100],int n,int pos);

int main(int argc,char *argv[])
{
    
    char str[5][100]={"apple","ant","access","good","suk"};

    radixsort(str,5);


    for(int i=0;i<5;i++) printf("%s\n",str[i]);


    return 0;
}

int maxlength(char str[][100],int n){
    int maxlen=0;
    for(int i=0;i<n;i++){
        if(strlen(str[i])>maxlen) maxlen=strlen(str[i]);
    }

    return maxlen;

}

void radixsort(char str[][100],int n){
    int maxlen=maxlength(str,5);

    for (int pos = maxlen-1; pos>=0; pos--) {
        countingsort(str,n,pos);
    }

}

void countingsort(char str[][100],int n,int pos){
    int count[256]={0};
    char output[n][100];

    for(int i=0;i<n;i++) count[str[i][pos]]++;

    for(int i=1;i<256;i++) count[i]+=count[i-1];

    for(int i=n-1;i>=0;i--){
        int index=count[str[i][pos]]-1;
        strcpy(output[index],str[i]);
        count[str[i][pos]]--;
    }

    for(int i=0;i<n;i++) strcpy(str[i],output[i]);



}