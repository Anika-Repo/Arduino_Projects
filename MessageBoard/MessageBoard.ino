#include <LiquidCrystal.h>
int rs = 2, e = 3, d4= 4, d5= 5, d6=6, d7=7, pb=8;
LiquidCrystal lcd(rs,e,d4,d5,d6,d7);

int num = 0;
void setup()
{
  pinMode(pb, INPUT);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Press the pb");
  lcd.setCursor(0,1);
  lcd.print("To see next post");
}

void loop()
{
 	
    while(digitalRead(pb)==LOW)
    {
    	lcd.clear();
		num++;
      	delay(1000);
    
  if (num==1)
  {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Art club friday");
    }
  if (num==2)
  {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("field trip friday");
    }
  if( num==3)
  {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("No school Monday");
    }
    if( num==4)
  {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Num = 0");
   num = 0;
    }
  }
    
}