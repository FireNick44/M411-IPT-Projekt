#include <stdlib.h>
#include <stdio.h>
#include <time.h> //Wird f�r "random" Funktion ben�tigt.


int random(int, int);
void ausgabe();

int main()
{
  srand(time(NULL));
  int rTmp = random(1, 10);
  
  
  ausgabe();
  printf("Hello: %i\n", rTmp = random(1, 10)); //Test 2
  system("pause");
  return 0;
}


int random(int min, int max) {

  int r = rand() % max + min;

  return(r);
}

void ausgabe() {
  printf("Was M�chten Sie Vergleichen?\n");
}
