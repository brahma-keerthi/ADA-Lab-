#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int search(int txt[],int pat[],  int n, int m){
    int count = 0, i , j;

    for(i = 0; i<n-m; i++){
        j = 0;
        while (txt[i+j] == pat[j] && j<m){
            count++;
            j++;
        }
        if (j==m)
            return count;
    }
    
    return count;
}

void main(){
    srand(time(0));
    int n, i, *arr, pat[4];
    FILE *a, *b, *w;
    system("rm best.txt");
    system("rm avg.txt");
    system("rm worst.txt");
    a =fopen("avg.txt", "a");
    b = fopen("best.txt", "a");
    w = fopen("worst.txt", "a");

    for(n = 100; n<=1000; n+=100){
        arr = (int *)calloc(sizeof(int), n);

        // best case ->> first 4 character matching
        pat[0] = pat[1] = pat[2] = pat[3] = 0;
        fprintf(b, "%d  %d\n", n, search(arr,pat, n, 4));

        // Worst case ->> all comparition all traversal
        pat[3] = 1;
        fprintf(w, "%d  %d\n", n, search(arr,pat, n, 4));

        // avg case -->> Half traversals and half comparitions
        pat[2] = pat[3] =1;
        arr[n/2] = arr[n/2 +1] = 1;
        fprintf(a, "%d  %d\n", n, search(arr,pat, n, 4));
    }

    fclose(w);
    fclose(a);
    fclose(b);
}