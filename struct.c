#include<stdio.h>
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

struct steam {int price; char* game;};

void printgames(struct steam wishlist){
  printf("game: %s\n", wishlist.game);
  printf("price: %d\n", wishlist.price);
}
struct steam sales(struct steam g, int offprice){
  struct steam g0;
  g0.game = g.game;
  g0.price = g.price -  offprice;
  return g0;
}
	   
int main() {
  struct steam g1;
  g1.price = 40;
  g1.game = "fallout";
  printgames(g1);
  g1 = sales(g1,10);
  printgames(g1);
  g1.price -= 10;
  printgames(g1);
  return 0;
}
