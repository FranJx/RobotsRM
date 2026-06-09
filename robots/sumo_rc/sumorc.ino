// ===============================
// ROBOT BLUETOOTH
// ===============================

// --- MOTOR A ---
const int MA_IN1 = 12;
const int MA_IN2 = 11;
const int PWM_A  = 3;

// --- MOTOR B ---
const int MB_IN1 = 4;
const int MB_IN2 = 10;
const int PWM_B  = 9;

int velocidad = 130; // 0 a 255

char comando;

void setup() {

  Serial.begin(9600);

  pinMode(MA_IN1, OUTPUT);
  pinMode(MA_IN2, OUTPUT);
  pinMode(PWM_A, OUTPUT);

  pinMode(MB_IN1, OUTPUT);
  pinMode(MB_IN2, OUTPUT);
  pinMode(PWM_B, OUTPUT);

  detener();

  Serial.println("Robot Bluetooth Listo");
}

// ===============================
// FUNCIONES MOTORES
// ===============================

void detener() {

  digitalWrite(MA_IN1, LOW);
  digitalWrite(MA_IN2, LOW);

  digitalWrite(MB_IN1, LOW);
  digitalWrite(MB_IN2, LOW);

  analogWrite(PWM_A, 0);
  analogWrite(PWM_B, 0);
}

void adelante() {

  digitalWrite(MA_IN1, HIGH);
  digitalWrite(MA_IN2, LOW);

  digitalWrite(MB_IN1, HIGH);
  digitalWrite(MB_IN2, LOW);

  analogWrite(PWM_A, velocidad);
  analogWrite(PWM_B, velocidad);
}

void atras() {

  digitalWrite(MA_IN1, LOW);
  digitalWrite(MA_IN2, HIGH);

  digitalWrite(MB_IN1, LOW);
  digitalWrite(MB_IN2, HIGH);

  analogWrite(PWM_A, velocidad);
  analogWrite(PWM_B, velocidad);
}

void girarDerecha() {

  digitalWrite(MA_IN1, HIGH);
  digitalWrite(MA_IN2, LOW);

  digitalWrite(MB_IN1, LOW);
  digitalWrite(MB_IN2, HIGH);

  analogWrite(PWM_A, velocidad);
  analogWrite(PWM_B, velocidad);
}

void girarIzquierda() {

  digitalWrite(MA_IN1, LOW);
  digitalWrite(MA_IN2, HIGH);

  digitalWrite(MB_IN1, HIGH);
  digitalWrite(MB_IN2, LOW);

  analogWrite(PWM_A, velocidad);
  analogWrite(PWM_B, velocidad);
}

// ===============================
// LOOP
// ===============================

void loop() {

  if (Serial.available()) {

    comando = Serial.read();

    // -------- MOVIMIENTO --------

    if (comando == 'F') {
      adelante();
      Serial.println("ADELANTE");
    }

    else if (comando == 'B') {
      atras();
      Serial.println("ATRAS");
    }

    else if (comando == 'L') {
      girarIzquierda();
      Serial.println("IZQUIERDA");
    }

    else if (comando == 'R') {
      girarDerecha();
      Serial.println("DERECHA");
    }

    else if (comando == 'S') {
      detener();
      Serial.println("STOP");
    }

    // -------- VELOCIDAD --------
    else if (comando == '0') velocidad = 0;
    else if (comando == '1') velocidad = 25;
    else if (comando == '2') velocidad = 50;
    else if (comando == '3') velocidad = 75;
    else if (comando == '4') velocidad = 100;
    else if (comando == '5') velocidad = 125;
    else if (comando == '6') velocidad = 150;
    else if (comando == '7') velocidad = 175;
    else if (comando == '8') velocidad = 200;
    else if (comando == '9') velocidad = 255;
  }
}