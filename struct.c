#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>

struct steam {char game[30]; int price;};

//prints out variables of struct steam type in a reasonable way
void printgames(struct steam g) {
  printf("game: %s\n", g.game);
  printf("price: %d\n\n", g.price);
}

//returns an example of the struct when run
struct steam randGame() {
  char games[12][30] = {"Pong", "Pork", "Space Invaders", "Asteroids",
			"Pac-Man", "Defender", "Donkey Kong", "Frogger",
			"Galaga", "Joust", "Pitfall!", "Tetris"};
  struct steam g;
  int i = rand() % 12;
  strcpy(g.game, games[i]);
  g.price = rand() % 9999;
  return g;
}

//modifies int price
void *sales(struct steam *g, int offprice) {
  g->price = g->price - offprice;
}

//modifies string game
void *addWords(struct steam *g, char *s) {
  strcat(g->game, s);
}

int main() {
  
  srand(time(NULL));
  struct steam g1 = randGame();
  struct steam g2 = randGame();
  struct steam g3 = randGame();
  
  printf("random games \n");
  printgames(g1);
  printgames(g2);
  printgames(g3);
  
  printf("modifying int price (100 off) \n");
  sales(&g3,100);
  printgames(g3);

  printf("modifying string game (adding to name) \n");
  addWords(&g3, ".beta");
  printgames(g3);
  
  return 0;
}
