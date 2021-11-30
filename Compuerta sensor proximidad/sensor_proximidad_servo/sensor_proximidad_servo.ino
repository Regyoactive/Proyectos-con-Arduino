
#include <Servo.h>

int trigPin = 3; 
int echoPin = 2;
int distance = 400;
int duration = 400000;
int SERVO_PIN = 4;

Servo ser; 

int angle = 0;  // angulo

void setup() {
  Serial.begin(9600);         // se inicializa
  ser.attach(SERVO_PIN);     // vinculamos el pin 4 con servo 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  ser.write(angle); //angulo en el que se abre el servo
}

void loop() {
  digitalWrite(trigPin, HIGH);
    delay(1);
    digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  Serial.println(distance);
  
  if(distance > 40){
    Serial.println("No se detecta proximidad");
    ser.write(0); //no se abre
  }
  
  else if (distance > 5){ 
    Serial.println("Acercamiento detectado");
    ser.write(90); //se abre en angulo recto
    delay(5000);
  }
  delay(100);
}
