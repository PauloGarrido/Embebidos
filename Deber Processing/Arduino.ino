/* Definimos pines */
#define PIN_POT1 A0  // Conectamos un potenciómetro en el pin analógico A0
#define PIN_POT2 A1  // Conectamos un potenciómetro en el pin analógico A1

String dato;         // Para enviar un dato por el puerto serie

void setup(){
  /* Establecemos los potenciómetros como entrada */
  pinMode(PIN_POT1, INPUT); 
  pinMode(PIN_POT2, INPUT); 
  /* Iniciamos el puerto serie */
  Serial.begin(9600);
}

void loop(){
  /* Obtenemos valores de los potenciómetro (varían de 0 a 1000) */
  int nivelDePot1 = analogRead(PIN_POT1);  // potenciómetro1
  int nivelDePot2 = analogRead(PIN_POT2);  // potenciómetro2
  nivelDePot1 = map(nivelDePot1, 0, 1023, 0, 1000);
  if(nivelDePot1 < 15){ // si el valor es muy bajo...
    nivelDePot1 = 0;    // ...se hace 0 directamente
  }
  nivelDePot2 = map(nivelDePot2, 0, 1023, 0, 1000);
  if(nivelDePot2 < 15){
    nivelDePot2 = 0;
  }
  nivelDePot1 = constrain(nivelDePot1, 0, 1000);
  nivelDePot2 = constrain(nivelDePot2, 0, 1000);   
  
  /* Enviamos dato por puerto serie */
  dato = "";
  dato += nivelDePot2;
  dato += ",";
  dato += nivelDePot1;
  Serial.println(dato);
  
  delay(50); // pequeña pausa para no saturar el puerto serie
}
