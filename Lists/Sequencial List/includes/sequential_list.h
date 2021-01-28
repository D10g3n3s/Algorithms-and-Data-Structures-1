#ifndef LIST_H
#define LIST_H

	#define TAM_MAX 100 /*estimativa do tamanho máximo da LIST*/
	#define TRUE 1 
	#define FALSE 0
	#define boolean int /*define um tipo booleano*/
	#define inicial 0
	#define ERRO -32000

	#include "item.h"

	typedef struct list_ LIST;

	LIST *create_list(void);
	boolean insert_list(LIST *LIST, ITEM *item);
	boolean remove_list(LIST *LIST, int chave);
	void delete_list(LIST **LIST);
	ITEM *search_list(LIST *LIST, int chave);

	int list_length(LIST *LIST);
	boolean empty_list(LIST *LIST);
	boolean full_list(LIST *LIST);
	void print_list(LIST *LIST);
  
#endif
