#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void calcular_ecuacion(int min, int max);
void calcular_ecuacion_dos (int min, int max);
void calcular_ecuacion_tres (int min, int max);
void saludo();
void menu();

int main(){
    int numerox, numeroy;
    int min = -100, max = 100;

    calcular_ecuacion(min, max);
    /*x = 2x + 21;
    * -1x = 21
    * x= (21/-1) 
    */
}

//ax = bx + c
void calcular_ecuacion (int min, int max) {
    int num1, num2, num3;
    printf("introduce un numero\n");
    scanf("%d",&num1);
    srand(time(0));
    //num1 = x;
    //num2 = y
    num2 = rand() % (max - min + 1) + min;
    num3 = rand() % (max - min + 1) + min;
    
    float calculo = num1 - (num2);
    float total = num3 / calculo;  
    printf("El resultado de la ecuacion %dx = %dx + %d es x = %f", num1, num2, num3, total);



}

void calcular_ecuacion_dos (int min, int max) {
    int num1, num;
    printf("introduce un numero distinto de 0\n");
    scanf("%d",&num1);
    srand(time(0));
    //num1 = x;
    //num2 = y
    num = rand() % (max - min + 1) + min;
    
    float calculo = num / num1;

    printf("El resultado de la ecuacion %dx = %d es x = %f", num1, num, calculo);



}

void calcular_ecuacion_tres (int min, int max) {
    //ax = num1 bx=num2 c=num3 d=num4
    int num1, num2, num3, num4, num;
    printf("introduce un numero\n");
    scanf("%d",&num1);
    printf("introduce otro\n");
    scanf("%d",&num2);
    srand(time(0));
    
    num3 = rand() % (max - min + 1) + min;
    num4 = rand() % (max - min + 1) + min;
    
    float calculo_a_b = num1 + num2;
    float calculo_c_d = num3 + num4;
    float total = calculo_c_d / calculo_a_b;  
    printf("El resultado de la ecuacion %dx %dx = %d + %d es x = %f", num1, num2, num3, num4, total);
}

void saludo(){
    printf("\n----------------------------------------------------");
    printf("\nBienvenido usuario a la calculadora de ecuaciones.");
    printf("\n-----------------------------------------------------");
}


void menu(){
    printf("\n1. ax = bx + c");
    printf("\n2. ax = b");
    printf("\n3. ax + bx = c + d");
    printf("\n4. Salir del programa.");
    printf("\nIntroduce una opcion:");
}

int comprobar_numero(int *num, int min_valido){
    printf("Introduce un dato\n");
    do{
        scanf("%d", num);
        if(num == min_valido){
            printf("El valor %d debe de ser distinto de %d. Introduce uno nuevo: \n", num, min_valido);
        }else{
            printf("DATO CORRECTAMENTE INTRODUCIDO\n");
        }
    }while(num);
}