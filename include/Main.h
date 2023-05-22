//motores balanceados -> motorDireito = motorEsquerdo + 4
#include <stdio.h>
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

int primeiroMovimento = 1;

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

    analogWrite(pwm_esquerdo, 120);
    analogWrite(pwm_direito, 124);
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