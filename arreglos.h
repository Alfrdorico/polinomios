/******************************Definición de tipo de dato polinomio//*****************************************/
typedef struct{int longitud; double arreglo[100];} arreglo;

/*****************************************Declaración de funciones*****************************************/
//1. Algoritmo de Ordenamiento por inserción
arreglo insercion(double arreglo[], int longitud);

/*****************************************Definición de funciones*****************************************/
//1.  Algoritmo de Ordenamiento por inserción
arreglo insercion(double arreglo[], int longitud){
  //La variable pivote indica la posición en el arreglo del elemento que estamos comparando para mover.
  int pivote = 1;
  //La variabe j nos lleva desde la posición del Pivote hacia atrás, hasta la primera posición.
  int j = 0;
  //la variable aux es el valor en la posición del pivote. Lo estamos comparando para saber si haremos un cambio o no.
  double aux = 0;

  //Mientras haya elementos por comparar
  while (pivote < longitud){
    //tomamos el elemento a comparar.
    aux = arreglo[pivote];
    //empezamos a comparar con los elementos anteriores:
    j=1;
    //si el elemento en la posición del pivote es menor que el j-ésimo anterior
    //recorre el elemento j-ésimo anterior una posición a la derecha
    while (aux < arreglo[pivote-j] && pivote-j>=0) {
      arreglo[pivote-(j-1)]=arreglo[pivote-j];
      //pasa al siguiente elemento a la derecha y repite este proceso
      j++;
    }
    //cuando haya terminado de recorrer los menores, pone en la última posición libre el valor de la posición del pivote
    arreglo[pivote-(j-1)] = aux;
    pivote++;
  }

  arreglo ordenado;
  ordenado.longitud=longitud;
  for(j=0; j < ordenado.longitud; j++)
    ordenado.arreglo[j] = arreglo[j];
  return ordenado;
}
