// include the library code:
#include <LiquidCrystal.h>
#include <Wire.h>

#define REDLITE 3
#define GREENLITE 5
#define BLUELITE 6

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);


// you can change the overall brightness by range 0 -> 255
int brightness = 255;
int time; 
int minute;
int seconde;
long milliref;//  varialble for memo of last used milli

void setup() {
  pinMode(REDLITE, OUTPUT);
  pinMode(GREENLITE, OUTPUT);
  pinMode(BLUELITE, OUTPUT);

  lcd.clear(); //clear screen and set cursor to zero
  
  lcd.begin(16, 2); // set up the LCD's number of rows and columns:
  
  setBacklight(200,0,3);//set backlight color to purple
  lcd.print("PRET POUR LES ");// Print a message to the LCD.
  lcd.setCursor(0,1);
  lcd.print("DENTS ETHAN?? :)");
  delay(2000);//wait 2 seconds
  
  int co = 0;//set backlight color to change from purple to orange
  while (co<50){
    setBacklight(200, co, 3);
    delay(70);
    co++;
  }
  
  lcd.clear();
  setBacklight(255, 35, 0);
  lcd.setCursor(2, 0);
  lcd.print("ATTENTION!!!");
  lcd.setCursor(2, 1);
  lcd.print("ATTENTION!!!");
  delay(2000);
  
  lcd.clear();
  
  
 
  
  seconde=19;
  time = 13;
  
  setBacklight(0,255,0);
  lcd.setCursor(0,0);
  lcd.print("C'EST PARTI!!");

  while (time>0){ //beguining of the countdown
    if (millis()>(milliref+1000)){
      lcd.setCursor(12, 1);
      lcd.print(seconde);
      seconde=seconde-1;
      milliref= milliref+1000;
      if (seconde<10){ // change offset of seconds when they < to 10
        lcd.setCursor(13,1);
        lcd.print(seconde);
        lcd.setCursor(12,1);//print a 0 before the new posotions of the seconds
        lcd.print("0");
      }
    }
    
    if (seconde<1){
      time = time-1;
      seconde=14;
      lcd.clear();
      setBacklight(200,0,65);
      lcd.setCursor(0,0);
      lcd.print("CHANGE!!");
      delay(2000);
      lcd.clear();
      setBacklight(0,255,0);
      lcd.setCursor(0,0);
      lcd.print("C'EST PARTI!!");
     
    }      
        
  }  


  if (time <= 0){ // If time gets to 0
    setBacklight(0,255,115);
    lcd.clear();
    delay(500);
    lcd.setCursor(0,0);
    lcd.print("BRAVO!!!!!!");   
    lcd.setCursor(0,1);
    lcd.print("C'est FINI");
    delay(5000);
    lcd.clear();
    delay(1200);
    setBacklight(0,0,0);

    
  }
}


void loop(){
}

void setBacklight(uint8_t r, uint8_t g, uint8_t b) { // declare fuction to change backlight colors 
  // normalize the red LED - its brighter than the rest!
  r = map(r, 0, 255, 0, 100);
  g = map(g, 0, 255, 0, 150);

  r = map(r, 0, 255, 0, brightness);
  g = map(g, 0, 255, 0, brightness);
  b = map(b, 0, 255, 0, brightness);

  // common anode so invert!
  r = map(r, 0, 255, 255, 0);
  g = map(g, 0, 255, 255, 0);
  b = map(b, 0, 255, 255, 0);
  Serial.print("R = "); 
  Serial.print(r, DEC);
  Serial.print(" G = "); 
  Serial.print(g, DEC);
  Serial.print(" B = "); 
  Serial.println(b, DEC);
  analogWrite(REDLITE, r);
  analogWrite(GREENLITE, g);
  analogWrite(BLUELITE, b);
}



