
/*
	- Author: MASC
	- Programma che esegue conversioni in decimale/binario
	- main.cpp
*/

#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <cstdlib>
#include <Windows.h>

using namespace std;

string numero;
int num, c;
char * binario;
bool err = false;

void da_dec_a_bin(int numero, char binario[]);
int da_bin_a_dec(string numero);
bool ripeti();

int main(){

    start: 
	cout << "1. Convertire decimale a binario\n;";
	cout << "2. Convertire binario a decimale\n";
	cout << "----------------------------------------\n";
	
	cin >> num;
	
	system("cls");
	
	switch (num){
		case 1:
		c=7;
		cout << "Inserisci numero in forma decimale: ";
		cin>>num;
		
		numero=num;
        
        binario = new char[numero.length()];
		
        cout << "Il corrispettivo valore in binario e': " ; 
		da_dec_a_bin(num, binario); 
		cout << "\n--------------------------------------\n";
	
	if (ripeti()){
        system("cls");
        goto start;   
    }
	break;
	case 2:
    
    c=7;
    num=0;
    do{
        if(err)
            Sleep(2000);
            system("cls");
			
	cout << "Inserire numero in binario: ";
	cin >> numero;
    
    for (c=0; c< numero.length(); c++){
       
        if(numero.at(c)!= '1' or numero.at(c)!= '0'){
            err=false;
        } else
            err=true;
    }
    
    if(numero.length()==8 and !err){
        err= false;
        
        cout << "Il corrispettivo in decimale e': ";
		da_bin_a_dec(numero);
		cout << "\n-------------------------------------\n";
        
        } else {
            err=true;
            cout << "Un numero binario deve essere formato da 8 cifre, di soli 0-1.\n";
        }
		
    }while(err);
	
    if (ripeti()){
        system("cls");
        goto start;       
    }
	break;	
	}
       
	return 0;
}

int da_bin_a_dec(string numero){
    int esp=0;
    c=7;
    do{
        if (numero.at(c)== '1'){
            num+= pow(2.0, esp);
		}
        esp++;
		c--;
        
	} while(c>=0);
	
    return num;
    
    }
    
void da_dec_a_bin(int numero, char binario[]){
    do{
		if (num%2!=0){
			binario[c]= '1';
		} else {
			binario[c]='0';
		}
		num/=2;
		c--;
	} while(c>=0);
	for (c=0 ; c<=7; c++){
	cout << binario[c];
	}
    delete binario;
}

bool ripeti(){
    bool b = false;
    char s;
    cout << "Digitare 'm' per ritornare al menu principale o 'e' per uscire.\n";
    cin >> s;
    if (s=='m'){
        b= true;
    } else {
        b=false;
    }           
           return b;
}