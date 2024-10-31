#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dll.h"
#include "errno.h"
//#include <stdbool.h>

int has_content(const char *str);

struct t_dll *dll_new(){

    t_dll *dll =  malloc(sizeof(t_dll));
    dll->length = 0;
    dll->head = NULL;
    dll->tail = NULL;
    //check errors
    if (errno > 0) {
        printf("Error description: %s\n", strerror(errno));
        exit(1);

    }

    return dll;
}

void dll_free(t_dll *dll){
    free(dll);
}

void dll_add(t_dll *dll, void *data) {
    t_node *node = malloc(sizeof(t_node));
    dll->length ++;
    node->next = NULL;
    node->data = data;
    node->prev = dll->tail;
    dll->tail = node; 

    //si es el primer se anotael header
    //si es posterior se recupera el nodo anterior 
    //para poner el puntero al siguiente del anterior

    if ( dll->length == 1 ){
        dll->head = node;
    } else {
        t_node *prev = node -> prev;
        prev->next = node;
    }

   
}


t_node *dll_get_first(t_dll *dll) {
    return dll->head;
}


void dll_remove(t_dll *dll, void *data, int (*comparator) (void *left, void *right)) {

    //start from begginig
    t_node *current_node = dll->head;
    
    for ( int size = 0 ; size < dll->length; size++ ) {
        if (! has_content( data)) {
            break;
        }
        //if found
        if ( comparator(current_node->data,data) == 0 ) {
            t_node *previous = current_node->prev;
            t_node *next = current_node->next;
            //si es el primer
            if (previous != NULL )
                previous->next = next;
            free(current_node);
            dll->length--;
        }
        current_node = current_node->next;
    }
}


int has_content(const char *str) {
    // Check if pointer is not NULL and the string is not empty
    return (str != NULL && str[0] != '\0');
}

void dll_print(t_dll *dll ){

    if (dll == NULL) {
        printf(" dll is NULL");
        exit(1);
    }
    t_node *current = dll->head;
    
    while (current != NULL ) {
        printf("debug ");
        char *datos = current-> data;
        printf(" datos: %s \n", datos);
        current = current->next;
    }


}
/*
*********************************************************************
struct t_dll *init_dll()
{
    struct t_dll *dll = (struct t_dll *)malloc(sizeof(struct t_dll));
    dll->length = 0;
    dll->data = NULL;
    return dll;
}

void add_node(struct t_dll *dll, char *data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if(dll->length == 0){
        dll->data = data;
        dll->length++;
        return;
    }

    struct node *current_node = dll->data;
    while(current_node->next != NULL){
        current_node = current_node->next;
    }
    current_node->next = new_node;
    new_node->prev = current_node;
    dll->length++;
}

void print_dll(struct t_dll *dll)
{
    struct node *current_node = dll->data;
    while(current_node != NULL){
        printf("%s\n", current_node->data);
        current_node = current_node->next;
    }
}   

*****************************************

*/