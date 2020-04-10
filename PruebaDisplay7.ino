//Paso 1
const int pins[7] = { 2, 3, 4, 5, 6, 7, 8 }; //Declaramos los puertos
//Paso 2
//Un display tiene 7 segmentos, cada segmento tiene una letra que la representa
//para encender un segmento utilizamos el número 0 (cero); 1 (uno) es para apagarlo
//Buscar el orden de los segmentos y representar el caracter que se desea mostra
//el orden es gfedcba
//el 0b es para indicar que es binario debe ir antes de cada fila del array
                                  //    gfedcba
const byte numbersDisplayAnode[10] = {0b1000000,     //0
                                
                                  0b1111001, //1
                                  0b0100100, //2
                                  0b0110000, //3
                                  0b0011001, //4
                                  0b0010010, //5
                                  0b0000010, //6
                                  0b1111000, //7
                                  0b0000000, //8
                                  0b0010000}; //9
                                  

void setup() {
  //Paso 3
  //recorre todos los puertos y les indica que son de salida
  for(int i = 0; i < 7; i++) {
    pinMode(pins[i], OUTPUT);  
  }

  //Paso 5
  lightSegments(0);
}

void loop() {
  //Paso 6
  //Mantiene el ciclo, con un retraso de 1000
  for(int i = 0; i < 10; i++) {
    lightSegments(i);
    delay(1000);
  }
}

//Paso 4
//Recorre uno por uno cada linea de la matriz
//enciende cada segmento
void lightSegments(int number) {
  byte numberBit = numbersDisplayAnode[number];
  for (int i = 0; i < 7; i++)  {
    int bit = bitRead(numberBit, i);
    digitalWrite(pins[i], bit);
  }
}
