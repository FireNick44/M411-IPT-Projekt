#include <stdlib.h> 
#include <stdio.h>  
#include <string.h>     //Wird f�r "string"-Funktionen ben�tigt.
#include <string>   
#include <time.h>       //Wird f�r "random"-Funktionen ben�tigt.
#include <conio.h>      //Wird f�r Tastatureingaben ben�tigt.
#include <Windows.h>    //Wird f�r Sleep-Funktion ben�tigt.


// Struktur f�r Karten
typedef struct Karten
{
  int Nr;
  char Bez[40];
  int Trefferpunkte;
  int Geschw;
  double Schaden;
  struct Karten* pNext;
}struKarten;


// Prototypen der Methoden
int rundestart();                                               // Start einer Runde
int rundeneustart();                                            // Neustart einer Runde
int ausgabe(struKarten*, struKarten*);                          // Funktion f�r Ausgabe der Karten
struKarten* createlist(struKarten*, struKarten*);               // Funktion f�r das Kreieren von Listen und Hinzuf�gen von Karten mit Hilfe der Methode "karte"
struKarten* removelist(struKarten*, struKarten*);               // Funktion f�r das Entfernen von einer Karte/n aus einer Liste
struKarten* karte(int, const char*, int, int, double);          // Funktion f�r das Erstellen und Abf�llen der Karten mit Werten
struKarten* firstlast_gew(struKarten*);                         // Funktion f�r den Gewinner einer Karte
struKarten* firstlast_verl(struKarten*, struKarten*);           // Funktion f�r den Verlierer einer Karte
struKarten* vergleiche(int, struKarten*, struKarten*);          // Funktion f�r das Vergleichen von Karten aus zwei Listen

int listcount(struKarten*);                                     // Einfache Funktion f�rs Z�hlen von Elementen in einer Liste
int men�();                                                     // Hauptmen�
int einstellungen();                                            // Einstellungen
void farbmatrix(char, char);                                    // Farbmatrix f�rs Einstellen der Farben auf der CMD
void falsche_eingabe();                                         // Einfache Ausgabe bei falscher Eingabe
void end();                                                     // Ausgabe f�r Spielende wenn man das Spiel verl�sst
void logo();                                                    // Ausgabe f�r Logo des Spiels
void verlieren();                                               // Ausgabe wenn man eine Karte verliert
void gewinnen();                                                // Ausgabe wenn man eine Karte gewinnt

// Weitere Beschreibungen findet man in den einzelnen Funktionen.


// Globale Variablen
bool admin = false;                                             // Wird f�r die Einstellungen/Entwicklermodus ben�tigt.
bool first = true;                                              // Wird f�r die Einstellungen/Farben ben�tigt.
char hintergrundfarbe;                                          // Hintergrundfarbe der CMD.
char textfarbe;                                                 // Textfarbe der CMD.


int ausgabe(struKarten* pListePlayer, struKarten* pListeCPU) {

  char c;
  char j;
  bool men� = false;
  bool kartegew = false;

  while (pListePlayer != NULL && !men�) {
    kartegew = false;

    int AnzPlayer = listcount(pListePlayer);    // Z�hlt Anzahl Karten im eigenen Stapel.

    int AnzCPU = listcount(pListeCPU);          // Z�hlt Anzahl Karten im CPU-Stapel.

    while (!kartegew && !men� && AnzPlayer > 0) {  // In dieser While-Schleife wird immer wieder die gleiche Karte ausgegeben, bis man eine Eingabe macht.
      system("cls");

      printf("\n\n");
      printf("\n  ==================================");
      printf("\n\n               KARTE               ");
      printf("\n\n    _____________________________ ");
      printf("\n   /                             \x5C");
      printf("\n  /  CoC Quartett | Karte Nr. %-2i  \x5C", pListePlayer->Nr);
      printf("\n  |                               |");
      printf("\n  |      --------------------     |");
      printf("\n  |      ---%-14s---     |", pListePlayer->Bez);
      printf("\n  |      --------------------     |");
      printf("\n  |                               |");
      printf("\n  |                               |");
      printf("\n  |                               |");
      printf("\n  |                               |");
      printf("\n  |                               |");
      printf("\n  |                               |");
      printf("\n  |                               |");
      printf("\n  |    ----------------------     |");
      printf("\n  |   |Trefferpunkte   | %4i|    |", pListePlayer->Trefferpunkte);
      printf("\n  |   |                |     |    |");
      printf("\n  |   |Geschwindigkeit | %4i|    |", pListePlayer->Geschw);
      printf("\n  |   |                |     |    |");
      printf("\n  |   |Schaden         | %4.1lf|    |", pListePlayer->Schaden);
      printf("\n  |    ----------------------     |");
      printf("\n  \x5C                               /");
      printf("\n   \x5C_____________________________/");
      printf("\n\n");

      printf("\n  Ihre n\x84""chste Karte lautet: %-14s ", pListePlayer->pNext->Bez);
      printf("\n  Sie besitzen insgesamt noch %i Karten.", AnzPlayer);
      

      printf("\n\n\n  =================================");
      printf("\n  Trefferpunkte?         (1)");
      printf("\n  Geschwindigkeit?       (2)");
      printf("\n  Schaden?               (3)");
      printf("\n\n  Neu Starten            (4)");
      printf("\n  Zur\x81" "ck zum Hauptmen\x81   (5)");
      printf("\n  =================================");
      printf("\n\n  (1/2/3/4/5): ");

      c = _getch();

      if (c == '1' || c == 't') {
        printf("\n\n  M\x94""chten Sie wirklich Trefferpunkte abfragen?");
        printf("\n\n  (J/N): ");

        j = _getch();
        if (j == 'j') {
          //vergleiche(1, pListePlayer, pListeCPU);
        }

        else if (j == 'n');

        else falsche_eingabe();
      }

      else if (c == '2' || c == 'g') {
        printf("\n\n  M\x94""chten Sie wirklich Geschwindigkeit abfragen?");
        printf("\n\n  (J/N): ");

        j = _getch();
        if (j == 'j') {
          //vergleiche(2, pListePlayer, pListeCPU);
        }
      }

      else if (c == '3' || c == 's') {
        printf("\n\n  M\x94""chten Sie wirklich Schaden abfragen?");
        printf("\n\n  (J/N): ");

        j = _getch();
        if (j == 'j') {
          //vergleiche(3, pListePlayer, pListeCPU);
        }
      }

      else if (c == '4') {
        printf("\n\n  M\x94""chten Sie wirklich das Spiel neustarten?");
        printf("\n  Ihre Karten werden somit neu gemischt und Sie verlieren Ihren Spielstand.");
        printf("\n\n  (J/N): ");

        j = _getch();
        if (j == 'j') {
          rundeneustart();
          men� = true;
        }

        else if (j == 'n');

        else falsche_eingabe();
      }

      else if (c == '5') {
        printf("\n\n  M\x94""chten Sie wirklich zum Hauptmen\x81 zur\x81""ck?");
        printf("\n  (J/N): ");

        j = _getch();
        if (j == 'j') men� = true;
      }

      else if (c != '1' && c != '2' && c != '3' && c != '4' && c != '5')
      {
        falsche_eingabe();
      }

    }

    while (AnzPlayer <= 0 && AnzCPU >= 10 && !men�) // Spielende: Wenn man das Spiel verliert.
    {
      system("cls");

      printf("\n  ==================================");
      printf("\n\n  Sie besitzen keine Karten mehr. Sie haben das Spiel verloren.");
      printf("\n\n  ==================================");
      printf("\n\n\n\n  M\x94""chten Sie zum Hauptmen\x81 zur\x81""ck?");


      c = _getch();
      if (c == 'j') men� = true;
    }

    while (AnzPlayer >= 10 && AnzCPU <= 0 && !men�) // Spielende: Wenn man das Spiel gewinnt.
    {
      system("cls");

      printf("\n  ==================================");
      printf("\n\n  Der CPU-Spieler besitzt keine Karten mehr. Sie haben das Spiel gewonnen.");
      printf("\n\n  ==================================");
      printf("\n\n\n\n  M\x94""chten Sie zum Hauptmen\x81 zur\x81""ck?");

      c = _getch();
      if (c == 'j') men� = true;
    }

  }
  return 0;
}

struKarten* firstlast(struKarten* pListeGewinner, struKarten* pListeVerlierer)
{
  // In dieser Funktion wird aus der Liste des Verl. die erste Karte und aus der Liste des Gew. die erste Karte
  // an die letzte Stelle des Gew. versetzt


  struKarten* pTempFirst = pListeGewinner;
  struKarten* pTempLast = pListeGewinner;
  struKarten* pTempLastMinus = NULL;

  int f; //waren gedacht als index f�r eine for schleife
  int l; //waren gedacht als index f�r eine for schleife
  int lm; //waren gedacht als index f�r eine for schleife

  while (pTempLast->pNext != NULL)
  {

    pTempLastMinus = pTempLast;
    pTempLast = pTempLast->pNext;

    printf("pTempFirst %i\n", f = pTempFirst->Nr);
    printf("pTempLast %i\n", l = pTempLast->Nr);
    printf("pTempLastMinus %i\n\n", lm = pTempLastMinus->Nr);
  }
  printf("==================================\n");


  pTempLast->pNext = pTempFirst;

  pListeGewinner = pTempFirst->pNext; //pListeGewinner zeigt direkt auf die 2. Karte
  pTempLast->pNext->pNext = NULL; //Bei der Karte 1 wird pNext auf 0 gesetzt
  pListeGewinner->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext = pTempLast->pNext; //Bei Orginal-Liste wird pNext auf Karte 11 bzw 1 gesetzt.

  pTempLast = pListeGewinner;

  while (pTempLast->pNext != NULL)
  {

    pTempLastMinus = pTempLast;
    pTempLast = pTempLast->pNext;

    //printf("pTempFirst %i\n", pTempFirst->Nr);
    //printf("pTempLast %i\n", pTempLast->Nr);
    //printf("pTempLastMinus %i\n\n", pTempLastMinus->Nr);

    int z = pTempLast->Nr;
    //Zum Testen
    printf("\n  pTemp Zeigt auf die Karte Nr: %i", z);

  }
  printf("\n  ==================================");



  system("pause");

  return 0;
}

struKarten* firstlast_gew(struKarten* pListe)
{
  struKarten* pTemp = pListe;
  pListe = pListe->pNext;
  pTemp->pNext = NULL;
  
  printf("\n  Die erste Karte ist: %i", pTemp->Nr);
  printf("\n  Diese wird jetzt an den hintersten Platz versetzt.");
  system("pause");

  struKarten* pLast = pListe;

  while (pLast->pNext != NULL) {
    pLast = pLast->pNext;
  }

  pLast->pNext = pTemp;
  pListe = pLast;


  printf("\n  Die letzte Karte ist: %i", pLast->Nr);
  printf("\n  Hinter dieser Karte befindet sich jetzt die Karte: %i", pTemp->Nr);


  printf("\n  Die ganze Liste besteht jetzt aus den Karten:\n");

  for (struKarten* pAusgabe = pListe; pAusgabe->pNext != NULL; pAusgabe->pNext)
  {
    printf("\n  %c", pAusgabe->Bez);
  }
  

  system("pause");
  return pListe;
}

struKarten* vergleiche(int Typ, struKarten* pListePlayer, struKarten* pListeCPU) {

  if (Typ == 1) {

    if (pListePlayer->Trefferpunkte > pListeCPU->Trefferpunkte) {
      firstlast(pListePlayer, pListeCPU);

    }

    else if (pListePlayer->Trefferpunkte = pListeCPU->Trefferpunkte) {

    }

    else if (pListePlayer->Trefferpunkte < pListeCPU->Trefferpunkte) {

    }
  }

  else if (Typ == 2) {

  }

  else if (Typ == 3) {


  }

  return 0;
}

struKarten* createlist(struKarten* pListe, struKarten* pKarte)
{

  if (pListe == NULL) {   // Als erstes die Referenz zur ersten Karte "pStart", bzw. der Liste, die anf�ngt mit pStart.
    pListe = pKarte;      // Wenn diese Liste leer ist, dann referenziert pNew mit dem ganzen Inhalt auf die erste Karte "pStart".
    pKarte->pNext = NULL; // Die n�chste Karte existiert dann noch nicht. Die Referenz dazu ist vorerst leer.
  }
  else {
    struKarten* pLast = pListe; // Beispiel: "Barbar" wird von pLast referenziert, weil zu Beginn die erste Karte auch die letzte ist.
    while (pLast->pNext != NULL) {
      pLast = pLast->pNext;     // Schleife: Zum finden der letzten Karte. Solange die Referenz auf die n�chste Karte jeder Karte nicht NULL, also nicht leer ist,
                                // ist diese die letzte Karte. Wird beim ersten mal gar nicht ausgef�hrt weil Barbar schon die letzte Karte ist und keinen pNext hat.
    }
    pLast->pNext = pKarte;      // Jeder neue Inhalt, der sich in pNew befindet (Beispiel: Bogensch�tzin) ist die n�chste Karte der tempor�r "letzten" Karte (Beispiel: Barbar).
  }
  return pListe;                // Die Liste wird samt allen neuen Elementen zur�ckgegeben.
}

struKarten* removelist(struKarten* pListe, struKarten* pKarte)
{
  if (pListe == pKarte)
  {
    pListe = pListe->pNext;
    pKarte->pNext = NULL;
  }

  else
  {
    struKarten* pTmp = pListe;
    while (pTmp->pNext != pKarte) {
      pTmp = pTmp->pNext;
    }
    pTmp->pNext = pKarte->pNext;
    pKarte->pNext = NULL;
  }


  return pListe;
}

struKarten* karte(int pTruppe, const char* pBez, int Hp, int Spd, double Dmg)
{

  struKarten* pTmp = (struKarten*)malloc(sizeof(struKarten));

  pTmp->Nr = pTruppe;
  strcpy_s(pTmp->Bez, pBez);
  pTmp->Trefferpunkte = Hp;
  pTmp->Geschw = Spd;
  pTmp->Schaden = Dmg;
  pTmp->pNext = NULL;

  return pTmp;
}

int rundestart()
{
  system("cls");

  /*
  for (int i = 0; i < 3; i++) {
    system("cls");
    printf("\n\n");
    printf("\n  ==================================");
    printf("\n\n  Karten werden erstellt und gemischt .");
    printf("\n\n  Bitte Warten");
    Sleep(500);
    system("cls");
    printf("\n\n");
    printf("\n  ==================================");
    printf("\n\n  Karten werden erstellt und gemischt ..");
    printf("\n\n  Bitte Warten");
    Sleep(500);
    system("cls");
    printf("\n\n");
    printf("\n  ==================================");
    printf("\n\n  Karten werden erstellt und gemischt ...");
    printf("\n\n  Bitte Warten");
    Sleep(500);
  }*/

  struKarten* pStart = (struKarten*)malloc(sizeof(struKarten));        //Erstellt Startliste mit der beim Verteilen gearbeitet wird

  struKarten* pListePlayer = (struKarten*)malloc(sizeof(struKarten));  //Erstellt Liste von Player
  struKarten* pListeCPU = (struKarten*)malloc(sizeof(struKarten));     //Erstellt Liste von CPU

  pStart = createlist(pStart, karte(1, "Barbar", 160, 16, 30.3));
  pStart = createlist(pStart, karte(2, "Bogensch\x81tzin", 48, 24, 25.7));
  pStart = createlist(pStart, karte(3, "Drache", 3100, 16, 240.1));
  pStart = createlist(pStart, karte(4, "P.E.K.K.A", 5300, 16, 470.3));
  pStart = createlist(pStart, karte(5, "Hexe", 300, 12, 100.2));
  pStart = createlist(pStart, karte(6, "Schweinereiter", 270, 24, 60.0));
  pStart = createlist(pStart, karte(7, "Lakai", 58, 32, 38.2));
  pStart = createlist(pStart, karte(8, "Tunnelgr\x84""ber", 610, 32, 88.7));
  pStart = createlist(pStart, karte(9, "Riese", 800, 12, 31.5));
  pStart = createlist(pStart, karte(10, "Ballon", 390, 10, 108.0));



  int runde = 0;    // Verteilen: Runde 1 bis 5 werden dem Player Karten zugeteilt, Runde 5 bis 10 dem CPU

  for (runde; runde < 5; runde++)
  {
    int anz = listcount(pStart);            // Es werden alle Elemente der Liste pStart gez�hlt.
    //int pEnd = 1;
    
    srand(time(NULL));
    int r = rand() % anz;

    struKarten* pKarte = pStart;  // pKarte ist eine Variable, in der man eine zuf�llige Karte aus einer Liste (pStart) hineinspeichert.

    for (int c = 1; c <= r; c++)
    {
      pKarte = pKarte->pNext;
    }

    /*
    //Ausgabe zum Testen
    printf("\n  Die zuf\xE4llige Karte ist Karte Nr: %i ", z);
    printf("\n  Diese Karte heisst %c.", pKarte->Bez);
    printf("\n  Diese wird jetzt aus der Startliste entfernt.");
    system("pause");
    */

    pStart = removelist(pStart, pKarte);              // Parameter: Die Liste, aus der entfernt wird und welche Karte.
    pListePlayer = createlist(pListePlayer, pKarte);  // Parameter: Die Liste, zu der hinzugef�gt wird und welche Karte.
  }

  for (runde = 5; runde < 10; runde++)
  {
    int anz = listcount(pStart);            // Es werden alle Elemente der Liste pStart gez�hlt. 5 wurden schon entfernt.
    //int pEnd = 1;


    srand(time(NULL));
    int r = rand() % anz;

    struKarten* pKarte = pStart;  // pKarte ist eine Variable, in der man eine zuf�llige Karte aus einer Liste (pStart) hineinspeichert.

    int z = 0;
    for (int c = 1; c <= r; c++)
    {
      pKarte = pKarte->pNext;
      z = pKarte->Nr;
    }

    /*
    //Ausgabe zum Testen
    printf("\n  Die zuf\xE4llige Karte ist Karte Nr: %i ", z);
    printf("\n  Diese Karte heisst %c.", pKarte->Bez);
    printf("\n  Diese wird jetzt aus der Startliste entfernt und der Playerliste hinzugef�gt.");
    system("pause");
    */

    pStart = removelist(pStart, pKarte);        // Parameter: Die Liste, aus der entfernt wird und welche Karte.
    pListeCPU = createlist(pListeCPU, pKarte);  // Parameter: Die Liste, zu der hinzugef�gt wird und welche Karte.
  }


  //pListeCPU = pStart;

  firstlast_gew(pListePlayer);

  //ausgabe(pListePlayer, pListeCPU);
  return 0;
}

int rundeneustart()
{
  // Genau gleiche Funktion wie rundestart, wird aber nur ausgef�hrt wenn man das Spiel neustarten m�chte.

  system("cls");


  printf("\n\n");
  printf("\n  ==================================");
  printf("\n\n  Karten werden wieder neu erstellt und gemischt .");
  printf("\n\n  Bitte Warten");
  Sleep(500);
  system("cls");
  printf("\n\n");
  printf("\n  ==================================");
  printf("\n\n  Karten werden wieder neu erstellt und gemischt ..");
  printf("\n\n  Bitte Warten");
  Sleep(500);
  system("cls");
  printf("\n\n");
  printf("\n  ==================================");
  printf("\n\n  Karten werden wieder neu erstellt und gemischt ...");
  printf("\n\n  Bitte Warten");
  Sleep(500);

  struKarten* pStart = (struKarten*)malloc(sizeof(struKarten));

  struKarten* pListePlayer = (struKarten*)malloc(sizeof(struKarten));
  struKarten* pListeCPU = (struKarten*)malloc(sizeof(struKarten));

  pStart = createlist(pStart, karte(1, "Barbar", 160, 16, 30.3));
  pStart = createlist(pStart, karte(2, "Bogensch\x81tzin", 48, 24, 25.7));
  pStart = createlist(pStart, karte(3, "Drache", 3100, 16, 240.1));
  pStart = createlist(pStart, karte(4, "P.E.K.K.A", 5300, 16, 470.3));
  pStart = createlist(pStart, karte(5, "Hexe", 300, 12, 100.2));
  pStart = createlist(pStart, karte(6, "Schweinereiter", 270, 24, 60.0));
  pStart = createlist(pStart, karte(7, "Lakai", 58, 32, 38.2));
  pStart = createlist(pStart, karte(8, "Tunnelgr\x84""ber", 610, 32, 88.7));
  pStart = createlist(pStart, karte(9, "Riese", 800, 12, 31.5));
  pStart = createlist(pStart, karte(10, "Ballon", 390, 10, 108.0));

  int runde = 0;    

  for (runde; runde < 5; runde++)
  {
    int anz = listcount(pStart);


    srand(time(NULL));
    int r = rand() % anz;

    struKarten* pKarte = pStart;

    int z = 0;
    for (int c = 1; c <= r; c++)
    {
      pKarte = pKarte->pNext;
      z = pKarte->Nr;
    }

    /*
    // Ausgabe zum Testen
    printf("\n  Die zuf\xE4llige Karte ist Karte Nr: %i ", z);
    printf("\n  Diese Karte heisst %c.", pKarte->Bez);
    printf("\n  Diese wird jetzt aus der Startliste entfernt und der Playerliste hinzugef�gt.");
    system("pause");
    */

    pStart = removelist(pStart, pKarte);
    pListePlayer = createlist(pListePlayer, pKarte);
  }

  for (runde = 5; runde < 10; runde++)
  {
    int anz = listcount(pStart);


    srand(time(NULL));
    int r = rand() % anz;

    struKarten* pKarte = pStart;

    int z = 0;
    for (int c = 1; c <= r; c++)
    {
      pKarte = pKarte->pNext;
      z = pKarte->Nr;
    }

    /*
    //Ausgabe zum Testen
    printf("\n  Die zuf\xE4llige Karte ist Karte Nr: %i ", z);
    printf("\n  Diese Karte heisst %c.", pKarte->Bez);
    printf("\n  Diese wird jetzt aus der Startliste entfernt und der Playerliste hinzugef�gt.");
    system("pause");
    */

    pStart = removelist(pStart, pKarte);        
    pListeCPU = createlist(pListeCPU, pKarte);  
  }

  ausgabe(pListePlayer, pListeCPU);

  return 0;
}

int listcount(struKarten* pListe) {
  int anz = 0;
  struKarten* pTmp = pListe;
  for (pTmp; pTmp != NULL; pTmp = pTmp->pNext) {  // Es werden alle Elemente in einer Liste gez�hlt.
    anz++;
  }
  return anz;
}


int main()
{
  srand(time(NULL));                                            // Rand Initialisierung f�r die Methode "random".
  system("mode con cols=150 lines=70");                         // Setzt die Gr�sse der CMD

  men�();                                                       // Men� wird Aufgerufen
  end();                                                        // Spiel wird beendet

  return 0;
}

int men�()
{
  bool hauptmen� = true; // �berpr�ft ob das Men� geschlossen werden soll.

  while (hauptmen�)
  {
    //variablen
    char eingabe; // Variable f�r Eingabe

    system("cls"); // Leeren des Bildschirms

    logo();

    printf("\n  ==================================");
    printf("\n              Hauptmen\x81             ");
    printf("\n");
    printf("\n  Spiel starten     (1)");
    printf("\n  Einstellungen     (2)");
    printf("\n  Beenden           (3)");
    printf("\n  ==================================");
    printf("\n");
    printf("\n  (1/2/3): ");

    eingabe = _getch(); //getch oder getche (getche gibt ein Echo mit aus.)

    //1 Spieler (PC vs Spieler)
    if (eingabe == '1')
    {
      rundestart();
    }

    //Einstellungen
    else if (eingabe == '2')
    {
      einstellungen();
    }

    //Ende
    else if (eingabe == '3')
    {
      printf("\n\n  M\x94""chten Sie das Spiel wirklich beenden?");
      printf("\n  (J/N) ");

      eingabe = _getch();

      if (eingabe == 'J' || eingabe == 'j') hauptmen� = false;
    }

    //falsche Eingabe
    else if (eingabe != '1' && eingabe != '2' && eingabe != '3')
    {
      falsche_eingabe();
    }
  }
  return 0;
}

int einstellungen()
{
  //Variablen
  bool debug;
  bool settings = true;
  bool farben = true;

  char eingabe;
  char neue_hintergrundfarbe;
  char neue_textfarbe;

  //Erste Ausf�hrung


  while (settings)
  {
    system("cls");

    logo();

    printf("\n  ==================================");
    printf("\n  Einstellungen:     ");
    printf("\n  Farbe           (1)");
    printf("\n  Version         (2)");
    printf("\n  Entwicklermodus (3)");
    printf("\n  Zur\x81""ck          (4)");
    printf("\n  ==================================");
    printf("\n\n  (1/2/3/4): ");

    eingabe = _getch(); //getch oder getche (getche gibt ein Echo mit aus.)

    if (eingabe == '1')
    {
      farben = true;
      while (farben)
      {
        char on[6] = { 'A','k','t','i','v','\0' };
        char off[6] = { ' ',' ','-',' ',' ','\0' };

        char s_h[6] = { ' ',' ','-',' ',' ','\0' };
        char g_h[6] = { ' ',' ','-',' ',' ','\0' };
        char w_h[6] = { ' ',' ','-',' ',' ','\0' };
        char gr_h[6] = { ' ',' ','-',' ',' ','\0' };
        char b_h[6] = { ' ',' ','-',' ',' ','\0' };
        char r_h[6] = { ' ',' ','-',' ',' ','\0' };

        char s_t[6] = { ' ',' ','-',' ',' ','\0' };
        char g_t[6] = { ' ',' ','-',' ',' ','\0' };
        char w_t[6] = { ' ',' ','-',' ',' ','\0' };
        char gr_t[6] = { ' ',' ','-',' ',' ','\0' };
        char b_t[6] = { ' ',' ','-',' ',' ','\0' };
        char r_t[6] = { ' ',' ','-',' ',' ','\0' };

        if (first) {
          hintergrundfarbe = '0';
          textfarbe = 'F';
          strcpy_s(s_h, on);
          strcpy_s(w_t, on);
          first = false;
        }

        if (hintergrundfarbe == '0')      strcpy_s(s_h, on);
        else if (hintergrundfarbe == '8') strcpy_s(g_h, on);
        else if (hintergrundfarbe == 'F') strcpy_s(w_h, on);
        else if (hintergrundfarbe == '2') strcpy_s(gr_h, on);
        else if (hintergrundfarbe == '1') strcpy_s(b_h, on);
        else if (hintergrundfarbe == '4') strcpy_s(r_h, on);

        if (textfarbe == '0')      strcpy_s(s_t, on);
        else if (textfarbe == '8') strcpy_s(g_t, on);
        else if (textfarbe == 'F') strcpy_s(w_t, on);
        else if (textfarbe == '2') strcpy_s(gr_t, on);
        else if (textfarbe == '1') strcpy_s(b_t, on);
        else if (textfarbe == '4') strcpy_s(r_t, on);


        system("cls");

        printf("\n\n  Farben:");
        printf("\n  ==============================================");
        printf("\n  *Die Hintergrundfarbe und die Textfarbe k\x94nnen nicht gleich sein.");
        printf("\n   Nur eine Farbe kann Aktiv sein.");

        //Farben die zur Auswahl stehen (kann noch mehr dazu kommen)
        printf("\n\n  Hintergrundfarbe      |  Textfarbe                                ");
        printf("\n  ======================|=======================");
        printf("\n  Schwarz = 1  [%s]  |  Schwarz = 1  [%s]", s_h, s_t);
        printf("\n  Grau    = 2  [%s]  |  Grau    = 2  [%s]", g_h, g_t);
        printf("\n  Weiss   = 3  [%s]  |  Weiss   = 3  [%s]", w_h, w_t);
        printf("\n  Gr\x81n    = 4  [%s]  |  Gr\x81n    = 4  [%s]", gr_h, gr_t);
        printf("\n  Blau    = 5  [%s]  |  Blau    = 5  [%s]", b_h, b_t);
        printf("\n  Rot     = 6  [%s]  |  Rot     = 6  [%s]", r_h, r_t);
        printf("\n  ======================|=======================");

        printf("\n\n  Hintergrundfarbe (1) ");
        printf("\n  Textfarbe        (2)");
        printf("\n  Zur\x81""ck           (3)");

        printf("\n  (1/2/3): ");
        eingabe = _getch();
        if (eingabe == '1')
        {
          printf("\n  ==============================================");
          printf("\n\n  Hintergrundfarbe: ");
          eingabe = _getch();

          if (eingabe == '1') neue_hintergrundfarbe = '0';
          else if (eingabe == '2') neue_hintergrundfarbe = '8';
          else if (eingabe == '3') neue_hintergrundfarbe = 'F';
          else if (eingabe == '4') neue_hintergrundfarbe = '2';
          else if (eingabe == '5') neue_hintergrundfarbe = '1';
          else if (eingabe == '6') neue_hintergrundfarbe = '4';
          else if (eingabe != '1' && eingabe != '2' && eingabe != '3' && eingabe != '4' && eingabe != '5' && eingabe != '6') falsche_eingabe();

          if (neue_hintergrundfarbe != textfarbe) {
            hintergrundfarbe = neue_hintergrundfarbe;
            farbmatrix(hintergrundfarbe, textfarbe);
          }

          else if (neue_hintergrundfarbe == textfarbe) {
            printf("\n  *Die Hintergrundfarbe und die Textfarbe k\x94nnen nicht gleich sein.");
            system("timeout 1 >null");
            system("cls");
          }

        }
        else if (eingabe == '2') {
          printf("\n  ==============================================");
          printf("\n\n  Textfarbe: ");
          eingabe = _getch();

          if (eingabe == '1') neue_textfarbe = '0';
          else if (eingabe == '2') neue_textfarbe = '8';
          else if (eingabe == '3') neue_textfarbe = 'F';
          else if (eingabe == '4') neue_textfarbe = '2';
          else if (eingabe == '5') neue_textfarbe = '1';
          else if (eingabe == '6') neue_textfarbe = '4';
          else if (eingabe != '1' && eingabe != '2' && eingabe != '3' && eingabe != '4' && eingabe != '5' && eingabe != '6') falsche_eingabe();

          if (neue_textfarbe != hintergrundfarbe) {
            textfarbe = neue_textfarbe;
            farbmatrix(hintergrundfarbe, textfarbe);
          }
          else if (neue_textfarbe == hintergrundfarbe) {
            printf("\n  *Die Hintergrundfarbe und die Textfarbe k\x94nnen nicht gleich sein.");
            system("timeout 1 >null");
            system("cls");
          }

        }
        else if (eingabe == '3') farben = false;
        else if (eingabe != '1' && eingabe != '2' && eingabe != '3') falsche_eingabe();
      }
    }
    else if (eingabe == '2')
    {
      system("cls");
      logo();
      printf("\n\n");
      printf("      .@@@@@@@@@@@@@@@@@@.                                        .@@@@@@@@            \n");
      printf("      @                  @.                                    @@@@@@@@@@@@@           \n");
      printf("     @@                  @@.                                  @@@@@@@@@@@@@@@@         \n");
      printf("    @@                    @@                                 ,@@@@@@@@       @@        \n");
      printf("    @@                    &@                                @  @@@@'           @       \n");
      printf("    @ @@@@@@@    .@@@@@@@@ @.                             ,@                    @ ,@.  \n");
      printf("    @@   (o)      (O)     @@@                             @@ @@@@    /@@@@@.    @@  @  \n");
      printf("   .@@        ((           @@         Version 1.1         @@  (O)      (O)     .@@  @  \n");
      printf("   @@@  @@@@@@@@@@@@@@@    @@          x64-Debug          @        /           @@@.(.) \n");
      printf("       @@ ########## @@@                                  @       (@.          @@@     \n");
      printf("      @@@            @@@                                 .@@@@@@@@@@@@@@@@@@   @@,     \n");
      printf("      @@ ##________## @@@                                @@@@ ########## @@@@ .@@*     \n");
      printf("      @@@ '########'  @@@                                '@@@              @@@@@@*     \n");
      printf("      @@@             @@@           Clash Of Clans        @@@@ #########,@@@@@@@       \n");
      printf("                                       Quartett!           @@@@@@@@@@@@@@@@@@@         \n");
      printf("                                                             @@@@@@@@@@@@@@@@          \n");
      system("timeout 3 >null");
      printf("\n\n");
    }

    else if (eingabe == '3') {
      if (admin == true) {
        admin = false;
        printf("\n  Entwicklermodus Deativiert ");
        system("timeout 1 >null");
        system("cls");
      }
      else if (admin == false) {
        admin = true;
        printf("\n  Entwicklermodus Aktiviert ");
        system("timeout 1 >null");
        system("cls");
      }
    }
    else if (eingabe == '4') settings = false;
    else if (eingabe != '1' && eingabe != '2' && eingabe != '3' && eingabe != '4') falsche_eingabe();
  }
  return 0;
}

void farbmatrix(char hintergrundfarbe, char textfarbe)
{
  char SysPrint[20];

  sprintf_s(SysPrint, "color %c%c", hintergrundfarbe, textfarbe);
  system(SysPrint);
}



void falsche_eingabe()
{
  printf("\n  Falsche Eingabe ");
  system("timeout 1 >null");
  system("cls");
}

void verlieren()
{
  system("cls");

  printf("\n  ==================================");
  printf("\n\n  ------------VERLOREN------------");
  printf("\n  Sie verlieren diese Karte leider.");
  printf("\n\n  ==================================");
  Sleep(1500);
}

void gewinnen()
{
  system("cls");

  printf("\n  ==================================");
  printf("\n\n  ------------GEWONNEN------------");
  printf("\n  Sie gewinnen diese Karte.");
  printf("\n\n  ==================================");
  Sleep(1500);
}

void logo()
{
  printf("\n     ___  _             _             __     ___ _");
  printf("\n    / __\x5C| |  __ _  ___| |__     ___ / _|   / __\x5C | __ _ _ __  ___");
  printf("\n   / /   | | / _` / __ | '_ \x5C   / _ \x5C| |_  / /  | |/ _` | '_ \x5C/ __|");
  printf("\n  / /___ | |(  _| \x5C__ \x5C| | | |  |(_) | _| / /___| | (_| | | | \x5C__ \x5C ");
  printf("\n  \x5C____/ |_| \x5C__,_|___/|_| |_|  \x5C___/|_|  \x5C____/|_|\x5C__,_|_| |_|___/");
  printf("\n");
  printf("    .d88888b.                            888            888    888     \n");
  printf("   d88P   Y88b                           888            888    888     \n");
  printf("   888     888                           888            888    888     \n");
  printf("   888     888 888  888  8888b.  888d888 888888 .d88b.  888888 888888  \n");
  printf("   888     888 888  888     '88b 888P'   888   d8P  Y8b 888    888     \n");
  printf("   888 Y8b 888 888  888 .d888888 888     888   88888888 888    888     \n");
  printf("   Y88b.Y8b88P Y88b 888 888  888 888     Y88b. Y8b.     Y88b.  Y88b.   \n");
  printf("    'Y888888'   'Y88888 'Y888888 888      'Y888 'Y8888'  'Y888  'Y888  \n");
  printf("          Y8b                                                          \n\n");
}

void end()
{
  system("cls");

  printf("\n\n");
  printf("  oooooooooooo                   .o8           \n");
  printf("  `888'     `8                  '888           \n");
  printf("   888         ooo. .oo.    .oooo888   .d88b.  \n");
  printf("   888oooo8    `888P'Y88b  d88' `888  d8P  Y8b \n");
  printf("   888    '     888   888  888   888  88888888 \n");
  printf("   888       o  888   888  888   888  Y8b.     \n");
  printf("  o888ooooood8 o888o o888o `Y8bod88P'  'Y8888' \n\n\n");

  Sleep(700);
}