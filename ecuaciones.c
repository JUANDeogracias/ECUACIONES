#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void calcular_ecuacion(int min, int max);
int main(){
    int numerox, numeroy;
    int min = -100, max = 100;

    calcular_ecuacion(min, max);
    
    /*x = 2x + 21;
    * -1x = 21
    * x= (21/-1) 
    */
}

void calcular_ecuacion (int min, int max) {
    int num1, num2, num;
    printf("introduce un numero\n");
    scanf("%d",&num);
    srand(time(0));
    //num1 = x;
    //num2 = y
    num1 = rand() % (max - min + 1) + min;
    num2 = rand() % (max - min + 1) + min;
    
    float calculo = num1 - (num2);
    float total = num / calculo;  
    printf("El resultado de la ecuacion %dx = %dx + %d es x = %f", num1, num2, num, total);



}

