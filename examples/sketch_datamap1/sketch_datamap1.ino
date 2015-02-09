#include <DataMap.h>

DataMap DM;

void setup() {
  // initialize serial communications
  Serial.begin(9600);

  Serial.println(DM.add("sensor0", "30 min", "config"));
  Serial.println(DM.add("temperature", "25.8", "measure"));
  Serial.println(DM.add("location" , "4234.34234, 2895.234", "measure"));
  Serial.println(DM.add("zulu" , "12:09", "measure"));
}

void loop() { 
 
  //String s;
  //char buffer[30];

  Serial.println(DM.lookup("sensor0", "config"));
  Serial.println(DM.lookup("temperature", "measure"));
  Serial.println(DM.lookup("location", "measure"));
  Serial.println(DM.lookup("zulu", "measure"));
  
  
  Serial.println(DM.remove("temperature", "measure"));
  Serial.println(DM.lookup("temperature", "measure"));
  Serial.println(DM.lookup("zulu", "measure"));
  
  while(true);
}
