#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 4096

int read_file(char *text, char *filename);

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Uso: ./readability file\n");
        return 1;
    }

    char text[MAX];

    if (read_file(text, argv[1])) {
        printf("Archivo no encontrado\n");
        return 1;
    }
    float l=0;
    float p=0;
    float o=0;
    int i=0;
    while(text[i]!='\0'){
        
        if(isalpha(text[i])){
            l++;
        }
        if(isspace(text[i])){
            p++;
        }
        if(text[i]=='.'||text[i]=='?'||text[i]=='!'){
            o++;
        }

        i++;
    }
    float L=(100*l)/p;
    float s=(100*o)/p;

    float index = (0.0588 * L )-(0.296 * s) - 15.8;
    int resultado = round(index);
    if(resultado < 1){

        printf("before grade 1\n");
    }
    if(resultado > 16){
        printf("grade 16+\n");
    }
    if (resultado >1 && resultado <16){
        printf("grade %d\n",resultado);
    }
    
    return 0;   
}

int read_file(char *text, char *filename) {

    FILE *fp;
    char c;
    char full_name[30];
    
    sprintf(full_name, "texts/%s.txt", filename);
    fp = fopen(full_name, "r");
    
    if (!fp) {
        return 1;
    } 
    
    do {
        c = getc(fp);
        *text = c;
        text++;
    } while (c != EOF);
    
    text--;
    *text = '\0';
    
    return 0;
}
