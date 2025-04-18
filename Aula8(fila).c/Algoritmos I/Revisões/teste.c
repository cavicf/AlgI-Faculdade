#include <stdio.h>
#include <stdlib.h>

int TTT (int x[], int n) {
   if (n == 0) return 0;
   if (x[n] > 0) return x[n] + TTT (x, n-1);
   else return TTT (x, n-1);
}

int main(){
    int n, r, i;
    r = 0;
    scanf("%d", &n);

    int *x = (int *)malloc(sizeof(int)*n+1);
    
    x[0] = 0;

    for(i=1; i<n+1;i++){
        scanf("%d", &x[i]);
    }

    r = TTT(x, n);
    printf("%d", r);

    return 0;
}

/*
    5
    0  1  2  3  4  5
    0  12 5  3  1  10 = 31


*/