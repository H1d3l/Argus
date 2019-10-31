#include <Ultrasonic.h>

//Define os pinos para o trigger e echo do sensor ultrassonico do meio
#define pino_trigger_middle 12
#define pino_echo_middle 13
#define pino_trigger_left 10
#define pino_echo_left 11
#define pino_trigger_right 8
#define pino_echo_right 9

Ultrasonic ultrasonic_middle(pino_trigger_middle,pino_echo_middle);//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic_left(pino_trigger_left,pino_echo_left);//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic_right(pino_trigger_right,pino_echo_right);//Inicializa o sensor nos pinos definidos acima



int distance_obstacle = 30; //distância para o robô parar e recalcular o melhor caminho

void setup() {
     
  Serial.begin(9600);// inicializa a comunicação serial para mostrar dados
  pinMode(4, OUTPUT);  // define pino 13 como saida  
  

}


void loop() {
  turn_on_led();
  int distance_middle = read_ultrasonic_middle();
  int distance_left = read_ultrasonic_left();
  int distance_right = read_ultrasonic_right();


  Serial.print("Distance in CM meio: ");
  Serial.println(distance_middle);
  Serial.print("Distance in CM esquerda: ");
  Serial.println(distance_left);
  Serial.print("Distance in CM direita: ");
  Serial.println(distance_right);

}

void turn_on_led(){
  digitalWrite(4, HIGH);// Ativa o pino 13 (colocando 5v nele)  
  delay(500);// Aguarda 1 segundo
  digitalWrite(4, LOW);// Desliga o pino 12
  delay(500);// Aguarda 1 segundo
  
}
int read_ultrasonic_middle(){
  int distance = ultrasonic_middle.read(CM);
  return distance;
  
}
int read_ultrasonic_left(){
  int distance = ultrasonic_left.read(CM);
  return distance;
  
}
int read_ultrasonic_right(){
  int distance = ultrasonic_right.read(CM);
  return distance;
  
}
