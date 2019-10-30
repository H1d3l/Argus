#include <Ultrasonic.h>

//Define os pinos para o trigger e echo do sensor ultrassonico do meio
#define pino_trigger_middle 4
#define pino_echo_middle 5

Ultrassonic ultrassonic_middle (pino_trigger_middle,pino_echo_middle,40000UL);//Inicializa o sensor nos pinos definidos acima

int distance_obstacle = 30; //distância para o robô parar e recalcular o melhor caminho

void setup() {
     
  Serial.begin(9600);// inicializa a comunicação serial para mostrar dados
  pinMode(13, OUTPUT);  // define pino 13 como saida  
  pinMode(pino_trigger_middle, OUTPUT); //define o pino TRIG como saída
  pinMode(pino_echo_middle, INPUT);  //define o pino ECHO como entrada 
  

}

void loop() {
  turn_on_led()
  main()

}

void turn_on_led(){
  digitalWrite(13, HIGH);// Ativa o pino 13 (colocando 5v nele)  
  delay(1000);// Aguarda 1 segundo
  digitalWrite(13, LOW);// Desliga o pino 12
  delay(1000);// Aguarda 1 segundo
  
}

void main(){
  int distance = read_distance_cm() // Ler o sensor de distância  
  Serial.print("distancia em cm: "); 
  Serial.println(distancia);

  if(distance>distance_obstacle){
    walk forward()//implementar andar para frente    
  }
  else{
      rotacao_Parado();  //implementar parar o robô  
      posicionaCarroMelhorCaminho(); //implementar calcula o melhor caminho    
        main();
  }
}

int read_distance_cm(){
  return ultrassonic_middle.read(CM)
}
