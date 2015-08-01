void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT); //设置引脚13为输出

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH); //打开数字引脚 13
  delay(1000); //暂停1秒
  digitalWrite(13, LOW); //关闭数字引脚 13
  delay(1000); // 暂停1秒
}

