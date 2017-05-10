#iclude <stdio.h>
#include <stdlib.h>
int main(){
    char st[80], ch;
    char text[]="gooogle\n apple\n vaz\n milk\n year\n time\n";
    FILE f1, f2;
    f1=fopen("newfile1.txt","w");
    fprintf(f1,"%s\n",text);
    fclose(f1);
    f1=fopen("newfile1.txt", "r");
    f2=fopen("newfile2.txt", "w");
    while(!feof(f1)){
    return 0;
}
