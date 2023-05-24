#include <Arduino.h>

//pinos de sensor
#define sensor_frontal A0
#define sensor_esquerdo A1
#define sensor_direito A2
#define sensor_borda_esquerdo 2
#define sensor_borda_direito 3

#define microstart 4 //iniciação de rotina

//controle da velocidade do motor
#define pwm_esquerdo 5
#define pwm_direito 6

//controle do sentido de giro da roda
#define motor_esquerdoA 7
#define motor_esquerdoB 8
//esquerdo: B == frente, A == trás
#define motor_direitoA 9
#define motor_direitoB 10
//direito: A == frente, B == trás

// put function declarations here:
void Frente();
void FullFrente();
void Tras();
void Esquerda();
void Direita();
void BordaEsquerda();
void BordaDireita();

int primeiroMovimento = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensor_frontal, INPUT);
  pinMode(sensor_esquerdo, INPUT);
  pinMode(sensor_direito, INPUT);
  pinMode(sensor_borda_esquerdo, INPUT);
  pinMode(sensor_borda_direito, INPUT);

  pinMode(microstart, INPUT);

  pinMode(pwm_esquerdo, OUTPUT);
  pinMode(pwm_direito, OUTPUT);
  pinMode(motor_esquerdoA, OUTPUT);
  pinMode(motor_esquerdoB, OUTPUT);
  pinMode(motor_direitoA, OUTPUT);
  pinMode(motor_direitoB, OUTPUT);

  while(!digitalRead(microstart == 0)); //caso n funcione: botar no loop

  int primeiroMovimento =1;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(microstart)){
    //os sensores de borda tem logica invertida
    
    if(digitalRead(sensor_borda_esquerdo) && digitalRead(sensor_borda_direito)){
      if(primeiroMovimento == 1)
        Frente();
      
      else{
        if(digitalRead(sensor_frontal))
          FullFrente();
        else if(digitalRead(sensor_esquerdo))
          Esquerda();
        else if(digitalRead(sensor_direito))
          Direita();
        else
          Frente();
      }
    }

    else if(!digitalRead(sensor_borda_esquerdo)){
      primeiroMovimento = 0;
      BordaEsquerda();
    }

    else if(!digitalRead(sensor_borda_direito)){
      primeiroMovimento = 0;
      BordaDireita();
    }
  }
}

// put function definitions here:
void Frente(){
    digitalWrite(motor_esquerdoA, LOW); 
    digitalWrite(motor_esquerdoB, HIGH);
    digitalWrite(motor_direitoA, HIGH);
    digitalWrite(motor_direitoB, LOW);

    analogWrite(pwm_esquerdo, 100);
    analogWrite(pwm_direito, 104);
}

void FullFrente(){
    digitalWrite(motor_esquerdoA, LOW);
    digitalWrite(motor_esquerdoB, HIGH);
    digitalWrite(motor_direitoA, HIGH);
    digitalWrite(motor_direitoB, LOW);

    //balanceamento alternativo
    analogWrite(pwm_esquerdo, 174);
    analogWrite(pwm_direito, 220);
}

void Tras(){
    digitalWrite(motor_esquerdoA, HIGH);
    digitalWrite(motor_esquerdoB, LOW);
    digitalWrite(motor_direitoA, LOW);
    digitalWrite(motor_direitoB, HIGH);

    analogWrite(pwm_esquerdo, 130);
    analogWrite(pwm_direito, 134);
}

void Esquerda(){
    digitalWrite(motor_esquerdoA, HIGH);
    digitalWrite(motor_esquerdoB, LOW);
    digitalWrite(motor_direitoA, HIGH);
    digitalWrite(motor_direitoB, LOW);

    analogWrite(pwm_esquerdo, 110);
    analogWrite(pwm_direito, 114);
}

void Direita(){
    digitalWrite(motor_esquerdoA, LOW);
    digitalWrite(motor_esquerdoB, HIGH);
    digitalWrite(motor_direitoA, LOW);
    digitalWrite(motor_direitoB, HIGH);

    analogWrite(pwm_esquerdo, 110);
    analogWrite(pwm_direito, 114);
}

void BordaEsquerda(){
    Tras();
    delay(200);
    Direita();
    delay(800);
    Frente();
}

void BordaDireita(){
    Tras();
    delay(200);
    Esquerda();
    delay(800);
    Frente();
}

/*
void Parar(){
  digitalWrite(motor_esquerdoA, LOW);
  digitalWrite(motor_esquerdoB, LOW);
  digitalWrite(motor_direitoA, LOW);
  digitalWrite(motor_direitoB, LOW);
  analogWrite(pwm_esquerdo, 0);
  analogWrite(pwm_direito, 0);
}
*/