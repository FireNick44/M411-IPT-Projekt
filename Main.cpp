#include <stdlib.h>
#include <stdio.h>
#include <string.h> //Wird f�r "string" Funktionen ben�tigt.
#include <time.h>   //Wird f�r "random" Funktionen ben�tigt.
#include <conio.h>   //Wird f�r Tastatur Eingaben ben�tigt.

int random(int, int); // Zuf�llige Zahl mit Angabe von Wertebereich
void ausgabe(); // Test Methode
void end(); // Spielende
void logo();
void karten(); // Algorithmus f�r das Mischen und Verteilen der Karten
void f�llkarten(); // Algorithmus f�r das Abf�llen der Karten mit Werten
void einstellungen(); // Farbeinstellungen
void rundestart(); // Start einer Runde



typedef struct Karten // Struktur f�r Karten 
{
  int Nr;
  char Marke[20];
  char Modell[20];
  int Leistung;
  int Gewicht;
  double H�chsttempo;
  struct Karten* pNext;
}struKarten;


int main()
{
  // Rand Initialisierung f�r die Methode "random".
  srand(time(NULL));

  system("mode con cols=138 lines=30");
  int main;

  bool men� = true;
  while (men� == true)
  {
    //variablen
    int spielmodus;
    char eingabe; //Variabel f�r Eingabe

    system("cls"); // Leeren des Bildschirms

    logo();

    printf("\n  ==================================");
    printf("\n  W\x84hlen Sie ihren Spielmodus:");
    printf("\n  1 Spieler     (1)");
    printf("\n  Einstellungen (2)");
    printf("\n  Beenden       (3)");
    printf("\n  ==================================");
    printf("\n");
    printf("\n  (1/2/3): ");

    eingabe = _getch(); //getch oder getche (getche gibt ein Echo mit aus.)

    //1 Spieler (PC vs Spieler)
    if (eingabe == '1')
    {

    }

    //Einstellungen
    else if (eingabe == '2')
    {

    }

    //Ende
    else if (eingabe == '3')
    {
      char e;
      printf("\n\n  M\x94""chten Sie das Spiel wirklich beenden?");
      printf("\n  (J/N) ");
      scanf_s(" %c", &e, 1);
      if (e == 'j' || e == 'J') men� = false;
    }

    //falsche Eingabe
    else if (eingabe != '1' && eingabe != '2' && eingabe != '3')
    {
      printf("\n  Falsche Eingabe");
      system("timeout 1 >null");
      system("cls");
    }
  }
  end();
  return 0;
}

int random(int min, int max) {
  // Random-Funktion, wo Zahlen f�r das zuf�llige Verteilen der Karten 
  int r = rand() % max + min;

  return(r);
}

void logo()
{
  printf("\n\n");
  printf("    .d88888b.                            888            888    888     \n");
  printf("   d88P   Y88b                           888            888    888     \n");
  printf("   888     888                           888            888    888     \n");
  printf("   888     888 888  888  8888b.  888d888 888888 .d88b.  888888 888888  \n");
  printf("   888     888 888  888     '88b 888P'   888   d8P  Y8b 888    888     \n");
  printf("   888 Y8b 888 888  888 .d888888 888     888   88888888 888    888     \n");
  printf("   Y88b.Y8b88P Y88b 888 888  888 888     Y88b. Y8b.     Y88b.  Y88b.   \n");
  printf("    'Y888888'   'Y88888 'Y888888 888      'Y888 'Y8888'  'Y888  'Y888  \n");
  printf("          Y8b                                                          \n");

  //printf("                                  \n");
  //printf("                                  \n");
  //printf("      .@@@@@@@@@@@@@@@@@@@.       \n");
  //printf("     @@                  @@.      \n");
  //printf("    @@                    @@      \n");
  //printf("    @@                    &@      \n");
  //printf("    @ @@@@@@@    %@@@@@@@@ @.     \n");
  //printf("    @@   (o)      (O)     @@@     \n");
  //printf("   .@@        ((           @@     \n");
  //printf("   @@@  @@@@@@@@@@@@@@@    @@     \n");
  //printf("       @@ ########## @@@          \n");
  //printf("      @@@            @@@          \n");
  //printf("      @@ ##________## @@@         \n");
  //printf("      @@@ '########'  @@@         \n");
  //printf("      @@@             @@@         \n");
  //printf("       @               @          \n");
  //printf("                                  \n");

  //printf("             %@@@@@@@@            \n");
  //printf("          @@@@@@@@@@@@@           \n");
  //printf("         @@@@@@@@@@@@@@@@         \n");
  //printf("        ,@@@@@@@@       @@        \n");
  //printf("       @  @@@@%           @       \n");
  //printf("     ,@                    @ ,@.  \n");
  //printf("     @@ @@@%    /@@@@@.    @@  @  \n");
  //printf("     @@  (O)      (O)     .@@  @  \n");
  //printf("     @        /           @@@.(.) \n");
  //printf("     @       (@.          @@@     \n");
  //printf("    .@@@@@@@@@@@@@@@@@@   @@,     \n");
  //printf("    @@@@ ########## @@@@ .@@*     \n");
  //printf("    '@@@              @@@@@@*     \n");
  //printf("     @@@@ #########,@@@@@@@       \n");
  //printf("      @@@@@@@@@@@@@@@@@@@         \n");
  //printf("        @@@@@@@@@@@@@@@@          \n");
  //printf("                                  \n");
}

void ausgabe() {

  char c;
  printf("\n\n");
  printf("\n  ==================================");
  printf("\n  Was M\x94""chten Sie Vergleichen?");
  printf("\n  1 = Variable 1: value X... ");
  printf("\n  2 = Variable 2:");
  printf("\n  3 = Variable 3:");
  printf("\n  4 = Variable 4:");
  printf("\n  ==================================");
  printf("\n  5 = Neu Starten");
  printf("\n  6 = Beenden");
  printf("\n  (1/2/3/4/5/6): ");
}

void end()
{
  char e;

  // Nachfrage zum Beenden
  printf("\n  M\x94""chten Sie das Spiel wirklich beenden?\n");
  printf("  (J/N) ");
  scanf_s(" %c", &e,1);
  system("cls");
  if (e == 'J' || e == 'j')
  {
    printf("  oooooooooooo                   .o8          \n");
    printf("  `888'     `8                  '888          \n");
    printf("   888         ooo. .oo.    .oooo888   .d88b. \n");
    printf("   888oooo8    `888P'Y88b  d88' `888  d8P  Y8b\n");
    printf("   888    '     888   888  888   888  88888888\n");
    printf("   888       o  888   888  888   888  Y8b.    \n");
    printf("  o888ooooood8 o888o o888o `Y8bod88P'  'Y8888'\n\n\n");
  }
}



void rundestart()
{

}

void karten()
{
  f�llkarten();
  
}

void f�llkarten()
{

}



void einstellungen()
{

}

void farbmatrix(char hintergrundfarbe, char textfarbe)
{
  //Alles mit schwarzem Hintergrund
  if (hintergrundfarbe == '0' && textfarbe == 'F')      system("color 0F");
  else if (hintergrundfarbe == '0' && textfarbe == '8') system("color 08");
  else if (hintergrundfarbe == '0' && textfarbe == '2') system("color 02");
  else if (hintergrundfarbe == '0' && textfarbe == '4') system("color 04");
  else if (hintergrundfarbe == '0' && textfarbe == '1') system("color 01");

  //Alles mit grauem Hintergrund
  else if (hintergrundfarbe == '8' && textfarbe == '0') system("color 80");
  else if (hintergrundfarbe == '8' && textfarbe == 'F') system("color 8F");
  else if (hintergrundfarbe == '8' && textfarbe == '2') system("color 82");
  else if (hintergrundfarbe == '8' && textfarbe == '1') system("color 81");
  else if (hintergrundfarbe == '8' && textfarbe == '4') system("color 84");

  //Alles mit weissem Hintergrund
  else if (hintergrundfarbe == 'F' && textfarbe == '0') system("color F0");
  else if (hintergrundfarbe == 'F' && textfarbe == '8') system("color F8");
  else if (hintergrundfarbe == 'F' && textfarbe == '2') system("color F2");
  else if (hintergrundfarbe == 'F' && textfarbe == '1') system("color F1");
  else if (hintergrundfarbe == 'F' && textfarbe == '4') system("color F4");

  //Alles mit Gr�nem Hintergrund
  else if (hintergrundfarbe == '2' && textfarbe == '0') system("color 20");
  else if (hintergrundfarbe == '2' && textfarbe == '8') system("color 28");
  else if (hintergrundfarbe == '2' && textfarbe == 'F') system("color 2F");
  else if (hintergrundfarbe == '2' && textfarbe == '1') system("color 21");
  else if (hintergrundfarbe == '2' && textfarbe == '4') system("color 24");

  //Alles mit Blauem Hintergrund
  else if (hintergrundfarbe == '1' && textfarbe == '0') system("color 10");
  else if (hintergrundfarbe == '1' && textfarbe == '8') system("color 18");
  else if (hintergrundfarbe == '1' && textfarbe == 'F') system("color 1F");
  else if (hintergrundfarbe == '1' && textfarbe == '2') system("color 12");
  else if (hintergrundfarbe == '1' && textfarbe == '4') system("color 14");

  //Alles mit Rotem Hintergrund
  else if (hintergrundfarbe == '4' && textfarbe == '0') system("color 40");
  else if (hintergrundfarbe == '4' && textfarbe == '8') system("color 48");
  else if (hintergrundfarbe == '4' && textfarbe == 'F') system("color 4F");
  else if (hintergrundfarbe == '4' && textfarbe == '2') system("color 42");
  else if (hintergrundfarbe == '4' && textfarbe == '1') system("color 41");
}
