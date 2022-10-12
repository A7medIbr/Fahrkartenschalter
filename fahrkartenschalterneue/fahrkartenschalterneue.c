/*********************************************************************************************************************************
Datum:				20.02.2021
Autor:				Ahmed Ibrahim
Kurzbeschreibung:	Das Programm soll Fahrkartenbestellung ausgeben
Nur damit Nader es kapiert!
**********************************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#define  MAXIMALE_PERSONEN 5
#define  MAXIMALE_STADTNAME 20


//=========Funktions-Prototypen ==========================================================================================================================
int   eingabeMenge();                           // funktion um die Personzahl einzugeben und zuueberpruefen
int   pruefeGeldbetraege(float geldbetrag);     // funktion um die eingegbene Geldstueck zuueberpruefung
float preisGeber();                           // funktion um die Menuauswahl auszugeben and der richtige preis zuermittlen  
float bezahlen(float zuZahlen);                 // funktion um die Bezahlvorgang durchzufuehren und ueberpruefung
void ausgabeTicket(int intMenuauswahl ,int intMenge);   // funktion um die Fahrschein auszugeben 
char stadName(int intMenuauswahl);
void  FlashStandardInput(void);	               //diese Funktion räumt den Buffer
//==========Hauptprogramm =====================================================================================================================================
int main()
{
	printf("===============================================================\n");
	printf("Herzlich willkommen am Fahrkartenschalter Hauptbahnhof Hamburg!\n");
	printf("===============================================================\n\n");

	int intMenuauswahl = 0, intMenge = 0;                      //Deklaration von variablen 
	float floPreis = 0, floZuzahlen = 0, floGezahlt = 0;
	char* stadtname = 0;


	floPreis = preisGeber();                         //floPreis bekommt jetzt den wert von der Funktion preisGeber
	intMenge = eingabeMenge();
	floZuzahlen = floPreis * intMenge;              //Der zu zahlender Gesamtbetrag ergibt sich aus Ticket Preis mal Personanzahl
	floGezahlt = bezahlen(floZuzahlen);

	if (floGezahlt == floZuzahlen)                //falls der gezahlte Beitrag gleich den zuzahlende Beitrag 
	{
		ausgabeTicket( intMenuauswahl, intMenge);    //aufraufe der ausgabeGetraenke funktion
		printf("\n\nVielen Dank fuer Ihre Buchung.\n");  //alles oki, gibt das aus!
		printf("\n\nWir wuenschen Ihnen eine gute Reise!\n");
		if (intMenge == 1)                   //Dient der Ausgabe,ob einzahln oder mehrzahl von Fahrkarten 
		{
			printf("\n\nIhre Fahrkarte wird gedruckt!\n");
		}
		else
		{
			printf("\n\nIhre Fahrkarten werden gedruckt!\n");
		}
	}
	else if (floGezahlt > floZuzahlen)    //falls der bezahlt Betrag höhe als der zu zahlende Betrag dann soll Rückgeld ermittelt und ausbezahlt werden
	{
		float floRueckgeld = floGezahlt - floZuzahlen;
		ausgabeTicket( intMenuauswahl,  intMenge);    //aufraufe der ausgabeGetraenke funktion
		printf("\n\nVielen Dank fuer Ihre Buchung.\n");
		printf("\n\nWir wuenschen Ihnen eine gute Reise!\n");
		if (intMenge == 1)
		{
			printf("\n\nIhre Fahrkarte wird gedruckt!\n");
		}
		else
		{
			printf("\n\nIhre Fahrkarten werden gedruckt!\n");
		}
		printf("\n\nIhre Rueckgeld betraegt:%.2f\n", floRueckgeld); //Ausgabe des Rückgeldbetrags

	}
	else  //falls 0 eingegebn wird die Transaktion abgebrochen
	{
		printf("\n\nBezahlvorgang abgebrochen.\n");
		printf("Ausgabe von %.2f Euro.\n", floGezahlt);
	}

	return 0;
}
//===============EINGABEMENGE===================================================================================================================================
int eingabeMenge()
{
	int intMenge = 1;
	do
	{
		printf("\n---Mengenauswahl--- ");
		printf("\nBitte geben Sie  die Anzahl der Fahrpersonen ein (maximal 5): ");
		scanf_s("%d", &intMenge);    //Person Menge eingabe von den kunden entnehmen 
		FlashStandardInput();        //diese Funktion räumt den Buffer, falls der Benutzer z.b eine leere Zeile eingibt 
		if (intMenge > MAXIMALE_PERSONEN || intMenge < 1)  //falls die eingegeben Zahlmenge gößer als die 5 oder kleiner als 1 ist dann Fehler Meldung ausgeben
			printf("Sie haben die maximale Personenzahl ueberschrieten!Bitte geben sie ernuet ein:");

	} while (intMenge > MAXIMALE_PERSONEN || intMenge < 1);	//die Schleife läuft bis die Bedingung erfüllt ist

	return intMenge;   // Menge wird zurückgegeben

}
//===============PREIS===================================================================================================================================
//hier soll den Preis ermitellt werden
float preisGeber()
{
	float floPreis;
	int intMenuauswahl = 0;
	
	// erstmal bekommet der Kunde, die Auswahlliste 
	do
	{
		printf("---Destinationsauswahl---\n\n");
		printf("Bitte Waehlen Sie eine Zieldestination aus:\n");
		printf("1) Berlin   (75,00 Euro)\n");
		printf("2) Muenchen (125,00 Euro)\n");
		printf("3) Kassel   (70,00 Euro)\n");
		printf("4) Koeln    (65,00 Euro)\n");
		printf("5) Bremen   (30,00 Euro)\n");
		printf("6) Kiel     (25,00 Euro)\n");
		printf("Geben sie 1, 2, 3, 4, 5 oder 6 ein: ");
		scanf_s("%d", &intMenuauswahl);  // intMenuauswahl wird vom Buntzer eingespeisst
		FlashStandardInput();
		//nachdem auswahl der Destination, wird die richtige Preis ermittelt
		switch (intMenuauswahl)
		{
		case 1: floPreis = 75, 00; break;
		case 2: floPreis = 125, 00; break;
		case 3: floPreis = 70.00; break;
		case 4: floPreis = 65.00; break;
		case 5: floPreis = 30.00; break;
		case 6: floPreis = 25.00; break;
		default:
			printf("Diese Stadt fahren wir leider nich an,bitte treffe eine andere Auswahl!\n");// Fehlermeldung im Falle ungültige Eingabe
		}
	} while (intMenuauswahl > 6 || intMenuauswahl < 1);//die Schleife läuft bis die gültige EIngabe 1,2 oder 3 eingetippt wurde.

	return floPreis;  // Preis wird zurückgegeben
}
//===============BEZAHLVORGANG===================================================================================================================================
// hier soll die Bezhalvorgang durchgeführt, dabei werden die Summen verglichen
float bezahlen(float zuZahlen)
{
	printf("\n--- Bezahlvorgang ---\n");
	printf("\nBezahlvorgang abbrechen mit 0\n");
	float einzahlen, gezahlt = 0.0;
	do
	{
		float fehlende = zuZahlen - gezahlt; //Der offene diffrenz Betrag wird ermittelt
		printf("\nEs fehlen noch %.2f Euro.", fehlende);
		printf("\nBitte zahlen Sie den fehlenden Geldbetrag ein: ");
		scanf_s("%f", &einzahlen);
		FlashStandardInput();
		// Abbruch pruefen
		if (einzahlen == 0) //um die Zahlvorgang abzubrechen
		{
			break;
		}
		// eingeworfenen Betrag anrechnen
		if (pruefeGeldbetraege(einzahlen))
		{
			gezahlt += einzahlen;
		}
		else
		{
			printf("\nIhr Geldbetrag ist ung\x81ltig.");
		}

	} while (gezahlt < zuZahlen);

	return gezahlt;
}
//===============GELD PRUEFEN===================================================================================================================================
/*	prueft Geldbeträge auf Gueltigkeit(gültig sind 0.5 ,1 , 2, 5, 10, 20, 50, 100, 200 EURO)
	Parameter:  	entpricht eingeworfenem Geldstueck
	Return-Value:	1, gueltige Betrag
					0, falsche  Betrag
*/
int pruefeGeldbetraege(float geldbetrag)
{
	// Geldbetrag in ganze Zahl umrechnen, also in Cent.
	// Da die case Anweisung nicht mit floats arbeiten kann.
	int cent = (int)(geldbetrag * 100);
	switch (cent) {
	case 5:		return 1;
	case 10:	return 1;
	case 20:	return 1;
	case 50:	return 1;
	case 100:	return 1;
	case 200:	return 1;
	case 500:	return 1;
	case 1000:	return 1;
	case 2000:	return 1;
	case 5000:	return 1;
	case 10000:	return 1;
	case 20000:	return 1;
	default:	return 0;
	}
}
//===============AUSGABE GETRAENKE===================================================================================================================================
void ausgabeTicket(int intMenuauswahl, int intMenge)
{
	if (intMenge == 1)
	{
		printf("\nIhre Destination nach %s wurde fuer %d Person gebucht.",stadtName(stadtname),intMenge);
	}

	else
	{
		printf("\nIhre Destination wurde fuer %d Personen gebucht.", intMenge);
	}
}


char stadName(int intMenuauswahl)
{
	char* stadtname = 0;
	printf("\n---Fahrkartenausgabe ---\n");

	if (intMenuauswahl == 1) {
		stadtname = "Berlin";
	}
	else if (intMenuauswahl == 2) {
		stadtname = "Muenchen";
	}
	else if (intMenuauswahl == 3) {
		stadtname = "Kassel";
	}
	else if (intMenuauswahl == 4) {
		stadtname = "Koeln";
	}

	else if (intMenuauswahl == 5) {
		stadtname = "Bremen";
	}
	else if (intMenuauswahl == 6) {
		stadtname = "Kiel";
	}
	return stadtname;
}

//================FLASH STANDARD INPUT=============================================================================================================================
void FlashStandardInput(void)											// Hilfsfunktion für die Löschung des Eingabepuffers
{
	int intCharacter;
	while ((intCharacter = getchar()) != '\n' && intCharacter != EOF); // ansonsten rewind (stdin)
}
