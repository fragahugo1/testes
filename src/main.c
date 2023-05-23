#include <Main.h>

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

  while(digitalRead(microstart == 0));

  int primeiroMovimento =1;
}

void loop() {
  // put your main code here, to run repeatedly:
  while(digitalRead(microstart)){
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
      BordaEsquerda();
      primeiroMovimento = 0;
    }

    else if(!digitalRead(sensor_borda_direito)){
      BordaDireita();
      primeiroMovimento = 0;
    }
  }
}