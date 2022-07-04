#include<stdio.h>
#include<stdlib.h>

void main(){
    int n, key;
    printf("Enter the size of array>> ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the array elements>> ");
    for(int i = 0;i<n; i++)
        scanf("%d", &arr[i]);

    printf("Enter key>> ");
    scanf("%d", &key);

    for (int i = 0; i<n; i++){
        if (key == arr[i]){
            printf("Key found at index>> %d", i);
            exit(0);
        }
    }
    printf("Key not found");
}