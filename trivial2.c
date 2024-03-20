#include<stdio.h>
#include<string.h>
#define max_pregunta 250
#define max_respuesta 100

//En esta estructura se guarda el perfil del jugador, tenemos el nombre con un espacio de 100 de caracteres y la edad.
typedef struct 
{
  char nombre[100];
  int edad;
} Usuario;
void atomo(); 

/*
Esta función esta creada para saludar al jugador y comentarle en que consistirá el juego.
Leemos la variable "pausa" para asegurarnos de que le ha dado tiempo suficiente al usuario a leer el saludo, de esta manera evitamos hacer una llamada al sistema.
*/
void saludo(){
  char pausa;
  printf("Bienvenido usuario al trivial de física, aquí podrás medir tu conocimiento sobre física. Tu puntuación irá aumentando a medida que completes los diferentes niveles\n");
  printf("¿Creés que podrás superar el nivel más difícil?.\nPara continuar introduzca cualquier letra y pulse ENTER:\n");
  scanf("%c", &pausa);
  while (getchar() != '\n');

}

//Motramos el menú con las diferentes acciones que puede realizar un usuario.
void mostrar_menu(){
  printf("-------------------Trivial Lope de Vega----------------\n");
  printf("\t1. Iniciar Juego.\n");
  printf("\t\t2. Configuración del juego.\n");
  printf("\t\t\t3. Salir del juego.\n");
  printf("--------------------------------------------------------\n");
  printf("Introduce el número de la opción que deseas seleccionar.\n");
  
}

//Nos despedimos  del jugador antes de cerrar el programa.
void despido(){
  printf("------------------------------------\n");
  printf("Gracias por jugar, desde el equipo de desarrollo esperamos que le haya gustado  nuestro juego.\n");
  printf("Si tiene alguna sugerencia o comentario no dude en contactarnos.\n");
  printf("------------------------------------\n");
}

/*
Esta funcion tiene como entrada dos enteros llamados "min" y "max"
La salida es una variable de tipo entero llamada "opcion".
La función solicita al usuario que introduza un número, si el número se encuentra entre el mínimo y el máximo, que lo determinan las entradas, devuelve ese mismo número, en el caso de que no se encuentre entre los límites muestra un mensaje de error y vuelve a pedir otro número hasta que introduzac un número correcto.
*/
int validar_opcion(int min, int max){
  int opcion=0;
  scanf("%d", &opcion);
	if ((opcion < min) || (opcion > max)) {
    printf("Opción no válida. Por favor, introduzca una opción correcta.\n");
    return -1;
  } else {
    return opcion;
  }
}

/*
Esta función recibe un entero y no devuelve nada ya que lo que hace es imprimir un mensaje por pantalla con la puntuación obtenida.
*/
void mostrar_puntuacion(int puntuacion){
  printf("\n\n=============================================================\n");
  printf("¡Bien!, parece que has terminado con la dificultad elegida\n");
  printf("Puntuación : %d\n", puntuacion);
  printf("=============================================================\n\n");
}

/*
Esta función recibe el puntero de una variable de tipo Usuario, estructura definida anteriormente.
No devuelve nada ya que lo que hace es reemplazar los valores que tiene esa estructura por los que introduzca el usuario
*/
void creacrion_perfil(Usuario *persona){
  printf("Bienvenido al apartado donde podrás personalizar tu perfil y donde podrás elegir también el nivel de dificultad.\n");
  printf("Lo primero que necesito para crear tu perfil es tu nombre, porfavor introduce un nombre:\n");
  fgets(persona->nombre, sizeof(persona->nombre), stdin);
    while (getchar() != '\n');
  printf("Muy bien %s, ahora necesito tu edad, ¿cuantos años tienes?\n", persona->nombre);
  scanf("%d",&persona->edad);
  
}

/*
Es una función que no tiene entradas y de lo que se encarga es de mostrar los diferentes modos de dificultad y llamar a la función que valida la opción que elija el usuario, a esta función le pasa un mínimo y un máximo que se declara en esta misma función.
Devuelve un entero que representa la dificultad del juego elegido por el usuario.
*/
int mostrar_dificultad(){
  int dificultad, min=1,max=3;
  printf("------------------------------------------\n");
  printf("\t(1)Básico\n");
  printf("\t\t(2)Intermedio\n");
  printf("\t\t\t(3)Avanzado\n");
  printf("------------------------------------------\n");
  printf("Selecciona la dificultad del juego:\n");
  dificultad = validar_opcion(min, max);
  return dificultad;
}

/*
En esta función recibe tres parámetros:
1. un puntero que lo utilizamos para acceder al fichero con las preguntas
2. Otro puntero para acceder al fichero con las respuestas(La leemos como un entero)
3. El puntero que apunta a puntuación para poder modificar la puntuación del jugador.
No devuelve nada ya que ya que solo muestra por pantalla la pregunta con las posibles respuestas, a continuación pide el usuario que elija una de las opciones(1-4), comprueba si la respuesta es correcta, en el caso de se correcta, imprime un mensaje por pantalla de respuesta correcta y aumenta la puntuación, en el caso de ser falsa da imprime un mensaje de respuesta incorrecta  y no suma ni resta puntuación.
Esto se encuentra dentro de un bucle que dejará de ejecutarse cuando detecte que ha llegao al final del archivo
*/
void mostrar_preguntas_respuestas_i(FILE *archivo_preguntas,FILE *archivo_respuestas, int *puntuacion) {
    if (archivo_preguntas == NULL || archivo_respuestas == NULL) {
        printf("Error al abrir los archivos.\n");
        return;
    }
    char pregunta[max_pregunta];
    char respuestas[4][max_respuesta];
    int respuesta_correcta;
    printf("====== Que comniece el juego ======\n");
    while (fgets(pregunta, sizeof(pregunta), archivo_preguntas) != NULL) {
      printf("%s", pregunta);
      for (int i = 0; i < 4; i++) {
        fgets(respuestas[i], sizeof(respuestas[i]), archivo_preguntas);
        printf("%d) %s", i + 1, respuestas[i]);
      }
      fscanf(archivo_respuestas, "%d", &respuesta_correcta);
      int respuesta_usuario;
      printf("Ingrese su respuesta (1-4): ");
      scanf("%d", &respuesta_usuario);
      printf("|-----------------------|\n");
      if (respuesta_usuario == respuesta_correcta) {
        printf("|  Respuesta correcta!  |\n");
        *puntuacion += 10;
      } else {
        printf("| Respuesta incorrecta. |\n");
      }
      printf("|-----------------------|\n\n\n\n");
      while (getchar() != '\n');
    }
  fclose(archivo_preguntas);
  fclose(archivo_respuestas);
}

/*
Esta función tiene como entradas:
1. El modo seleccionado
2. El puntero de un boolean que se modifica en caso de que el usuario desee salir
3. La estructura antes mencionada
4. El puntero de la dificultad
5. El puntero de la puntuación para poder modificarla
Esta función se encarga de hacer las llamadas a funciones correspondientes al modo elegido por el usuario.
*/
void modos(int modo, int *salida, Usuario *persona, int *dificultad, int *puntuacion ){
  FILE *archivo_preguntas ;
  FILE *archivo_respuestas;
  switch(modo){
    case 1:
      *dificultad = mostrar_dificultad();
      switch (*dificultad)
      {
      case 1:
        printf("Modo básico activado!\n");
        archivo_preguntas = fopen("basico.txt", "r");
        archivo_respuestas = fopen("respuestas_correctas_basico.txt", "r");
        mostrar_preguntas_respuestas_i( archivo_preguntas, archivo_respuestas, puntuacion) ;
        break;
      case 2:
        printf("Modo intermedio activado!\n");
        archivo_preguntas = fopen("preguntas_intermedia.txt", "r");
        archivo_respuestas = fopen("respuestas_correctas_inter.txt", "r");
        mostrar_preguntas_respuestas_i( archivo_preguntas, archivo_respuestas, puntuacion) ;
        break;
      default:
        archivo_preguntas = fopen("avanzado.txt", "r");
        archivo_respuestas = fopen("respuestas_correctas_avanzado.txt", "r");
        printf("Modo avanzado activado!\n");
        mostrar_preguntas_respuestas_i( archivo_preguntas, archivo_respuestas, puntuacion) ;
    }
    mostrar_puntuacion(*puntuacion);
      fclose(archivo_preguntas);
      fclose(archivo_respuestas);
      break;
    case 2:
      creacrion_perfil(&(*persona));
      printf("%s\n",persona->nombre );
      printf("%d\n", persona->edad);
      *dificultad=mostrar_dificultad();
      printf("%d", *dificultad);
      break;
    default:
      *salida = 1;
  }
}

/*
Es la función principal del programa 
*/
int main(){
  saludo();
  Usuario persona;
  int  salida = 0, dificultad, puntuacion = 0, min=1, max=3;
  while (salida == 0)
  {
    int opcion = 0;
    mostrar_menu();
    while (opcion <= 0) {
    opcion = validar_opcion(min, max);
    }
    modos(opcion, &salida, &persona, &dificultad, &puntuacion);
  }
  despido();
  atomo();
  return 0;

}
/*
Es una función que imprime el dibujo de un átomo, es solamente para verlo y no afecta al funcionamiento del juego.
*/
void atomo(){
  printf("\n                           :==-+                   ");
  printf("\n                         :==---+=                  ");
  printf("\n             ...        -==    :==                 ");
  printf("\n           -====+=-:   ==-      =+                 ");
  printf("\n          :==    :-==-==:       ==.                ");
  printf("\n          -+-       .+=+-       -=:                ");
  printf("\n          +:=.      .==-==-  ..:=+=::---           ");
  printf("\n          :=+:      =+::-+=+++===+---+-=*=-.       ");
  printf("\n            ==.   :=+++=--:-==: =+    :..:==.      ");
  printf("\n            .=+-=+=++.      .-=-+=        :==      ");
  printf("\n           .-=++-.-=-  :=++=. :===       .==.      ");
  printf("\n         :=+=:.==:++  :+====+  -=+-     -==.       ");
  printf("\n      .-=+-.    ====  :+====+  ++-== .-==-         ");
  printf("\n      =:--       +==.  -+++=. :=- -+++=:           ");
  printf("\n      -+-        =+==-        ++==+-++.            ");
  printf("\n      :==.       += -==:.:--=++=-:  =---           ");
  printf("\n       :=+=------++--=++++---++     :===           ");
  printf("\n          .:----=+=-::.:-=-.==:       ==           ");
  printf("\n                ===      .-+=+        --:          ");
  printf("\n                ==+.      .=+==-:.    --:          ");
  printf("\n                 +=      :==  :--+=---==           ");
  printf("\n                 ==.    -==       ::::.            ");
  printf("\n                 .+=. :=+-                         ");
  printf("\n                  .=++=-.                    \n");
}