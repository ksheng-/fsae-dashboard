const int pot = A0;
const int bcdPins[] = {2,3,4,5};
const unsigned char mask = 1;

void setup(){
  for(int i =0; i<sizeof(bcdPins)/sizeof(int);i++){
    pinMode(bcdPins[i], OUTPUT);
  }
}

void loop(){
int sensorVal = analogRead(pot);
unsigned char displayVal = sensorVal/103;
toDecoder(displayVal);
delay(50);
}

void toDecoder(unsigned char num){
  for(int i =0; i<(sizeof(bcdPins)/sizeof(int)); i++){
    digitalWrite(bcdPins[i], (num&mask));
    num = num >> 1;
   }
}
