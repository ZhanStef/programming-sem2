#include <stdio.h>
#include <stdlib.h>
#define N 20
#include <string.h>

typedef struct stud{
    char family[20];
    int math;
    int saod;
    int prog;
    int phiz;
    struct stud *next;
}student;

int FirstSt1(char *st1, char *st2);
void vivod(student *head);
void vvod(student *p);
student * FindPlaceAfter(student *head, char *string);

int main()
{
    student *p, *head, *temp;
    int answ;
    p=head=(student *) malloc (sizeof(student));
    head->next=NULL;
	strcpy(head->family, "сервисная");
    //vvod(p);
    while(1){
        printf("\nХотите внести ещё: 1/0 ");
        scanf("%d",&answ);
        if(answ){
            p=(student*) malloc (sizeof(student));
            vvod(p);
            temp=FindPlaceAfter(head, p->family);
            p->next=temp->next;
            temp->next=p;
        }
        else{
            break;
        }
    }
    vivod(head);
    return 0;
}

int FirstSt1(char *st1, char *st2){//выводит 1 если 1ая раньше должна стоять и 0 если 2ая раньше
    int i;
    for(i=0;st1[i]!='\0' && st2[i]!='\0'; i++){
        if(st1[i]==st2[i]) {
            continue;
        }
        else{
            if(st1[i]<st2[i]) {
                return 1;//надо продолжать в вызывающец функции
            }
            else{
                return 0;//st2 раньше должна быть те надо записывать
            }
        }
    }
    if(st1[i]=='\0' && st2[i]=='\0') return 0;
    if(st1[i]!='\0' && st2[i]=='\0'){
        return 0;//st2 короче и надо записывать
    }
    else{
        return 1;
    }
}

student * FindPlaceAfter(student *head, char *string){
    student *p=head;
    while(p->next!=NULL && (FirstSt1(p->family,string)!=0)){//дошли до последнего тогда за ним записывать
		p=p->next;//или строка структуры на которую перешли оказалась позже которую пытаемся пристроить
    }
    return p;
}

void vvod(student *p){
    printf("\nВведите фамилию: ");
    scanf("%s", p->family);
    /*printf("\nВведите оценку по матану: ");
    scanf("%d", &(p->math));
    printf("\nВведите оценку по физике: ");
    scanf("%d", &(p->phiz));
    printf("\nВведите оценку по программир: ");
    scanf("%d", &(p->prog));
    printf("\nВведите оценку по физике: ");
    scanf("%d", &(p->saod));
*/}

void vivod(student *head){
    student *p;
    for(p=head;p!=NULL;p=p->next){
        printf("\n%s ",p->family);/*
        printf("Физика: %d ", p->phiz);
        printf("Матан: %d ", p->math);
        printf("Программир: %d ", p->prog);
        printf("САОД: %d ", p->saod);
*/    }
}
