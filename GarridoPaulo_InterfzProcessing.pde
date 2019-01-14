int fx=500;
int fy=250;
int lad1_1=0;
int lad2_1=0;
int lad3_1=0;
int lad4_1=0;
int lad1_2=0;
int lad2_2=0;
int lad3_2=0;
int lad4_2=0;
int lad1_3=0;
int lad2_3=0;
int lad3_3=0;
int lad4_3=0;

void setup() {
  size(1200, 700);
}

void draw() {
  background(0);
  fill (0, 175, 255);
  noStroke();
  smooth ();
  /////////////////////////////////////////////////
  fill(250, 0, 0);
  rect(150, 150, 250, 250);
  fill(0, 255, 0);
  rect(650, 450, 300, 150);
  fill(0, 0, 255);
  rect(900, 100, 150, 150);
  /////////////////////////////////////////////////

  /////////////////////////////////////////////////
  if (fx>1200) {
    fx=fx-1200;
  }
  if (fx<0) {
    fx=1200;
  }
  if (fy>600) {
    fy=fy-600;
  }
  if (fy<0) {
    fy=600;
  }
  /////////////////////////////////////////////////
  if ((fx>90 && fx<385)&&(fy>90 && fy<385)) {
    lad1_1=1;
    fill(250, 255, 2550);
    rect(150, 150, 250, 250);
  } else
  {
    lad1_1=0;
  }

  /////////////////////////////////////////////////
  if ((fx>590 && fx<935)&&(fy>400 && fy<585))
  {
    lad1_1=1;
    fill(255, 255, 255);
    rect(650, 450, 300, 150);
  } else
  {
    lad1_1=0;
  }

  /////////////////////////////////////////////////
  if ((fx>840 && fx<1035)&&(fy>50 && fy<235))
  {
    //fx=fx*1;
    //fy=fy*1;
    lad1_3=1;
    fill(255, 255, 255);
    rect(900, 100, 150, 150);
  } else {
    lad1_3=0;
  }

  /////////////////////////////////////////////////
  figura();
}



void figura() {
  beginShape();
  fill(247, 98, 67);
  vertex(15+fx, 25+fy);
  vertex(20+fx, 25+fy);
  vertex(20+fx, 20+fy);
  vertex(25+fx, 20+fy);
  vertex(25+fx, 15+fy);
  vertex(50+fx, 15+fy);
  vertex(50+fx, 20+fy);
  vertex(55+fx, 20+fy);
  vertex(55+fx, 25+fy);
  vertex(60+fx, 25+fy);
  vertex(60+fx, 35+fy);
  vertex(50+fx, 35+fy);
  vertex(50+fx, 30+fy);
  vertex(25+fx, 30+fy);
  vertex(25+fx, 35+fy);
  vertex(15+fx, 35+fy);
  vertex(15+fx, 25+fy);
  endShape();

  beginShape();
  fill(255, 235, 205);
  vertex(20+fx, 35+fy);
  vertex(20+fx, 45+fy);
  vertex(25+fx, 45+fy);
  vertex(25+fx, 50+fy);
  vertex(50+fx, 50+fy);
  vertex(50+fx, 45+fy);
  vertex(55+fx, 45+fy);
  vertex(55+fx, 35+fy);
  vertex(50+fx, 35+fy);
  vertex(50+fx, 30+fy);
  vertex(25+fx, 30+fy);
  vertex(25+fx, 30+fy);
  vertex(25+fx, 35+fy);
  vertex(20+fx, 35+fy);
  endShape();
  fill(0);
  rect(30+fx, 30+fy, 6.5, 7.5);
  rect(40+fx, 30+fy, 6.5, 7.5);
}

void keyPressed() {
  if (key == 'a') {
    if ((lad1_1==1)||(lad1_2==1)||(lad1_3==1)) {
    } else
      fx = fx - 5;
  }
  if (key == 'd') {  
    if ((lad1_1==1)||(lad1_2==1)||(lad1_3==1)) {
    } else
      fx = fx + 5;
  }  

  if (key == 'w') {
    if ((lad1_1==1)||(lad1_2==1)||(lad1_3==1)) {
    } else
      fy = fy - 5;
  }

  if (key == 's') {  
    if ((lad1_1==1)||(lad1_2==1)||(lad1_3==1)) {
    } else
      fy = fy + 5;
  }
}
