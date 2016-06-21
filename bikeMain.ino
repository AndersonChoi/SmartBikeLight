#include <NS_Rainbow.h>

#define PIN1 11
#define PIN2 12
#define N_CELL1 16
#define N_CELL2 16
#define LIGHT_PIN 0

NS_Rainbow ns_stick = NS_Rainbow(N_CELL1,PIN1);
NS_Rainbow ns_stick2 = NS_Rainbow(N_CELL2,PIN2);

void setup() {
  delay(100);
  ns_stick.begin();
  ns_stick2.begin();
  ns_stick.setBrightness(255);   
  ns_stick2.setBrightness(255);   
  Serial.begin(9600);   
  pinMode( LIGHT_PIN, OUTPUT );
}

void loop() {
  unsigned int   t = 50;   // t: delay time
  unsigned int  i=0;
  int bright=0;
  int analog_bright=analogRead(LIGHT_PIN);
  
  Serial.println(analog_bright);//400~800
  bright=800-analog_bright;
  if(bright<0)
    bright=0;
    
  if(bright>140)
    bright=255;
    
  Serial.print("bright:");
  Serial.println(bright);

  setBrightAndColor(&ns_stick,bright);
  setBrightAndColor(&ns_stick2,bright);
  
  delay(t); 
}

void setBrightAndColor(NS_Rainbow *stick,int bright)
{
  int i=0;
  for(i=0;i<16;i++)
  {
    stick->setBrightness(bright);   
    stick->setColor(i, 255,   255,   255); 
  }   
  stick->show();
}
