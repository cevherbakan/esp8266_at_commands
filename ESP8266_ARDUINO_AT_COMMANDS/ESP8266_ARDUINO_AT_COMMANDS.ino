
#include <SoftwareSerial.h>
SoftwareSerial ESPserial(10, 11); // RX | TX


int dogru;
int yanlis;

void setup() 
{
    Serial.begin(9600);    

    ESPserial.begin(9600);  
 
    Serial.println("");
    Serial.println("çalışıyor");
        delay(2000);
    Serial.println("hazır");
    Serial.println("");

    ESPserial.println("AT+IPR=9600");
        readSerial();
        
         ESPserial.println("AT+GMR");
         readSerial();

        ESPserial.println("AT");
        readSerial();
        ESPserial.println("AT+CWJAP=\"GHOST\",\"12345678\"");
        readSerial();
        ESPserial.println("AT+CWMODE=1");
        readSerial();
        ESPserial.println("AT+CIPMUX=0");
        readSerial();

        
        
  
}
 
void loop() 
{
        ESPserial.println("AT+CIPSTART=\"TCP\",\"167.71.121.3\",80");
        readSerial();

                ESPserial.println("AT+CIPSEND=49");
        readSerial();
                ESPserial.println("GET /methods/getAllDayTimeSituation.php?key=123");
                //ESPserial.println("GET /methods/getInstantRequest.php?key=123");
                                     
        readSerial();
}

void readSerial()
{
        delay(20);//200
     if( ESPserial.available())   {  
      String val= ESPserial.readString();
      Serial.println(val);


      }

 }
