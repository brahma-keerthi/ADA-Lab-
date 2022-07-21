#include<stdio.h>
#include<stdlib.h>
#define INF 999999

void main(){
    int i, j, x, n, y, num = 0, *vis;
    printf("Enter num of vertices>> ");
    scanf("%d", &n);
    vis = (int *)calloc(sizeof(int), n);
    int graph[n][n];
    printf("Enter the matrix>> ");
    for(i = 0; i<n; i++)
        for(j = 0; j<n; j++)
            scanf("%d", &graph[i][j]);

    vis[0] = 1; // Start from oth node
    printf("Edge : Weight\n");
    while(num < n - 1){ // Until num of edges equal num of node - 1
        int min = INF;
        x = 0;
        y = 0;
        for(i = 0; i<n; i++){
            // weight comparition starts only when node is visited
            if (vis[i] == 1){
                for(j = 0; j<n; j++){
                    // when node is not visited and there exits path, select min path in row
                    if (vis[j] == 0 && graph[i][j] != 0 ){
                        if (min > graph[i][j]){
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%d - %d : %d\n", x, y, graph[x][y]);
        vis[y] = 1;
        num++;
    }
}