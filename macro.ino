#include <HID-Project.h> // Inclui a biblioteca HID-Project

// Configuração do potenciômetro
int lastVolumeValue = 0; // Para armazenar o último valor lido do potenciômetro
int volumeThreshold = 10; // Diferença mínima para mudar o volume
int potentiometerPin = A0; // Pino onde o potenciômetro está conectado

// Função para digitar os códigos com delay
void typeWithDelay(const char *text) {
  while (*text) {
    Keyboard.write(*text);  // Envia o caractere
    delay(50);  // Pequeno delay de 50ms entre cada caractere
    text++;
  }
}

void setup() 
{
  // Configura os pinos dos botões
  pinMode(7, INPUT); // paste
  pinMode(8, INPUT); // cut
  pinMode(9, INPUT); // custom
  pinMode(10, INPUT); // undo
  pinMode(16, INPUT); // redo
  pinMode(13, INPUT); // pino 13
  pinMode(12, INPUT); // pino 12
  pinMode(11, INPUT); // pino 11

  // Puxando os pinos pra HIGH pra esperar LOW (quando apertado)
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(16, HIGH);
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);

  pinMode(potentiometerPin, INPUT); // Configura o pino do potenciômetro
  Keyboard.begin(); // Inicia o teclado
}

void loop() 
{
  // --- Controle de volume pelo potenciômetro ---
  int potentiometerValue = analogRead(potentiometerPin); // Lê o valor do potenciômetro

  // Verifica se a mudança no valor do potenciômetro é significativa o bastante
  if (abs(potentiometerValue - lastVolumeValue) > volumeThreshold) 
  {
    if (potentiometerValue > lastVolumeValue) 
    {
      // Aumenta o volume
      Consumer.write(MEDIA_VOLUME_UP);
      delay(100); // Pequeno delay para simular um "toque"
    } 
    else if (potentiometerValue < lastVolumeValue) 
    {
      // Abaixa o volume
      Consumer.write(MEDIA_VOLUME_DOWN);
      delay(100); 
    }

    lastVolumeValue = potentiometerValue; // Atualiza o valor lido
  }

  // --- Funções de macro para as teclas ---
  if (digitalRead(7) == LOW) {
    Keyboard.press(KEY_LEFT_ALT); // Pressiona Alt
    Keyboard.press('p'); // Pressiona p
    delay(50); // Aguarda um pequeno intervalo
    Keyboard.releaseAll(); // Solta todas as teclas
    delay(250); // Pequeno delay para evitar múltiplos acionamentos
  }
  else if (digitalRead(8) == LOW) { // cut
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.write('x');
    Keyboard.releaseAll();
    delay(250);  
  }
  else if (digitalRead(9) == LOW) { // custom (dígito '6')
    Keyboard.write('6'); // Tecla o dígito '6'
    Keyboard.releaseAll();
    delay(250);
  }  
  else if (digitalRead(10) == LOW) { // undo
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.write('z');
    Keyboard.releaseAll();
    delay(250);
  }  
  else if (digitalRead(16) == LOW) { // redo
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.write('y');
    Keyboard.releaseAll();
    delay(250);
  }  
  else if (digitalRead(13) == LOW) { // pino 13: código "6@wuOoX@D+jk8NSd"
    typeWithDelay("email 1");
    Keyboard.releaseAll();
    delay(250);
  }  
  else if (digitalRead(12) == LOW) { // pino 12: código "VL4k*|W3kif$9MlN"
    typeWithDelay("email 2");
    Keyboard.releaseAll();
    delay(250);
  }
  else if (digitalRead(11) == LOW) { // pino 11: código "UsFMR4Fo0$8&xkl"
    typeWithDelay("email 3");
    Keyboard.releaseAll();
    delay(250);
  }

  delay(100); // Pequeno delay para suavizar a leitura do potenciômetro
}
