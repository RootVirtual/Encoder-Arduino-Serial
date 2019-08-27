/*
 * ENCODER - ARDUINO
 * 
 * AÑADE VALORES CON EL DESPLAZAMIENTO DEL ENCODER
 * 
 * CON BOTÓN RESET
 * 

 Manda por Serial el valor recogido por el encoder, empezando en el punto 0.
 Al presionar el botón se resetea Arduino, colocando el valor de nuevo en 0.
 (Arduino tarda de 2 a 4 segundo en reiniciar)

*/

// CONEXIÓN ENCODER
//
//   Encoder   Arduino       Arduino    Botón
//      |         |             |         |
//     Red ------ 5v           Gnd ------ \
//    Black ---- Gnd          Reset ----- |
//    Green ----- 2
//    White ----- 3
//


const int encoderPin1 = 2;
const int encoderPin2 = 3;

volatile int lastEncoded = 0;
volatile long encoderValue = 0;

long lastencoderValue = 0;

int lastMSB = 0;
int lastLSB = 0;

void setup() {
  Serial.begin (9600);

  lastEncoded = 0;
  encoderValue = 0;
  lastencoderValue = 0;
  lastMSB = 0;
  lastLSB = 0;

  pinMode(encoderPin1, INPUT_PULLUP); 
  pinMode(encoderPin2, INPUT_PULLUP);

  digitalWrite(encoderPin1, HIGH); //Enciende el pulso 1
  digitalWrite(encoderPin2, HIGH); //Enciende el pulso 2

  //Llamada a updateEncoder() cuando detecta cambio en uno de los pulsos high/low
  //Interrupción 0 (pin 2) o interrupción 1 (pin 3) 
  attachInterrupt(0, updateEncoder, CHANGE); 
  attachInterrupt(1, updateEncoder, CHANGE);
  delay(1000);

}

void loop(){ 
  //Manda el valor de posición. Referencia es 0, donde empieza.
  //Divido el valor entre 100 para reducir el número, ya que detecta muchos pasos por vuelta.
  Serial.println(encoderValue/100);
  delay(100); //Para normalizar la salida y no volver loco al Serial
  
}


void updateEncoder(){
  int MSB = digitalRead(encoderPin1); //MSB (most significant bit)
  int LSB = digitalRead(encoderPin2); //LSB (least significant bit)

  int encoded = (MSB << 1) |LSB; //Pasa el valor del pin 2 a número
  int sum  = (lastEncoded << 2) | encoded; //y lo añade al valor obtenido antes

  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoderValue ++;
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoderValue --;

  lastEncoded = encoded; //store this value for next time
}
