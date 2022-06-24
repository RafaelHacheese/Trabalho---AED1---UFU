#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct strLista *Lista;

Lista cria_lista();
char getPos(Lista lst, int pos);
int lista_vazia(Lista lst);
int lista_cheia(Lista lst);
int insere_ord(Lista lst, char str[]);
int remove_elem(Lista lst, char str[]);
int tamanho_lista(Lista lst);
int esvazia_lista(Lista lst);
int remove_todas(Lista lst, char elem[]);
Lista intercala_listas(Lista ,Lista );
#endif // LISTA_H_INCLUDED
