/*
	- Author: MASC
	- Programma che risolve semplici equazioni di primo grado.
	- Main.cpp
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <equazione.h>

using namespace std;

    string eq;
    int num_x=0;                           
    int num_n=0;
    int nu;
    
    void backToMenu();
	
int main()
{
    
    start:
	cout << "------------ Programma per risolvere semplici equazioni di primo grado. ------------- \n";
    cout << "------------------------------------------------------------------------------------- \n";
    cout << "                                 | REGOLE DA SEGUIRE |\n";
    cout << "------------------------------------------------------------------------------------- \n";
    cout << "1) Apporre SEMPRE il segno della 'x' o dei numeri, prima degli stessi, ANCHE al primo.\n";
    cout << "2) Il contenuto dell'equazione deve essere SEMPRE e SOLO presente nel primo membro.   \n";
    cout << "3) I calcoli permessi sono: ADDIZIONE e SOTTRAZIONE\n";
    cout << "ESEMPI: '+x+90x-30=0' / '+3+8x+2=0'\n";
    cout << "-------------------------------------------------------------------------------------\n\n";
    
    cout << "Inserire equazione: ";
    cin >> eq;
    
    equazione r;
    if (r.compare(true, true, 0 , r.s_piu, eq) or r.compare(true, true, 0 , r.s_meno, eq)){
     
     cout << "x= " << r.exe(eq) << endl;
     
    } else {
         cout << "Rileggi le regole con attenzione e riprova." << endl;
    }
       
       
    char scelta;
    fflush(stdin);
    printf("\nVuoi tornare al menu principale? y/n\n");
    scanf("%c", &scelta);
    
    if (scelta=='y'){
		
        system("cls");
        goto start;
		
    } else {		
        exit(0);
    }
       system("pause");
	return 0;
}
