#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DLINA_STR_SLOVA 60
#define SCHITIVAEM 80
#define BUCKVA_OR_CIFRA(X) ((X>=65 && X<=90) || (X>=48 && X<=57) || (X>=97 && X<=122))
#define RAZDELITEL_PREDLOJENII(X) (X=='?' || X=='!' || X=='.')
#define RAZDELITEL_SLOV(X) (X==' ' || X=='\n')
#define ESHE_SLOVO(X) X=(sl *)malloc(sizeof(sl)); tail->next=X; tail=X;

typedef struct slovo{
    struct slovo * next;
    char str[DLINA_STR_SLOVA];
    int flag;
} sl;

sl * ZapolnenieOcheredi(sl *tail);
void VivodOcheredi(sl * head, sl *tail);

int main(){
    sl *head=(sl *) malloc(sizeof(sl));
    sl *tail=(sl *) head;
    tail = ZapolnenieOcheredi(tail);
    VivodOcheredi(head, tail);
    return 0;
}

sl * ZapolnenieOcheredi(sl *tail){
    FILE *f1;
    if(!(f1=fopen("file.txt","r"))){
            printf("\nOpen file failure. ");
    }
    int g=0;
    unsigned int i;
    sl *p=tail;
    int flag=1;
    char Arr[SCHITIVAEM];
    while(fgets(Arr, SCHITIVAEM, f1)){
        for(i=0; i<strlen(Arr);){
            if(RAZDELITEL_SLOV(Arr[i])){
                if(g!=0){
                    ESHE_SLOVO(p);
                    p->flag=0;
                    g=0;
                }
                while(RAZDELITEL_SLOV(Arr[i]) && g<DLINA_STR_SLOVA ){
                        p->str[g++]=Arr[i++];
                }
            }
            if(BUCKVA_OR_CIFRA(Arr[i])){
                ESHE_SLOVO(p);
                if(flag==1){
                    p->flag=1;
                    flag=0;
                    g=0;
                }
                else{
                    p->flag=0;
                    g=0;
                }
                while(BUCKVA_OR_CIFRA(Arr[i]) && g!=DLINA_STR_SLOVA){
                    p->str[g++]=Arr[i++];
                }
            }
            if(RAZDELITEL_PREDLOJENII(Arr[i])){
                p->flag=1;
                flag=1;
                ESHE_SLOVO(p);
                g=0;
                p->flag=0;
                while (RAZDELITEL_PREDLOJENII(Arr[i]) && g!=DLINA_STR_SLOVA) {
                    p->str[g++]=Arr[i++];
                }
            }
            if(Arr[i]==0){
                p->flag=1;
                ESHE_SLOVO(p);
                p->flag=0;
                p->str[0]=0;
                fclose(f1);
                return tail;
            }
        }
    }
}


void VivodOcheredi(sl * head, sl *tail){
    sl *p=head;
    int i;
    while (p!=tail) {
        for(i=0;i<20;i++){
            if(p->str[i]!=0){
                putchar(p->str[i]);
            }
            else{
                //putchar(' ');
                break;
            }
        }
        if(p->flag==1){
            printf("(<=slovo and flag=1) ");
        }
        else{
            printf("(<=slovo and flag=0) ");
        }
        p=p->next;
    }
    for(i=0;i<20;i++){
        if(p->str[i]!=0){
            putchar(p->str[i]);
        }
        else{
            //putchar(' ');
            break;
        }
    }
    if(p->flag==1){
        printf("(<=slovo and flag=1) ");
    }
    else{
        printf("(<=slovo and flag=0) ");
    }
//	putchar(0);
}
