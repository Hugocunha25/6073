// Definição dos pinos
const int SEM1_VERMELHO = 7; // Substituído o pino 1
const int SEM1_AMARELO = 8; // Substituído o pino 2
const int SEM1_VERDE = 3;
const int SEM2_VERMELHO = 4;
const int SEM2_AMARELO = 5;
const int SEM2_VERDE = 6;

// Tempos de transição (em milissegundos)
const int TEMPO_VERDE = 5000;
const int TEMPO_AMARELO = 2500;

// Variável para controlar o estado atual
int estadoAtual = 1;

void setup() {
  // Configurar todos os pinos como saída
  pinMode(SEM1_VERMELHO, OUTPUT);
  pinMode(SEM1_AMARELO, OUTPUT);
  pinMode(SEM1_VERDE, OUTPUT);
  pinMode(SEM2_VERMELHO, OUTPUT);
  pinMode(SEM2_AMARELO, OUTPUT);
  pinMode(SEM2_VERDE, OUTPUT);
}

void loop() {
  switch (estadoAtual) {
    case 1:
      // Semáforo 1 Verde, Semáforo 2 Vermelho
      digitalWrite(SEM1_VERDE, HIGH);
      digitalWrite(SEM2_VERMELHO, HIGH);
      digitalWrite(SEM1_VERMELHO, LOW);
      digitalWrite(SEM1_AMARELO, LOW);
      digitalWrite(SEM2_VERDE, LOW);
      digitalWrite(SEM2_AMARELO, LOW);
      delay(TEMPO_VERDE);
      estadoAtual = 2;
      break;

    case 2:
      // Semáforo 1 Amarelo, Semáforo 2 Vermelho
      digitalWrite(SEM1_AMARELO, HIGH);
      digitalWrite(SEM2_VERMELHO, HIGH);
      digitalWrite(SEM1_VERDE, LOW);
      digitalWrite(SEM1_VERMELHO, LOW);
      digitalWrite(SEM2_VERDE, LOW);
      digitalWrite(SEM2_AMARELO, LOW);
      delay(TEMPO_AMARELO);
      estadoAtual = 3;
      break;

    case 3:
      // Semáforo 1 Vermelho, Semáforo 2 Verde
      digitalWrite(SEM1_VERMELHO, HIGH);
      digitalWrite(SEM2_VERDE, HIGH);
      digitalWrite(SEM1_VERDE, LOW);
      digitalWrite(SEM1_AMARELO, LOW);
      digitalWrite(SEM2_VERMELHO, LOW);
      digitalWrite(SEM2_AMARELO, LOW);
      delay(TEMPO_VERDE);
      estadoAtual = 4;
      break;

    case 4:
      // Semáforo 1 Vermelho, Semáforo 2 Amarelo
      digitalWrite(SEM1_VERMELHO, HIGH);
      digitalWrite(SEM2_AMARELO, HIGH);
      digitalWrite(SEM1_VERDE, LOW);
      digitalWrite(SEM1_AMARELO, LOW);
      digitalWrite(SEM2_VERDE, LOW);
      digitalWrite(SEM2_VERMELHO, LOW);
      delay(TEMPO_AMARELO);
      estadoAtual = 1;  
      break;
  }
}
