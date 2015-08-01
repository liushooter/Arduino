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
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2, HIGH);
  delay(timer);
  digitalWrite(2, LOW);

  digitalWrite(3, HIGH);
  delay(timer);
  digitalWrite(3, LOW);
//
  digitalWrite(4, HIGH);
  delay(timer);
  digitalWrite(4, LOW);

  ////////////////////

  digitalWrite(4, HIGH);
  delay(timer);
  digitalWrite(4, LOW);

  digitalWrite(3, HIGH);
  delay(timer);
  digitalWrite(3, LOW);
}
