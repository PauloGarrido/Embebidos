#include "baseexamen.h"
// Definicion de matrices de CNN

float matriz_s [60][5];//Datos validos
float matriz_d [90][5];//Datos de desecho
float stor [15][5];//Datos de desecho
int col = 0; //Variable de recorrido de columnas
int fil; //Variable de recorrido de filas
float prom = 0; //Variable de promedio
float suma = 0;
int col_s = 0; //Variable para matriz s
int fil_s = 0; //Variable para matriz d
int col_d = 0;
int fil_d = 0;
int etiq = 1;
float dist = 0;
float dist_total;
float dist_mayor = 2000;
float label;
int e1 = 0;
int e2 = 0;
int e3 = 0;
int mnew = 0;
int on = 0;
int s = 0;
int d = 0;
int i = 0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  if (on == 0) {
    etiquetas();
    datos();
    cnn();
  }
  on = 1;
}

void cnn() {
  for (; fil < 75; fil++) {
    for (; fil_s < 3; fil_s++) {
      for (; col_s < 4; col_s++) {
        dist = dist + pow(matriz[fil][col_s] - matriz_s[fil_s][col_s], 2);
      }
      dist_total = sqrt(dist);
      if (dist_total < dist_mayor) {
        dist_mayor = dist_total;
        label = matriz_s[fil_s][4];
      }//end if
      dist = 0;
      col_s = 0;
    }//end for fil_s
    fil_s = 0;
    dist_mayor = 2000;
    if (label == matriz[fil][4]) {
      Serial.print(fil);
      Serial.print(":");
      Serial.println('D');

    }
    else {
      Serial.print(fil);
      Serial.print(":");
      Serial.println('S');
      stor[fil][0] = matriz[fil][0];
      stor[fil][1] = matriz[fil][1];
      stor[fil][2] = matriz[fil][2];
      stor[fil][3] = matriz[fil][3];
      stor[fil][4] = matriz[fil][4];
    }

  }

  if (s == 1)
  {
    for (; d < 10; d++)
    {
      Serial.println("Nueva Matriz: ");
      Serial.print(stor[d][0]);
    }
    s = 0;
  }
}

void datos() {
  for (; etiq < 4; etiq++) {
    for (; col < 4; col++) {
      for (fil = i; fil < 25 * etiq; fil++) {
        suma = suma + matriz[fil][col];
      }
      prom = suma / 25;
      matriz_s[etiq - 1][col] = prom; //Almacenar promedios en matriz_s
      Serial.println(prom);
      suma = 0;
      fil = 0;
    }
    col = 0;
    i = 25 * etiq;
  }
  col = 0;
  fil = 0;
  for (; fil < 3; fil++) {
    matriz_s[fil][4] = fil + 1; //Llenar etiquetas en matriz_s
    for (; fil < 3; fil++) {
      for (; col < 4; col++) {
        Serial.print(matriz_s[fil][col]);
        Serial.print(',');
      }
      Serial.println(    );
      col = 0;
    }
  }
  fil = 0;
}

void etiquetas() {
  for (; mnew < 75; mnew++) {
    if (matriz[mnew][4] == 1) {
      e1++;
    }
    if (matriz[mnew][4] == 2) {
      e2++;
    }
    else {
      e3++;
    }
  }
  Serial.println("Etiqueta 1,2,3: ");
  Serial.println(e1);
  Serial.println(e2);
  Serial.println(e3);
}
