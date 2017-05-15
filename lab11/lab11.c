#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <conio.h> //windows
//#include <ncurses.h>//linux -lncurses

void input(FILE *);
void print(FILE *);
void add(FILE *);
void del_less10kg(FILE *);
void txtupdate(FILE *);

typedef struct passenger{
    char fam[20];
    char name[20];
    char otech[20];
    int c_bags; // count_bags
    int w_bags; // weight_bags
    char flag_del;//1=>to del, 0=>keep
} pas;

pas t1;

int main(){
//initscr();
    char ch;
    FILE *tf=fopen("file1.dat","wb");
    if(tf==NULL){
		printf("\nFile access denied ");
		return -1;
	}
    fclose(tf);
    while (1){
        printf("\n  1 - new list passenger and delete previous");
        printf("\n  2 - show list passengers");
        printf("\n  3 - add in exist list of passengers");
        printf("\n  4 - delete passengers with luggage weight <10 kg");
        printf("\n  5 - update database in file1.txt");
        printf("\n  0 - quit\n");
		while((ch=getchar())=='\n'){
			putchar(ch);
		}
        //c=getch();
        //scanf("%c",&c);
        switch(ch){
            case '1': input(tf);
            break;
            case '2': print(tf);
            break;
            case '3': add(tf);
            break;
            case '4': del_less10kg(tf);
            break;
            case '5': txtupdate(tf);
            break;
            case '0': return 0;
            default : printf("\n wrong input ");
         }
    }
  //  ndwin();
    return 0;
}
//from lection
void input(FILE *tf){
    char ch;
    tf=fopen("file1.dat","wb");
    if(tf==NULL){
		printf("\nFile access denied ");
		return -1;
	}
    printf("\n Passengers entry \n");
    do{
        t1.flag_del=0;
        printf("\n Family: ");
        scanf("%s",t1.fam);
        printf("\n Name: ");
        scanf("%s",t1.name);
        printf("\n Otchestvo: ");
        scanf("%s",t1.otech);
        printf("\n Amount of bags: ");
        scanf("%d",&t1.c_bags);
        printf("\n Total weight: ");
        scanf("%d",&t1.w_bags);
        fwrite(&t1,sizeof(pas),1,tf);
        printf("\n Finished?  y/n  ");
        while((ch=getchar())=='\n'){
			putchar(ch);
		}
        //scanf("%*s%c",&ch);
    }
    while (ch != 'y');
    fclose(tf);
}
void print(FILE *tf){
    int i;
    tf=fopen("file1.dat","rb");
    if(tf==NULL){
		printf("\nFile access denied ");
		return -1;
	}
    i=1;
    while (fread(&t1,sizeof(pas),1,tf)){
        if(t1.flag_del==0){
            printf("\n%3d Family: %20s \nName: %20s \nOtchestvo: %20s \nAmount of bags: %20d \nTotal weight: %20d",i,t1.fam,t1.name,t1.otech,t1.c_bags,t1.w_bags);
            i++;
        }
    }
	fclose(tf);
}
void add(FILE *tf){
    char ch;
    tf=fopen("file1.dat","ab"); //amend
    if(tf==NULL){
		printf("\nFile access denied ");
		return -1;
	}
    printf("\n Passengers entry \n");
    do{
        printf("\n Family: ");
        scanf("%s",t1.fam);
        printf("\n Name: ");
        scanf("%s",t1.name);
        printf("\n Otchestvo: ");
        scanf("%s",t1.otech);
        printf("\n Amount of bags: ");
        scanf("%d",&t1.c_bags);
        printf("\n Total weight: ");
        scanf("%d",&t1.w_bags);
        fwrite(&t1,sizeof(pas),1,tf);
        printf("\n Finished?  y/n  ");
        while((ch=getchar())=='\n'){
			putchar(ch);
		}
        //scanf("%c",&ch);
    }
  while (ch != 'y');
  fclose(tf);
}

void del_less10kg(FILE *tf){
    tf=fopen("file1.dat","rb+");
    if(tf==NULL){
		printf("\nFile access denied ");
		return -1;
	}
    while (fread(&t1,sizeof(pas),1,tf)){
        if(t1.w_bags<10){
            t1.flag_del=1;
            fseek(tf,-sizeof(pas),SEEK_CUR);
            fwrite(&t1,sizeof(pas),1,tf);
        }
    }
    fclose(tf);
}

void txtupdate(FILE *tf){
    tf=fopen("file1.dat", "rb");
    if(tf==NULL){
		printf("\nFile access denied ");
		return -1;
	}
    FILE *nf;
    nf=fopen("~temp", "wb");
    while(fread(&t1,sizeof(pas),1,tf)){
        if(t1.flag_del==0){
            fwrite(&t1,sizeof(pas),1,nf);
        }
    }
    fclose(tf);
    fclose(nf);
    remove("file1.dat");
    rename("~temp","file1.dat");
}
