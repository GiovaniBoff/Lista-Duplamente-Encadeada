#include <stdio.h>
#include <stdlib.h>


typedef struct nodo Nodo;
typedef struct dados Dados;

struct dados
{
    int numero;
    char letra;
};

struct nodo
{
    Dados dados;
    Nodo *anterior;
    Nodo *proximo;
};

void menu(){
    printf("=================================\n");
    printf("1 - Criar lista\n");
    printf("2 - Remover lista\n");
    printf("3 - Adicionar no inicio da lista\n");
    printf("4 - Adicionar no fim da lista\n");
    printf("5 - Remover o primeiro da lista\n");
    printf("6 - Remover o ultimo da lista\n");
    printf("7 - Imprimir lista do Inicio\n");
    printf("8 - Imprimir lista do fim\n");
    printf("=================================\n");
}
void cria_lista(Nodo **pp_ini, Nodo **pp_fim)
{
    printf("Criando lista.....\n");
    *pp_ini = NULL;
    *pp_fim = NULL;
    printf("Lista criada com sucesso...\n");
}

void destroi_lista(Nodo **pp_ini,Nodo **pp_fim){
    Nodo *p_ini;
    p_ini = *pp_ini;

    Nodo *nodo_aux;
    nodo_aux = p_ini;
    while (nodo_aux) {
        p_ini = p_ini->proximo;
        free(nodo_aux);
        nodo_aux = p_ini;
  }
  //Precisa colocar NULL em *pp_ini:
  *pp_ini = NULL;
  //quando sair do while, *pp_ini serah NULL, mas *pp_fim nao eh NULL,
  //portanto, tem que colocar NULL em *pp_fim.
  *pp_fim = NULL;

}

void imprime_lista_inicio(Nodo *p_ini)
{
    if (p_ini == NULL)
    {
        printf("Lista vazia \n");
        return;
    }

    while (p_ini)
    {
        printf("%c , %d \n", p_ini->dados.letra, p_ini->dados.numero);
        p_ini = p_ini->proximo;
    }
}
void imprime_lista_fim(Nodo *p_fim)
{
    if (p_fim == NULL)
    {
        printf("Lista vazia \n");
        return;
    }
    while (p_fim)
    {
        printf("%c , %d \n", p_fim->dados.letra, p_fim->dados.numero);
        p_fim = p_fim->anterior;
    }
}

void insere_inicio(Nodo **pp_ini, Nodo **pp_fim, Dados d)
{
    Nodo *nodo_aux, *p_ini, *p_fim;
    p_ini = *pp_ini;
    p_fim = *pp_fim;
    nodo_aux = (Nodo *)malloc(sizeof(Nodo));
    if (nodo_aux)
    {
        nodo_aux->dados = d;
        //verifica se primeiro nodo da lista esta vazio.
        if (p_ini == NULL)
        {
            nodo_aux->anterior = NULL; //Seta anterior nulo.
            nodo_aux->proximo = p_fim; //Aponta para nodo fim.
            p_ini = nodo_aux;          //Implementa nodo_aux no nodo inicial.
            p_fim = nodo_aux;          //Implementa nodo_aux no nodo fim, pois existe somente um nodo na lista.
        }
        else
        {
            nodo_aux->proximo = p_ini;  //nodo_aux->proximo aponta para o inicio da lista.
            p_ini->anterior = nodo_aux; //p_ini-> anterior aponta para nodo_aux.
            nodo_aux->anterior = NULL;  //nodo_aux->anterior recebe null, pois se tornara o primeiro da lista.
            p_ini = nodo_aux;           //Atualiza o inicio da lista.
        }
        //Atualiza ponteiros
        *pp_ini = p_ini;
        *pp_fim = p_fim;
    }
}

void insere_fim(Nodo **pp_ini, Nodo **pp_fim, Dados d)
{
    Nodo *nodo_aux, *p_ini, *p_fim;
    p_ini = *pp_ini;
    p_fim = *pp_fim;
    nodo_aux = (Nodo *)malloc(sizeof(Nodo));
    if (nodo_aux)
    {
        nodo_aux->dados = d;
        //verifica se primeiro nodo da lista esta vazio.
        if (p_ini == NULL)
        {
            nodo_aux->anterior = NULL; //Seta anterior nulo.
            nodo_aux->proximo = p_fim; //Aponta para nodo fim.
            p_ini = nodo_aux;          //Implementa nodo_aux no nodo inicial.
            p_fim = nodo_aux;          //Implementa nodo_aux no nodo fim, pois existe somente um nodo na lista.
        }
        else
        {
            nodo_aux->anterior = p_fim; //nodo_aux->anterior aponta para o ultimo da lista.
            p_fim->proximo = nodo_aux;  //p_fim->proximo aponta pra nodo_aux.
            nodo_aux->proximo = NULL;   //nodo_aux->proximo recebe null, pois sera o ultimo da lista.
            p_fim = nodo_aux;           //Atualiza o fim da lista
        }
        //Atualiza ponteiros
        *pp_ini = p_ini;
        *pp_fim = p_fim;
    }
}

void remove_primeiro(Nodo **pp_ini, Nodo **pp_fim)
{
    if ((*pp_ini != NULL) && (*pp_fim != NULL))
    {
        //Verifica se tem apenas um item, e entao a lista ficara fazia
        if (*pp_ini == *pp_fim)
        {
            *pp_ini = NULL;
            *pp_fim = NULL;
        }
        else
        {
            (*pp_ini)->proximo->anterior = NULL;
            *pp_ini = (*pp_ini)->proximo;
        }
    }
}
void remove_ultimo(Nodo **pp_ini,Nodo **pp_fim)
{
    if ((*pp_ini != NULL) && (*pp_fim != NULL))
    {
        //Verifica se tem apenas um item, e entao a lista ficara fazia
        if (*pp_ini == *pp_fim)
        {
            *pp_ini = NULL;
            *pp_fim = NULL;
        }
        else
        {
            (*pp_fim)->anterior->proximo = NULL;
            *pp_fim = (*pp_fim)->anterior;
        }
    }
}
int main(int argc, char const *argv[])
{
    int op;
    Nodo *nodo_ini, *nodo_fim;
    Dados d;
    int n;
    char l;
    menu();
    while(op !=9){
        printf("Escolha uma opcao: "); scanf("%d",&op);
        switch (op)
        {
            case 1:
                printf("\e[H\e[2J");//Limpa tela
                printf("Opçao 1 - Criar lista\n");
                cria_lista(&nodo_ini,&nodo_fim);
                menu();
                
                break;
            case 2:
                printf("\e[H\e[2J");//Limpa tela
                printf("Opcao 2 - Remover lista\n");
                destroi_lista(&nodo_ini,&nodo_fim);
                printf("Lista removida !!\n");
                menu();
                break;
            case 3:
                
                printf("\e[H\e[2J");//Limpa tela
                printf("Opcao 3 - Adicionar no inicio da lista\n");
                printf("Informe um numero: ");scanf("%d",&n);
                getchar();
                printf("Informe uma letra: ");scanf("%c",&l);
                d.letra = l; d.numero = n;
                insere_inicio(&nodo_ini,&nodo_fim,d);
                menu();
                break;
            case 4:
                printf("\e[H\e[2J");//Limpa tela
                printf("Opcao 4 - Adicionar no fim da lista\n");
                printf("Informe um numero: ");scanf("%d",&n);
                getchar();
                printf("Informe uma letra: ");scanf("%c",&l);
                d.letra = l; d.numero = n;
                insere_inicio(&nodo_ini,&nodo_fim,d);
                menu();
                break;
            case 5:
                printf("\e[H\e[2J");//Limpa tela
                printf("Opcao 5 - Remover primeiro da lista \n");
                remove_primeiro(&nodo_ini,&nodo_fim);
                menu();
                break;
            case 6:
                printf("\e[H\e[2J");//Limpa tela
                printf("Opcao 6 - Remover ultimo da lista \n");
                remove_ultimo(&nodo_ini,&nodo_fim);
                menu();
                break;
            case 7:
                printf("\e[H\e[2J");//Limpa tela
                printf("Opcao 7 - Imprimir lista do Inicio \n");
                imprime_lista_inicio(nodo_ini);
                menu();
                break;
            case 8:
                printf("\e[H\e[2J");//Limpa tela
                printf("Opcao 8 - Imprimir lista do fim \n");
                imprime_lista_fim(nodo_fim);
                menu();
                break;
            default:
                printf("\e[H\e[2J");//Limpa tela
                printf("Opcao incorreta!\n");
                break;
        }
    }
    
    return 0;
}
