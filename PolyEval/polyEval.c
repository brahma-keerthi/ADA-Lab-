#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define X 2

//  1 + 2*x + 3*x2 + .....

int polyEval(int arr[], int x,  int n){
    int count = 0, i , power = 1;
    int ans = arr[0];

    for(i = 1; i<n; i++){
        power *= x;
        ans += power * arr[i];
        count ++;
    }
    return count;
}

void main(){
    int n, i, *arr, pat[4];
    FILE *a, *b, *w;
    system("rm count.txt");
    a =fopen("count.txt", "a");

    for(n = 100; n<=1000; n+=100){
        arr = (int *)malloc(sizeof(int)* n);

        for(i = 0; i<n; i++)
            arr[i] = i+1;
        fprintf(a, "%d  %d\n", n, polyEval(arr, X, n));
    }

    fclose(a);
}