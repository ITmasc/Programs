#include <stdio.h>

void menu();
int menuSel();
double celToFar(double *val, double *converted);
double FarToCel(double *val, double *converted);

int main(int argc, char **argv)
{
    
    double converted=0;
    double val=0;
    
	printf("Converter\n");
    menu();
    
    switch(menuSel()){
        case 1:
        printf("Insert value: ");
        scanf("%lf", &val);
        
        printf("%f", celToFar(&val, &converted));
        break;
        case 2:
        printf("Insert value: ");
        scanf("%lf", &val);
        
        printf("%f",FarToCel(&val, &converted));
        break;
    }
    
	return 0;
}

double celToFar(double *val, double *converted){
   
    *converted = 1.8 * *val + 32;

    return *converted;
}

double FarToCel(double *val, double *converted){
   
    *converted = (*val - 32) / 1.8;

    return *converted;
}

void menu(){
    
    char *c[] = { "1. Celsius to Farheneit", "2. Farheneit to Celsius"};
    
    for (int i=0; i< 2; i++)
    printf("%s\n", c[i]);
    
}

int menuSel(){
    int sel;
    
    printf("Make a choice: ");
    scanf("%d", &sel);
    
    return sel;
    
}
