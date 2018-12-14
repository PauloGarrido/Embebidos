#include <knn.h>
#include "datos_silla.h"

int on = 0;
float result;
int f = 0;
int acier = 0;
int rend = 0;;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (on == 0) {
    for (; f < 30; f++) {
      result = knn(120, 5, 3, 3, vector[f]);
      if (result == vector[f][4])
        acier++;
    }
    rend = (acier *100)/ 308;
    Serial.println(acier);
    Serial.println(rend);
    on = 1;
  }
}
