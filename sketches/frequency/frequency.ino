const int pot = A0;
const int bcdPins[] = {2,3,4,5};
const unsigned char mask = 1;
int counter;
int prevVal;
int currentVal;

void setup(){
  for(int i =0; i<sizeof(bcdPins)/sizeof(int);i++){
    pinMode(bcdPins[i], OUTPUT);
    prevVal =1;
  }
    Serial.begin(9600);
}

void loop(){
int freq = getFreq();
//convert freq to displayVal
int displayVal = (freq/10);

toDecoder(displayVal);

}

void toDecoder(unsigned char num){
  for(int i =0; i<(sizeof(bcdPins)/sizeof(int)); i++){
    digitalWrite(bcdPins[i], (num&mask));
    num = num >> 1;
   }
}

int getFreq(){
counter =0;
for(int i =0; i<100; i++){
  int t1=millis();
  int sensorVal = analogRead(pot);
  if(sensorVal<300)
    currentVal =0;
  if(sensorVal>800)
    currentVal = 1;
  if(prevVal!=currentVal)
    counter++;
  prevVal=currentVal;
  int t2=millis();
  delay(5-(t2-t1));
   Serial.println(sensorVal);
}
 ;
  return (counter);
}
