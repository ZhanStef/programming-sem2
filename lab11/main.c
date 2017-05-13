#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void input(FILE *);
void print(FILE *);
void add(FILE *);
void del_10kg(FILE *);

typedef struct passenger{
    char fam[20];
    char name[20];
    char otech[20];
    int count_bags;
    int weight_bags;
} pas;

int main(){
    char c;
    FILE *tf;
    while (1){
        puts("\n  1 – new passenger");
        puts("\n  2 – list of passengers");
        puts("\n  3 – add passenger");
        puts("\n  4 – delete passengers with luggage");
        puts("\n  0 - выход");

        c=getch();
        switch(c){
            case '1':input(tf);break;
            case '2':print(tf);break;
            case '3':app(tf);break;
            case '4':find(tf);break;
            case '0':return 0;
            default : puts(" неверный режим");
         }
    }
    return 0;
}
//frome lection
void input(FILE *tf)
{ char ch;
  tf=fopen("file1.dat","wb"); // открытие бинарного файла для записи
  system(“CLS”);
  printf("\n Ввод товаров\n");
  do
  { printf("\n название: "); scanf("%s",&t1.name);
    printf(" цена: "); scanf("%f",&t1.c);
    printf(" количество: "); scanf("%d",&t1.kol);
    fwrite(&t1,sizeof(t1),1,tf); // запись в файл одной структуры t1
    printf("\n Закончить?  y/n  ");
    ch=getch();
  }
  while (ch != 'y');
  fclose(tf);
}
void print(FILE *tf)
{ int i;
  system(“CLS”);
  tf=fopen("file1.dat","rb"); // открытие бинарного файла для чтения
  i=1;
  fread(&t1,sizeof(t1),1,tf); // чтение из файла одной структуры t1
  while (!feof(tf))
  { printf("\n  %3d tovar %10s cena %6.2f kolic %4d",i,t1.name,t1.c,t1.kol);
    fread(&t1,sizeof(t1),1,tf);
    i++;
  }
  getch();
}
void app(FILE *tf)
{ char ch;
  tf=fopen("file1.dat","ab"); // открытие бинарного файла для добавления
  system(“CLS”);
  printf("\n  Ввод товаров \n");
  do
  {  printf("\n название: "); scanf("%s",&t1.name);
    printf(" цена: "); scanf("%f",&t1.c);
    printf(" количество: "); scanf("%d",&t1.kol);
    fwrite(&t1,sizeof(t1),1,tf);
    printf(" Закончить?  y/n ");
    ch=getch();
  }
  while (ch != 'y');
  fclose(tf);
}
void find(FILE *tf)
{ char c,tov[10];
  tf=fopen("file1.dat","rb+"); // открытие бинарного файла для чтения и записи
  system(“CLS”);
  puts(" Название искомого товара: ");
  gets(tov);
  fread(&t1,sizeof(t1),1,tf);
  while (!feof(tf))
  {  if (strcmp(t1.name,tov)==0)
     {
        printf(" tovar %10s cena %6.2f kolic %d",t1.name,t1.c,t1.kol);
         getch();
      }
      fread(&t1,sizeof(t1),1,tf);
  }
  fclose(tf);
}
