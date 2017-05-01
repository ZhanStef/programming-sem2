#include <stdio.h>
#include <stdlib.h>

typedef struct school * sptr;
typedef struct school school;
struct school {
	int shkola;
	int vipusk;
	int postupilo;
};

int cmp(sptr p1, sptr p2);
void ShakerSort(sptr *A, int n);

int main(){
	school massiv[]={
		{122, 200, 100},
		{13, 90, 88},
		{1,30,30},
		{5,45,20},
		{7,20,2},
		{44,100,70},
		{33,100,60},
		{9,30,1}
	};
	int i;
	//вычислим размер массива
	int sizearr=(sizeof(massiv)/sizeof(massiv[0]));
	for(i=0;i<sizearr;i++){
		printf("\nШкола№ %d ,выпуск: %d, поступивших: %d",massiv[i].shkola, massiv[i].vipusk, massiv[i].postupilo);
	}
	printf("\nПосле сортировки по поступившим");
	// создаем массив указателей на структуру
	sptr *M;
	M=(sptr *)malloc(sizeof(sptr)*sizearr);
	for(i=0;i<sizearr;i++){
		M[i]=&massiv[i];
		printf("\n%p=%p",M[i],&massiv[i]);
	}
//	for(i=0;i<sizearr;i++){
	ShakerSort(M,sizearr);
	for(i=0;i<sizearr;i++){
		printf("\nШкола№ %d ,выпуск: %d, поступивших: %d",M[i]->shkola, M[i]->vipusk, M[i]->postupilo);
		printf("\nстало %p=было %p",M[i],&massiv[i]);
	}
	return 0;
}

int cmp(sptr p1, sptr p2){ /*функция возвращающая 1 если p1 больше поступило в вуз,
возвр 0 если равно и возвр -1 если в p2 больше поступивших в вуз*/
	if(p1->vipusk > p2->vipusk){
	return 1;
	}
	else{
		if(p1->vipusk < p2->vipusk){
			return -1;
		}
		else{
			return 0;
		}
	}
}

void ShakerSort(sptr *A, int n){
    int g, L=0, R=n-1, k=n;//k-последний обмен текущей (j),
	sptr temp;
    do{
	for(g=R;g>=L+1;g--){
	    if((A[g]->postupilo)<(A[g-1]->postupilo)){
		temp=A[g-1];
		A[g-1]=A[g];
		A[g]=temp;
		k=g;
	    }
	}
	L=k;
	for(g=L;g<=R-1;g++){
	    if((A[g]->postupilo)>(A[g-1]->postupilo)){
		temp=A[g+1];
		A[g+1]=A[g];
		A[g]=temp;
		k=g;
	    }
	}
	R=k;
    }while(L<R);
}
