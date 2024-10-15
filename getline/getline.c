#include <stdio.h>
#include <stdlib.h>


//#define BUF_SIZE = 100

int main(void)
{
    size_t BUF_SIZE = 100;
    char* buffer; 
    size_t characters;
    buffer = calloc(BUF_SIZE,sizeof(char));
    printf("Type something: ");
    characters = getline(&buffer,&BUF_SIZE,stdin);
    printf("%zu characters were read.\n",characters);
    printf("You typed: '%s'\n",buffer);

    free(buffer);

}

