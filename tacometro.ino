
int pinoLed = 13; //PINO DIGITAL UTILIZADO PELO LED  

int luz=12;
unsigned long precount=0;
unsigned long count=0;
unsigned int ciclo=0;
unsigned int speed=0;
unsigned long refresh=0;
 #include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <TimerOne.h>
//Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x27,16,2);  
void setup(){  

  pinMode(pinoLed, OUTPUT); //DEFINE O PINO COMO SAÍDA   
   pinMode(luz, OUTPUT);
  digitalWrite(pinoLed, LOW); //LED INICIA DESLIGADO
   digitalWrite(luz,HIGH); 
  lcd.init();
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(blinkLED); // blinkLED to run every 0.15 seconds
  Serial.begin(9600);
}  
 void blinkLED(void)
{
 ciclo=count;
 count=0;
 speed=ciclo*60;
 refresh+=1;
 //lcd.clear();
}
  
void interrupcao(){
 precount++;
 if(precount>=3){
  count+=1;
  precount=0;
 }
// Serial.println(count);
 }
void loop(){
  if(refresh>=4){
    refresh=0;
    lcd.clear();
  }
   lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
  lcd.print("Ciclos:");
  lcd.print(ciclo);
  lcd.setCursor(1,1);
  lcd.print("RPM:");
  lcd.print(speed);
   attachInterrupt(0,interrupcao,RISING); //
 // if (digitalRead(pinoSensor) == HIGH){ //SE A LEITURA DO PINO FOR IGUAL A LOW, FAZ
  //      digitalWrite(pinoLed, LOW); //ACENDE O LED
  //}else{//SENÃO, FAZ
 //       digitalWrite(pinoLed, HIGH); //apaga O LED
 // }    
}
