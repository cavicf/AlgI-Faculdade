#include <stdio.h>

void hm(int mnts, int *h, int *m);

int main(){
    int h;
    int m;
    int mnts;

    printf("Digite a quantidade de minutos que deseja converter: \n");
    scanf("%d", &mnts);

    hm(mnts, &h, &m);

    printf("Sao %d horas e %d minutos totais", h, m);

}

void hm(int mnts, int *h, int *m){
    *h = mnts/60;
    *m = mnts%60;
}