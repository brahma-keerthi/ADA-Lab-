#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int arr[], int n, int i){
    // arr, size , root
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[largest] < arr[left])
        largest = left;
    if (right < n && arr[largest] < arr[right])
        largest = right;

    if (i != largest){
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    for(int i = n/2 -1 ; i>-1; i--){
        heapify(arr, n, i);
    }

    for( int i = n-1; i>-1; i--){
        swap(&arr[i] , &arr[0]);
        heapify(arr, i, 0);
    }
}

void main(){
    int n, i;
    printf("Enter the array size>> ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array >> ");
    for(i = 0; i<n; i++)
        scanf("%d", &arr[i]);

    printf("Before sorting >> \n");
    for(i = 0; i<n ; i++)
        printf("%d  ", arr[i]);
    heapSort(arr, n);
    printf("\nAfter sorting >> \n");
    for(i = 0; i<n ; i++)
        printf("%d  ", arr[i]);
}