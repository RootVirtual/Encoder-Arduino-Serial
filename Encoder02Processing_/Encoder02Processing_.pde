
import processing.serial.*;

Serial myPort;  // Create object from Serial class
String val;      // Data received from the serial port
int valor=0;
int linea=0;

void setup() 
{
  size(2000, 200);
  // I know that the first port in the serial list on my mac
  // is always my  FTDI adaptor, so I open Serial.list()[0].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
  String portName = Serial.list()[1];
  myPort = new Serial(this, portName, 9600);
  
  delay(3000);
}

void draw(){
  noStroke();
  if ( myPort.available() > 0) {  // If data is available,
    val = myPort.readStringUntil('\n');         // read it and store it in val
    if(val != null){
      valor=Integer.parseInt(val.trim());
    }
  }
  
  linea=int(map(valor, 0, 50, 0, 500)); 
  
  fill(#00188E);
  rect(0,0,width,height);
  for(int i=2;i<2000;i=i+8){
    for(int j=1;j<200;j=j+8){
      if((linea>i-random(-0,20)) && (linea<i+random(-0,20))){
        fill(#2661D3);
        //ellipse(i, j, 5, 5);
        fill(#ACC2ED);
        ellipse(i, j, 5, 5);
      }
    }
  }
  
  rect(linea-2, 0, 4, height);
  
  fill(#102176);
  rect(0, height/2-10, width, 20);
  rect(width/2-30, height/2+10, 60, 30);
  fill(255);
  textSize(24);
  text(valor, width/2-20, height/2+30);
  stroke(255);
  strokeWeight(0.8);
  for(int i=0;i<width;i+=10){
    line(i, height/2-10, i, height/2-5);
  }
  strokeWeight(1);
  for(int i=0;i<width;i+=100){
    line(i, height/2-10, i, height/2-2);
  }
  strokeWeight(1.5);
  line(1000, height/2-20, 1000, height/2+10);
  line(1500, height/2-20, 1500, height/2+10);
  
  
}



/*

// Wiring / Arduino Code
// Code for sensing a switch status and writing the value to the serial port.

int switchPin = 4;                       // Switch connected to pin 4

void setup() {
  pinMode(switchPin, INPUT);             // Set pin 0 as an input
  Serial.begin(9600);                    // Start serial communication at 9600 bps
}

void loop() {
  if (digitalRead(switchPin) == HIGH) {  // If switch is ON,
    Serial.write(1);               // send 1 to Processing
  } else {                               // If the switch is not ON,
    Serial.write(0);               // send 0 to Processing
  }
  delay(100);                            // Wait 100 milliseconds
}

*/
