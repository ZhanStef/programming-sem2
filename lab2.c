#include <stdio.h>

void _10to2(int a);
void vvod();

int main(){
    int i;
    vvod();
    scanf("%d",&i);
    printf("\n 2ичное в 10ичное: ");
    _10to2(i);
    printf("\n");
    scanf("%d",&i);
    mas(i);
    return 0;
}

/*void vvod(){  //не рекурсивный вариант
    int i;
    for(i=1;i;){
	scanf("%d",&i);
	if(i)printf("\b%d",i);
    }
}*/

void vvod(){
    int i;
    scanf("%d",&i);
    if(i){
	printf("%d",i);
	vvod();
    }
}

void _10to2(int a){
    if(a){
	if(a/2){
	    _10to2(a/2);
	}
	printf("%d",a%2);
    }
}

void mas(n){
    int A[n], i;
    for(i=0;i<n;i++){
	printf("Ввод эл #%d",i+1);
	scanf("%d",A[i]);
    }
    for(){
    scanf("%d", );
}