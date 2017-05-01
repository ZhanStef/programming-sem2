#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void ShakerSort(int *A, int n);
void PrintLinearMas(int *p, int n);

int main(){
	int *A,*B,n,m,i;
	srand(time(NULL));
	printf("\nВведите размер массива А: ");
	scanf("%d", &n);
	printf("\nВведите размер массива B: ");
	scanf("%d", &m);
	
	A=(int *)malloc(sizeof(int)*n);
	B=(int *)malloc(sizeof(int)*m);

	for(i=0;i<n;i++){
		A[i]=rand()%201-100;
	}
	
	for(i=0;i<m;i++){
		B[i]=rand()%2001-1000;
	}

	printf("\nВывод массива до сортировки А: ");
	PrintLinearMas(A,n);
	printf("\nВывод массива до сортировки B: ");
	PrintLinearMas(B,m);
	
	ShakerSort(A, n);
	ShakerSort(B, m);
	printf("\nВывод массива А после сортировки: ");
	PrintLinearMas(A,n);
	printf("\nВывод массива B после сортировки: ");
	PrintLinearMas(B,m);
	
	return 0;
}


void ShakerSort(int *A, int n){
    int g, temp, L=0, R=n-1, k=n;//k-последний обмен текущей (j),
    do{
	for(g=R;g>=L+1;g--){
	    if(A[g]>A[g-1]){
		temp=A[g-1];
		A[g-1]=A[g];
		A[g]=temp;
		k=g;
	    }
	}
	L=k;
	for(g=L;g<=R-1;g++){
	    if(A[g]<A[g+1]){
		temp=A[g+1];
		A[g+1]=A[g];
		A[g]=temp;
		k=g;
	    }
	}
	R=k;
    }while(L<R);
}

void PrintLinearMas(int *p, int n){
    int i;
    for(i=0; i<n; i++){
	printf(" %d",*(p+i));//p[i]
    }
}
