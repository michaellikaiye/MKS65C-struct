#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>

struct steam {char game[20]; int price;};

//prints out variables of struct steam type in a reasonable way
void printgames(struct steam g) {
  printf("game: %s\n", g.game);
  printf("price: %d\n\n", g.price);
}

//returns an example of the struct when run
struct steam randO() {
  struct steam g;
  int i = 0;
  for(i; i< ((rand() % 15)+1); i++)
    g.game[i] = 'A' + (rand() % 26);
  g.game[i] = '\0';
  g.price = (rand()%100000);
  return g;
}

//modifies int price
struct steam sales(struct steam g, int offprice) {
  struct steam *p = &g;
  p->price = g.price - offprice;
  return g;
}

//modifies string game
struct steam addWords(struct steam g, char *s) {
  int l = strlen(g.game);
  int i;
  for (i = 0; (i + l) < 20 && s[i] != '\0'; i++)
    *(g.game + l + i) = *(s + i);
  *(g.game + l + i) = '\0';

  return g;
}

int main() {
  
  srand(time(NULL));
  struct steam g1 = randO();
  struct steam g2 = randO();
  struct steam g3 = randO();
  
  printf("random games \n");
  printgames(g1);
  printgames(g2);
  printgames(g3);
  
  printf("modifying int price (100 off) \n");
  g3 = sales(g3,100);
  printgames(g3);

  printf("modifying string game (adding to name) \n");  
  g3 = addWords(g3, ".beta");
  printgames(g3);
  
  return 0;
}
