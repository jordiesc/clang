
#ifndef DLL_H
#define DLL_H    


typedef struct t_node 
{

    struct t_node *next;
    struct t_node *prev;
    char *data;
} t_node;

typedef struct t_dll
{   
    int length;
    struct t_node *head;
    struct t_node *tail; 
} t_dll;



t_dll *dll_new();
void dll_free(t_dll *dll);
void dll_add(t_dll *dll, char *data);
void dll_print(t_dll *dll);

void dll_remove(t_dll *dll, char *data); 

t_node *dll_get_first(t_dll *dll);
t_node *dll_get_last(t_dll *dll);
t_node *dll_get_next(t_node *node);
t_node *dll_get_prev(t_node *node);
char *dll_get_data(t_node *node);   
char *dll_get_data_first(t_dll *dll);
char *dll_get_data_last(t_dll *dll);        



#endif