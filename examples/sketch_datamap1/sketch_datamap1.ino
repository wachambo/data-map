#include <DataMap.h>

DataMap DM;

void setup() {
  // initialize serial communications
  Serial.begin(9600);

  Serial.println(DM.addConfig("sensor0", "30 min"));
  Serial.println(DM.addMeasure("temperature", "25.8"));
  Serial.println(DM.addMeasure("location" , "4234.34234, 2895.234"));
  Serial.println(DM.addMeasure("zulu" , "12:09"));
}

void loop() { 
 
  //String s;
  //char buffer[30];

  Serial.println(DM.lookupConfig("sensor0"));
  Serial.println(DM.lookupMeasure("temperature"));
  Serial.println(DM.lookupMeasure("location"));
  Serial.println(DM.lookupMeasure("zulu"));
  
  
  Serial.println(DM.removeMeasure("temperature"));
  Serial.println(DM.lookupMeasure("temperature"));
  Serial.println(DM.lookupMeasure("zulu"));
  
  while(true);
}
