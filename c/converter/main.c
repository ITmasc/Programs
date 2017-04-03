#include <stdio.h>

#ifdef _WIN32_WINNT
#define clear() system("cls")
#else
#define clear() system("clear")
#endif

void menu();
int menuSel();
int backMenu();

double celToFar(double *val, double *converted);
double celToK(double *val, double *converted);

double FarToCel(double *val, double *converted);
double FarToK(double *val, double *converted);

double kToCel(double *val, double *converted);
double kToFar(double *val, double *converted);

int main(int argc, char **argv)
{
    
    double converted=0;
    double val=0;
     start: 
    
	printf("Converter\n");
    menu();
    
    switch(menuSel()){
        case 1:
        printf("Insert value: ");
        scanf("%lf", &val);
        
        printf("%f", celToFar(&val, &converted));
        
        if(backMenu() == 121){
           clear();
        goto start;
        
        }
        break;
        case 2:
        printf("Insert value: ");
        scanf("%lf", &val);
        
        printf("%f",celToK(&val, &converted));
        break;
        case 3:
        printf("Insert value: ");
        scanf("%lf", &val);
        
        printf("%f",FarToCel(&val, &converted));
        break;
        case 4:
        printf("Insert value: ");
        scanf("%lf", &val);
        
        printf("%f",FarToK(&val, &converted));
        break;
        
        case 5:
        printf("Insert value: ");
        scanf("%lf", &val);
        
        printf("%f",kToCel(&val, &converted));
        break;
        case 6:
        printf("Insert value: ");
        scanf("%lf", &val);
        
        printf("%f",kToFar(&val, &converted));
        break;
    }
    
	return 0;
}


// Celsius

double celToFar(double *val, double *converted){
   
    *converted = 1.8 * *val + 32;

    return *converted;
}

double celToK(double *val, double *converted){
    
    *converted = *val + 273.15;

    return *converted;
}

// Fahreneit

double FarToCel(double *val, double *converted){
   
    *converted = (*val - 32) / 1.8;

    return *converted;
}

double FarToK(double *val, double *converted){
    
    *converted = (*val + 459.67) / 1.8;

    return *converted;
}

// Kelvin

double kToCel(double *val, double *converted){
    
    *converted = *val - 273.15;

    return *converted;
}

double kToFar(double *val, double *converted){
    
    *converted = (*val * 1.8) / 459.67;

    return *converted;
}

void menu(){
    
    const char *c[] = { "1. Celsius to Farheneit", "2. Celsius to Kelvin", "3. Fahreneit to Celsius",
                "4. Fahreneit to Kelvin", "5. Kelvin to Celsius", "6. Kelvin to Fahreneit"};
    
    for (int i=0; i< 6; i++)
    printf("%s\n", c[i]);
    
}

int menuSel(){
    int sel;
    
    printf("Make a choice: ");
    scanf("%d", &sel);
    
    return sel;
    
}

int backMenu(){
    
    char c;
    
    printf("\nBack to main menu? y/n");
    printf("\nYour answer is: ");
    scanf(" %c", &c);
    
    return c;
}
