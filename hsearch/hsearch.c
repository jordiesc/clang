#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <stdio.h> 
#include <string.h>

#pragma GCC diagnostic warning "-Wformat"
/**
 * @brief Clang does not have hastable
 * glib is a collection on libraries or utilities
 * provicded by gnu  
 */

void addEntry(char* value, char* key);
char *strptr;
ENTRY entrada; 

int main(void)
{

    char *data[] = {"jordi", "joan" , "josep", "tobies", "yolanda"};
    ENTRY *efound = NULL;

    int ldata = sizeof(data) / sizeof(data[0]);
    printf("hello search data is : %i \n ", ldata);

    hcreate(ldata);
    for (int i = 0; i < ldata ; i++) {
        //with this char buffer[12];
        //the compiler return the same address each time
        //so we had to allocate memory
        char* buffer = (char *)calloc(20,sizeof(char));
        sprintf(buffer, "%d", i);
         addEntry(data[i], buffer ); 
    }

    entrada.key = "2";
    entrada.data = "any";
    efound = hsearch(entrada,FIND);

    if (efound == NULL) {
        printf("error");
        hdestroy();
        exit(EXIT_FAILURE);
    //strcmp return 0 when are equals    
    } else if( strcmp((char *)efound->data,"josep")== 0) {
        printf("....success... \n");
        printf("the value is: %s:",(char *)efound->data);
        hdestroy();
        exit(EXIT_SUCCESS);
    } else {
        printf("unknow error");
        printf("the value is: %s:",(char *)efound->data);
        hdestroy();
        exit(EXIT_FAILURE);

    } 

}

void addEntry(char* value, char* key) {
    printf(" value is %s: \t with key %s: \n",value,key);
    entrada.data = value;
    entrada.key = key;
    hsearch(entrada,ENTER);
    
}