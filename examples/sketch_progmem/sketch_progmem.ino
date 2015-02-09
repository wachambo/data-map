#include <avr/pgmspace.h>

const char message[] PROGMEM = "Hello World";
char buffer[30];

void setup() {
  Serial.begin(9600);
}

void loop() {
  strcpy_flash(buffer, message);
  Serial.println(".........");
  Serial.println(buffer);
  
  while(true);
}


/** Copy the string in program memory (Flash) into a string in SRAM
  @param[out] str is the string allocated in SRAM memory
  @param[in] p_str is the string allocated in program memory (Flash)
 */
void strcpy_flash (char* str, const char* p_str)
{
  for (int i=0; char c = (char)pgm_read_byte(&p_str[i]); i++)
      //Serial.println(c);
      str[i] = c;
}
