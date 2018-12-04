#include "datos_entrenamiento.h"

float suma = 0;
int col = 0, col_n = 0; //Variable de recorrido de columnas
int fil = 0, fil_n = 0; //Variable de recorrido de filas
int on = 0;
int cont = 0;
int i = 0; //Variable auxiliar
int j=0; //Variabel auxiliar
float matriz_n [30][5];
float prom1 = 0, prom2 = 0, prom3 = 0, prom4 = 0; //Variable de promedio
float dist1 = 0, dist2 = 0, dist3 = 0;
float ran11 = 0.1, ran12 = 0.13, ran21 = 0.15, ran22 = 0.2, ran31 = 0.18, ran32 = 0.21;
float dist_total = 2000;
float total = 0;
float d1 = 0, d2 = 0, d3 = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (on == 0) {
    for (; col < 4; col++) {
      for (fil = 0; fil < 40; fil++) {
        suma = suma + matriz[fil][col];
        cont++;
      }
      prom1 = suma / cont;
      matriz_n[0][col] = prom1;
      suma = 0;
      cont = 0;
    }
    for (fil = 0; fil < 40; fil++) {
      dist1 = sqrt(pow(matriz[fil][0] - matriz_n[0][col_n], 2) +
                   pow(matriz[fil][1] - matriz_n[0][col_n], 2) +
                   pow(matriz[fil][2] - matriz_n[0][col_n], 2) +
                   pow(matriz[fil][3] - matriz_n[0][col_n], 2)) ;
    }
    if (dist_total > dist1) {
      dist_total = dist1;
    }
    fil = 0;
    col = 0;
    dist_total = 2000;
    for (; col < 4; col++) {
      for (fil = 40; fil < 80; fil++) {
        suma = suma + matriz[fil][col];
        cont++;
      }
      prom2 = suma / cont;
      matriz_n[1][col] = prom2;
      suma = 0;
      cont = 0;
    }
    for (fil = 40; fil < 80; fil++) {
      dist2 = sqrt(pow(matriz[fil][0] - matriz_n[1][col_n], 2) +
                   pow(matriz[fil][1] - matriz_n[1][col_n], 2) +
                   pow(matriz[fil][2] - matriz_n[1][col_n], 2) +
                   pow(matriz[fil][3] - matriz_n[1][col_n], 2)) ;
    }
    if (dist_total > dist2) {
      dist_total = dist2;
    }
    fil = 0;
    col = 0;
    dist_total = 2000;
    for (; col < 4; col++) {
      for (fil = 80; fil < 120; fil++) {
        suma = suma + matriz[fil][col];
        cont++;
      }
      prom3 = suma / cont;
      matriz_n[2][col] = prom3;
      suma = 0;
      cont = 0;
    }
    for (fil = 80; fil < 120; fil++) {
      dist3 = sqrt(pow(matriz[fil][0] - matriz_n[2][col_n], 2) +
                   pow(matriz[fil][1] - matriz_n[2][col_n], 2) +
                   pow(matriz[fil][2] - matriz_n[2][col_n], 2) +
                   pow(matriz[fil][3] - matriz_n[2][col_n], 2)) ;
    }
    if (dist_total > dist3) {
      dist_total = dist3;
    }
    fil = 0;
    col = 0;
    dist_total = 2000;
  }
  on = 1;
}
