#include <LiquidCrystal.h>
#include <Keypad.h>

char keys [4][4] = {
  {'1','2','3','+'}
  {'4','5','6','-'}
  {'7','8','9','*'}
  {'1','2','3','/'}};

byte pinesFilas [4] = {8,9,10,11};
byte pinesColumnas [4] = {A0,A1,A2,A3};

Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, 4,4);

char key;

char op;
long num1, num2;
bool num1Complete = false;

void setup() {
  lcd.begin(16,2);
}

void loop() {

key = teclado.getKey();
  if(key){
        {
          if(key == '1'||key == '2'||key == '3'||key == '4'||key == '5'||key == '6'
          ||key == '7'||key == '8'||key == '9'||key == '0')
          {
            if(num1Complete == false){
              num1 += key;
            }
            else{
              num2+= key;
            }
          }
          else{
            if(num1Complete == false){
              op = key;
              num1Complete = true;
            }
            else{
              if(op=='+'){num1 = num1.toInt() + num2.toInt();}
              if(op=='-'){num1 = num1.toInt() - num2.toInt();}
              if(op=='*'){num1 = num1.toInt() * num2.toInt();}
              if(op=='/'){num1 = num1.toInt() / num2.toInt();}
              num2 = "";
              op = key;
            }
          }
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("");
          lcd.print(op);
          lcd.print("");
          lcd.print(num2);  
  }
  delay(100)
}
