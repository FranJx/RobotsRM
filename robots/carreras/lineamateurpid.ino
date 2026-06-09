// ===== SENSORES =====
#define S1 A0
#define S2 A1
#define S3 A2
#define S4 A3

// ===== MOTOR IZQUIERDO =====
#define PWMA 6
#define MA1 7
#define MA2 8

// ===== MOTOR DERECHO =====
#define PWMB 11
#define MB1 10
#define MB2 9

// ===== PID =====
float Kp = 30.0;
float Ki = 0.0;
float Kd = 15.0;

float error = 0;
float errorAnterior = 0;
float integral = 0;
float derivada = 0;
float correccion = 0;

int velocidadBase = 180;

void setup() {

  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);

  pinMode(PWMA, OUTPUT);
  pinMode(MA1, OUTPUT);
  pinMode(MA2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(MB1, OUTPUT);
  pinMode(MB2, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int s1 = !digitalRead(S1);
  int s2 = !digitalRead(S2);
  int s3 = !digitalRead(S3);
  int s4 = !digitalRead(S4);

  int suma = s1 + s2 + s3 + s4;

  // Línea perdida
  if (suma == 0) {
    motores(0, 0);
    return;
  }

  // Posición ponderada de la línea
  float posicion =
      (-3.0 * s1) +
      (-1.0 * s2) +
      ( 1.0 * s3) +
      ( 3.0 * s4);

  error = posicion / suma;

  // ===== PID =====
  integral += error;
  derivada = error - errorAnterior;

  correccion =
      (Kp * error) +
      (Ki * integral) +
      (Kd * derivada);

  errorAnterior = error;

  int velIzq = velocidadBase + correccion;
  int velDer = velocidadBase - correccion;

  velIzq = constrain(velIzq, 0, 255);
  velDer = constrain(velDer, 0, 255);

  motores(velIzq, velDer);

  Serial.print("Error: ");
  Serial.print(error);
  Serial.print("  Izq:");
  Serial.print(velIzq);
  Serial.print("  Der:");
  Serial.println(velDer);
}

// ===================================

void motores(int izq, int der) {

  digitalWrite(MA1, HIGH);
  digitalWrite(MA2, LOW);

  digitalWrite(MB1, HIGH);
  digitalWrite(MB2, LOW);

  analogWrite(PWMA, izq);
  analogWrite(PWMB, der);
}