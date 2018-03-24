/******************************Definición de tipo de dato polinomio//*****************************************/
typedef struct{int grado; double coeficientes[100];} polinomio;
typedef struct{int longitud; double arreglo[100];} array;


/*****************************************Declaración de funciones*****************************************/
//1. Algoritmo de Horner en x-c
double horner(int grado, double coeficientes[], double x, double c=0);
long double horner(int grado, long double coeficientes[], long double x, double c=0);
double horner_completo(int grado, double coeficientes[], double x, double c=0);
long double horner_completo(int grado, long double coeficientes[], long double x, double c=0);

//2. Calcular la derivada n-ésima de un polinomio en un punto x0
double dif_x0(int grado, double coeficientes[], double x0, int orden=1);
long double dif_x0(int grado, long double coeficientes[], long double x0, int orden=1);

//3. Raíces de POLINOMIOS
array raices_racionales(int grado, double coeficientes[]);

//4. Algoritmo de Ordenamiento por inserción
array insercion(double arreglo[], int longitud);

/*****************************************Definición de funciones*****************************************/
//1.  Algoritmo de Horner en x-c
double horner(int grado, double coeficientes[], double x, double c){
  int k=0;
  double polinomio=0;

  //Algoritmo de Horner:
  polinomio=coeficientes[grado];
  for(k=(grado-1); k>=0; k--)
    polinomio=coeficientes[k]+((x-c)*polinomio);

  return polinomio;
}
long double horner(int grado, long double coeficientes[], long double x, double c){
  int k=0;
  long double polinomio=0;

  //Algoritmo de Horner:
  polinomio = coeficientes[grado];
  for(k = (grado-1); k>=0; k--)
    polinomio=coeficientes[k]+((x-c)*polinomio);

  return polinomio;
}

double horner_completo(int grado, double coeficientes[], double x, double c){
  int k=0;
  double q[grado+1];
  q[grado]=coeficientes[grado];
  for(k=grado-1;k>=0;k--)
    q[k]=coeficientes[k]+q[k+1]*x;
  return q[0];
}
long double horner_completo(int grado, long double coeficientes[], long double x, double c){
  int k=0;
  long double q[grado+1];
  q[grado]=coeficientes[grado];
  for(k=grado-1;k>=0;k--)
    q[k]=coeficientes[k]+q[k+1]*x;
  return q[0];
}

//2. Calcular la derivada n-ésima de un polinomio en un punto x0
double dif_x0(int grado, double coeficientes[], double x0, int orden){
  int k=0;
  double derivada[grado];

  //Obtiene la derivada del polinomio
  for(k = 1; k <= grado; k++)
    derivada[k-1]=coeficientes[k]*k;
  return horner(grado-1,derivada,x0);
}
long double dif_x0(int grado, long double coeficientes[], double x0, int orden){
  int k=0;
  double derivada[grado];

  //Obtiene la derivada del polinomio
  for(k = 1; k <= grado; k++)
    derivada[k-1]=coeficientes[k]*k;
  return horner(grado-1,derivada,x0);
}

//3. Raíces de POLINOMIOS
array raices_racionales(int grado, double coeficientes[]){
  int i = 0, k = 0;
    //construir las posibles raíces
    int factores_a0[100], factores_an[100];
    double posibles_raices[100];

    //iniciar los arreglos
    for(i = 0; i < 100; i++){ factores_a0[i]=0; factores_an[i]=0; posibles_raices[i]=0;}

    //tomar los coeficientes a0 y an
    int a0 = fabs((int)coeficientes[0]), an = fabs((int)coeficientes[grado]);

    //tomar los factores enteros de a0
    int longitud_factores_a0 = 0;
    for(k = a0; k >= 1; k--)
      if(a0 % k == 0)
        factores_a0[longitud_factores_a0++] = k;

    //tomar los factores enteros de an
    int longitud_factores_an = 0;
    for(k = an; k >= 1; k--)
      if(an % k == 0)
        factores_an[longitud_factores_an++] = k;

    //construir las posibles Raíces
    int j = 0;
    //recorremos ambos arreglos. Por cada factor de a0 tomamos cada factor de an y hacemos la división
    for (i = 0; i < longitud_factores_a0; i++)
      for(k = 0; k < longitud_factores_an; k++){
        posibles_raices[j++] = (double)factores_a0[i]/(double)factores_an[k];
        //cout<<j1<<": "<<factores_a0[i1]<<"/"<<factores_an[k1]<<"\n";
      }
    //OBSERVACIÓN: al finalizar ambos ciclos, el valor de j almacena la cantidad de posibles raíces racionales POSITIVAS.

    //Probar las posibles raíces racionales. Se utiliza el algoritmo de Horner
    array raices_racionales;

    int cont_raices = 0;
    //división sintética (algoritmo Completo de Horner). Probamos con cada valor posible y su negativo
    for(i = 0; i < j; i++){
      if(horner(grado, coeficientes, posibles_raices[i]) == 0)
        raices_racionales.arreglo[cont_raices++] = posibles_raices[i];
      if(horner(grado, coeficientes,-posibles_raices[i])==0)
        raices_racionales.arreglo[cont_raices++] = -posibles_raices[i];
    }
    raices_racionales.longitud = cont_raices;
    //ordenamos las raíces para eliminar las entradas repetidas.
    raices_racionales = insercion(raices_racionales.arreglo,raices_racionales.longitud);
    //quitamos los números que se repiten
    j=1; i=0;
    double aux = raices_racionales.arreglo[0];
    array ordenado;

    ordenado.arreglo[i] = aux;

    do{
      if(aux != raices_racionales.arreglo[j]){
        aux = raices_racionales.arreglo[j];
        ordenado.arreglo[++i]=aux;
      }
      j++;
    }while(j<raices_racionales.longitud);
    ordenado.longitud=i+1;
    return ordenado;
  }


  //4.  Algoritmo de Ordenamiento por inserción
  array insercion(double arreglo[], int longitud){
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

    array ordenado;
    ordenado.longitud=longitud;
    for(j=0; j < ordenado.longitud; j++)
      ordenado.arreglo[j] = arreglo[j];
    return ordenado;
  }
