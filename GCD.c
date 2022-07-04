#include<stdio.h>
#include<stdlib.h>

int gcd;

int euclid(int a, int b){
    int r = 1, count = 0;
    while(r!=0){
        r = a%b;
        a = b;
        b = r;
        count++;
    }
    gcd = a;
    return count;
}

int sub(int a, int b){
    int count = 0;
    while(b!=0){
        count++;
        if (a>b)
            a -= b;
        else
            b -= a;
    }
    gcd = a;
    return count;
}

int intCheck(int a, int b){
    int temp, count = 0;
    int min = (a<b)?a:b;
    while(min != 1){
        count++;
        temp = a%min;
        if(temp == 0){
            temp = b%min;
            if(temp == 0)
                break;
        }
        min--;
    }
    gcd = min;
    return count;
}

void main(){
    int a, b;
    printf("Enter 2 non-negative numbers>> ");
    scanf("%d%d", &a, &b);
    
    printf("Count for Euclid's method>> %d\n", euclid(a, b));
    printf("Count for Modified Subtraction method>> %d\n", sub(a, b));
    printf("Count for Integer Checking method>> %d\n", intCheck(a, b));
    printf("GCD>> %d\n", gcd);
}