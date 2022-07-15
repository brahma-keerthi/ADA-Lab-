#include<stdio.h>
#include<stdlib.h>

int stk[100], top = -1, n;

void dfs(int graph[][n], int start, int * visited){
    int j;
    visited[start] = 1;

    for(j= 0; j<n; j++){
        if(graph[start][j] && !visited[j])
            dfs(graph, j, visited);
    }
    stk[++top] = start;
}

void main(){
    printf("Enter num of nodes>> ");
    scanf("%d", &n);
    int graph[n][n], *indeg = (int *)calloc(sizeof(int), n);
    int * visited = (int *)calloc(sizeof(int), n);

    printf("Enter DAG matrix>> ");
    for(int i = 0; i<n; i++){
        for(int j = 0 ; j<n; j++)
            scanf("%d", &graph[i][j]);
    }

    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            indeg[i] += graph[j][i];

    int start;
    for(int i = 0; i<n; i++){
        if(indeg[i] == 0){
            start = i;
            break;
        }
    }
    printf("%d", start);
    // stk[++top] = start;
    dfs(graph, start, visited);

    printf("Topological Sorting>>> ");
    for(int i = top; i>-1; i--)
        printf("%d _-->> ", stk[i]);
}