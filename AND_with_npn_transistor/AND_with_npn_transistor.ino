#include <Arduino_LED_Matrix.h>

//definisco i pin di ingresso A e B con delle costanti
const int A = 12;
const int B = 11; 

//definisco i (mezzi) frame per il display led
// per mostrare   1 e 0
const byte uno [8][6] ={
  {0,0,0,1,0,0},
  {0,0,1,1,0,0},
  {0,1,0,1,0,0},
  {0,0,0,1,0,0},
  {0,0,0,1,0,0},
  {0,0,0,1,0,0},
  {0,0,0,1,0,0},
  {0,0,0,1,0,0}
};

const byte zero [8][6] ={
  {0,1,1,1,1,0},
  {0,1,0,0,1,0},
  {0,1,0,0,1,0},
  {0,1,0,0,1,0},
  {0,1,0,0,1,0},
  {0,1,0,0,1,0},
  {0,1,0,0,1,0},
  {0,1,1,1,1,0}
};
//creo matrice led
ArduinoLEDMatrix led_matrix;

void setup() {
  //setto i pin A e B in modalità OUTPUT
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);

  led_matrix.begin();
  delay(500);
}



void loop() {
  //in sequenza provo tutte le combinazioni
  //della tabella di verità utilizzando la matrice led per indicare
  //i valori immessi in input

  //A = 0 , B = 0
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);

  //mostro su display usando una funzione ad hoc
  mostra_valori_LED(false,false);
  //attendo 5 secondi
  delay(5000);

  //A = 1 , B = 0
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);

  //mostro su display usando una funzione ad hoc
  mostra_valori_LED(true,false);
  //attendo 5 secondi
  delay(5000);

  //A = 0 , B = 1
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);

  //mostro su display usando una funzione ad hoc
  mostra_valori_LED(false,true);
  //attendo 5 secondi
  delay(5000);

  //A = 1 , B = 1
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);

  //mostro su display usando una funzione ad hoc
  mostra_valori_LED(true,true);
  //attendo 5 secondi
  delay(5000);
}


void mostra_valori_LED(bool a, bool b){
  byte all_matrix [8][12];
  if (a){
    for(int i = 0;i<8;i++){
      for(int j = 0;j<6;j++){
          all_matrix[i][j] = uno[i][j];
      }      
    }
  }else{
    for(int i = 0;i<8;i++){
      for(int j = 0;j<6;j++){
          all_matrix[i][j] = zero[i][j];
      }      
    }
  }
  if (b){
    for(int i = 0;i<8;i++){
      for(int j = 6;j<12;j++){
          all_matrix[i][j] = uno[i][j-6];
      }      
    }
  }
  else{
    for(int i = 0;i<8;i++){
      for(int j = 6;j<12;j++){
          all_matrix[i][j] = zero[i][j-6];
      }      
    }
  }
  led_matrix.renderBitmap(all_matrix,8,12);
  delay(500);
}
