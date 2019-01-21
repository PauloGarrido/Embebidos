int fx=0;
int fy=200;
int vx=0;
int x1=0;
int i=0;

void setup() {
  size(1200, 600);
  background(200, 200, 200);
}
void draw() {
  background(200, 200, 200);
  beginShape();
  fill(0, 0, 0);
  vertex(95+fx, 180+fy);
  vertex(95+fx, 220+fy);
  vertex(110+fx, 220+fy);
  vertex(110+fx, 225+fy);
  vertex(90+fx, 225+fy);
  vertex(90+fx, 195+fy);
  vertex(80+fx, 195+fy);
  vertex(80+fx, 185+fy);
  vertex(70+fx, 185+fy);
  vertex(70+fx, 195+fy);
  vertex(60+fx, 195+fy);
  vertex(60+fx, 205+fy);
  vertex(55+fx, 205+fy);
  vertex(55+fx, 220+fy);
  vertex(70+fx, 220+fy);
  vertex(70+fx, 225+fy);
  vertex(50+fx, 225+fy);
  vertex(50+fx, 185+fy);
  vertex(40+fx, 185+fy);
  vertex(40+fx, 175+fy);
  vertex(35+fx, 175+fy);
  vertex(35+fx, 160+fy);
  vertex(30+fx, 160+fy);
  vertex(30+fx, 155+fy);
  vertex(25+fx, 155+fy);
  vertex(25+fx, 155+fy);
  vertex(15+fx, 155+fy);
  vertex(15+fx, 100+fy);
  vertex(20+fx, 100+fy);
  vertex(20+fx, 120+fy);
  vertex(25+fx, 120+fy);
  vertex(25+fx, 130+fy);
  vertex(35+fx, 130+fy);
  vertex(35+fx, 140+fy);
  vertex(55+fx, 140+fy);
  vertex(55+fx, 130+fy);
  vertex(65+fx, 130+fy);
  vertex(65+fx, 120+fy);
  vertex(75+fx, 120+fy);
  vertex(75+fx, 110+fy);
  vertex(85+fx, 110+fy);
  vertex(85+fx, 100+fy);
  vertex(95+fx, 100+fy);
  vertex(95+fx, 25+fy);
  vertex(125+fx, 105+fy); 
  vertex(145+fx, 105+fy);
  vertex(145+fx, 125+fy);
  vertex(135+fx, 125+fy);
  vertex(135+fx, 115+fy);
  vertex(125+fx, 115+fy);
  vertex(125+fx, 155+fy);
  vertex(115+fx, 155+fy);
  vertex(115+fx, 170+fy);
  vertex(105+fx, 170+fy);
  vertex(105+fx, 25+fy);
  vertex(105+fx, 15+fy);
  vertex(115+fx, 15+fy);
  vertex(115+fx, 15+fy); 
  vertex(175+fx, 15+fy);
  vertex(175+fx, 25+fy); 
  vertex(185+fx, 25+fy); 
  vertex(185+fx, 65+fy); 
  vertex(135+fx, 65+fy); 
  vertex(135+fx, 75+fy); 
  vertex(165+fx, 75+fy); 
  vertex(165+fx, 85+fy);
  vertex(125+fx, 85+fy);
  vertex(105+fx, 180+fy);
  endShape(); 
  noFill();
  fill(200, 200, 200);
  rect(110+fx, 20+fy, 15, 15);
  fill(200, 200, 200);
  rect(170+fx, 45+fy, 7, 7);
  stroke (0, 0, 0); //random -> Para que varia color
  line(0, 400, 1200, 400);
  //-----------------------------------------------------
  if (fx>1200) {
    fx=fx-1100;
  }
  if (fx<0) {
    fx=1200;
  }
  if (fy>300) {
    fy=100;
  }
  if (fy<200) {
    fy=300;
  }
  //-------------------------------------------------
  if (i==1) {
    if (fy>200) {
      fy=fy-2;
    } else {
      i=0;
      fy=300;
    }
  }
}


void keyPressed() {
  if (key == 'a') {
    fx = fx - 5;
  }
  if (key == 'd') {  
    fx = fx + 5;
  }  

  if (key == 'w') {
    fy = fy - 5;
  }

  if (key == 's') {  
    fy = fy + 5;
  }
}
