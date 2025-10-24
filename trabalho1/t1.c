#include <stdio.h>
#include "t1.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
DataQuebrada quebraData(char data[]);

int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ // função utilizada para testes
    int i, fat = 1;

    for (i = x; i > 1; i--)
        fat = fat * i;

    return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{

    DataQuebrada dq;
    dq.valido = 1;
    int i = 0;
    int contDia = 0, conteMes = 0, contAno = 0;
    char matriz[3][5];

    // dia
    while (data[i] != '/' && data[i] != '\0' && contDia < 2)
    {
        matriz[0][contDia] = data[i];
        i++;
        contDia++;
    }
    matriz[0][contDia] = '\0';
    i++;
    // mes
    while (data[i] != '/' && data[i] != '\0' && conteMes < 2)
    {

        matriz[1][conteMes] = data[i];
        i++;
        conteMes++;
    }
    matriz[1][conteMes] = '\0';
    i++;
    // ano
    while (data[i] != '\0' && contAno < 4)
    {
        matriz[2][contAno] = data[i];
        i++;
        contAno++;
    }
    matriz[2][contAno] = '\0';
    int d = 0;
    d = atoi(matriz[0]);
    int m = 0;
    m = atoi(matriz[1]);
    int a = 0;
    a = atoi(matriz[2]);

    if (contDia < 1 || contDia > 2 || d < 1 || d > 31)
    {
        dq.valido = 0;
    }

    if (conteMes < 1 || conteMes > 2 || m < 1 || m > 12)
    {
        dq.valido = 0;
    }

    switch (m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (d < 1 || d > 31)
        {
            dq.valido = 0;
        }
    case 2:
        if (a % 4 == 0 && (a % 100 != 0 || a % 400 == 0))
        {
            if (d < 1 || d > 29)
                dq.valido = 0;
        }
        else
        {
            if (d < 1 || d > 28)
                dq.valido = 0;
        }
    case 4:
    case 6:
    case 9:
    case 11:
        if (d < 1 || d > 30)
        {
            dq.valido = 0;
        }
    }

    return dq.valido;
}

// /*
//  Q2 = diferença entre duas datas
//  @objetivo
//     Calcular a diferença em anos, meses e dias entre duas datas
//  @entrada
//     uma string datainicial, uma string datafinal.
//  @saida
//     Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
//     1 -> cálculo de diferença realizado com sucesso
//     2 -> datainicial inválida
//     3 -> datafinal inválida
//     4 -> datainicial > datafinal
//     Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
//  */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    // calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;
    dma.retorno = 1;

    if (q1(datainicial) == 0)
    {
        dma.retorno = 2;
        return dma;
    }

    if (q1(datafinal) == 0)
    {
        dma.retorno = 3;
        return dma;
    }
    DataQuebrada dqI = quebraData(datainicial);
    DataQuebrada dqF = quebraData(datafinal);
    if (dqI.iAno > dqF.iAno)
    {
        dma.retorno = 4;
        return dma;
    }
    return dma;
}
// /*
//  Q3 = encontrar caracter em texto
//  @objetivo
//     Pesquisar quantas vezes um determinado caracter ocorre em um texto
//  @entrada
//     uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
//         Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
//  @saida
//     Um número n >= 0.
//  */
int q3(char texto[], char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0, size = 0;
    size = strlen(texto);
    if (isCaseSensitive)
    {
        for (int i = 0; i < size; i++)
        {
            if (texto[i] == c)
            {
                qtdOcorrencias++;
            }
        }
    }
    else
    {
        if (isCaseSensitive == 0)
        {
            char testo[size];
            char ch = c;
            for (int i = 0; i < size; i++)
            {
                testo[i] = texto[i];
            }
            if (ch >= 'A' && ch <= 'Z')
            {
                ch = ch + 32;
            }
            for (int i = 0; i < size; i++)
            {
                if (testo[i] >= 'A' && testo[i] <= 'Z')
                    testo[i] = testo[i] + 32;
            }
            for (int i = 0; i < size; i++)
            {
                if (testo[i] == ch)
                    qtdOcorrencias++;
            }
        }
    }
    return qtdOcorrencias;
}

// /*
//  Q4 = encontrar palavra em texto
//  @objetivo
//     Pesquisar todas as ocorrências de uma palavra em um texto
//  @entrada
//     uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
//  @saida
//     Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
//     O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
//         posicoes[0] = 13;
//         posicoes[1] = 16;
//         Observe que o índice da posição no texto deve começar ser contado a partir de 1.
//         O retorno da função, n, nesse caso seria 1;

//  */
int q4(char *frase, char *busca, int pos[30])
{

    int qtdOcorrencias = 0;
    int sizebusca = strlen(busca);
    int sizetexto = strlen(frase);
    for (int i = 0; i < sizetexto; i++)
    {
        if (frase[i] == '\n')
            frase[i] = '\0';
    }

    for (int i = 0; i < sizetexto; i++)
    {
        if (frase[i] == '\n')
            frase = '\0';
    }
    int achou = 0;
    int k = 0;
    for (int i = 0; frase[i] != '\0'; i++)
    {

        if (frase[i] == busca[0])
        {
            achou = 1;

            for (int j = 1; busca[j] != '\0'; j++)
            {
                if (busca[j] == frase[i + j])
                {
                    achou++;
                }
                else
                    break;
            }
            if (achou == sizebusca)
            {
                qtdOcorrencias++;
                pos[k] = i + 1;
                k++;
                pos[k] = i + sizebusca;
                k++;
                i++;
            }
        }
    }
    return qtdOcorrencias;
}
// /*
//  Q5 = inverte número
//  @objetivo
//     Inverter número inteiro
//  @entrada
//     uma int num.
//  @saida
//     Número invertido
//  */

int q5(int numero)
{
    int num = 0, BEMVINDOAIZENAOMUNDOINVERTIDO = 0;
    do
    {
        BEMVINDOAIZENAOMUNDOINVERTIDO = numero % 10;
        num = num * 10 + BEMVINDOAIZENAOMUNDOINVERTIDO;
        numero /= 10;
    } while (numero != 0);
    return num;
}

// /*
//  Q6 = ocorrência de um número em outro
//  @objetivo
//     Verificar quantidade de vezes da ocorrência de um número em outro
//  @entrada
//     Um número base (numerobase) e um número de busca (numerobusca).
//  @saida
//     Quantidade de vezes que número de busca ocorre em número base
//  */

int q6(int numerobase, int numerobusca)
{

    int pow=1;
    int copyBusca = numerobusca;
    int copyBase = numerobase;
    int qtdOcorrencias = 0;

    do{
        pow*=10;
        copyBusca/=10;
    }while(copyBusca!=0);

    while(copyBase!=0){
        if(copyBase%pow == numerobusca){
            qtdOcorrencias++;   
            copyBase/=pow;
        }else{
        copyBase/=10;
    }
}
    return qtdOcorrencias;
}

// /*
//  Q7 = jogo busca palavras
//  @objetivo
//     Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
//  @entrada
//     Uma matriz de caracteres e uma string de busca (palavra).
//  @saida
//     1 se achou 0 se não achou
//  */

//  int q7(char matriz[8][10], char palavra[5])
//  {
//      int achou;
//      return achou;
//  }

DataQuebrada quebraData(char data[])
{
    DataQuebrada dq;
    char sDia[3];
    char sMes[3];
    char sAno[5];
    int i;

    for (i = 0; data[i] != '/'; i++)
    {
        sDia[i] = data[i];
    }
    if (i == 1 || i == 2)
    {                   // testa se tem 1 ou dois digitos
        sDia[i] = '\0'; // coloca o barra zero no final
    }
    else
    {
        dq.valido = 0;
        return dq;
    }

    int j = i + 1; // anda 1 cada para pular a barra
    i = 0;

    for (; data[j] != '/'; j++)
    {
        sMes[i] = data[j];
        i++;
    }

    if (i == 1 || i == 2)
    {                   // testa se tem 1 ou dois digitos
        sMes[i] = '\0'; // coloca o barra zero no final
    }
    else
    {
        dq.valido = 0;
        return dq;
    }

    j = j + 1; // anda 1 cada para pular a barra
    i = 0;

    for (; data[j] != '\0'; j++)
    {
        sAno[i] = data[j];
        i++;
    }

    if (i == 2 || i == 4)
    {                   // testa se tem 2 ou 4 digitos
        sAno[i] = '\0'; // coloca o barra zero no final
    }
    else
    {
        dq.valido = 0;
        return dq;
    }

    dq.iDia = atoi(sDia);
    dq.iMes = atoi(sMes);
    dq.iAno = atoi(sAno);

    dq.valido = 1;

    return dq;
}
