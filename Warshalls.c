#include<stdlib.h>
#include<stdio.h>

void main(){
    int p[10][10] , temp[10][10], i, j, k, n;
    printf("Enter the order of Matrix>> ");
    scanf("%d", &n);
    printf("Enter matrix>> \n");
    for(i = 0; i<n; i++){
        for(j = 0; j<n; j++)
            scanf("%d", &temp[i][j]);
            p[i][j] = temp[i][j];
    }

    for(k = 0; k<n; k++){
        for(i = 0; i<n; i++){
            for(j = 0; j<n; j++){
                temp[i][j] = temp[i][j] || (temp[i][k] && temp[k][j]);
            }
        }
    }

    printf("Transitive closure>> \n");
    for(i = 0; i<n; i++){
        for(j = 0; j<n; j++){
            printf("%d  ", temp[i][j]);
        }
        printf("\n");
    }
}