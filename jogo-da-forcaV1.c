/*
 *  Projeto de Linguagem de Progamação 1
 *  Jogo da forca
 *  Feito por Pedro e Fernando
 *  Versão: 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

int num_aleatorio();
void jogo();
char *word();
void adc();
void pause(float delay1);
void caveira_fechada();
void caveira_aberta();
void animacao_caveira();
void tela_de_carregamento();

int main()
{
    tela_de_carregamento();
    system("cls");

    jogo();

    return 0;
}

void jogo()
{

    printf("/*********************************\\\n");
    printf("|          JOGO DA FORCA          |\n");
    printf("\\*********************************/\n\n\n");

    printf("  ____________________  \n");
    printf("  |/                 |  \n");
    printf("  |                     \n");
    printf("  |                     \n");
    printf("  |                     \n");
    printf("  |                     \n");
    printf("  |                     \n");
    printf("  |                     \n");
    printf("  |                     \n");
    printf("  |                     \n");
    printf("  |                     \n");
    printf("  |                     \n");
    printf("_/|\\_____              \n");

    char plv[50];
    char *palavra;

    *palavra = plv;
    *palavra = word();

    printf("%s", plv);
    printf("\n%ld", strlen(plv));
}

void pause(float delay1)
{
    if (delay1 < 0.001)
        return;
    float inst1 = 0, inst2 = 0;
    inst1 = (float)clock() / (float)CLOCKS_PER_SEC;
    while (inst2 - inst1 < delay1)
        inst2 = (float)clock() / (float)CLOCKS_PER_SEC;
    return;
}

int num_aleatorio()
{
    srand(time(NULL));
    char count[100];
    int numlinha = 0;
    FILE *num = fopen("Test.txt", "r");
    do
    {
        fgets(count, 50, num);
        numlinha++;
    } while (numlinha != EOF);
    return rand() % numlinha;
}

char *word()
{
    char *palavra;
    FILE *ar = fopen("Test.txt", "r");
    int i = 0;
    for (i = 0; i < num_aleatorio(); i++)
    {
        fgets(palavra, 20, ar);
    }
    printf("%s", palavra);
    fclose(ar);
    return palavra;
}

void adc()
{
    char novap;
    FILE *add = fopen("Test.txt", "a");
    printf("\nDigite uma nova palavra: ");
    scanf("%c", &novap);
    fprintf(add, "%c", novap);
    fclose(add);
    return;
}

void caveira_fechada()
{
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

void caveira_aberta()
{
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

void animacao_caveira()
{
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

void tela_de_carregamento()
{
    int i;
    printf("Loading program...\n");
    for (i = 0; i < 25; i++)
    {
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