/*
	- Author: MASC
	- Programma che risolve semplici equazioni di primo grado.
	- equazione.cpp
*/

#include "equazione.h"
#include <string>
#include <iostream>

using namespace std;

equazione::equazione()
{

}


float equazione::exe(string eq){
	
     for (int i=0; i< eq.length()-2; i++){
         if(compare(true, false, i+1 , s_ug, eq)){
             
        // Controlla se è presente una x senza coefficiente e che quindi vale 1
       if ( compare(true, true, i+1 , s_x, eq)){        
        if (compare(true, true, i, s_piu, eq)){
            num_x++;
         // D  cout << "1) num_x++: " << num_x <<endl;
            }  else if (compare(true, true, i, s_meno, eq)){
            num_x--;
         // D  cout << "2) num_x--: " << num_x << endl;
       }
       }
            // Controlla se è presente un numero a singola o doppia cifra
     
           else if ((eq.at(i) == '+' and isdigit(eq.at(i+1))  and eq.at(i+2)!= 'x' and eq.at(i+3)!= 'x') ){  
            if (isdigit(eq.at(i+2))){
               
                if (i==0){
                    toInt= (eq.at(i+1) - '0');
                    num_n= (toInt*10) + (eq.at(i+2) - '0');
                   // cout << num_n << endl;
                } else{
                    toInt= (eq.at(i+1) - '0');
                num_n+= (toInt*10) + (eq.at(i+2) - '0');
                }
               // cout << num_n << endl;
             //   cout << "3-bis) num_n+=: " << num_n << endl;
               
            } else{
            num_n+= (eq.at(i+1) - '0');
       //     cout << "3) num_n+=: " << num_n << endl;
            
            }
        }  
        
        else if ((eq.at(i) == '-' and isdigit(eq.at(i+1)) and eq.at(i+2)!= 'x')){ 
            
             if (isdigit(eq.at(i+2))){
               
             
                if (i==0){
                    toInt= (eq.at(i+1) - '0') * (-1);
                    num_n= (toInt*10) + (eq.at(i+2) - '0') ;
                    cout << num_n << endl;
                } else{
                    toInt= (eq.at(i+1) - '0');
                num_n-= (toInt*10) + (eq.at(i+2) - '0');
                }
                
               
            } else{
            num_n-= (eq.at(i+1) - '0');
                                             
            
            }
         //   cout << "4) num_n-= " << num_n << endl;
        
        } 
        
        // Controlla se è presente una x con singolo o doppio coefficiente    +20+2x=0
        
          else if ((isdigit(eq.at(i+1)) and eq.at(i+2) == 'x' and eq.at(i) == '+')  
              or (isdigit(eq.at(i+1)) and eq.at(i) == '+' and isdigit(eq.at(i+2)) 
				and eq.at(i+3)== 'x' ) ){           
              
              if (isdigit(eq.at(i+2)) ){
               
              
                if (i==0){
                    toInt= (eq.at(i+1) - '0');
                    num_x= (toInt*10) + (eq.at(i+2) - '0');
                    
                } else{
                    toInt= (eq.at(i+1) - '0');
                num_x+= (toInt*10) + (eq.at(i+2) - '0');
                
                
                }
           
            //    cout << "5-bis) num_x+=: " << num_x << endl;
                //num_x+= n;
            } else {
            num_x+= (eq.at(i+1) - '0');
         //   cout << "5) num_x+=: " << num_x << endl;                                  
            
            }
        }else if ((isdigit(eq.at(i+1)) and eq.at(i+2)== 'x' and eq.at(i) == '-')
			
            or (isdigit(eq.at(i+1)) and eq.at(i) == '-' and isdigit(eq.at(i+2)) and eq.at(i+3)== 'x' )){
            
            if (isdigit(eq.at(i+2))){
               
              
                if (i==0){
                    toInt= (eq.at(i+1) - '0') * (-1);
                    num_x= (toInt*10) + (eq.at(i+2) - '0');
                    
                } else{
                    toInt= (eq.at(i+1) - '0');
                num_x-= (toInt*10) + (eq.at(i+2) - '0');
                
                
                }
                
            } else{
            num_x-= (eq.at(i+1) - '0');
                                       
            
            }
        //   cout << "6) num_x-=: " << num_x << endl;
        }
        
        
    }
	
 } 
    

    float ris = (float)num_n/(float)num_x;
	
    if(ris!=0.0)
     return ris*(-1) ;
   else
      return  ris;
    
}

bool equazione::compare(bool isChar, bool isEq, int index, char sign, std::string eq){
	
    bool result = false;
    if(isChar and isEq){
        
       if(eq.at(index) == sign)
        result = true;
        
    } else if (isChar and !isEq){
        if(eq.at(index) != sign)
        result = true;
    }
    
    else if (!isChar and isEq){
        if (isdigit(eq.at(index))){
            result = true;
        }
    } else {
         if (!isdigit(eq.at(index))){
            result = true;
        }
    } 

    return result;
}
equazione::~equazione()
{
}

