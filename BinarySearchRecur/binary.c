#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int count = 0;

void search(int arr[], int key, int first, int last){
    if (first <= last){
        count++;
        int mid = (first + last)/2;
    
        if (key == arr[mid])
            return;
        else if(key > arr[mid])
            search(arr, key, mid + 1, last);
        else
            search(arr, key, first, mid - 1);
    }
}

void main(){
    srand(time(0));
    int n, i, *arr, key;
    FILE *a, *b, *w;
    system("rm best.txt");
    system("rm avg.txt");
    system("rm worst.txt");
    a =fopen("avg.txt", "a");
    b = fopen("best.txt", "a");
    w = fopen("worst.txt", "a");

    for(n = 100; n<=1000; n+=100){
        arr = (int *)malloc(sizeof(int)*n);
        for(i = 0; i<n ; i++)
            arr[i] = i + 1;

        // best case ->> mid is key
        key = arr[(n-1)/2];
        search(arr, key, 0, n-1);
        fprintf(b, "%d  %d\n", n, count);
        count = 0;

        // Worst case ->> key is one corner of array
        key = arr[n-1];
        search(arr, key, 0, n-1);
        fprintf(w, "%d  %d\n", n, count);
        count = 0;

        // avg case -->> key is in 1/4th position
        key = arr[(n-1)/8] ;
        search(arr, key, 0, n-1);
        fprintf(a, "%d  %d\n", n, count);
        count = 0;
    }

    fclose(w);
    fclose(a);
    fclose(b);
}