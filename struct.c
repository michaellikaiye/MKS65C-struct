#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
/* Create a struct that has at least 2 data members, one must be a string. */
/* You can provide struct prototypes outside of functions. */
/* Don't just combine random things, make it meaningful (like food and price, athlete and associated statistic, Pokemon and something about Pokemon ..) */


/* Write a function that returns an example of your struct when run. */
/* This should not return the same struct every time. */
/* Write a function that prints out variables of your structs type in a reasonable way. */
/* Write a function that modifies values of your struct's type. */
/* Write a main function that tests all these things. */
/* Have meaningful output. */
/* DONT FORGET A MAKEFILE */

typedef unsigned long size_t;

struct steam {int price; char game[20];};

void printgames(struct steam wishlist){
  printf("game: %s\n", wishlist.game);
  printf("price: %d\n", wishlist.price);
}

struct steam randO() {
  struct steam gz;
  int i = 0;
  char string[20] = "";
  int size = (rand() % 15)+3;
  for(i;i< size; i++) {
    char r = 'A' + (rand() % 26);
    char * p = &r;
    string[i] = r;
  }
  int j = 0;
  for(j;j<size;j++) {
    gz.game[j] = string[j];
  }
  gz.price = (rand()%10000);
  return gz;
}

struct steam sales(struct steam g, int offprice){
  struct steam g0;
  int j = 0;
  for(j;j<20;j++) {
    g0.game[j] = g.game[j];
  }

  g0.price = g.price -  offprice;
  return g0;
}
	   
int main() {
  
  srand(time(NULL));
  struct steam g1 = randO();
  
  struct steam g2 = randO();
  
  printgames(g1);
  printgames(g2);
  g1 = sales(g1,10);
  printgames(g1);
  return 0;
}
