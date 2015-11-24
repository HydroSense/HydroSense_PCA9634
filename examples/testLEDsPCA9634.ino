/* LED test program 
  Alan Marchiori
  Bucknell University
  tested on Rev1.1 HydroSense Wireless Link board
  with PCA9634 on i2c address 0x20
  using a TeensyLC MCU on Arduino 1.0.6 (with Teensyduino installed)
  The teensy uses the library i2c_t3 for i2c communication
  instead of the usual "Wire" library. If using a standard Arduino, you will have
  to manually change the inculdes to use Wire. The libraries should be mostly
  compatible. (some calls are "enhanced" in the i2c_t3 library, these will have
  to be modified appropriately as well).
*/

// set this to the hardware serial port you wish to use
//#define HWSERIAL Serial1

#include <i2c_t3.h>
#include "HydroSense_pca9634.h"

HydroSense_pca9634 leds( 0x20 );

void setup() {
  Serial.begin( 9600 );
  Wire.begin( I2C_MASTER, 0x00, I2C_PINS_18_19, I2C_PULLUP_EXT, I2C_RATE_1200 );
  leds.begin( );
}

void loop(){
 leds.set_led ( LED_ERROR, LED_RED );
 delay(1500);  
 
 leds.set_led( LED_SIGNAL, LED_RED );
 delay(1500);  
 leds.set_led( LED_SIGNAL, LED_YELLOW );
 delay(1500);  
 leds.set_led( LED_SIGNAL, LED_GREEN );
 leds.set_led ( LED_ERROR, LED_OFF );
 
 leds.set_led( LED_GPS, LED_RED );
 delay(1500);
 leds.set_led( LED_GPS, LED_YELLOW );
 delay(1500); 
 leds.set_led( LED_GPS, LED_GREEN );
 delay(1500); 
 leds.set_led ( LED_GPS, LED_OFF );
 leds.set_led ( LED_SIGNAL, LED_OFF );
}

int16_t v = 0;
int8_t inc = 1;

void loop1() {
  
  int i, r;
 // Serial.print("Set brightness: ");
  //Serial.print(v);

  for (i=0; i<8; i++){
    r = leds.set_brightness(i, v);
 //   Serial.print(", ");
//    Serial.print(i);
//    Serial.print("=");
//    Serial.print(r);
  }
  
  
//  Serial.println();
  v = v + inc;
 
  if ( inc > 0 && v >= 255){
    inc = -1;    
  } else if (inc < 0 && v <= 0){
    inc = 1;
  }    

  delay (1);
 //delayMicroseconds(100);
}

