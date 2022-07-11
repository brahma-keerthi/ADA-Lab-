#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int max, count = 0;

void dfs(int arr[][max],int *visited, int i, FILE *fp){
    // Prints the visited vertex in order in connect.txt
    fprintf(fp, "%d  ", i);
    visited[i] = 1;
    int j;

    for(j = 0; j<max; j++){
        count ++;
        // If the edge in present to next node and next node in not visited
        if (arr[i][j] == 1 && !visited[j]){
            dfs(arr, visited, j, fp);
        }
    }
}

void main(){
    int i, *visited;
    FILE *c, *fp;
    system("rm count.txt");
    system("rm connect.txt");
    c = fopen("count.txt", "a");
    fp = fopen("connect.txt", "a");

    srand(time(0));

    for(max = 10; max<=100; max+=10){
        // Initializing to zero
        visited = (int *)calloc(sizeof(int), max);

        int arr[max][max];

        // Filling up adjacency matrix with 0,1
        for(i = 0; i<max; i++)
            for(int j = 0; j<max ; j++)
                arr[i][j] = rand()%2;

        // Selection of random start vertex
        i = rand()%max;

        dfs(arr, visited, i, fp);
        fprintf(c, "%d   %d\n", max, count);
        fprintf(fp, "\n\n\n");
        count = 0;
    }

    // Connectivity of graph is determined in connect.txt
    fclose(fp);
    fclose(c);
}