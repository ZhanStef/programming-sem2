﻿#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DLINA_STR_SLOVA 20
#define SCHITIVAEM 80
#define BUCKVA_OR_CIFRA(X) ((X>=34 && X<=90) || (X>=48 && X<=57) || (X>=97 && X<=122))
#define RAZDELITEL_PREDLOJENII(X) (X=='?' || X=='!' || X=='.')
#define ESHE_SLOVO(X) X=(sl *)malloc(sizeof(sl)); tail->next=X; tail=X;

typedef struct slovo{
    struct slovo * next;
    char str[DLINA_STR_SLOVA];
    int flag;
} sl;

void ZapolnenieOcheredi(sl *tail);
void VivodOcheredi(sl * head, sl *tail);

int main(){
    sl *head=(sl *) malloc(sizeof(sl)), *tail=(sl*)&head;
    ZapolnenieOcheredi(tail);
    VivodOcheredi(head, tail);
    return 0;
}

void ZapolnenieOcheredi(sl *tail){
    FILE *f1=fopen("file.txt","r");
    int g=0, flag=1;
    unsigned int i;
    sl *p=tail;
    char Arr[SCHITIVAEM];
    while(fgets(Arr, SCHITIVAEM, f1)){
        for(i=0; i<strlen(Arr); i++){
                if(g==0){
                    if(BUCKVA_OR_CIFRA(Arr[i]) && flag!=0){
                        p->flag=1;
                        flag=0;
                    }
                    p->str[g++]=Arr[i++];
                }
                while (BUCKVA_OR_CIFRA(Arr[i]) && g!=DLINA_STR_SLOVA){
                    p->str[g++]=Arr[i++];
                }
                if(g==DLINA_STR_SLOVA){
                    if(p->flag==1){
                        ESHE_SLOVO(p);
                        p->flag=1;
                        g=0;
                        continue;
                    }
                    else{
                        ESHE_SLOVO(p);
                        p->flag=0;
                        g=0;
                        continue;
                    }
                }
                if(RAZDELITEL_PREDLOJENII(Arr[i])){
                    flag=1;
                    ESHE_SLOVO(p);
                    g=0;
                }
                else{
                    ESHE_SLOVO(p);
                    p->flag=0;
                    g=0;
                }
        }
    }
    fclose(f1);
}

void VivodOcheredi(sl * head, sl *tail){
    sl *p=head;
    int i;
    while (p!=tail) {
        for(i=0;i<20;i++){
            putchar(p->str[i]);
        }
        p=p->next;
    }
    printf("%s", p->str);
}
