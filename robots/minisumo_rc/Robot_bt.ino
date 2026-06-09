#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

//PINES CONECTAR MOTOR 1

int in1 = 13;
int in2 = 12;
//PINES CONECTAR MOTOR 2

int in3 = 11;
int in4 = 10;


void setup()
{

  Serial.begin(9600);
  mySerial.begin(9600);
// Declaramos pines como salida

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);


}

void loop()
{

  if (mySerial.available() > 0) {
    char letra = mySerial.read();


    if (letra == 'F') { //forward
  
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      
    }

       if (letra == 'B') {//backward
  
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
     
    }

       if (letra == 'R') { //rigth

      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);

    }

       if (letra == 'L') { //left

      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      
    }

       if (letra == 'S') { //stop

      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);

    }

  }



}
