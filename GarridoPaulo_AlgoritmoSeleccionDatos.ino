#include "datos_entrenamiento.h"

float suma = 0, rend=0, acier=0;
int col = 0; //Variable de recorrido de columnas
int fil = 0, fil_n = 0; //Variable de recorrido de filas
int on = 0;
int cont = 0;
int etiq = 0;
int aux = 0;
int i = 0; //Variable auxiliar
int j = 0; //Variabel auxiliar
float matriz_u[] = {};
float matriz_n [] = {};
float matriz_p[30][5];
float matriz_nueva[30][5];
float divis = 0;
float prom1 = 0; //Variable de promedio
float dist1 = 0;
float dist_mayor = 0;
float dist_total = 2000;
float total = 0;
float result = 0;


void setup() {
  Serial.begin(9600);
}

void loop() {

}

float knn_datos(float lim1, float lim2) {
  if (on == 0) {
    for (; etiq < 4; etiq++) {
      for (; col < 4; col++) {
        for (fil = 0; fil < 40 * etiq; fil++) {
          suma = suma + matriz[fil][col];
          cont++;
        }
        prom1 = suma / cont;
        matriz_p[etiq - 1][col] = prom1;
        suma = 0;
        fil = 0;
      }
      aux = 40 * etiq;
      col = 0;
    }
    aux = 0;
    for (etiq = 0; etiq < 4; etiq++) {
      for (fil = 0; fil < 40 * etiq; fil++) {
        for (; col < 4; col++) {
          dist1 = dist1 + pow((matriz[fil][col] - matriz_p[etiq - 1][col]), 2);
        }
        dist_total = sqrt(dist1);
        matriz_n[fil] = dist_total;
        if (dist_total > dist_mayor) {
          dist_mayor = dist_total;
          matriz_u[etiq - 1] = dist_mayor;
        }
        col = 0;
        dist_total = 2000;
        dist1 = 0;
      }
      dist_mayor = 0;
      aux = 40 * etiq;
    }
    for (etiq = 0; etiq < 4; etiq++) {
      for (fil = 0; fil < 40 * etiq; fil++) {
        for (col = 0; col < 5; col++) {
          divis = matriz_n[fil] / matriz_u[etiq - 1];
          if ((divis <= lim1) & (divis >= lim2))
          {
            matriz_nueva[fil_n][col] = matriz[fil][col];
          }
          divis = 0;
        }
      }
      for (fil = 0; fil < 30; fil++) {
        for (col = 0; col < 5; col++) {
          Serial.print(matriz_nueva[fil][col]);
         }
      }
    }
    for (fil = 0; fil < 30; fil++) {
      for (col = 0; col < 5; col++)
        if (result == matriz_nueva[fil][col])
          acier++;
    }
    rend = (acier * 100) / 30;
    Serial.println(acier);
    Serial.println(rend);
  }
  on = 1;
}
