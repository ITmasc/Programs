
/*
	- Author: MASC
	- Programma che risolve semplici equazioni di primo grado.
	- equazione.h
*/

#ifndef EQUAZIONE_H
#define EQUAZIONE_H
#include <string>

class equazione
{
    
public:
    equazione();
    ~equazione();
    

    const char s_piu = '+';
    const char s_meno = '-';
    const char s_x = 'x';
    const char s_ug = '=';
    
    int num_x = 0;
    int num_n = 0;
    int toInt = 0;
    
	// Funzione utilizzata per verificare l'eguaglianza di due char o bool
    bool compare(bool isChar, bool isEq, int index, char sign, std::string eq);
	
	// Funzione utilizzata per eseguire la risoluzione dell'equazione
    float exe(std::string eq);
};

#endif // EQUAZIONE_H
