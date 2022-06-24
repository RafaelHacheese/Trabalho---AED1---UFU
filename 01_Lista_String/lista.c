#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#define MAX1 15
#define MAX2 20

struct strLista{
	char arrStr[MAX1][MAX2];
	int fim; // indica qnts string tenho na Listaa

};

Lista cria_lista(){
	Lista lst = (Lista)malloc(sizeof(Lista));
	if(lst != NULL)
		lst->fim = 0;

	return lst;
}

int lista_vazia(Lista lst){
	if(lst == NULL)
        return -1;
    if(lst->fim == 0)
		return 1;
	else
		return 0;
}

int lista_cheia(Lista lst){
	if(lst->fim == MAX1)
		return -1;
	else
		return 0;
}


int insere_ord(Lista lst, char string[]){
	if(lst == NULL || lista_cheia(lst))
		return 0;

	// se Listaa vazia ou se for na ultima posicao
	if( (lista_vazia(lst)) || (strcmp(string, lst->arrStr[lst->fim - 1]) <= 0) ){
		strcpy(lst->arrStr[ lst->fim ], string);

	}else{
		int pos = 0;
		while( ((pos < lst->fim) && (strcmp(string, lst->arrStr[pos]) < 0))
	      ||   ((pos < lst->fim) && (strcmp(string, lst->arrStr[pos]) == 0) ))
			pos ++;

		for(int i = lst->fim; i > pos; i--){
			strcpy(lst->arrStr[i], lst->arrStr[i-1]);
		}

		// posicao pos esta livre
        strcpy(lst->arrStr[pos], string);

	}

	lst->fim ++;
	return 1;
}

int remove_elem(Lista lst, char arrStr[]){
	if(lst == NULL || lista_vazia(lst))
		return 0;

	int pos = 0;
	while( pos < lst->fim && strcmp(arrStr, lst->arrStr[ pos ]) )
		pos ++;

	if(pos == lst->fim)
		return 0;
	// pos == pos da str que quero remover
	for(int i = pos; i < (lst->fim)-1; i++)
		strcpy(lst->arrStr[i], lst->arrStr[i+1]);

	lst->fim --;
	return 1;
}

char getPos(Lista lst, int pos){
	if(pos < lst->fim)
		return lst->arrStr[pos];

	return -1; //Falha
}

int tamanho_lista(Lista lst){
    if(lst == NULL)
        return -1; //Falha

    else
	return lst->fim;
}

int esvazia_lista(Lista lst){
	if(lista_vazia(lst)) return 0;

	free(lst);
	lst = NULL;

	return 1;
}

int remove_todas(Lista lst, char elem[]){

    if(lst == NULL || lista_vazia(lst))
		return 0; // ERRO, lista vazia ou n iniciliazada

    for(int i= 0; i < lst->fim; i++){

        if ( strcmp(lst->arrStr[i],elem) == 0 ) {

            for (int j = i; j < lst->fim-1; j++)
                strcpy(lst->arrStr[j],lst->arrStr[j+1]); // Deslocamento dos nós sucessores.

            lst->fim--;
            i--;

        }
        else
            continue;
    }

    return 1;

        /*
	int idx = 0;
	while( idx < lst->fim && strcmp(str, lst->arrStr[ idx ]) )
		idx ++;
	if(idx == lst->fim)
		return 0;
	// idx == pos da str que quero remover
	for(int i = idx; i < (lst->fim)-1; i++)
		strcpy(lst->arrStr[i], lst->arrStr[i+1]);
	lst->fim --;*/
}
