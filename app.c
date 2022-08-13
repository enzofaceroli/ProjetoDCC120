#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

void tela();
void instrucoes();
void gerarPotes();
void mostrarPotes();
int checar();
int checarStatus();
void jogo();
void telaFinal();

int main()
{
    int potes[7][4] = {
        {1, 1, 1, 1},
        {2, 2, 2, 2},
        {3, 3, 3, 3},
        {4, 4, 4, 4},
        {5, 5, 5, 5},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};
    int fase = 1;
    printf("\e[1;1H\e[2J");
    tela();
#ifdef _WIN32
    Sleep(5000);
#else
    sleep(5);
#endif
    printf("\e[1;1H\e[2J");
    instrucoes();
    printf("\e[1;1H\e[2J");
    int tirar = 0;
    int colocar = 0;
    int aux = 0;
    srand(time(NULL));
    for (fase = 1; fase <= 5; fase++)
    {
        gerarPotes(potes, tirar, colocar, aux, fase);
        mostrarPotes(potes, fase);
        while (checar(potes) == 0)
        {
            jogo(potes, tirar, colocar, aux, fase);
        }
    }
    telaFinal();
    return 0;
}

void gerarPotes(int potes[7][4], int tirar, int colocar, int aux, int fase)
{
    for (int i = 0; i < fase * 100; i++)
    {
        tirar = rand() % 8;
        colocar = rand() % 8;
        printf("\e[1;1H\e[2J");
        if (tirar > 0 && tirar < 8 && colocar > 0 && colocar < 8)
        {
            if (checarStatus(potes, colocar) < 4 && checarStatus(potes, tirar) != 0)
            {
                for (int i = 0; i < 7; i++)
                {
                    if (potes[tirar - 1][i] != 0)
                    {
                        aux = potes[tirar - 1][i];
                        potes[tirar - 1][i] = 0;
                        break;
                    }
                }
                for (int i = 3; i >= 0; i--)
                {
                    if (potes[colocar - 1][i] == 0)
                    {
                        potes[colocar - 1][i] = aux;
                        break;
                    }
                }
            }
        }
    }
}

void tela()
{
    printf("##########################################################\n\n");
    printf("              QUEBRA-CABECA DA AGUA COLORIDA\n\n\n\n\n\n");
    printf("                      Carregando...\n\n");
    printf("##########################################################\n");
    return;
}

void instrucoes()
{
    char letra;
    printf("############################################################\n\n");
    printf("                         INSTRUCOES\n\n\n");
    printf(" O jogo possui 5 fases, e em cada delas, fica mais dificil.\nO objetivo eh mover as bolinhas de um pote pra outro ate\nque todos os potes tenham apenas bolinhas da mesma cor.\n\n                         BOA SORTE!     \n\n");
    printf("           Pressione qualquer tecla para continuar.\n\n");
    printf("############################################################\n");
    getchar();

    return;
}

void mostrarPotes(int potes[7][4], int fase)
{
    printf("FASE: %d\n\n\n", fase);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            switch (potes[j][i])
            {
            case 0:
                printf("|   | ");
                break;
            case 1:
                printf("|\e[1;91mOOO");
                printf("\e[0;0m");
                printf("| ");
                break;
            case 2:
                printf("|\e[1;92mOOO");
                printf("\e[0;0m");
                printf("| ");
                break;
            case 3:
                printf("|\e[1;93mOOO");
                printf("\e[0;0m");
                printf("| ");
                break;
            case 4:
                printf("|\e[1;94mOOO");
                printf("\e[0;0m");
                printf("| ");
                break;
            case 5:
                printf("|\e[1;95mOOO");
                printf("\e[0;0m");
                printf("| ");
                break;
            case 6:
                printf("|\e[1;96mOOO");
                printf("\e[0;0m");
                printf("| ");
                break;
            }
        }
        printf("\n");
    }
    printf("  1     2     3     4     5     6     7\n");
    return;
}

int checar(int potes[7][4])
{
    int resultado = 1;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (potes[i][j] != potes[i][j + 1])
            {
                resultado = 0;
            }
        }
    }
    return resultado;
}

int checarStatus(int vetor[][4], int poteSelecionado)
{
    int resultado = 0;
    for (int i = 0; i < 4; i++)
    {
        if (vetor[poteSelecionado - 1][i] != 0)
        {
            resultado++;
        }
    }
    return resultado;
}

void jogo(int potes[7][4], int tirar, int colocar, int aux, int fase)
{
    scanf("%d %d", &tirar, &colocar);
    printf("\e[1;1H\e[2J");
    if (tirar > 0 && tirar < 8 && colocar > 0 && colocar < 8)
    {
        if (checarStatus(potes, colocar) < 4 && checarStatus(potes, tirar) != 0)
        {
            for (int i = 0; i < 7; i++)
            {
                if (potes[tirar - 1][i] != 0)
                {
                    aux = potes[tirar - 1][i];
                    potes[tirar - 1][i] = 0;
                    break;
                }
            }
            for (int i = 3; i >= 0; i--)
            {
                if (potes[colocar - 1][i] == 0)
                {
                    potes[colocar - 1][i] = aux;
                    break;
                }
            }
        }
    }
    mostrarPotes(potes, fase);
    if (checar(potes) != 0)
    {
        printf("\e[1;1H\e[2J");
        printf("Voce a venceu a %da fase!\n\n\n", fase);
    }
    return;
}

void telaFinal()
{
    printf("##########################################################\n\n");
    printf("                   VOCE VENCEU O JOGO!\n\n                   Obrigado por jogar.\n\n\n\n");
    printf("   Enzo Faceroli Marques Moreira, Hugo Noyma Povoleri\n   DCC119/120: Turma X - 2022.1\n\n");
    printf("##########################################################\n");
#ifdef _WIN32
    Sleep(5000);
#else
    sleep(5);
#endif
    printf("\e[1;1H\e[2J");
    printf("##########################################################\n\n");
    printf("                        CREDITOS\n\n   Design: Enzo, Hugo\n   Logica: Enzo, Hugo\n   Desenvolvimento: Enzo, Hugo\n   Processo Criativo: Enzo, Hugo\n");
    printf("   Enzo Faceroli Marques Moreira, Hugo Noyma Povoleri\n   DCC119/120: Turma X - 2022.1\n\n");
    printf("##########################################################\n");
    return;
}