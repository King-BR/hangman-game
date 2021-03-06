/* 
 * Projeto de Linguagem de Progamação 1
 * Jogo da forca
 * Feito por Pedro e Fernando
 * Versão: 4.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#include <conio.h>
#include "funcoes.h"

char magicword[30];

int num_aleatorio();
void jogar();
void novojogo();
void word();
void adc();
void pause(float delay1);
void caveira_fechada();
void caveira_aberta();
void animacao_caveira();
void tela_de_carregamento();
void forca();
void forca_cabeca();
void forca_rosto();
void forca_tronco();
void forca_bracos();
void forca_pernas();

int main() {

    setlocale(LC_ALL, "portuguese-brazilian");

    system("cls");
    tela_de_carregamento ();
    system("cls");

    jogar();

    return 0;
}

void jogar() {
    int err = 0;
    char letra;
    int aux = 0;
    int venceu;
    word();

    int i, j;

    i = strlen(magicword);
    i--;

    char palavra[i];

    for (j = 0; j <= i; j++) {
        palavra[j] = '_';
    }


    do{
        fflush(stdin);
        venceu = 1;
        printf("/*********************************\\  \n");
        printf("|          JOGO DA FORCA          |   \n");
        printf("\\*********************************/  \n\n\n");

        if(err == 0){
            forca();
        }else if(err == 1){
            forca_cabeca();
        }else if(err == 2){
            forca_rosto();
        }else if(err == 3){
            forca_tronco();
        }else if(err == 4){
            forca_bracos();
        }else if(err == 5){
            forca_pernas();
        }

        printf("\n\n");

        for (j = 0; j < i; j++) {
            printf("%c ",palavra[j]);
        }
        
        //printf("\n\nhackzinho: %s", magicword);
        
        
    
        printf("\n\nDigite uma letra: ");
        scanf("%c",&letra);
        
        for (j = 0; j < i; j++) {
            if (letra == magicword[j]) {
                palavra[j] = letra;
                aux = 1;
            }
            //printf("\n%d",aux);
        }
        //system("pause");
        if(aux == 0){
            err++;
        }else{
            aux = 0;
        }
        //printf("\n%d",aux);
        //printf("\n%d",err);
       // system("pause");
        for (j = 0; j < i; j++) {
            if ('_' == palavra[j]) {
                venceu = 0;
            }
            //printf("\n%d",aux);
        }
        if (err == 5) {
            system("cls");
            forca_pernas();
            pause(0.5);
            system("cls");
            animacao_caveira();
            printf("\n\nA palavra era: %s\n\n", magicword);
            system("pause");
            break;
        }else if(venceu == 1){
            printf("\n\n\n");
            printf("       Voce ganhou!     \n");
            printf("       ___________      \n");
            printf("      '._==_==_=_.'     \n");
            printf("      .-\\:      /-.    \n");
            printf("     | (|:.     |) |    \n");
            printf("      '-|:.     |-'     \n");
            printf("        \\::.    /      \n");
            printf("         '::. .'        \n");
            printf("           ) (          \n");
            printf("         _.' '._        \n");
            printf("        '-------'       \n\n");
            printf("\n\n");
            break;
        }
        
        
    
        system("cls");
    }while (err != 5);

    adc();

    return;
}



int num_aleatorio() {
    int i, numlinha = 0;
    int x;
    FILE *num = fopen("Test.txt", "r");
    do {
        x = fgetc(num);
        if (x == '\n') {
            numlinha++;
        }
    } while (x != EOF);
    fclose(num);
    srand(time(NULL));
    i = (rand() % numlinha);
    if (i != 0) {
        return i;
    } else {
        num_aleatorio();
    }
}

void word() {
    int x = num_aleatorio();
    char palavra[50];
    FILE *ar = fopen("Test.txt", "r");
    int i = 0;
    while (i < x) {
        fgets(palavra, 20, ar);
        i++;
    }
    fclose(ar);
    strcpy(magicword, palavra);
}

void adc() {
    char quer;

    fflush(stdin);
    printf("Voce deseja adicionar uma nova palavra no jogo?(s/n): ");
    scanf("%c", &quer);
    if (quer == 's')
    {
        char novap[50];
        FILE *add = fopen("Test.txt", "a");
        printf("\nDigite uma nova palavra: ");
        scanf("%s", &novap);
        fprintf(add, "\n%s", novap);
        fclose(add);
    }

    novojogo();
}

void pause(float delay1) {
    if (delay1 < 0.001)
        return;
    float inst1 = 0, inst2 = 0;
    inst1 = (float)clock() / (float)CLOCKS_PER_SEC;
    while (inst2 - inst1 < delay1)
        inst2 = (float)clock() / (float)CLOCKS_PER_SEC;
    return;
}

void caveira_fechada() {
    printf("        Voce perdeu!       \n");
    printf("                           \n");
    printf("       ---0000000---       \n");
    printf("    -00000000000000000-    \n");
    printf("   |0000000000000000000|   \n");
    printf("   |0000000000000000000|   \n");
    printf("  0|0000000000000000000|0  \n");
    printf("  00|00000000000000000|00  \n");
    printf("  00|0     00000     0|00  \n");
    printf("   0|       000       |0   \n");
    printf("   0|      00_00      |0   \n");
    printf("    |0000000___0000000|    \n");
    printf("   000___000-_-000___000   \n");
    printf("      |___0000000___|      \n");
    printf("     00__TTTTTTTTT__00     \n");
    printf("     000-TTTTTTTTT-000     \n");
    printf("      000TTTTTTTTT000      \n");
    printf("        00000000000        \n");
    printf("                           \n");
    printf("                           \n");
}

void caveira_aberta() {
    printf("        Voce perdeu!       \n");
    printf("                           \n");
    printf("       ---0000000---       \n");
    printf("    -00000000000000000-    \n");
    printf("   |0000000000000000000|   \n");
    printf("   |0000000000000000000|   \n");
    printf("  0|0000000000000000000|0  \n");
    printf("  00|00000000000000000|00  \n");
    printf("  00|0     00000     0|00  \n");
    printf("   0|       000       |0   \n");
    printf("   0|      00_00      |0   \n");
    printf("    |0000000___0000000|    \n");
    printf("   000___000-_-000___000   \n");
    printf("      |___0000000___|      \n");
    printf("     00__TTTTTTTTT__00     \n");
    printf("     000-         -000     \n");
    printf("      000TTTTTTTTT000      \n");
    printf("        00000000000        \n");
    printf("                           \n");
    printf("                           \n");
}

void animacao_caveira() {
    caveira_fechada();
    pause(0.5);
    system("cls");
    caveira_aberta();
    pause(0.5);
    system("cls");
    caveira_fechada();
    pause(0.5);
    system("cls");
    caveira_aberta();
    pause(0.5);
    system("cls");
    caveira_fechada();
}

void forca()
{
    printf("  ____________________    \n");
    printf("  |/                 |    \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("_/|\\_____                \n");
}

void forca_cabeca()
{
    printf("  ____________________    \n");
    printf("  |/                 |    \n");
    printf("  |                (   )  \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("_/|\\_____                \n");
}

void forca_rosto()
{
    printf("  ____________________    \n");
    printf("  |/                 |    \n");
    printf("  |                (*-*)  \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("_/|\\_____                \n");
}

void forca_tronco()
{
    printf("  ____________________    \n");
    printf("  |/                 |    \n");
    printf("  |                (*-*)  \n");
    printf("  |                  |    \n");
    printf("  |                  |    \n");
    printf("  |                  |    \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("_/|\\_____                \n");
}

void forca_bracos()
{
    printf("  ____________________    \n");
    printf("  |/                 |    \n");
    printf("  |                (*-*)  \n");
    printf("  |                 /|\\  \n");
    printf("  |                / | \\ \n");
    printf("  |                  |    \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("_/|\\_____                \n");
}

void forca_pernas()
{
    printf("  ____________________    \n");
    printf("  |/                 |    \n");
    printf("  |                (*-*)  \n");
    printf("  |                 /|\\  \n");
    printf("  |                / | \\ \n");
    printf("  |                  |    \n");
    printf("  |                 / \\  \n");
    printf("  |                /   \\ \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("_/|\\_____                \n");
}

void tela_de_carregamento() {
    int i;
    printf("Loading program...\n");
    for (i = 0; i < 25; i++) {
        pause(0.15);
        printf("=");
    }
    printf("\n\nFinishing installation");
    pause(0.3);
    printf(".");
    pause(0.3);
    printf(".");
    pause(0.3);
    printf(".\n\n");
    pause(0.3);
    printf("Jogo feito por Pedro e Fernando\n\n");
    pause(2);
}

void novojogo() {
    char quer;

    fflush(stdin);
    printf("Quer jogar novamente? (s/n): ");
    scanf("%c", &quer);
    if (quer == 's')
    {
        system("cls");
        jogar();
    }
}