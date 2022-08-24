#include<stdio.h>

#define nSize 10 //size of array

int main(){
    int nArr[nSize]={0};
    int i=0;

    printf("Enter 10 Elements: ");
    for (i=0; i<10; i++)
        scanf("%d", &nArr[i]);
 
    for(i=0; i<nSize-1 ; i++) { if(nArr[i]>nArr[i+1])
        //if(nArr[i]<nArr[i+1]) to check descending order
        {
            printf("Array is not sorted in assenting order");
        }
    }
    printf("Array is sorted in assenting order");
    return 0;
}
