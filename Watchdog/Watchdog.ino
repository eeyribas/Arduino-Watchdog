#include <avr/wdt.h>

/*
Watchdog Time Setting Table for different Arduino controllers

THRESHOLD VALUE  CONSTANT NAME SUPPORTED ON
15 ms WDTO_15MS ATMega 8, 168, 328, 1280, 2560
30 ms WDTO_30MS ATMega 8, 168, 328, 1280, 2560
60 ms WDTO_60MS ATMega 8, 168, 328, 1280, 2560
120 ms  WDTO_120MS  ATMega 8, 168, 328, 1280, 2560
250 ms  WDTO_250MS  ATMega 8, 168, 328, 1280, 2560
500 ms  WDTO_500MS  ATMega 8, 168, 328, 1280, 2560
1 s WDTO_1S ATMega 8, 168, 328, 1280, 2560
2 s WDTO_2S ATMega 8, 168, 328, 1280, 2560
4 s WDTO_4S ATMega 168, 328, 1280, 2560
8 s WDTO_8S ATMega 168, 328, 1280, 2560
*/

void setup() 
{
  Serial.begin(9600);

  pinMode(8, OUTPUT);
  wdt_enable(WDTO_8S);
  digitalWrite(8, LOW);
}

void loop() 
{
  char get_data = 'a';
  if (Serial.available()) {
    get_data = Serial.read();
    if (get_data == '1')
      digitalWrite(8, LOW);
    else
      digitalWrite(8, HIGH);

    wdt_reset();
  }
}