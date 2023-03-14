#include <U8g2lib.h>

#define OLED_SDA D3
#define OLED_SCL D4
#define LM35 A0


U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, OLED_SCL, OLED_SDA, U8X8_PIN_NONE);

void setup() {
  u8g2.begin();
  Serial.begin(9600);

  //__________________________ Display "Heritage College" on the first page___________________
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.setCursor(15, 20);
  u8g2.print("Heritage Institute ");
  u8g2.setCursor(25, 40);
  u8g2.print("DEPT OF AEIE");
  
  u8g2.sendBuffer();
  delay(10000);
  u8g2.clearBuffer();
}




void loop() {
  int delayTime = 1000; // Set the delay time to 2 seconds
  u8g2.clearBuffer();
  

 //_________________________________________________display part __________________________

 
  // Display "Amit Sutradhar" on the second page__________1
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.setCursor(40, 30);
  u8g2.print("DC SIR");
  u8g2.setCursor(20, 45);
  u8g2.print("Amit Sutradhar");
  u8g2.sendBuffer();
  delay(delayTime);
  
  u8g2.clearBuffer();


  
  // Display temperature on the third page_________________2 
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.setCursor(30, 30);
  u8g2.print("Temperature:");
  
  float temperature = getTemperature();
  u8g2.setCursor(40, 45);
  u8g2.print(temperature, 1);
  u8g2.print(" degC");
  
  u8g2.sendBuffer();
  delay(delayTime);

  // Print temperature on serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" degC");
}

float getTemperature() {
  int sensorValue = analogRead(LM35);
  float voltage = sensorValue * (5.0 / 1023.0);  
  float temperature = voltage * 60.0;
  return temperature;
}
