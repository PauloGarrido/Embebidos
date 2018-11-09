//Librerias con los datos de la matriz
#include"datos_entrenamiento.h"
#include"datos_test.h"
//-------------****---------------
//Variables
int col = 0;
int fil = 0;
float fil1 = 0;
float fil2 = 0;
float fil3 = 0;
float res1 = 0;
float res2 = 0;
float res3 = 0;
float distancia = 0;
float distancia1 = 0;
float distancia2 = 0;
float distancia3 = 0;
float num1 = 1000;
float num2 = 1000;
float num3 = 1000;
int cx = 0;
//-------------****---------------

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (cx == 0) {
    Serial.println("--------------------------");
    distancia_1();
    Serial.println(res1);//El numero al cual correcponde
    Serial.println(num1);//La distancia
    Serial.println(fil1);//En cual fila esta
    Serial.println("--------------------------");
    distancia_2();
    Serial.println(res2);//El numero al cual correcponde
    Serial.println(num2);//La distancia
    Serial.println(fil2);//En cual fila esta
    Serial.println("--------------------------");
    distancia_3();
    Serial.println(res3);
    Serial.println(num2);
    Serial.println(fil3);//En cual fila esta
    Serial.println("--------------------------");
  }
  cx = 1;
}

void distancia_1() {
  for (; fil < 120; fil++) {
    distancia = sqrt( pow(matriz[fil][0] - prueba[0][0], 2) +
                      pow(matriz[fil][1] - prueba[0][1], 2) +
                      pow(matriz[fil][2] - prueba[0][2], 2) +
                      pow(matriz[fil][3] - prueba[0][3], 2));
    if (distancia < num1) {
      num1 = distancia;
      res1 = matriz[fil][4];
      fil1 = fil;

    }
  }
  fil = 0;
  distancia = 0;
}

void distancia_2() {
  for (; fil < 120; fil++) {
    distancia = sqrt( pow(matriz[fil][0] - prueba[0][0], 2) +
                      pow(matriz[fil][1] - prueba[0][1], 2) +
                      pow(matriz[fil][2] - prueba[0][2], 2) +
                      pow(matriz[fil][3] - prueba[0][3], 2));
    if (distancia < num2 && distancia > num1 ) {
      num2 = distancia;
      res2 = matriz[fil][4];
      fil2 = fil;

    }
  }
  fil = 0;
  distancia = 0;

}

void distancia_3() {
  for (; fil < 120; fil++) {
    distancia = sqrt( pow(matriz[fil][0] - prueba[0][0], 2) +
                      pow(matriz[fil][1] - prueba[0][1], 2) +
                      pow(matriz[fil][2] - prueba[0][2], 2) +
                      pow(matriz[fil][3] - prueba[0][3], 2));
    if (distancia < num3 && distancia > num2) {
      num3 = distancia;
      res3 = matriz[fil][4];
      fil3 = fil;
    }
  }
  fil = 0;
  distancia = 0;
}
