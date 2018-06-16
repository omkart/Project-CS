import processing.serial.*;
Serial myPort;  // Create object from Serial class
String val;     // Data received from the serial port

int i = 1;
PFont f;
int red = 0;
int green = 0;
int yellow = 0;
int blue = 0;
int end = 10;
int start = 0 ; 

void setup() {
  
  size(500, 500);
  printArray(PFont.list());
  f = createFont("SourceCodePro-Regular.ttf", 50);
  textFont(f);
  textAlign(CENTER, CENTER);
  myPort = new Serial(this, Serial.list()[0], 9600);

  
}


void draw() {
    
  while(start == 1)
  {
  }
  while (myPort.available() > 0) 
  {  // If data is available,
  val = myPort.readStringUntil(end);         // read it and store it in val
  }
  if (val != null)
  {  
  print(val);//print it out in the console
  int res = Integer.parseInt(val);
  

  if (res ==  1)
  {
    red++;
    val = null;
  }
  else if (res == 2)
  {
    green++;
    val = null;
  }
  else if (res == 3)
  {
    yellow++;
    val = null;
  }
  else if (res == 4 )
  {
    blue++;
    val = null;
  }
  delay(500);
  strokeWeight(2);
  fill(255);
  rect(100, 100, 90, 70);
  rect(310, 100, 90, 70);
  rect(100, 250, 90, 70);
  rect(310, 250, 90, 70);
  fill(255, 0, 0);
  ellipse(145 , 400, 50 ,50);
  fill(255, 255, 0);
  ellipse(355 , 400, 50 ,50);
  fill(0);
  textSize(25);
  text("RED", 145, 70);
  text("GREEN", 355, 70);
  text("BLUE", 145, 220);
  text("YELLOW", 355, 220);
  textSize(60);
  fill(255, 0, 0);
  text(red, 145, 120);
  fill(0, 255, 0);
  text(green, 355, 120);
  fill(0, 0, 255);
  text(blue, 145, 270);
  fill(255, 201, 14);
  text(yellow, 355, 270);
}
}

void mousePressed() {
  if (dist(mouseX, mouseY,145,400)<=25 && i == 1 ) {
      start = 1;
      i = 0;
   }
 else if (dist(mouseX, mouseY,355,400)<=25 ){
   red = 0;
   green = 0;
   yellow = 0;
   blue = 0;
 } 
 else if (dist(mouseX, mouseY,145,400)<=25 && i == 0 ) {
      start = 0;
      i = 1;
      
   }
}

void serialEvent(Serial p) {
  val = p.readString();
}