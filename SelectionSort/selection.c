#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int sort(int arr[], int n){
    int count = 0, min = 0, i , j;
    for(i = 0; i<n-1; i++){
        min = i;
        for(j = i+1; j<n; j++){
            count++;
            if(arr[min] > arr[j])
                min = j;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min]  = temp;
    }
    return count;
}

void main(){
    srand(time(0));
    int n, i, *arr;
    FILE *a, *b, *w;
    system("rm best.txt");
    system("rm avg.txt");
    system("rm worst.txt");
    a =fopen("avg.txt", "a");
    b = fopen("best.txt", "a");
    w = fopen("worst.txt", "a");

    for(n = 100; n<=1000; n+=100){
        arr = (int *)malloc(sizeof(int)*n);

        // best case ->>sorted
        for(i = 0; i<n ; i++)
            arr[i] = i;
        fprintf(b, "%d  %d\n", n, sort(arr, n));

        // Worst case ->> Reverse sorted
        for(i = 0; i<n; i++)
            arr[i] = n -i;
        fprintf(w, "%d  %d\n", n, sort(arr, n));

        // avg case -->> Half sorted and half reverse sorted
        for(i = 0; i<n; i++)
            arr[i] = (i<n/2) ? i : n-i;
        fprintf(a, "%d  %d\n", n, sort(arr, n));
    }

    fclose(w);
    fclose(a);
    fclose(b);
}