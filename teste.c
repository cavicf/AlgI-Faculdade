#include <stdio.h>
#include <stdlib.h>

int TTT (int x[], int n) {
   if (n == 0) return 0;
   if (x[n] > 0) return x[n] + TTT (x, n-1);
   else return TTT (x, n-1);
}

int main(){
     int n, r, i;

    scanf("%d", &n);
    int x[n];

    for(i=0; i<n;i++){
        scanf("%d", &x[i]);
    }

    r = TTT(x, n-1);
    printf("%d", r);

    return 0;
}