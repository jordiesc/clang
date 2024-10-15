#include <stdio.h>
#include <stdlib.h>

int metodopuntero();
int metododos();

int main_disabled(void)
{
   // return metodopuntero();
   return metododos();

}

int metodopuntero() {


char *cards = malloc(sizeof(char) * 4);
cards[0] = 'J';
cards[1] = 'Q';
cards[2] = 'K';
cards[3] = '\0';
char a_card = cards[2];
cards[1] = a_card;

puts(cards);
return 0;
}

int metododos() {

char cardsarray []="JQK";
char *cards = cardsarray;
char a_card = cards[2];
cards[2] = cards[1];
cards[1] = cards[0];
cards[0] = cards[2];
cards[2] = cards[1];
cards[1] = a_card;

puts(cards);
return 0;
}