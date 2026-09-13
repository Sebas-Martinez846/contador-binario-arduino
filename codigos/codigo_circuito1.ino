// C++ code

const int BIT0 = 8;
const int BIT1 = 9;
const int BIT2 = 10;
const int BIT3 = 11;

int tiempo_espera = 1000;

void setup()
{
  pinMode(BIT0, OUTPUT);
  pinMode(BIT1, OUTPUT);
  pinMode(BIT2, OUTPUT);
  pinMode(BIT3, OUTPUT);
}

void loop()
{
  for (int numero = 0; numero <= 15; numero++)
  {
    digitalWrite(BIT0, bitRead(numero, 0));
    digitalWrite(BIT1, bitRead(numero, 1));
    digitalWrite(BIT2, bitRead(numero, 2));
    digitalWrite(BIT3, bitRead(numero, 3));

    delay(tiempo_espera);
  }
}