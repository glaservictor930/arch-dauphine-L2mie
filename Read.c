#include<stdio.h>
#include<stdlib.h>
#include"fileTabular.h"
#include<string.h>
#include<err.h>
#define T_MAX 256

//Trouver le nbre de lignes du fichier
int NbrLignes (char* initialcode){
     FILE *fichier = fopen(initialcode,"r");
     if (initialcode == NULL) {
        printf("%s intouvable", initialcode);
         return 0;
      }
     int compteur=0;
     char c = '0';
     for (c = getc(fichier); c != EOF; c = getc(fichier)){
       if (c=='\n')
        compteur+=1;
     }
     return compteur;
  }
  int ReadFile(char* initialcode, Sequences* seq, TabularInstructions *tabins){
    FILE *fichier = fopen(initialcode,"r");
    char *test1 = malloc(255*sizeof(char));
    char *test2 = malloc(255*sizeof(char));
    if (initialcode == NULL) {
       printf("%s intouvable", initialcode);
        return 0;
     }
     int n = NbrLignes(initialcode);
     if(tabins->size<n)
         tabins->instruction = realloc(tabins->instruction,n*sizeof(Instructions));
     char c,etiq = 0;
     int line_beg,cur_pos;
     for (int i = 0; i < n ;i++){
       line_beg = ftell(fichier);
       while((c = getc(fichier)) != '\n'){
        if (c==':')
          etiq = 1; 
        }
        cur_pos = ftell(fichier);
          fseek(fichier,line_beg,SEEK_SET);
          char* line = malloc((cur_pos-line_beg)*sizeof(char));
          line = fgets(line,cur_pos-line_beg,fichier);
        if(etiq)
          sscanf(line,"%s %s ",seq->rupture[seq->size],tabins->instruction[i].keyWord);//,tabins->instruction[i].param);
        else
          sscanf(line,"%s ",tabins->instruction[i].keyWord);//,tabins->instruction[i].param);
        etiq = 0;
        fseek(fichier,1,SEEK_CUR);
        printf("%s\n",test1);
     }
 return 0;
}
