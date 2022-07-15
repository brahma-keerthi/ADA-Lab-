#include<stdio.h>
#include<stdlib.h>
int f = -1, r = -1, stk[1000], n;

int isEmpty(){
    if (f== -1 && r==-1)
        return 1;
    return 0;
}

int deq(){
    if (f==r){
        int node = stk[f];
        f=r=-1;
        return node;
    }
    else
        return stk[f++];
}

void enq(int item){
    if (isEmpty()){
        f = r = 0;
        stk[f] = item;
    }
    else{
        stk[++r] =  item;
    }
}

void main(){
    int i, j, count=0, k = 0;
    printf("Enter the num of nodes>>");
    scanf("%d", &n);
    int graph[n][n];
    int * visited = (int *)calloc(sizeof(int), n);

    printf("Enter the matrix>> ");
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter start vertex>> ");
    scanf("%d", &i);

    printf("BFS TRAVERSAL>> ");
    printf("%d ->> ", i);
    visited[i] = 1;
        enq(i);
        while(!isEmpty()){
           int node = deq();

           for(j = 0; j<n; j++){
                count ++;
                if (graph[node][j] && !visited[j]){
                printf("%d -->> ", j);
                   visited[j] =1;
                   enq(j);
                }
            }
        }
    }
