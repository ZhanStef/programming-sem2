#include <stdio.h>

double _cos(double x, double eps);
double _pow(double x, unsigned int n);
long int fact(int x);

int main()
{
    double x, eps;
//    int g=2;
//    printf("квадрат 2.0 = %lf\n",_pow(g*1.0,2));
//    printf("4! = %ld\n",fact(4));
    scanf("%lf %lf",&x, &eps);
    printf("x:%lf eps:%lf _cosx=%lf ", x,eps, _cos(x,eps) );
    return 0;
}

double _cos(double x, double eps){
    double x1, x2;
    int i=2;
    x1=1-(x*x/2);
    printf("Первый член ряда Тейл: %lf\n",x1);
    x2=x1+_pow(-1.0,i)*_pow(x,2*i)/(double)fact(2*i);
    printf("Второй член ряда Тейл: %lf\n",x2);
    while (x2-x1>eps){
	i++;
	x1=x2;
	x2=x2+(_pow(-1.0,i)*_pow(x,2*i)/(double)fact(2*i));
    printf("член ряда Тейл: %lf\n",x2);
    }
    return x2;
}

double _pow(double x, unsigned int n){
    double g=x;
    int i;
    for(i=1; i<n; i++){
	g=g*x;
    }
    return g;
}

long int fact(int x){
    int g=1, i;
    for (i=1; i<=x; i++){
	g*=i;
    }
    return g;
}

