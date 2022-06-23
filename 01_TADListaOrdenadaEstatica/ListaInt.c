#include <stdlib.h>
#include "ListaInt.h"
#define MAX 20

struct lista {
    int no[MAX];// N� que vai ser limitado por MAX[20] posi��es(definido pelo programador).
    int fim; // O fim vai indicar qual � a pr�xima posi��o dispon�vel.
};

// _______________________________________________________________________________________________________________

/*
Opera��o: cria_lista

- Entrada: Sem entrada.
  Pr�-Condi��o: Sem pr�-condi��es.
- Processo: Aloca��o e cria��o da lista e de seu ponteiro.
- Sa�da: Ponteiro que referencia o local onde foi criada a lista(Podendo ser NULL quando mal-alocado).
- P�s-condi��o: Sem p�s-condi��o.
*/

Lista cria_lista() { // Alocar uma instancia da estrutura lista(malloc).

    Lista lst; // Criando um ponteiro de lista.
    lst = (Lista) malloc(sizeof (struct lista)); // Tamanho da Struct lista.

    if (lst != NULL) { // Verifica se houve aloca��o bem sucedida.
        lst -> fim = 0; // O fim = 0 indica que a primeira posicao livre do vetor.
    }
    return lst; // Retornamos o endere�o de ponteiro(lst).
}

// _______________________________________________________________________________________________________________

/*
Opera��o: lista_vazia;

- Entrada: Endere�o de uma lista.
- Pr�-Condi��o: Lista existir (Endere�o ser valido)
- Processo: Verifica se a lista est� vazia.
- Sa�da: -1 (Lista n�o existe), 0 (Lista n�o est� vazia), 1 (Lista vazia)
- P�s-condi��o: Sem p�s-condi��o.
*/
int lista_vazia(Lista lst) {
    if (lst == NULL) {
        return -1; // Ponteiro nao esta apontando pra lista valida/existente, entao declaramos como ERRO
    }
    if (lst->fim == 0)
        return 1; // A lista esta vazia
    else
        return 0; // Ha elementos dentro da lista, portanto nao esta vazia
}

// _______________________________________________________________________________________________________________

/*
Opera��o: lista_cheia

- Entrada: Endere�o de uma lista.
- Pr�-Condi��o: Lista existir (Endere�o ser valido)
- Processo: Verifica se a lista est� cheia.
- Sa�da: -1 (Lista n�o existe), 0 (Lista n�o est� cheia), 1 (Lista cheia)
- P�s-condi��o: Sem p�s-condi��o.
*/
int lista_cheia(Lista lst) {
    if (lst == NULL) {
        return -1; // Ponteiro nao esta apontando pra lista valida/existente, ent�o declaramos como ERRO
    }
    if ((lst -> fim == MAX)) { // Fim come�a com 0, entao ele eh como um contador de elementos
        return 1; // Quando fim == MAX significa que a lista esta cheia.
    } else {
        return 0; // A lista nao esta cheia.
    }

    // Pode se fazer tirando da linha 37 ate 40, apenas fazendo: return(lst->fim == MAX)
}

// _______________________________________________________________________________________________________________

/*
Opera��o: insere_elem;

- Entrada: Endere�o de uma lista e o elemento (inteiro) a ser inserido.
- Pr�-Condi��o: Lista existir (Endere�o ser valido) e elemento ser um inteiro.
- Processo: Insere (de forma ordenada) o elemento na lista fornecida.
- Sa�da: 0 (Lista n�o existe ou Lista cheia), 1 (Elemento inserido com sucesso).
- P�s-condi��o: O elemento foi inserido na lista de forma ordenada.
*/
int insere_elem(Lista lst, int elem){ //Insere o(s) elemento(s) de forma ordenada

    if (lst == NULL || lista_cheia(lst) == 1)
    return 0; // Nao tem como inserir porque lst eh NULL OU ela esta cheia (lista_cheia) == 1)

    // Trata lista vazia ou elemento >= ultimo da lista

    if (lista_vazia(lst) == 1 || elem <= lst->no[lst->fim-1]){ // Enquanto a lista estiver vazia e o elemento inserido for menor ou igual ao j� inserido antes
        lst->no[lst->fim] = elem; // Inser��o no final
    }else{
        int i, aux = 0;
        while(elem <= lst->no[aux]) //Percorrendo
            aux++;
        for(i=lst->fim;i>aux;i--) //Deslocando
            lst->no[i] = lst->no[i-1];
        lst->no[aux] = elem; //Incluindo o elemento na lista
    }
    lst->fim++; //Avan�a o fim
    return 1; //Sucesso
}

// _______________________________________________________________________________________________________________

/*
Opera��o: remove_elem;

- Entrada: Endere�o de uma lista e o elemento (inteiro) a ser removido.
-  Pr�-Condi��o: Lista existir (Endere�o ser valido) e elemento ser um inteiro.
- Processo: Remove o elemento na lista fornecida. Ap�s a remo��o, a lista mant�m-se ordenada.
- Sa�da: 0 (Lista n�o existe ou lista vazia, ou elemento n�o presente na lista), 1 (Elemento removido com sucesso).
- P�s-condi��o: O elemento foi removido na lista de forma ordenada.
*/

int remove_elem(Lista lst, int elem){
    if(lst == NULL || lista_vazia(lst) == 1 || elem > lst->no[0] || elem < lst->no[lst->fim-1]){
    //Quando elem > lst->no[0], significa que se o elemento que eu quero apagar � o 9 e minha lista � composta por L = {7,5}, o 9 n�o existe na minha lista.
    //Quando , elem < lst->no[lst->fim-1], significa que se o elemento que eu quero apagar � o 3 e minha lista � composta por L = {7,5}, o 3 n�o existe na minha lista.
        return 0; //Falha
        }
        int i, aux = 0;

    // Percorre at� ACHAR O ELEM OU N� MAIOR, ou final da lista

    while(aux < lst->fim && lst->no[aux] > elem)
    // Percorre com o aux enquanto o elemento que est� no auxiliar for maior que o elemento digitado
        aux++;

//       7        5       3
//      aux

    if(aux == lst->fim || lst->no[aux] < elem)
    // Elemento n�o vai existir quando o aux estiver no fim, e quando o elemento inserido for maior que o que est� no auxiliar
        return 0;

    // Deslocamento a esq. do sucessor at� o final da lista
    for(i=aux+1; i<lst->fim;i++){
        lst->no[i-1] = lst->no[i];
    }
        lst->fim--; // Decremento
        return 1; // Sucesso
}

// _______________________________________________________________________________________________________________

/*
Opera��o: apaga_lista
- Entrada: Endere�o do endere�o de uma lista
- Pr�-Condi��o: endere�o ser v�lido (primeiro endere�o �ponteiro de ponteiro�)
- Processo: liberar a instancia da lista e apagar o seu endere�o
- Sa�da: 1 (sucesso) ou 0 (falha)
- P�s-condi��o: instancia da lista liberada.
*/

int apaga_lista(Lista *end_lst){
    if(end_lst == NULL) //Se o ponteiro n�o aponta pra lista
        return 0;

    free(*end_lst); // Limpa a regi�o da lista (liberando a memoria para o computador)
    *end_lst = NULL; // apontar pra NULL para n�o conseguirem acessar aquela area novamente

    return 1;
}

// _______________________________________________________________________________________________________________

/*
Opera��o: esvazia_lista

- Entrada: Endere�o de uma lista
- Pr�-Condi��o: Lista existir (Endere�o ser valido)
- Processo: Colocar a lista no estado de vazia
- Sa�da: 1 (sucesso) ou 0 (falha)
- P�s-condi��o: a instancia da lista no estado de vazia
*/

int esvazia_lista(Lista lst){
     if(lst == NULL ){
        return 0;
     }
    lst->fim = 0;
    return 1;
}

// _______________________________________________________________________________________________________________

/*
Opera��o: get_elem_pos

- Entrada: Endere�o de uma lista, posi��o a obter o elemento e uma variavel para receber a informa��o da dita posi��o.
-  Pr�-Condi��o: Lista existir (Endere�o ser valido).
- Processo: Atrav�s da posi��o fornecida, busca-se na lista o elemento correspondente aquela posi��o e o retorna atraves da variavel fornecida.
- Sa�da: 1 (sucesso) ou 0 (falha)
- P�s-condi��o: A variavel recebe o valor do elemento presente na posi��o fornecida.

*/

int get_elem_pos(Lista lst, int pos, int *elem){
        // pos = Posi��o do elemento na lista (come�a com 1)
    if(lst == NULL || lista_vazia(lst) || pos <= 0 || pos > lst->fim)
        return 0; // FALHA
    *elem = lst->no[pos-1]; // subtra��o pq temos que passar o indice real da lista
    return 1; //Sucesso
}

// _______________________________________________________________________________________________________________

// Opera��es especiais:
// _______________________________________________________________________________________________________________


// _______________________________________________________________________________________________________________

/*
Opera��o: remove_negativos

- Entrada: Endere�o de uma lista
-  Pr�-Condi��o: Lista existir (Endere�o ser valido)
- Processo: Percorre toda a lista e remove(se existir) os numeros negativos presentes na mesma (mantendo sua ordena��o).
- Sa�da: 1 (sucesso) ou 0 (falha)
- P�s-condi��o: A lista agora n�o prov�m de elementos negativos.
*/

int remove_negativos(Lista x){ // Definimos a Lista como x para que n�o haja erro de interpreta��o do que estamos instanciando

    int i;

    if(x == NULL || lista_vazia(x) == 1)
    return 0;

    for(i = 0; i < x->fim; i++){
        if((int)x->no[i] < 0){
            remove_elem(x, x->no[i]);
            i--; //remove o elemento se for negativo e verifica o pr�ximo
        }
    }

    return 1;

}

// _______________________________________________________________________________________________________________

/*
Opera��o: remove_pares


- Entrada: Endere�o de uma lista
-  Pr�-Condi��o: Lista existir (Endere�o ser valido)
- Processo: Percorre toda a lista e remove(se existir) os numeros pares presentes na mesma (mantendo sua ordena��o).
- Sa�da: 1 (sucesso) ou 0 (falha)
- P�s-condi��o: A lista agora n�o prov�m de elementos pares.*/

int remove_pares(Lista x){

    int i;

    if(x == NULL || lista_vazia(x) == 1)
    return 0;

    for(i = 0; i < x->fim; i++){
        if((int)x->no[i] % 2 == 0){
            remove_elem(x, x->no[i]);
            i--; //remove o elemento se for par e verifica o pr�ximo
        }
    }

    return 1;

}
// _______________________________________________________________________________________________________________


/*
Opera��o: tamanho_lista
- Entrada: Endere�o de uma lista e uma variavel para receber o tamanho da lista.
-  Pr�-Condi��o: Lista existir (Endere�o ser valido).
- Processo: Percorre toda a lista e contabiliza o tamanho da mesma.
- Sa�da: 1 (sucesso) ou 0 (falha)
- P�s-condi��o: A lista foi contabilizada e seu tamanho foi atribuido para a variavel vinda de argumento.*/

int tamanho_lista(Lista x, int *tamanho){

    if(x == NULL)
    return 0;

    *tamanho = x->fim; // Recebe o ponteiro tamanho do tipo float e vai retornar o tamanho da lista(qtde de elem)

    return 1;

}

// _______________________________________________________________________________________________________________

/*
Opera��o: intercala_listas
- Entrada: Endere�o de duas listas a serem intercaladas.
- Pr�-Condi��o: Listas existirem (Endere�o ser valido).
- Processo: Recebe duas listas ordenadas e retorna uma terceira, formada pelos elementos das duas listas intercalados, mantendo sua ordena��o. (Sem altera��o nas duas listas).
- Sa�da: NULL(Caso alguma das listas fornecidas n�o existe) ou ponteiro que referencia o local onde foi criada a terceira lista.
- P�s-condi��o: Sem p�s-condi��o.
*/

Lista intercala_listas(Lista l1, Lista l2){

    if(l1 == NULL || l2 == NULL)
    return NULL; //Uma das duas listas n�o existe, logo, n�o podemos seguir

    int vetor[MAX*2];

    int tam1,tam2,tamt;
    tamanho_lista(l1,&tam1);
    tamanho_lista(l2,&tam2);
    tamt = tam1+tam2;

    int i, j;

    // Preenchendo o "vetor" com todos os elementos das listas
    for(i=0; i< tam1;i++){
       vetor[i] = l1->no[i];
    }
    int temp = 0;

    for(j = tam1; j < tamt ;j++){
        vetor[j] = l2->no[temp];
        temp++;
    }

    int aux = 0;


    for(i=0;i<=tamt-1;i++){ //Percorrendo todos os indices do vetor e ordenando-os em ordem decrescente
        for(j=i; j<=tamt-1;j++){
            if(vetor[i] < vetor[j]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }

// Como a aloca��o da lista 3 � o dobro da comum[20], teremos que faze-los aqui:

 Lista l3; // Criando um ponteiro de lista.
    l3 = (Lista) malloc(2* sizeof (struct lista)); // Tamanho da Struct lista.

    if (l3 == NULL) { // Verifica se houve aloca��o bem sucedida.
         return NULL;
    }

   l3 -> fim = 0; // O fim = 0 indica que a primeira posicao livre do vetor.

   for(i=0;i<tamt;i++){
    insere_elem(l3,vetor[i]);
   }

   return l3;
}

// _______________________________________________________________________________________________________________

/*
Opera��o: libera
- Entrada: Endere�o de uma lista
- Pr�-Condi��o: Lista existir (Endere�o ser valido)
- Processo: Retira a aloca��o (Libera) de uma determinada lista.
- Sa�da: Sem saida (VOID).
- P�s-condi��o: A lista foi �liberada� da memoria.
*/

void libera(Lista x){

    if(x != NULL){
        free(x);
        x = NULL;
    }
}
// _______________________________________________________________________________________________________________
