#include<stdio.h>
#include<stdlib.h>

void main(){
    int p[10][10], n,k, i, j;
    printf("Enter order of matrix>> ");
    scanf("%d", &n);

    printf("Entet the matrix>> ");
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d", &p[i][j]);

    for(k = 0; k<n; k++){
        for(i = 0; i<n; i++){
            for(j = 0; j<n; j++){
                if(p[i][k] + p[k][j] < p[i][j])
                    p[i][j] = p[i][k] + p[k][j];
            }
        }
    }

    printf("The sortest distance matrix>> ");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d  ", p[i][j]);
        }
        printf("\n");
    }
}