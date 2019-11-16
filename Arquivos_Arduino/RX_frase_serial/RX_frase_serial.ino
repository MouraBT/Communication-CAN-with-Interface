#include <SPI.h>
#include "mcp_can.h"

const int spiCSPin = 10;


MCP_CAN CAN(spiCSPin);

void setup()
{
    Serial.begin(9600);
    pinMode(ledPin,OUTPUT);

    while (CAN_OK != CAN.begin(CAN_1000KBPS))
    {
        //Serial.println("CAN BUS Init Failed");
        delay(100);
    }
    //Serial.println("CAN BUS  Init OK!");
}


void loop()
{
    unsigned char len = 0;
    unsigned char buf[8];

    if(CAN_MSGAVAIL == CAN.checkReceive())
    {
        CAN.readMsgBuf(&len, buf);

        unsigned long canId = CAN.getCanId();

        for(int i = 0; i<len; i++)
        {
            Serial.print(char(buf[i]));
         
        }
        Serial.println();
    }
}
