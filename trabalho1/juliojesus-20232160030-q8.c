#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void mostraGame(char matriz[3][3])
{
    char a = 'A';

    printf("\n  1 2 3\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%c ", a);
        for (int j = 0; j < 3; j++)
        {
            printf("%c ", matriz[i][j]);
        }
        a++;
        printf("\n");
    }
}

void jogar(char matriz[3][3], int jogador)
{

    char jogada[8];
    if (jogador == 1)
    {
        printf("Jogador 1, informe sua jogada:\n");
    }
    else
    {
        printf("Jogador 2, informe sua jogada:\n");
    }

    fgets(jogada, sizeof(jogada), stdin);
    for (int i = 0; jogada[i] != '\0'; i++)
    {
        if (jogada[i] == '\n')
        {
            jogada[i] = '\0';
            break;
        }
    }

    for (int i = 0; jogada[i] != '\0'; i++)
    {
        if (jogada[i] >= 'a' && jogada[i] <= 'z')
        {
            jogada[i] = jogada[i] - 32;
        }
        printf("%c", jogada[i]);
        if(strcmp(jogada, "A1") != 0 && strcmp(jogada, "A2") != 0 && strcmp(jogada, "A3") != 0 && strcmp(jogada, "B1") != 0 && strcmp(jogada, "B2") != 0 && strcmp(jogada, "B3") != 0 && strcmp(jogada, "C1") != 0 && strcmp(jogada, "C2") != 0 &&strcmp(jogada, "C3") != 0){
            printf("Jogada inválida, jogue novamente.\n");
            jogar(matriz, jogador);
            return;
        }
}
if (strcmp(jogada, "A1") == 0)
{
    if (jogador == 1)
    {
        if (matriz[0][0] != ' ')
        {
            printf("Posição já ocupada, jogue novamente.\n");
            jogar(matriz, jogador);
            return;
        }
        matriz[0][0] = 'X';
    }
    else
    {
        if (matriz[0][0] != ' ')
        {
            printf("Posição já ocupada, jogue novamente.\n");
            jogar(matriz, jogador);
            return;
        }
        matriz[0][0] = 'O';
    }
}
else if (strcmp(jogada, "A2") == 0)
{
    if (jogador == 1)
    {
        if (matriz[0][1] != ' ')
        {
            printf("Posição já ocupada, jogue novamente.\n");
            jogar(matriz, jogador);
            return;
        }
        matriz[0][1] = 'X';
    }
    else
    {
        if (matriz[0][1] != ' ')
        {
            printf("Posição já ocupada, jogue novamente.\n");
            jogar(matriz, jogador);
            return;
        }
        matriz[0][1] = 'O';
    }
}
else if (strcmp(jogada, "A3") == 0)
{
    if (jogador == 1)
    {
        if (matriz[0][2] != ' ')
        {
            printf("Posição já ocupada, jogue novamente.\n");
            jogar(matriz, jogador);
            return;
        }
        matriz[0][2] = 'X';
    }
    else
    {
        if (matriz[0][2] != ' ')
        {
            printf("Posição já ocupada, jogue novamente.\n");
            jogar(matriz, jogador);
            return;
        }
        matriz[0][2] = 'O';
    }
}
else if (strcmp(jogada, "B1") == 0)
{
    if (jogador == 1)
    {
        if (matriz[1][0] != ' ')
        {
            printf("Posição já ocupada, jogue novamente.\n");
            jogar(matriz, jogador);
            return;
        }
        matriz[1][0] = 'X';
    }
    else
    {
        if (matriz[1][0] != ' ')
        {
            printf("Posição já ocupada, jogue novamente.\n");
            jogar(matriz, jogador);
            return;
        }
        matriz[1][0] = 'O';
    }
}
else if (strcmp(jogada, "B2") == 0)
{
    if (jogador == 1)
    {
        if (matriz[1][1] != ' ')
        {
            printf("Posição já ocupada, jogue novamente.\n");
            jogar(matriz, jogador);
            return;
        }
        matriz[1][1] = 'X';
    }
    else
    {
        if (matriz[1][1] != ' ')
        {
            printf("Posição já ocupada, jogue novamente.\n");
            jogar(matriz, jogador);
            return;
        }
        matriz[1][1] = 'O';
    }
}
else if (strcmp(jogada, "B3") == 0)
{
    if (jogador == 1)
    {
        if (matriz[1][2] != ' ')
        {
            printf("Posição já ocupada, jogue novamente.\n");
            jogar(matriz, jogador);
            return;
        }
        matriz[1][2] = 'X';
    }
    else
    {
        if (matriz[1][2] != ' ')
        {
            printf("Posição já ocupada, jogue novamente.\n");
            jogar(matriz, jogador);
            return;
        }
        matriz[1][2] = 'O';
    }
}
else if (strcmp(jogada, "C1") == 0)
{
    if (jogador == 1)
    {
        if (matriz[2][0] != ' ')
        {
            printf("Posição já ocupada, jogue novamente.\n");
            jogar(matriz, jogador);
            return;
        }
        matriz[2][0] = 'X';
    }
    else
    {
        if (matriz[2][0] != ' ')
        {
            printf("Posição já ocupada, jogue novamente.\n");
            jogar(matriz, jogador);
            return;
        }
        matriz[2][0] = 'O';
    }
}
else if (strcmp(jogada, "C2") == 0)
{
    if (jogador == 1)
    {
        if (matriz[2][1] != ' ')
        {
            printf("Posição já ocupada, jogue novamente.\n");
            jogar(matriz, jogador);
            return;
        }
        matriz[2][1] = 'X';
    }
    else
    {
        if (matriz[2][1] != ' ')
        {
            printf("Posição já ocupada, jogue novamente.\n");
            jogar(matriz, jogador);
            return;
        }
        matriz[2][1] = 'O';
    }
}
else if (strcmp(jogada, "C3") == 0)
{
    if (jogador == 1)
    {
        if (matriz[2][2] != ' ')
        {
            printf("Posição já ocupada, jogue novamente.\n");
            jogar(matriz, jogador);
            return;
        }
        matriz[2][2] = 'X';
    }
    else
    {
        if (matriz[2][2] != ' ')
        {
            printf("Posição já ocupada, jogue novamente.\n");
            jogar(matriz, jogador);
            return;
        }
        matriz[2][2] = 'O';
    }
}
}

int winner(char matriz[3][3])
{
    if ((matriz[0][0] == 'X' && matriz[0][1] == 'X' && matriz[0][2] == 'X') 
    || (matriz[1][0] == 'X' && matriz[1][1] == 'X' && matriz[1][2] == 'X') 
    || (matriz[2][0] == 'X' && matriz[2][1] == 'X' && matriz[2][2] == 'X'))
    {
        printf("Jogador 1 venceu\n");
        return 1;
    }
    else if ((matriz[0][0] == 'X' && matriz[1][0] == 'X' && matriz[2][0] == 'X') 
    || (matriz[0][1] == 'X' && matriz[1][1] == 'X' && matriz[2][1] == 'X') 
    || (matriz[0][2] == 'X' && matriz[1][2] == 'X' && matriz[2][2] == 'X'))
    {
        printf("Jogador 1 venceu\n");
        return 1;
    }
    else if ((matriz[0][0] == 'X' && matriz[1][1] == 'X' && matriz[2][2] == 'X') 
    || (matriz[0][2] == 'X' && matriz[1][1] == 'X' && matriz[2][0] == 'X'))
    {
        printf("Jogador 1 venceu\n");
        return 1;
    }
    else
    {
        printf(" ");
    }

    if ((matriz[0][0] == 'O' && matriz[0][1] == 'O' && matriz[0][2] == 'O') 
    || (matriz[1][0] == 'O' && matriz[1][1] == 'O' && matriz[1][2] == 'O') 
    || (matriz[2][0] == 'O' && matriz[2][1] == 'O' && matriz[2][2] == 'O'))
    {
        printf("Jogador 2 venceu\n");
        return 1;
    }
    else if ((matriz[0][0] == 'O' && matriz[1][0] == 'O' && matriz[2][0] == 'O') 
    || (matriz[0][1] == 'O' && matriz[1][1] == 'O' && matriz[2][1] == 'O') 
    || (matriz[0][2] == 'O' && matriz[1][2] == 'O' && matriz[2][2] == 'O'))
    {
        printf("Jogador 2 venceu\n");
        return 1;
    }
    else if ((matriz[0][0] == 'O' && matriz[1][1] == 'O' && matriz[2][2] == 'O') 
    || (matriz[0][2] == 'O' && matriz[1][1] == 'O' && matriz[2][0] == 'O'))
    {
        printf("Jogador 2 venceu\n");
        return 1;
    }
    else
    {
        printf(" ");
    }

    return 0;
}

int main()
{
    char matriz[3][3];
    int jogador;
    int contador = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matriz[i][j] = ' ';
        }
    }
    mostraGame(matriz);
    do
    {
        jogador = 1;
        jogar(matriz, jogador);
        mostraGame(matriz);
        if (winner(matriz) == 1)
        {
            break;
        }
        contador++;
        if(contador == 9){
            printf("Empate!\n");
            break;
        }
        jogador = 2;
        jogar(matriz, jogador);
        mostraGame(matriz);
        if (winner(matriz) == 1)
        {
            break;
        }
        contador++;
    } while (contador < 9);
}