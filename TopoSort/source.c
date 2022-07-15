#include<stdio.h>
#include<stdlib.h>

void main(){
    int n;
    printf("Enter the number of nodes>> ");
    scanf("%d", &n);
    int graph[n][n];
    int *indeg = (int *)calloc(sizeof(int), n);
    int *visited = (int *)calloc(sizeof(int), n);

    printf("Enter the matrix>> ");
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            scanf("%d", &graph[i][j]);

    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            indeg[i] += graph[j][i];

    printf("Topological Sort order>>\n");
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(!visited[j] && !indeg[j]){
                visited[j] = 1;
                printf("%d  -->> ", j);
            }

            for(int k = 0; k<n; k++){
                if(graph[j][k]){
                    graph[j][k] = 0;
                    indeg[k]--;
                }
            }
        }
    }
}