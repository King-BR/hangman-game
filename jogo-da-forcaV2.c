/* 
 *  Projeto de Linguagem de Progamação 1
 *  Jogo da forca
 *  Feito por Pedro e Fernando
 *  Versão: 2.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

char magicword[30];

int num_aleatorio();
void jogar();
void word();
void adc();
void pause(float delay1);
void caveira_fechada();
void caveira_aberta();
void animacao_caveira();
void tela_de_carregamento();
void forca();
void forca_cabeca();
void forca_tronco();
void forca_braco1();
void forca_braco2();
void forca_pernas();

int main() {

    setlocale(LC_ALL, "portuguese-brazilian");

    tela_de_carregamento ();
    system("cls");

    jogar();

    return 0;
}

void jogar() {
    int err = 0;
    char letra = "ç";
    int aux = 0;

    word();

    int i, j;

    i = strlen(magicword);
    i--;

    char palavra[i];

    for (j = 0; j <= i; j++) {
        palavra[j] = "_";
    }
    
    do {
        printf("/*********************************\\  \n");
        printf("|          JOGO DA FORCA          |   \n");
        printf("\\*********************************/  \n\n\n");

        switch (err) {
            case 0: {
                forca();
                break;
            }
            case 1: {
                forca_cabeca();
                break;
            }
            case 2: {
                forca_tronco();
                break;
            }
            case 3: {
                forca_braco1();
                break;
            }
            case 4: {
                forca_braco2();
                break;
            }
            case 5: {
                forca_pernas();
                break;
            }
        }


        
        for (j = 0; j < i; j++) {
            if (letra == magicword[j]) {
                printf("%c ",letra);
                palavra[j] = letra;
                aux = 1;
            } else {
                printf("_ ");
            }
        }

        if (aux == 0) {
            err++;
        } else {
            aux = 0;
        }


        printf("\n\nhackzinho: %s", magicword);

        if (err == 5) {
            printf("\n\nVoce perdeu!\nA palavra era: %s\n",magicword);
        } else {
            printf("Digite uma letra: ");
            scanf("%c",&letra);
        }

        system("pause");
        system("cls");
    } while (err != 5);

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
    char novap[50];
    FILE *add = fopen("Test.txt", "a");
    printf("\nDigite uma nova palavra: ");
    scanf("%s", &novap);
    fprintf(add, "\n%s", novap);
    fclose(add);
    system("cls");
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

void forca() {
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

void forca_cabeca() {
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

void forca_tronco() {
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

void forca_braco1() {
    printf("  ____________________    \n");
    printf("  |/                 |    \n");
    printf("  |                (*-*)  \n");
    printf("  |                 /|    \n");
    printf("  |                / |    \n");
    printf("  |                  |    \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("  |                       \n");
    printf("_/|\\_____                \n");
}

void forca_braco2() {
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

void forca_pernas() {
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
