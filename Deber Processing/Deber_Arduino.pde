import processing.serial.*;   // Para usar el puerto serie
import controlP5.*;           // Para control P5
ControlP5 cp5; 

Serial port;                  //Variable serial

int i=0,j=0;                  //Variables int


ArrayList<Punto> onda1;       // Conjunto de puntos para representar la onda1
int valores[] = {0, 0};       // Array para obtener los dos valores del puerto serie
float altura[] = {0.0};       // Array para las alturas recibidas

Serial puerto;                //Puerto serial

void setup(){
  size(1500,900);             // Tamaño de ventana 
  frameRate(30);              // FPS
  smooth();                   // Suavizado activado  
  cp5= new ControlP5(this);  
  cp5.addButton("CONECTAR")
  .setValue(0)
  .setPosition(50,50)
  .setSize(100,50)
  .setCaptionLabel("OFF")
  .setColorBackground(#FF0000)
  .setColorForeground(#00ECFF)
  ;
  cp5.addSlider("VALOR POT")
  .setColorLabel(#FFFFFF)
  .setPosition(100,150)
  .setSize(400,50)
  .setRange(0,1023)
  .setValue(0)
  .setNumberOfTickMarks(1023)
  .setColorActive(#FF0009)
  .setColorBackground(#760206)
  .setColorForeground(#FF0009)
  ;   
  
  /* Inicialización de variables */
  onda1 = new ArrayList<Punto>();
  /* Configuración de puerto serie */
  String nombrePuerto = Serial.list()[0];
  println("Puerto establecido a " + nombrePuerto);
  puerto = new Serial(this, nombrePuerto, 9600);
  puerto.bufferUntil('\n');   // Guardar datos hasta que encuentra salto de línea
}

void draw(){
  background(0);              // Pintamos color de fondo
  if(valores != null){
    altura[0] = map((float) valores[0], 0, 2000, 0, -height);
    println(valores[1]);
    cp5.getController("VALOR POT").setValue(float(valores[1]));
    
    onda1.add(new Punto(altura[0]));
    fill(#00D7FF);           // Relleno color rojo (para el texto) 
    text("Valor Potenciómetro 2: " + -altura[0], 20, 30);
    noFill();                // Sin relleno
    strokeWeight(3);         // Grosor del lápiz
    stroke(#00D7FF);         // Color del lápiz
    dibujaCurva(onda1);
  }
}

void dibujaCurva(ArrayList<Punto> onda){
  beginShape();                               // Empieza curva
  for(int i=0; i<onda.size(); i++){
    Punto punto = onda.get(i);
    punto.desplazar();       
    curveVertex(punto.getX(), punto.getY());  // Añadir un punto a la curva
    /* Borrar punto si se ha desplazado demasiado a la izquierda */
    if(punto.getX() < -width){
      onda.remove(i);
    }
  }
  if(onda.size() > 0){
    curveVertex(onda.get(onda.size() - 1).getX() + 1, onda.get(onda.size() - 1).getY());
    line(onda.get(onda.size() - 1).getX(), onda.get(onda.size() - 1).getY(), width, onda.get(onda.size() - 1).getY());     
  }
  /* Dibujar curva */
  endShape();                                   // Termina la curva 
}

void serialEvent(Serial p){
  String dato = p.readStringUntil('\n'); // Se lee el buffer del puerto serie
  
  if(dato != null){
    dato = trim(dato); 
    valores = int(split(dato, ','));
  }
}
public void CONECTAR(){
  j=1-j;
  if(j==1){
    cp5.getController("VALOR POT").setValue(0);
    cp5.getController("CONECTAR").setCaptionLabel("ON");
    cp5.getController("CONECTAR").setColorBackground(#3A7D83);
    println("ON");
    //port = new Serial (this, "COM8", 9600);
  }
  else{
    cp5.getController("CONECTAR").setCaptionLabel("OFF");
    cp5.getController("CONECTAR").setColorBackground(#FCB603);
    println("OFF");
    port.stop();   
    cp5.getController("VALOR POT").setValue(0);
  }
}
