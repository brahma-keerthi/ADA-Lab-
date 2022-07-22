#include<stdio.h>
#include<stdlib.h>
int n, graph[20][20];
int stk[20], tos = -1;
int a = -2, b = -2;

void dfs(int graph[][n], int start, int parent, int *vis){
    int j;
    vis[start] = 1;
    printf("%d  ", start);
    stk[++tos] = start;

    for( j= 0; j<n; j++){
        if ( graph[start][j] ){
            if ( j != parent ){
                a = j;
                b = parent;
            }
            if ( !vis[j]){
                dfs(graph, j,start, vis);
            }
        }

    }
}

void main(){
    int i, j, k;
    printf("Enter the num of vertices>> ");
    scanf("%d", &n);

    int graph[n][n];
    int * vis = (int *)calloc(sizeof(int), n);

    printf("Enter adjacency matrix >> ");
    for ( i= 0; i<n; i++){
        for (j = 0; j<n; j++)
            scanf("%d", &graph[i][j]);
    }

    printf("The dfs traversal is >>\n");
    for(i = 0; i<n; i++){
        if ( !vis[i] ){
            dfs(graph, i, -1, vis);
        }
    }

    if ( a != -2 && b!= -2){
        printf("\nCyclic graph where in cycle exits for >> \n");
        for(i = tos; i>-1; i--){
            if ( stk[tos] == a){
                tos = i;
            }
            if (stk[tos] == b)
                j = i;
        }
        for(k = tos; k>i; k--){
            printf("%d  ", stk[k]);
        }
    }

}