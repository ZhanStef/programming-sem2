#include <stdlib.h>
#include <stdio.h>
void FillRand(int, int *);
void FindMax(int, int, int **A, int *max_i, int *max_j);
void NewArrWithout_i_j(int m, int n, int **A, int **arr, int *max_i, int *max_j);
void PrintMas(int **A, int m, int n);

int main(){
    int n=5, i, m, max_i, max_j;
    printf("\nВведите число строк массива: ");
    scanf("%d", &m);
    int *arr[m], *arr2[m-1];
    for (i=0; i<m; i++){
	arr[i]=(int *) malloc(sizeof(int)*n);
        FillRand(n, arr[i]);
    }
    for (i=0; i<m-1; i++){
	arr2[i]=(int *) malloc(sizeof(int)*(n-1));
    }
//    printf("\n %d\n", arr[1][4]);
    FindMax(m, n, arr, &max_i, &max_j);
    NewArrWithout_i_j(m, n, arr, arr2, &max_i, &max_j);
    PrintMas(arr2, m-1, n-1);
    return 0;
}

void FillRand(int a, int * A){
    int i;
    for(i=0; i<a; i++){
        A[i]=(rand()%201-100);
    }
    for(i=0;i<a;i++){
	printf("%d ",A[i]);//проверка
	if(i==a-1) printf("\n ");
    }
}

void FindMax(int m, int n, int **A, int *max_i, int *max_j){
    int i, max, j;
    max=A[0][0];
    *max_i=0;
    *max_j=0;
    for(i=0; i<m; i++){
	for(j=0; j<n; j++){
	    if(max<A[i][j]){
		max=A[i][j];
		*max_i=i;
		*max_j=j;
	    }
	}
    }
    printf("\n Максимальныц элемент: %d на i:%d j:%d \n", max, *max_i, *max_j);
}
//*/
void NewArrWithout_i_j(int m, int n, int **A, int **arr, int *max_i, int *max_j){
    int i_arr, j_arr, i_A, j_A;
//ниже происходит копирование по след идеи: копирую до который надо исключить и копирую после.
    for(i_A=0, i_arr=0; i_A<m && i_A<*max_i; i_arr++, i_A++){
	for(j_A=0, j_arr=0; j_A<n && j_A<*max_j; j_A++, j_arr++){
	    arr[i_arr][j_arr]=A[i_A][j_A];
	}
	for(j_A+=1,j_arr; j_A<n; j_A++, j_arr++){
	    arr[i_arr][j_arr]=A[i_A][j_A];
	}
    }
    for(i_A+=1, i_arr; i_A<m; i_arr++, i_A++){
	for(j_A=0, j_arr=0; j_A<n && j_A<*max_j; j_A++, j_arr++){
	    arr[i_arr][j_arr]=A[i_A][j_A];
	}
	for(j_A+=1,j_arr; j_A<n; j_A++, j_arr++){
	    arr[i_arr][j_arr]=A[i_A][j_A];
	}
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