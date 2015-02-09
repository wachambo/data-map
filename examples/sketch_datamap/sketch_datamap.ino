#include <DataMap.h>

DataMap DM;

void setup() {
  // initialize serial communications
  Serial.begin(9600);

  DM.add("sensor0", "4573 - YES");
  DM.add("temperature", "25.8");
  DM.add("location" , "4234.34234, 2895.234");
}

void loop() {  
  String s;
  char buffer[30];
  
  Serial.print("size: ");
  Serial.println(DM.getSize());
  
  
  s = DM.lookup("sensor0");
  Serial.println(s);
  s = DM.lookup("temperature");
  Serial.println(s);
  s = DM.lookup("location");
  Serial.println(s);
  
  
  DM.remove("temperature");
  s = DM.lookup("temperature");
  Serial.println(s);
  Serial.println(DM.getSize());
  
  
  
  while(true);
}