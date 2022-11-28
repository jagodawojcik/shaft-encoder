#include <LiquidCrystal_I2C.h>

#define out A5
#define in1 2
#define in2 3
#define in3 4
LiquidCrystal_I2C lcd(0x20, 20, 4);

int t = 5;
int values[8] = {3, 7, 6, 1, 0, 4, 5, 1};
int last_position = -1;

void setup() {
  pinMode(out, OUTPUT);  
  pinMode(in1, INPUT);
  pinMode(in2, INPUT);  
  pinMode(in3, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3, 1);
  Serial.begin(9600);

}

void loop() {
  analogWrite (out, 500);
  
  int led1 = digitalRead(in1);
  int led2 = digitalRead(in2);
  int led3 = digitalRead(in3);

  int val= 1*led1+2*led2+4*led3;
  int position= values[val];

  if (last_position != position)
  {    
    lcd.clear(); 
    lcd.setCursor(1, 0);
    lcd.print("Position: ");
    lcd.setCursor(11, 0);
    lcd.print(position);
    last_position = position;
  }

  Serial.println(position);
  delay(100);
}
