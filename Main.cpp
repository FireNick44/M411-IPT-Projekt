#include <stdlib.h>
#include <stdio.h>
#include <time.h> //Wird f�r "random" Funktion ben�tigt.

void random();
void ausgabe();

int main()
{
  random();
  ausgabe();
  printf("Hello\n"); //Test 2
  system("pause");
  return 0;
}


void random() {

  srand(time(NULL));
  int random = rand();

}

void ausgabe() {
  printf("Was M�chten Sie Vergleichen?\n");
}
