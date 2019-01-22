class Punto {
  float x;        // Coordenada horizontal
  float y;        // Coordenada vertical
  int velocidad;  // Píxels que se desplaza a la izquierda en cada movimiento
  
  Punto(){
    x = width;
    y = height / 2;
    velocidad = 5;
  }
  
  /**
   * @param c_vertical Coordenada vertical
   */
  Punto(float c_vertical){
    this();
    c_vertical=c_vertical+800;
    setY(c_vertical);
  }  
  
  /**
   * @param c_horizontal Coordenada horizontal
   * @param c_vertical Coordenada vertical
   */
  Punto(float c_horizontal, float c_vertical){
    this();
    setX(c_horizontal);
    setY(c_vertical);
  }
  
  /**
   * Desplaza el punto hacia la izquierda
   */
  void desplazar(){
    setX(x - velocidad);
  }
  
  /**
   * Dibuja el punto
   */
  void dibujar(){
    ellipseMode(CENTER);
    ellipse(x, y, 2, 2);
  }
  
  /**
   * Establece el valor de la coordenada horizontal del punto
   * @param nuevoX La nueva coordenada horizontal
   */
   void setX(float nuevoX){
     x = nuevoX;
   }
   
  /**
   * Establece el valor de la coordenada vertical del punto
   * @param nuevoY La nueva coordenada vertical
   */
   void setY(float nuevoY){
     y = nuevoY;
   }
   
  /**
   * Establece la velocidad de movimiento hacia la izquierda del punto
   * @param velocidad La nueva velocidad
   */
   void setVelocidad(int v){
     velocidad = v;
   }
  
  
  /**
   * Devuelve el valor de la coordenada horizontal del punto
   * @return x La coordenada horizontal
   */
   float getX(){
     return x;
   }
   
  /**
   * Devuelve el valor de la coordenada vertical del punto
   * @return y La coordenada vertical
   */
   float getY(){
     return y;
   }
   
  /**
   * Devuelve la velocidad de movimiento hacia la izquierda del punto
   * @return velocidad La velocidad
   */
   int getVelocidad(){
     return velocidad;
   }
}
