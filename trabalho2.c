#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10

#include "trabalho2.h"

No *lista;
item vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/

/*  int retorno = 0;
    // a posicao pode já existir estrutura auxiliar
    retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    // se posição é um valor válido {entre 1 e 10}
    retorno = POSICAO_INVALIDA;
    // o tamanho ser muito grande
    retorno = SEM_ESPACO_DE_MEMORIA;
    // o tamanho nao pode ser menor que 1
    retorno = TAMANHO_INVALIDO;
    // deu tudo certo, crie
    retorno = SUCESSO;*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    posicao -= 1;
    int retorno = 0;
    if (tamanho >= 1)
    {
        if (tamanho <= 10)
        {
            if (posicao >= 0 && posicao < 10)
            {
                    if (vetorPrincipal[posicao].ptx == NULL)
                    {
                        int *new = malloc(tamanho * sizeof(int));
                        vetorPrincipal[posicao].ptx = new;
                        for (int i = 0; i < tamanho; i++)
                        {
                            vetorPrincipal[posicao].ptx[i] = -999;
                        }
                        vetorPrincipal[posicao].tamanho = tamanho;
                        vetorPrincipal[posicao].qtd = 0;
                        retorno = SUCESSO;
                    }
                    else
                    {
                        return JA_TEM_ESTRUTURA_AUXILIAR;
                    }
            }
            else
            {
                retorno = POSICAO_INVALIDA;
            }
        }
        else
        {
            retorno = SEM_ESPACO_DE_MEMORIA;
        }
    }
    else
    {
        retorno = TAMANHO_INVALIDO;
    }
    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int cont = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;
    posicao -= 1;
    if (posicao < 0 || posicao >= 10)
        retorno = POSICAO_INVALIDA;
    else
    {
        // testar se existe a estrutura auxiliar
        if (vetorPrincipal[posicao].ptx != NULL)
        {
            if (vetorPrincipal[posicao].qtd < vetorPrincipal[posicao].tamanho)
            {
                // insere
                vetorPrincipal[posicao].ptx[vetorPrincipal[posicao].qtd] = valor;
                vetorPrincipal[posicao].qtd++;
                retorno = SUCESSO;
            }
            else
            {
                retorno = SEM_ESPACO;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int cont = 0;
    int retorno = SUCESSO;
    posicao -= 1;
    if (posicao >= 0 && posicao < 10)
    {
        if (vetorPrincipal[posicao].ptx != NULL)
        {
            if (vetorPrincipal[posicao].qtd > 0)
            {
                vetorPrincipal[posicao].qtd--;
                vetorPrincipal[posicao].ptx[vetorPrincipal[posicao].qtd] = -999;
                retorno = SUCESSO;
            }
            else
            {
                retorno = ESTRUTURA_AUXILIAR_VAZIA;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }
    else
    {
        retorno = POSICAO_INVALIDA;
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    posicao -= 1;
    int cont = 0;
    int cont2 = 0;
    int retorno = SUCESSO;
    if (posicao >= 0 && posicao < 10)
    {
        if (vetorPrincipal[posicao].ptx != NULL)
        {
            if (vetorPrincipal[posicao].qtd == 0)
            {
                cont++;
                if (cont == vetorPrincipal[posicao].tamanho)
                    return ESTRUTURA_AUXILIAR_VAZIA;
            }
            for (int i = 0; i < vetorPrincipal[posicao].tamanho; i++)
            {
                if (vetorPrincipal[posicao].ptx[i] != valor)
                {
                    cont2++;
                    if (cont2 == vetorPrincipal[posicao].tamanho)
                        retorno = NUMERO_INEXISTENTE;
                }
                else
                {
                    vetorPrincipal[posicao].ptx[i] = -999;
                    vetorPrincipal[posicao].qtd--;
                    retorno = SUCESSO;
                }
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }
    else
    {
        retorno = POSICAO_INVALIDA;
    }

    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    posicao -= 1;
    int cont = 0;
    int retorno = 0;
    if (posicao >= 0 && posicao < 10)
    {
        if (vetorPrincipal[posicao].ptx != NULL)
        {
            if (vetorPrincipal[posicao].qtd != 0)
            {
                for (int i = 0; i < vetorPrincipal[posicao].tamanho; i++)
                {
                    if (vetorPrincipal[posicao].ptx[i] != -999)
                    {
                        vetorAux[i] = vetorPrincipal[posicao].ptx[i];
                    }
                }
                return SUCESSO;
            }
            return ESTRUTURA_AUXILIAR_VAZIA;
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }
    else
    {
        retorno = POSICAO_INVALIDA;
    }
    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int retorno = 0;
    posicao -= 1;
    if (posicao >= 0 && posicao < 10)
    {
        if (vetorPrincipal[posicao].ptx != NULL)
        {
            for (int i = 0; i < vetorPrincipal[posicao].qtd; i++)
            {
                if (vetorPrincipal[posicao].ptx[i] != -999)
                    vetorAux[i] = vetorPrincipal[posicao].ptx[i];
            }

            for (int j = 0; j < vetorPrincipal[posicao].tamanho; j++)
            {
                if (vetorAux[j] > vetorAux[j + 1])
                {
                    int temporario = vetorAux[j];
                    vetorAux[j] = vetorAux[j + 1];
                    vetorAux[j + 1] = temporario;
                }
            }

            return SUCESSO;
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }
    else
    {
        retorno = POSICAO_INVALIDA;
    }

    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int cont = 0, retorno = 0;

    for (int i = 0; i < TAM; i++)
    {
        if (vetorPrincipal[i].ptx != NULL)
        {
            cont += vetorPrincipal[i].qtd;
        }
    }
    if (cont == 0)
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

    int k = 0;
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < vetorPrincipal[i].tamanho; j++)
        {
            if(vetorPrincipal[i].ptx[j] != -999){
            vetorAux[k] = vetorPrincipal[i].ptx[j];
            k++;
            }
            retorno = SUCESSO;
        }
    }
    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int cont = 0;
    int retorno = 0;
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < vetorPrincipal[i].tamanho; j++)
        {
            if (vetorPrincipal[i].ptx[j] == -999)
            {
                cont++;
            }
        }
    }
    for (int i = 0; i < TAM; i++)
    {
        if (vetorPrincipal[i].qtd == 0)
        {
            retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
        }
    }
    int k = 0;
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < vetorPrincipal[i].tamanho; j++)
        {
            if (vetorPrincipal[i].ptx[j] != -999)
            {
                vetorAux[k] = vetorPrincipal[i].ptx[j];
                k++;
            }
            retorno = SUCESSO;
        }
    }

    for (int i = 0; i < k; i = i + 1)
    {
        for (int j = k - 1; j > i; j = j - 1)
        {
            if (vetorAux[j] < vetorAux[j - 1])
            {
                int temp = vetorAux[j];
                vetorAux[j] = vetorAux[j - 1];
                vetorAux[j - 1] = temp;
            }
        }
    }

    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{

    int tamanho = vetorPrincipal[posicao].tamanho;
    novoTamanho+=tamanho;
    int retorno = 0;
    posicao-=1;
    if (posicao >= 0 && posicao < 10)
    {
        if (novoTamanho >= 1)
        {
            if (novoTamanho <= 10)
            {
                if (vetorPrincipal[posicao].ptx != NULL)
                {
                    
                    int *new = realloc(vetorPrincipal[posicao].ptx, novoTamanho * sizeof(int));
                    if (new != NULL)
                    {
                        vetorPrincipal[posicao].ptx = new;
                        vetorPrincipal[posicao].tamanho = novoTamanho;
                        printf("TAMANHO NOVO: %d\n", vetorPrincipal[posicao].tamanho);
                        retorno = SUCESSO;
                    }
                    else
                    {
                        retorno = SEM_ESPACO_DE_MEMORIA;
                    }
                }
                else
                {
                    retorno = SEM_ESTRUTURA_AUXILIAR;
                }
            }
            else
            {
                retorno = SEM_ESPACO_DE_MEMORIA;
            }
        }
        else
        {
            retorno = NOVO_TAMANHO_INVALIDO;
        }
    }
    else
    {
        retorno = POSICAO_INVALIDA;
    }
    return retorno;
}
/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{

    int retorno = 0;

    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{

    return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa

*/

void inicializar()
{
    lista = NULL;
    lista = malloc(sizeof(No));
    lista->prox = NULL;
    lista->conteudo = 0;
    for (int i = 0; i < TAM; i++)
    {

        vetorPrincipal[i].ptx = NULL;
        vetorPrincipal[i].qtd = 0;
        vetorPrincipal[i].tamanho = 0;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
}
