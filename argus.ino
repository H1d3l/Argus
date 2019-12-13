#include <Ultrasonic.h>

#define pino_trigger_right 8
#define pino_trigger_middle 12
#define pino_trigger_left 10

#define pino_echo_right 9
#define pino_echo_middle 13
#define pino_echo_left 11

#define pino_enA A2 //pino enA da ponte h l298
#define pino_enB A3 //pino enB da ponte h l298
#define pino_in1 3 //pino in1 da ponte h l298 
#define pino_in2 4 //pino in2 da ponte h l298
#define pino_in3 5 //pino in3 da ponte h l298
#define pino_in4 6 //pino in4 da ponte h l298

Ultrasonic ultrasonic_middle(pino_trigger_middle,pino_echo_middle);//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic_left(pino_trigger_left,pino_echo_left);//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic_right(pino_trigger_right,pino_echo_right);//Inicializa o sensor nos pinos definidos acima

int distance_obstacle = 30; //distância para o robô parar e recalcular o melhor caminho
int motor_speed_one = 80;
int motor_speed_two = 95;

void setup() {
     
  Serial.begin(9600);// inicializa a comunicação serial para mostrar dados
  pinMode(2, OUTPUT);  // define pino 2 como saida led
  pinMode(pino_enA, OUTPUT);
  pinMode(pino_enB, OUTPUT);
  pinMode(pino_in1, OUTPUT);
  pinMode(pino_in2, OUTPUT);
  pinMode(pino_in3, OUTPUT);
  pinMode(pino_in4, OUTPUT);
  

}


void loop() {
  turn_on_led();
  go_forward();
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
void go_forward()
{
Serial.println("Robô: para o alto e avante");
digitalWrite(pino_in1, HIGH);                          //Configurar a ponte h 
digitalWrite(pino_in2, LOW);
digitalWrite(pino_in3, HIGH);
digitalWrite(pino_in4, LOW);
analogWrite(pino_enA, motor_speed_one);              // Defina a velocidade do motor Um
analogWrite(pino_enB, motor_speed_two);            // Defina a velocidade do motor Dois                         
}

void turn_on_led(){
  digitalWrite(2, HIGH);// Ativa o pino 13 (colocando 5v nele)  
  delay(500);// Aguarda 1 segundo
  digitalWrite(2, LOW);// Desliga o pino 12
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
