#include<stdio.h>
#include<stdlib.h>

void main(){
    int n, key;
    printf("Enter array size>> ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements in sorted order>> ");
    for (int i = 0; i<n; i++)
        scanf("%d", &arr[i]);

    printf("Enter key>> ");
    scanf("%d", &key);

    int high = n-1 , low = 0, mid;

    while(low<=high){
        mid = (high + low)/2;
        if (arr[mid]==key){
            printf("Key found at index>> %d", mid);
            exit(0);
        }
        else if (arr[mid] > key)
            high = mid - 1;
        else 
            low = mid + 1;
    }

    printf("Key not found");
}