#include <stdio.h>
#include <stdlib.h>
#define N 120
#include <string.h>


int main(){
    char c, st[N];
    char text[]="gooogle\napple\nvaz\nmilk\nyear\ntime\npolymer\n";
    FILE *f0, *f1, *f2;
    
    //write source string in file
    f0=fopen("newfile0.txt","w");
    fprintf(f0,"%s",text);
    fclose(f0);
    
    //open streams for delenie na glasnie i soglasnie
    f0=fopen("newfile0.txt", "r");
    f1=fopen("newfile1.txt", "w");
    f2=fopen("newfile2.txt", "w");
    
    while(fgets(st,N,f0)){
		c=st[0];
		if(c=='a'||c=='A'||c=='e'||c=='E'||c=='o'||c=='O'||c=='y'||c=='Y'
		||c=='u'||c=='U'){
			int i;
			for(i=0;i<strlen(st);i++){
				fputc(st[i],f1);
				fputc(' ',f1);
			}
		}
		else{
			int i;
			for(i=0;i<strlen(st);i++){
				fputc(st[i],f2);
				fputc(' ',f2);
			}
		}
	}
	fclose(f0);
	fclose(f1);
	fclose(f2);
    return 0;
}
