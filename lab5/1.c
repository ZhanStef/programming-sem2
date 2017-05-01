#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PrintMas(int **A, int m, int n);
void RandMas(int arr[], int n);
void PrintLinearMas(int *p, int n);

int main(int argc, char *argv[])
{
    int *A, n;
    printf("\nВведите количество элементов одномерного массива ");
    scanf("%d",&n);
    A=(int *)malloc(n*sizeof(int));
    if(A==NULL){
        printf("\nНе удалось выделить память");
        return -1;
    }
    //Заполяем массив числами
    RandMas(A,n);
    PrintLinearMas(A,n);
    //Создаем новый массив по м элементов
    int m, i, j, strok;
    printf("\nВведите количество элементов в строке при разбиении: ");
    scanf("%d", &m);
    if(n%m>0){
        strok=((n/m)+1);
    }
    else{
	strok=(n/m);
    }
    printf("\nstrok=%d",strok);
    int **B=(int**)malloc(sizeof(int*)*strok);
    for(i=0;i<strok;i++){
	B[i]=(int *) malloc(sizeof(int)*m);
    }
    for(i=0;i<strok;i++){
	for(j=0;(j<m) && ((i*m+j)<n);j++){
	    B[i][j]=A[i*m+j];
	}
    }
    for(--i,++j;j<m;j++){
	B[i][j]=0;
    }
/*    for(i=0;i<strok;i++){
	PrintMas(B,strok,m);
    }*/
    PrintMas(B, strok, m);
    return 0;
}

void RandMas(int arr[], int n){
    srand(time(NULL));
    for(;--n>=0;){
        arr[n]=rand()%200-100;
    }
}

void PrintMas(int **A, int m, int n){
    int i, j;
    printf("\n");
    for(i=0;i<m;i++){
	for(j=0;j<n;j++){
	    printf("%d ",A[i][j]);
	}
	printf("\n");
    }
}

void PrintLinearMas(int *p, int n){
    int i;
    for(i=0; i<n; i++){
	printf(" %d",*(p+i));//p[i]
    }
}