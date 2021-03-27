#include<bits/stdc++.h>

using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int *a,int s,int r){
    int pivot = a[r];
    int i=s-1;
    for(int j=s;j<=r;j++){
        if(a[j]<pivot){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[r]);
    return i+1;
}


void quick_sort(int *arr,int s,int r){
    if(s<r){
        int c=partition(arr,s,r);
        quick_sort(arr,s,c-1);
        quick_sort(arr,c+1,r);
    }
}

void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
	quick_sort(input,0,size-1);
}

int main()
{
    int arr[] = {1,2,3,4,5};
    quickSort(arr,sizeof(arr)/sizeof(int));
}