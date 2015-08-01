/*
KnightRider with Fading Effect V1
This is assignment for Fachkurs Interaction Foundations I of Krisitian Gohlke.
This Arduino controls 6 LED in a loop with fading effect. You can already inspect the result in serial monitor without wiring.
by Weng Xinyu in Wintersemester 2011/2012

*Note that LED 1 is LED[0] in sketch

LED 1  |----+----|
LED 2  :    |----+----|
LED 3  :    :    |----+----|
LED 4  :    :    :    |----+----|
LED 5  :    :    :    :    |----+----|
LED 6  :    :    :    :    :    |----+----|
       :    :    :    :    :    :    :    :
POTI   0    H   2H   3H   4H   5H   6H   1023  (H = 1023/7)
---------------------------------------------
For LED L:  |----+----|
            :    :    :
           H*L   :    :             Brightness:0
               H(L+1) :             Brightness:255
                     H(L+2)         Brightness:0

Step 1: check if it is affected, if val is within (H*L,H(L+2)), if true, goto step 2, otherweise turn off.
Step 2: calculate how bright it should be. The brightness is decided by the absolute distance to the middle point: abs(H(L+1)-val),
and map this value to the range from 0 to 255.
*/

const int LED[] = {3,5,6,9,10,11};
const int potPin = A0;
int val;
int H = 1023/7; //divide full poti range by (number of LEDs + 1)
int B; //brightness

void setup(){
  //get all pins ready for output
  for(int i = 0; i<6; i++){
    pinMode(LED[i],OUTPUT);
  }
  Serial.begin(9600);
}

void loop(){
  //read potentiometer
  val = analogRead(potPin);

  //go through each LED
  for(int L = 0; L<6; L++){

    //if poti value falls within the range
    if(val > H*L && val < (L+2)*H){

      //get the absolute distance and map it to (0,255)
      B = abs(val - (L+1)*H);
      B = map(B,0,H,255,0); //note that if distance is 0, brightness is 255

      //output value
      analogWrite(LED[L],B);
      Serial.print(B);
    }
    else{

      //otherwise turn of the LED for better result, otherwise the LED can still dim
      analogWrite(LED[L],0);
      Serial.print(0);
    }
    Serial.print("  ");
  }
  Serial.println();
  delay(10);
}
