#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <time.h>

void P50m50(int *p, int n);
void * P50(int *p, int n, int *plus, int *);
void * M50(int *p, int n, int *minus, int *);
void Printmas(int *, int);

int main(){
    srand(time(NULL));
    int *b, n, *plus=NULL, nplus=0, nminus=0, *minus=NULL;
    printf("\nВведите размер исходного массива: ");
    scanf("%d",&n);
    b=(int *) malloc(n*sizeof(int));
    P50m50(b,n);
    P50(b,n,plus,&nplus);
    M50(b,n,minus,&nminus);
    printf("\n Основной: ");
    Printmas(b,n);
    printf("\n Плюсовые эл: ");
    Printmas(plus,nplus);    
    printf("\n Минусовые эл: ");
    Printmas(minus,nminus);
    return 0;
}

void P50m50(int *p, int n){
    int i;
    for(i=0;i<n;i++){
	p[i]=rand()%101-50;
    }
    printf("\ncгенерирован массив размера: %d; со след элементами: ",n);
    for(i=0; i<n; i++){
    printf("№%d %d ",i,p[i]);
    }
}

void P50(int *p, int n, int *plus, int *g){
    int i;//g-counter of x>0, to know memspace
    *g=0;
    for (i=0;i<n;i++){
	if (p[i]>0) (*g)++;
    }
    plus=(int *) malloc((*g)*sizeof(int));
}

void M50(int *p, int n, int *minus, int *g){
    int i;//g-counter of x>0, to know memspace
    *g=0;
    for (i=0;i<n;i++){
	if (p[i]<0) (*g)++;
    }
    minus=(int *) malloc((*g)*sizeof(int));
    
}

void Printmas(int *p, int n){
    int i;
    for(i=0; i<n; i++){
	printf(" %d",*(p+i));//p[i]
    }
}