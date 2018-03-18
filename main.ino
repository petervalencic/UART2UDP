#include <string.h>

const byte numChars = 20;
char receivedChars[numChars];

byte ndx = 0;
boolean isFirst = 0;


void setup() {
  Serial.begin(9600);
  Serial.println("Begin..");

}

void loop() {

  //read from serial port..
  if (Serial.available() > 0) {
    char rc = Serial.read();

    //if flag is true then begin to parse
    if (isFirst == true)
    {
      //if read char is ',' then send string over ethernet... and eraye array..
      if (rc == ',')
      {
        if (ndx > 0)
        {
          Serial.print("T");
          Serial.println(receivedChars);
          Serial.println(ndx);
        }
        ndx = 0;
        memset(&receivedChars[0], 0, sizeof(receivedChars));
      }
      else
      {
        receivedChars[ndx] = rc;
        ndx++;
      }

    }

    //read until frist ',' thern set a flag to isFirst == true;
    if (rc == ',' && isFirst == false)
    {
      isFirst = true;
      Serial.println("begin");
    }
  }
}

