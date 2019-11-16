#include <SPI.h>
#include <mcp_can.h>

const int spiCSPin = 10;

MCP_CAN CAN(spiCSPin);

void setup()
{    
    Serial.begin(9600);
    CAN.begin(CAN_1000KBPS);
}

void loop()
{

  unsigned char c[1];
    
  if (Serial.available() > 0)
  {         
      c[0] = Serial.read(); 
      Serial.flush();
                       
  }

  CAN.sendMsgBuf(0x43, 0, 1, c);
  delay(200);
}

/*void loop()
{  
  String frase;
    
  while (Serial.available() > 0)
  {         
      char c = Serial.read();  
      Serial.flush();    
      unsigned long now = millis();
      if(c == '\n')
      {
        while(millis() - now < 1000) Serial.read();
        break;       
      }      
      frase += c;               
  }     
  Serial.println(frase);  
}*/
