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
    printf("Jogador 1, selecione a orientação (1-vertical, 0-horizontal): \n");
    scanf("%d", &orientacao);
    printf("Jogador 1, insira a posição (x): \n");
    scanf("%d", &x);
    printf("Jogador 1, insira a posição (y): \n");
    scanf("%d", &y);
    x -= 1;
    y -= 1;
    if ((x < 0 || x > 9) || (y < 0 || y > 9) || (a->tabuleiro[y][x] != ' ') || (orientacao != 0 && orientacao != 1))
    {
        while ((x < 0 || x > 9) || (y < 0 || y > 9) || (a->tabuleiro[y][x] != ' ') || (orientacao != 0 && orientacao != 1))
        {
            if (a->tabuleiro[y][x] != ' ')
                printf("Posição Ocupada por Navio\n");
            if (x < 0 || x > 9)
                printf("X invalido, jogue novamente, player 1.\n");
            if (y < 0 || y > 9)
                printf("Y invalido, jogue novamente, player 1.\n");

            printf("barco posicionado, jogue novamente, player 1.\n");
            printf("digite nova orientacao: ");
            scanf("%d", &orientacao);
            printf("digite novo X: ");
            scanf("%d", &x);
            printf("digite novo Y: ");
            scanf("%d", &y);
        }
        x -= 1;
        y -= 1;
    }

    if (x < 0)
        x = 0;
    if (y < 0)
        y = 0;
    if ((x >= 0 && x < tam) && (y >= 0 && y < tam) && (a->tabuleiro[y][x] == ' ') && (orientacao == 0) && (x + size) <= 10)
    {
        for (int i = 0; i < size; i++)
        {
            b->Barco[i] = 'N';
        }
        for (int k = 0; k < size; k++)
        {
            a->tabuleiro[y][x + k] = b->Barco[k];
        }
    }

    if ((x >= 0 && x < tam) && (y >= 0 && y < tam) && (a->tabuleiro[y][x] == ' ') && (orientacao == 1) && (y + size) <= 10)
    {
        for (int i = 0; i < size; i++)
        {
            b->Barco[i] = 'N';
        }
        for (int k = 0; k < size; k++)
        {
            a->tabuleiro[y + k][x] = b->Barco[k];
        }
    }
}

void player2posiciona(matriz *a, navio *b, int size, int x, int y, int orientacao)
{
    printf("Jogador 2, selecione a orientação (1-vertical, 0-horizontal): \n");
    scanf("%d", &orientacao);
    printf("Jogador 2, insira a posição (x): \n");
    scanf("%d", &x);
    printf("Jogador 2, insira a posição (y): \n");
    scanf("%d", &y);
    x -= 1;
    y -= 1;
    if ((x < 0 || x > 9) || (y < 0 || y > 9) || (a->tabuleiro2[y][x] != ' ') || (orientacao != 0 && orientacao != 1))
    {
        while ((x < 0 || x > 9) || (y < 0 || y > 9) || (a->tabuleiro2[y][x] != ' ') || (orientacao != 0 && orientacao != 1))
        {
            if (a->tabuleiro2[y][x] != ' ')
                printf("Posição Ocupada por Navio\n");
            if (x < 0 || x > 9)
                printf("X invalido, jogue novamente, player 2.\n");
            if (y < 0 || y > 9)
                printf("Y invalido, jogue novamente, player 2.\n");

            printf("barco posicionado, jogue novamente, player 2.\n");
            printf("digite nova orientacao: ");
            scanf("%d", &orientacao);
            printf("digite novo X: ");
            scanf("%d", &x);
            printf("digite novo Y: ");
            scanf("%d", &y);
        }
        x -= 1;
        y -= 1;
    }
    if (x < 0)
        x = 0;
    if (y < 0)
        y = 0;
    if ((x >= 0 && x < tam) && (y >= 0 && y < tam) && (a->tabuleiro2[y][x] == ' ') && (orientacao == 0) && (x + size) <= 10)
    {
        for (int i = 0; i < size; i++)
        {
            b->barco2[i] = 'N';
        }
        for (int k = 0; k < size; k++)
        {
            a->tabuleiro2[y][x + k] = b->barco2[k];
        }
    }

    if ((x >= 0 && x < tam) && (y >= 0 && y < tam) && (a->tabuleiro2[y][x] == ' ') && (orientacao == 1) && (y + size) <= 10)
    {
        for (int i = 0; i < size; i++)
        {
            b->barco2[i] = 'N';
        }
        for (int k = 0; k < size; k++)
        {
            a->tabuleiro2[y + k][x] = b->barco2[k];
        }
    }
}

void BOOM(matriz *a, navio *b, int x, int y)
{
    printf("Jogador 1, insira a posição (x) do ataque: \n");
    scanf("%d", &x);
    printf("digite posicao y");
    scanf("%d", &y);
    x -= 1;
    y -= 1;
    if ((x < 0 || x > 10) || (y < 0 || y > 10) || (a->tabuleiro2[y][x] == 'O') || (a->tabuleiro2[y][x] == 'X'))
    {
        while ((x < 0 || x > 10) || (y < 0 || y > 10) || (a->tabuleiro2[y][x] == 'O') || (a->tabuleiro2[y][x] == 'X'))
        {
            if (a->tabuleiro2[y][x] == 'O' || a->tabuleiro2[y][x] == 'X')
                printf("Posição ja atacada, jogue novamente, player 1.\n");
            if (x < 0 || x > 9)
                printf("X invalido, jogue novamente, player 1.\n");
            if (y < 0 || y > 9)
                printf("Y invalido, jogue novamente, player 1.\n");

            printf("digite novo X: ");
            scanf("%d", &x);
            printf("digite novo Y: ");
            scanf("%d", &y);
        }
        x -= 1;
        y -= 1;
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

    printf("Jogador 2, insira a posição (x) do ataque: \n");
    scanf("%d", &x);
    printf("digite posicao y");
    scanf("%d", &y);

    x -= 1;
    y -= 1;
    if ((x < 0 || x > 10) || (y < 0 || y > 10) || (a->tabuleiro[y][x] == 'O') || (a->tabuleiro[y][x] == 'X'))
    {
        while ((x < 0 || x > 10) || (y < 0 || y > 10) || (a->tabuleiro[y][x] == 'O') || (a->tabuleiro[y][x] == 'X'))
        {
            if (a->tabuleiro[y][x] == 'O' || a->tabuleiro[y][x] == 'X')
                printf("Posição ja atacada, jogue novamente, player 1.\n");
            if (x < 0 || x > 9)
                printf("X invalido, jogue novamente, player 1.\n");
            if (y < 0 || y > 9)
                printf("Y invalido, jogue novamente, player 1.\n");

            printf("digite novo X: ");
            scanf("%d", &x);
            printf("digite novo Y: ");
            scanf("%d", &y);
        }
        x -= 1;
        y -= 1;
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
    int tamanho = 0;
    int x = 0, y = 0;
    int orientacao = 0;
    b->restamdo1 = 10 + ((novosNavios - 5) * 2);
    b->restamdo2 = 10 + ((novosNavios - 5) * 2);

    if (novosNavios == 5)
    {
        b->restamdo1 = 10;
        b->restamdo2 = 10;
    }
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
    printf("+---------------------+"
           "|      PLAYER 1       |"
           "|       TURN!         |"
           "+---------------------+");
    telajogador1(a);
    printf("Navio de tamanho 4\n");
    player1posiciona(a, b, tamanho, x, y, orientacao);
    telajogador1(a);
    tamanho = 3;
    printf("Navio de tamanho 3\n");
    player1posiciona(a, b, tamanho, x, y, orientacao);
    telajogador1(a);

    do
    {
        tamanho = 1;
        printf("Navio de tamanho 1\n");
        player1posiciona(a, b, tamanho, x, y, orientacao);
        telajogador1(a);
        i++;
    } while (i < 3);
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
        printf("Navio de tamanho 2\n");

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
    printf("Navio de tamanho 4\n");
    player2posiciona(a, b, tamanhobarco2, x, y, orientacao);
    telajogador2(a);
    tamanhobarco2 = 3;
    cont2 += tamanho;
    printf("Navio de tamanho 3\n");
    player2posiciona(a, b, tamanhobarco2, x, y, orientacao);
    telajogador2(a);

    do
    {
        tamanhobarco2 = 1;
        telajogador2(a);
        printf("Navio de tamanho 1\n");
        player2posiciona(a, b, tamanhobarco2, x, y, orientacao);
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
        printf("Navio de tamanho 2\n");
        player2posiciona(a, b, tamanhobarco2, x, y, orientacao);
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
        BOOM(a, b, x, y);
        oqueojogador1vedo2(a);
        if (isThisWinner(b) != 0)
            break;
        printf("+---------------------+"
               "|      PLAYER 2       |"
               "|       TURN!         |"
               "+---------------------+");
        telajogador2(a);
        oqueojogador2ver(a);
        BOOM2(a, b, x, y);
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