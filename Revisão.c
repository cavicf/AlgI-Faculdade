#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//comentários de uma linha
/*comentarios de diversas linhas*/

 int main(int agrc, char *argv[]){
     //declaração das variaveis e entradas a, b e c
     double a, b, c;
     double delta;
     double x1, x2;
     double raiz;

     printf("digite as os campos da equacao: ");
     scanf("%lf %lf %lf", &a, &b, &c);
     printf("as entradas foram a: %lf, b: %lf, c: %lf\n", a, b, c);

     //calcular delta
     delta = pow(b,2)-(4*a*c);
     raiz = sqrt(delta);
     printf("o delta eh: %.2lf\n", delta);

     //testar delta, calcular raízes, imprimir
     if (delta<0){
         printf("nao possui raizes reais\n");
     }else if(delta == 0){
         x1 = (-b + raiz)/(2*a);
         printf("o resultado do x1 unico eh: %.2lf\n", x1);
     }
     else{
        x1 = (-b + raiz)/(2*a);
        x2 = (-b - raiz)/(2*a);
        printf("o resultado do x1 eh: %.2lf\n", x1);
        printf("o resultado do x2 eh: %.2lf\n", x2);

    int a, b, x, y;
    scanf("%d %d", &a, &b);
    for(x=0; x<=10; x++){
        y = (a*x)+ b;
        printf("X: 0%d    Y: 0%d\n", x, y);
    }

     return 0; 
 }

