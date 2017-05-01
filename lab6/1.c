#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Trngl(int *a, int *b, int *c, double * S);

int main(){
    printf("\nВведите длину 3 сторон триугольника: ");
    int a, b, c;
    double S;
    scanf("%d %d %d", &a, &b, &c);
    if(Trngl(&a,&b,&c,&S)){
	printf("\nПлощадь равна %6.3f ", S);
    }
    else{
	    printf("\nНе существует такого треугольника");
    }
    return 0;
}

int Trngl(int *a, int *b, int *c, double * S){
    double p;
    p=((*a)+(*b)+(*c))/2;
    *S=(p*(p-*a)*(p-*b)*(p-*c));
    if(*S<0){
	return 0;
    }
    else{
	*S=sqrt(*S);
    }
    return 1;
}