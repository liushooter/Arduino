/*
Note that LED 1 is LED[0] in sketch

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


*/

int timer = 500; // The higher the number, the slower the timing.

void setup() {
  for(int pin = 2; pin < 5; pin++){
    pinMode(pin, OUTPUT);
  }
}

void loop() {
  for(int pin = 2; pin < 5; pin++){
    digitalWrite(pin, HIGH);
    delay(timer);
    digitalWrite(pin, LOW);
  }

  ////////////////////
  for(int pin = 4; pin > 1; pin--){
    digitalWrite(pin, HIGH);
    delay(timer);
    digitalWrite(pin, LOW);
  }

}
