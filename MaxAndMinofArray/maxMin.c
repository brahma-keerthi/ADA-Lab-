#include<stdio.h>
#include<stdlib.h>

int count = 0;

int Max(int arr[], int first, int last){
    if (first == last)
        return arr[first];

    int mid = (first + last)/2;
    int t1 = Max(arr, first, mid);
    int t2 = Max(arr, mid + 1, last);

    count++;
    if (t1>t2)
        return t1;
    else
        return t2;
}

int Min(int arr[], int first, int last){
    if (first == last)
        return arr[last];

    int mid = (first + last)/2;
    int t1 = Min(arr, first, mid);
    int t2 = Min(arr, mid + 1, last);

    count++;
    if(t1<t2)
        return t1;
    else   
        return t2;
}

void main(){
    int n, i, *arr;
    FILE *w, *a;
    system("rm countMax.txt");
    system("rm countMin.txt");
    w = fopen("countMax.txt", "a");
    a = fopen("countMin.txt", "a");

    for(n = 100; n<=1000; n+=100){
        arr = (int *)malloc(sizeof(int)*n);

        for(i = 0; i<n; i++) 
           arr[i] = i+1;
           
        Max(arr, 0, n-1);
        fprintf(w, "%d  %d\n", n, count);
        count = 0;

        Min(arr, 0, n-1);
        fprintf(a, "%d  %d\n", n, count);
        count = 0;
    }
    fclose(a);
    fclose(w);
}