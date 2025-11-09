#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define tam 10
#define novosNavios 5
typedef struct barco
{
    char Barco[5];
    char barco2[5];
    int restamdo1;
    int restamdo2;
} navio;

typedef struct t
{
    char tabuleiro[tam][tam];
    char tabuleiro2[tam][tam];
    char tabuleirooculto[tam][tam];
    char tabuleirooculto2[tam][tam];
} matriz;
int isThisWinner(navio *b);
void telajogador1(matriz *a);
void telajogador2(matriz *a);
void oqueojogador1vedo2(matriz *a);
void oqueojogador2ver(matriz *a);
void player1posiciona(matriz *a, navio *b, int size, int x, int y, int orientacao);
void player2posiciona(matriz *a, navio *b, int size, int x, int y, int orientacao);
void BOOM(matriz *a, navio *b, int x, int y);
void BOOM2(matriz *a, navio *b, int x, int y);

void telajogador1(matriz *a)
{
    printf("PAINEL DO JOGADOR 1\n");
    printf("\n");
    printf("X:");
    int cima = 1;
    for (int i = 0; i < tam; i++)
    {
        printf("    |%d   ", cima);
        cima++;
    }
    printf("\nY:");
    printf("\n");

    for (int i = 0; i < tam; i++)
    {
        printf("%d", (2 + i) - 1);
        for (int j = 0; j < tam; j++)
        {
            printf("|   %c    ", a->tabuleiro[i][j]);
            if (j == tam - 1)
            {
                printf("      |");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void telajogador2(matriz *a)
{
    printf("PAINEL DO JOGADOR 2\n");
    printf("\n");
    printf("X:");
    int cima = 1;
    for (int i = 0; i < tam; i++)
    {
        printf("    |%d   ", cima);
        cima++;
    }
    printf("\nY:");
    printf("\n");
    for (int i = 0; i < tam; i++)
    {
        printf("%d", (2 + i) - 1);
        for (int j = 0; j < tam; j++)
        {
            printf("|   %c    ", a->tabuleiro2[i][j]);
            if (j == tam - 1)
            {
                printf("      |");
            }
        }
        printf("\n");
    }
    printf("\n");
}
void oqueojogador1vedo2(matriz *a)
{
    printf("PAINEL DE ACERTOS DO JOGADOR 1\n");
    printf("X:");
    int cima = 1;
    for (int i = 0; i < tam; i++)
    {
        printf("    |%d   ", cima);
        cima++;
    }
    printf("\nY:");
    printf("\n");
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            printf("|   %c    ", a->tabuleirooculto2[i][j]);
            if (j == tam - 1)
            {
                printf("      |");
            }
        }
        printf("\n");
    }
}
void oqueojogador2ver(matriz *a)
{
    printf("PAINEL DE ACERTOS DO JOGADOR 2\n");
    printf("X:");
    int cima = 1;
    for (int i = 0; i < tam; i++)
    {
        printf("    |%d   ", cima);
        cima++;
    }
    printf("\nY:");
    printf("\n");
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            printf("|   %c    ", a->tabuleirooculto[i][j]);
            if (j == tam - 1)
            {
                printf("      |");
            }
        }
        printf("\n");
    }
}
void player1posiciona(matriz *a, navio *b, int size, int x, int y, int orientacao)
{
    for (int i = 0; i < size; i++)
    {
        b->Barco[i] = 'N';
    }
    if (x < 0 && x > 9 && y < 0 && y > 9)
    {
        printf("Ataque inválido player 2, jogue novamente.\n");
        printf("digite novo X: ");
        scanf("%d", &x);
        printf("digite novo Y: ");
        scanf("%d", &y);
        player1posiciona(a, b, size, x - 1, y - 1, orientacao);
    }

    if (orientacao == 0)
    {
        if (y + size > tam)
        {
            printf("Y  inválida\n");
            printf("Player 1 jogue novamente\n");
            printf("nova orientacao \n");
            scanf("%d", &orientacao);
            printf("x: %d \n digite novo x\n", x);
            scanf("%d", &x);
            printf("y: %d \n digite novo y\n", y);
            scanf("%d", &y);
            player1posiciona(a, b, size, x - 1, y - 1, orientacao);
            return;
        }
    }
    else
    {
        if (x + size > tam)
        {
            printf("Y  inválida\n");
            printf("Player 1 jogue novamente\n");
            printf("nova orientacao \n");
            scanf("%d", &orientacao);
            printf("x: %d \n digite novo x\n", x);
            scanf("%d", &x);
            printf("y: %d \n digite novo y\n", y);
            scanf("%d", &y);
            player1posiciona(a, b, size, x - 1, y - 1, orientacao);
            return;
        }
    }
    if (orientacao == 1)
    {
        for (int k = 0; k < size; k++)
        {
            if (a->tabuleiro[x + k][y] != ' ' && a->tabuleiro[x + k][y] != 'N')
            {
                printf("Posição Posicao Ocupada por Navio\n");
                printf("Player 1 jogue novamente\n");
                printf("nova orientacao \n");
                scanf("%d", &orientacao);
                printf("digite novo X");
                scanf("%d", &x);
                printf("digite novo Y");
                scanf("%d", &y);
                player1posiciona(a, b, size, x - 1, y - 1, orientacao);
                return;
            }
        }
        for (int k = 0; k < size; k++)
        {
            if (a->tabuleiro[y + k][x] != ' ')
            {
                printf("Posição Posicao Ocupada por Navio\n");
                printf("Player 1 jogue novamente\n");
                printf("nova orientacao \n");
                scanf("%d", &orientacao);
                printf("digite novo X");
                scanf("%d", &x);
                printf("digite novo Y");
                scanf("%d", &y);
                player1posiciona(a, b, size, x - 1, y - 1, orientacao);
                return;
            }
            else if (a->tabuleiro[x + k][y] == ' ')
                a->tabuleiro[y + k][x] = b->Barco[k];
        }
    }
    else if (orientacao == 0)
    {

        for (int k = 0; k < size; k++)
        {
            if (a->tabuleiro[y][x + k] != ' ')
            {
                printf("Posição Ocupada por Navio\n");
                printf("Player 1 jogue novamente\n");
                printf("nova orientacao \n");
                scanf("%d", &orientacao);
                printf("digite novo X");
                scanf("%d", &x);
                printf("digite novo Y");
                scanf("%d", &y);
                player1posiciona(a, b, size, x - 1, y - 1, orientacao);
            }
        }
        for (int k = 0; k < size; k++)
        {
            if (a->tabuleiro[y][x + k] != ' ')
            {
                printf("Posição Posicao Ocupada por Navio\n");
                printf("Player 1 jogue novamente\n");
                printf("nova orientacao \n");
                scanf("%d", &orientacao);
                printf("digite novo X");
                scanf("%d", &x);
                printf("digite novo Y");
                scanf("%d", &y);
                player1posiciona(a, b, size, x - 1, y - 1, orientacao);
            }
            else if (a->tabuleiro[y][x + k] == ' ')
            {
                a->tabuleiro[y][x + k] = b->Barco[k];
            }
        }
    }
    else
    {
        printf("Orientação inválida\n");
        printf("Player 1 jogue novamente\n");
        printf("nova orientacao \n");
        scanf("%d", &orientacao);
        printf("digite novo X");
        scanf("%d", &x);
        printf("digite novo Y");
        scanf("%d", &y);
        player1posiciona(a, b, size, x - 1, y - 1, orientacao);
    }
}
void player2posiciona(matriz *a, navio *b, int size, int x, int y, int orientacao)
{
    for (int i = 0; i < size; i++)
    {
        b->barco2[i] = 'N';
    }

    if (x < 0 && x > 9 && y < 0 && y > 9)
    {
        printf("Ataque inválido player 2, jogue novamente.\n");
        printf("digite novo X: ");
        scanf("%d", &x);
        printf("digite novo Y: ");
        scanf("%d", &y);
        player2posiciona(a, b, size, x - 1, y - 1, orientacao);
    }

    if (orientacao == 0)
    {
        if (y + size > tam)
        {
            printf("Y  inválida\n");
            printf("Player 1 jogue novamente\n");
            printf("nova orientacao \n");
            scanf("%d", &orientacao);
            printf("x: %d \n digite novo x\n", x);
            scanf("%d", &x);
            printf("y: %d \n digite novo y\n", y);
            scanf("%d", &y);
            player2posiciona(a, b, size, x - 1, y - 1, orientacao);
        }
    }
    else
    {
        if (x + size > tam)
        {
            printf("Y  inválida\n");
            printf("Player 1 jogue novamente\n");
            printf("nova orientacao \n");
            scanf("%d", &orientacao);
            printf("x: %d \n digite novo x\n", x);
            scanf("%d", &x);
            printf("y: %d \n digite novo y\n", y);
            scanf("%d", &y);
            player2posiciona(a, b, size, x - 1, y - 1, orientacao);
        }
    }
    if (orientacao == 1)
    {
        for (int k = 0; k < size; k++)
        {
            if (a->tabuleiro2[y + x][x] != ' ' && a->tabuleiro2[x + k][y] != 'N')
            {
                printf("Posição Posicao Ocupada por Navio\n");
                printf("Player 1 jogue novamente\n");
                printf("nova orientacao \n");
                scanf("%d", &orientacao);
                printf("digite novo X");
                scanf("%d", &x);
                printf("digite novo Y");
                scanf("%d", &y);
                player2posiciona(a, b, size, x - 1, y - 1, orientacao);
                return;
            }
        }
        for (int k = 0; k < size; k++)
        {
            if (a->tabuleiro2[y + k][x] != ' ')
            {
                printf("Posição Posicao Ocupada por Navio\n");
                printf("Player 1 jogue novamente\n");
                printf("nova orientacao \n");
                scanf("%d", &orientacao);
                printf("digite novo X");
                scanf("%d", &x);
                printf("digite novo Y");
                scanf("%d", &y);
                player2posiciona(a, b, size, x - 1, y - 1, orientacao);
            }
            else if (a->tabuleiro2[y + k][x] == ' ')
                a->tabuleiro2[y + k][x] = b->barco2[k];
        }
    }
    else if (orientacao == 0)
    {

        for (int k = 0; k < size; k++)
        {
            if (a->tabuleiro2[y][x + k] != ' ')
            {
                printf("Posição Ocupada por Navio\n");
                printf("Player 1 jogue novamente\n");
                printf("nova orientacao \n");
                scanf("%d", &orientacao);
                printf("digite novo X");
                scanf("%d", &x);
                printf("digite novo Y");
                scanf("%d", &y);
                player2posiciona(a, b, size, x - 1, y - 1, orientacao);
            }
        }
        for (int k = 0; k < size; k++)
        {
            if (a->tabuleiro2[y][x + k] != ' ')
            {
                printf("Posição Posicao Ocupada por Navio\n");
                printf("Player 1 jogue novamente\n");
                printf("nova orientacao \n");
                scanf("%d", &orientacao);
                printf("digite novo X");
                scanf("%d", &x);
                printf("digite novo Y");
                scanf("%d", &y);
                player2posiciona(a, b, size, x - 1, y - 1, orientacao);
            }
            else if (a->tabuleiro2[y][x + k] == ' ')
            {
                a->tabuleiro2[y][x + k] = b->barco2[k];
            }
        }
    }
    else
    {
        printf("Orientação inválida\n");
        printf("Player 1 jogue novamente\n");
        printf("nova orientacao \n");
        scanf("%d", &orientacao);
        printf("digite novo X");
        scanf("%d", &x);
        printf("digite novo Y");
        scanf("%d", &y);
        player2posiciona(a, b, size, x - 1, y - 1, orientacao);
        return;
    }
}
void BOOM(matriz *a, navio *b, int x, int y)
{
    if (x < 0 && x > 9 && y < 0 && y > 9)
    {
        printf("Ataque inválido player 1, jogue novamente.\n");
        printf("digite novo X: ");
        scanf("%d", &x);
        printf("digite novo Y: ");
        scanf("%d", &y);
        BOOM(a, b, x, y);
        return;
    }

    if (x >= 0 && x < tam && y >= 0 && y < tam)
    {
        if (a->tabuleiro2[y][x] == 'N')
        {
            a->tabuleirooculto2[y][x] = 'O';
            a->tabuleiro2[y][x] = 'O';
            b->restamdo2--;
        }
        else
        {
            a->tabuleirooculto2[y][x] = 'X';
            a->tabuleiro2[y][x] = 'X';
        }
    }
}

void BOOM2(matriz *a, navio *b, int x, int y)
{
    if (x < 0 && x > 9 && y < 0 && y > 9)
    {
        printf("Ataque inválido player 2, jogue novamente.\n");
        printf("digite novo X: ");
        scanf("%d", &x);
        printf("digite novo Y: ");
        scanf("%d", &y);
        BOOM2(a, b, x, y);
    }

    if (x >= 0 && x < tam && y >= 0 && y < tam)
    {
        if (a->tabuleiro[y][x] == 'N')
        {
            a->tabuleirooculto[y][x] = 'O';
            a->tabuleiro[y][x] = 'O';
            b->restamdo1--;
        }
        else
        {
            a->tabuleirooculto[y][x] = 'X';
            a->tabuleiro[y][x] = 'X';
        }
    }
}

int isThisWinner(navio *b)
{

    if (b->restamdo1 == 0)
    {
        return 1;
    }
    else if (b->restamdo2 == 0)
    {
        return 2;
    }
    return 0;
}
int main()
{
    matriz *a = malloc(sizeof(matriz));
    navio *b = malloc(sizeof(navio));
    int tamanho;
    int x, y;
    b->restamdo1 = 10+((novosNavios-5)*2);
    b->restamdo2 = 10+((novosNavios-5)*2);

    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            a->tabuleiro[i][j] = ' ';
            a->tabuleiro2[i][j] = ' ';
            a->tabuleirooculto[i][j] = ' ';
            a->tabuleirooculto2[i][j] = ' ';
        }
    }
    int i = 0;
    tamanho = 4;
    int cont1 = 4;
    printf("+---------------------+"
           "|      PLAYER 1       |"
           "|       TURN!         |"
           "+---------------------+");
    telajogador1(a);
    printf("Jogador 1, selecione a orientação (1-vertical, 0-horizontal) navio de tamanho 4: \n");
    int orientacao;
    scanf("%d", &orientacao);
    printf("Jogador 1, insira a posição (x) do navio de tamsnho 4: \n");
    scanf("%d", &x);
    printf("Jogador 1, insira a posição (y) do navio de tamsnho 4: \n");
    scanf("%d", &y);
    player1posiciona(a, b, tamanho, x - 1, y - 1, orientacao);
    telajogador1(a);
    tamanho = 3;
    cont1 += tamanho;
    printf("Jogador 1, selecione a orientação (1-vertical, 0-horizontal) navio de tamanho 3: \n");
    scanf("%d", &orientacao);
    printf("Jogador 1, insira a posição (x) do navio de tamsnho 3: \n");
    scanf("%d", &x);
    printf("Jogador 1, insira a posição (y) do navio de tamsnho 3: \n");
    scanf("%d", &y);
    player1posiciona(a, b, tamanho, x - 1, y - 1, orientacao);
    telajogador1(a);

    do
    {
        tamanho = 1;
        printf("Jogador 1, insira a posição (x) do navio de tamsnho 1: \n");
        scanf("%d", &x);
        printf("Jogador 1, insira a posição (y) do navio de tamsnho 1: \n");
        scanf("%d", &y);
        player1posiciona(a, b, tamanho, x - 1, y - 1, orientacao);
        telajogador1(a);
        i++;
    } while (i < 3);
    cont1 = i + 1;
    i = 0;
    int new = novosNavios;
    tamanho = 2;
    if (new > 5)
    {
        new = 5;
    }
    else
    {
        new = 0;
    }
    do
    {
        if (new == 0)
            break;
        telajogador1(a);
        printf("AJogador 1, selecione a orientação (1-vertical, 0-horizontal) navio de tamanho 2: \n");
        scanf("%d", &orientacao);
        printf("Jogador 1, insira a posição (x) do navio de tamsnho 2: \n");
        scanf("%d", &x);
        printf("Jogador 1, insira a posição (y) do navio de tamsnho 2: \n");
        scanf("%d", &y);
        player1posiciona(a, b, tamanho, x - 1, y - 1, orientacao);
        i++;
    } while (i < new);

    printf("+---------------------+"
           "|      PLAYER 2       |"
           "|       TURN!         |"
           "+---------------------+");
    int tamanhobarco2 = 4;
    int cont2 = 4;
    telajogador2(a);
    printf("Jogazdor 2, selecione a orientação (1-vertical, 0-horizontal) navio de tamanho 4: \n");
    scanf("%d", &orientacao);
    printf("Jogador 2, insira a posição (x) do navio de tamsnho 4: \n");
    scanf("%d", &x);
    printf("Jogador 2, insira a posição (y) do navio de tamsnho 4: \n");
    scanf("%d", &y);
    player2posiciona(a, b, tamanhobarco2, x - 1, y - 1, orientacao);
    telajogador2(a);
    tamanhobarco2 = 3;
    cont2 += tamanho;
    printf("Jogador 2, selecione a orientação (1-vertical, 0-horizontal) navio de tamanho 3: \n");
    scanf("%d", &orientacao);
    printf("Jogador 2, insira a posição (x) do navio de tamsnho 3: \n");
    scanf("%d", &x);
    printf("Jogador 2, insira a posição (y) do navio de tamsnho 3: \n");
    scanf("%d", &y);
    player2posiciona(a, b, tamanhobarco2, x - 1, y - 1, orientacao);
    telajogador2(a);

    do
    {
        tamanhobarco2 = 1;
        telajogador2(a);
        printf("Jogador 2, insira a posição (x) do navio de tamsnho 1: \n");
        scanf("%d", &x);
        printf("Jogador 2, insira a posição (y) do navio de tamsnho 1: \n");
        scanf("%d", &y);
        player2posiciona(a, b, tamanhobarco2, x - 1, y - 1, orientacao);
        telajogador2(a);
        i++;
    } while (i < 3);
    cont2 = i + 1;
    i = 0;
    if (new > 5)
    {
        new = 5;
    }
    else
    {
        new = 0;
    }
    do
    {
        if (new < 1)
            break;
        tamanhobarco2 = 2;
        telajogador2(a);
        printf("A orientação (1-vertical, 0-horizontal) navio de tamanho 2: \n");
        scanf("%d", &orientacao);
        printf("Jogador 2, insira a posição (x) do navio de tamsnho 2: \n");
        scanf("%d", &x);
        printf("Jogador 2, insira a posição (y) do navio de tamsnho 2: \n");
        scanf("%d", &y);
        player2posiciona(a, b, tamanhobarco2, x - 1, y - 1, orientacao);
        telajogador2(a);
        i++;
    } while (i < new);

    while (isThisWinner(b) == 0)
    {
        printf("+---------------------+"
               "|      PLAYER 1       |"
               "|       TURN!         |"
               "+---------------------+");
        telajogador1(a);
        oqueojogador1vedo2(a);
        printf("Jogador 1, insira a posição (x) do seu ataque: \n");
        scanf("%d", &x);
        printf("Jogador 1, insira a posição (y) do seu ataque: \n");
        scanf("%d", &y);
        BOOM(a, b, x - 1, y - 1);
        oqueojogador1vedo2(a);
        if (isThisWinner(b) != 0)
            break;
        printf("+---------------------+"
               "|      PLAYER 2       |"
               "|       TURN!         |"
               "+---------------------+");
        telajogador2(a);
        oqueojogador2ver(a);
        printf("Jogador 2, insira a posição (x) do seu ataque: \n");
        scanf("%d", &x);
        printf("Jogador 2, insira a posição (y) do seu ataque: \n");
        scanf("%d", &y);
        BOOM2(a, b, x - 1, y - 1);
        oqueojogador2ver(a);
    }
    if (isThisWinner(b) == 1)
    {
        printf("+---------------------+"
               "|      PLAYER 1       |"
               "|       Wins!         |"
               "+---------------------+");
    }
    else if (isThisWinner(b) == 2)
    {
        printf("+---------------------+"
               "|      PLAYER 2       |"
               "|       Wins!         |"
               "+---------------------+");
    }
    else
    {
        printf("+---------------------+"
               "|     PLAYERS          |"
               "|   EMPATADOS!         |"
               "+---------------------+");
    }
    free(a);
    free(b);
    return 0;
}