/* Con el criterio del algoritmo k-nn planteado. Realice un método que permita seleccionar el valor el k.
    De esta forma su sistema será flexible. *Suba su método comentado al github de forma individual.
    ejemplo. int knn (int k){ // estructura return etiqueta. } // puede tener los parametros que desee su rutina.
*/
//Librerias con los datos de la matriz
#include"datos_entrenamiento.h"
#include"datos_test.h"
//-------------****---------------
//Variable
int col = 0;
int fil = 0;
float distancia = 0;
float mz[120][4];
int ax = 0;
float distancia1 = 0;
float clase = 0;
int numvecinos=3;

void setup() {
  Serial.begin(9600);
}

void loop() {
    matriz1();
}

void matriz1() {
  for (; fil < 120; fil++) {
    distancia = sqrt( pow(matriz[fil][0] - prueba[0][0], 2) +
                      pow(matriz[fil][1] - prueba[0][1], 2) +
                      pow(matriz[fil][2] - prueba[0][2], 2) +
                      pow(matriz[fil][3] - prueba[0][3], 2));
    mz[fil][0] = distancia;
    mz[fil][1] = matriz[fil][4];
  }
  for (int i = 0; i < 120; i++) {
    for (int j = i + 1 ; j < 120 ; j++) {
      if (mz[i][0] > mz[j][0]) {
        distancia1 = mz[i][0];
        clase = mz[i][1];
        mz[i][0] = mz[j][0];
        mz[i][1] = mz[j][1];
        mz[j][0] = distancia1;//Distancia
        mz[j][1] = clase;//Clase Flor
      }
    }
  }
  Serial.println("1=iris_setosa;2=iris_versicolor;3=iris_virginica");
  for(int k=numvecinos;k<0;k--){
    Serial.println(mz[k][1]);
  } 
}
