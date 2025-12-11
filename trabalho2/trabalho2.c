#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10

#include "trabalho2.h"
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
            for (int i = 0; i < vetorPrincipal[posicao].qtd; i++)
            {
                if (vetorPrincipal[posicao].ptx[i] == valor)
                {
                    for (int j = i; j < vetorPrincipal[posicao].qtd - 1; j++)
                    {
                        vetorPrincipal[posicao].ptx[j] = vetorPrincipal[posicao].ptx[j + 1];
                    }
                    vetorPrincipal[posicao].qtd--;
                    retorno = SUCESSO;
                    break;
                }
                else
                {
                    retorno = NUMERO_INEXISTENTE;
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
    int retorno = 0, k = 0;
    if (posicao >= 0 && posicao < 10)
    {
        if (vetorPrincipal[posicao].ptx != NULL)
        {
            if (vetorPrincipal[posicao].qtd != 0)
            {
                for (int i = 0; i < vetorPrincipal[posicao].qtd; i++)
                {
                    if (vetorPrincipal[posicao].ptx[i] != -999)
                    {
                        vetorAux[k] = vetorPrincipal[posicao].ptx[i];
                        k++;
                    }
                }
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
                for (int j = 0; j < vetorPrincipal[posicao].qtd - i - 1; j++)
                {
                    if (vetorAux[j] > vetorAux[j + 1])
                    {
                        int temporario = vetorAux[j];
                        vetorAux[j] = vetorAux[j + 1];
                        vetorAux[j + 1] = temporario;
                    }
                }
            }

            retorno = SUCESSO;
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
        for (int j = 0; j < vetorPrincipal[i].qtd; j++)
        {
            if (vetorPrincipal[i].ptx != NULL)
            {
                vetorAux[k] = vetorPrincipal[i].ptx[j];
                k++;
                retorno = SUCESSO;
            }
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
    int cont = 1;
    int retorno = 0;
    int k = 0;
    for (int i = 0; i < TAM; i++)
    {
        if (vetorPrincipal[i].ptx != NULL)
        {
            if (vetorPrincipal[i].qtd > 0)
            {
                cont = 0;
                break;
            }
        }
    }
    if (cont)
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < vetorPrincipal[i].qtd; j++)
        {
            vetorAux[k] = vetorPrincipal[i].ptx[j];
            k++;
            retorno = SUCESSO;
        }
    }
    for (int i = 0; i < k - 1; i++)
    {
        for (int j = 0; j < k - i - 1; j++)
        {
            if (vetorAux[j] > vetorAux[j + 1])
            {
                int temporario = vetorAux[j];
                vetorAux[j] = vetorAux[j + 1];
                vetorAux[j + 1] = temporario;
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

    posicao -= 1;
    int cont = 0;
    int tamanho = vetorPrincipal[posicao].tamanho;
    novoTamanho += tamanho;
    int retorno = 0;
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
                        for (int u = 0; u < vetorPrincipal[posicao].tamanho; u++)
                        {
                            cont = 0;
                            if (vetorPrincipal[posicao].ptx[u] != -999)
                            {
                                cont++;
                            }
                        }
                        vetorPrincipal[posicao].qtd = cont;

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
    posicao -= 1;
    if (posicao >= 0 && posicao < 10)
    {
        if (vetorPrincipal[posicao].ptx != NULL)
        {
            if (vetorPrincipal[posicao].qtd > 0)
            {
                retorno = vetorPrincipal[posicao].qtd;
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
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
    cabeca *new = malloc(sizeof(cabeca));
    new->head = NULL;
    No *valor = NULL;
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < vetorPrincipal[i].qtd; j++)
        {
            valor = malloc(sizeof(No));
            valor->conteudo = vetorPrincipal[i].ptx[j];
            valor->prox = NULL;
            if (new->head == NULL)
            {
                new->head = valor;
            }
            else
            {
                No *podeSerRabo = new->head;
                while (podeSerRabo->prox != NULL)
                {
                    podeSerRabo = podeSerRabo->prox;
                }
                podeSerRabo->prox = valor;
            }
        }
    }

    return new->head;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    int i = 0;
    while (inicio != NULL)
    {
        vetorAux[i] = inicio->conteudo;
        inicio = inicio->prox;
        i++;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
    No *apagar = *inicio;
    No *recu = NULL;
    while (apagar != NULL)
    {
        recu = apagar->prox;
        free(apagar);
        apagar = recu;
    }
    *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa

*/

void inicializar()
{
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
    for (int i = 0; i < TAM; i++)
    {

        free(vetorPrincipal[i].ptx);
    }
}
