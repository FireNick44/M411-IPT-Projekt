#include <stdlib.h>
#include <stdio.h>
#include <time.h> //Wird f�r "random" Funktion ben�tigt.


int random();
void ausgabe();

int main()
{
  srand(time(NULL));
  random(1,10);
  
  
  ausgabe();
  printf("Hello\n"); //Test 2
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
