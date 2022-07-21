#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int count = 0;

void merge(int arr[], int first, int mid, int last){
    int k = first;
    int n1 = mid - first + 1;
    int n2 = last - mid;
    //  a and b are two temp array for merging
    int a[n1];
    int b[n2];
    int i = 0, j = 0;

    for(int x = 0; x<n1; x++)
        a[x] = arr[first + x];

    for(int x = 0; x<n2; x++)
        b[x] = arr[mid + 1 + x];

    while(i < n1 && j < n2){
        count++;
        if (a[i] <= b[j]){
            arr[k++] = a[i++];
        }
        else
            arr[k++] = b[j++];
    }

    while(i<n1)
        arr[k++] = a[i++];
    while(j<n2)
        arr[k++] = b[j++];
}

// NOTE-> first and last is index not size of array
void divide(int arr[], int first, int last){
    if(first<last){
        int mid = (last + first)/2;

        divide(arr, first, mid);
        divide(arr, mid + 1, last);

        merge(arr, first, mid, last);
    }
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

        // BEST case -> array already sorted in reverse order
        for(i = 0; i<n; i++)
            arr[i] = i;
        divide(arr, 0, n-1);
        fprintf(b, "%d  %d\n", n, count);
        count = 0;

        // Worst case -> 1, 3, 5,7 , 2, 4, 6, 8
        for(i = 0; i<n; i++){
            if (i%2==0)
                arr[i] = n-i;
            else
                arr[i] = i;
        }
        divide(arr, 0, n-1);
        fprintf(w, "%d  %d\n", n, count);
        count = 0;

        // Average case -> half random numbers and half sorted
        for(i = 0; i<n; i++)
            arr[i] = (i>n/2) ? i + 1 : rand()%100;
        divide(arr, 0, n-1);
        fprintf(a, "%d  %d\n", n, count);
        count=0;
        
    }

    fclose(w);
    fclose(a);
    fclose(b);
}