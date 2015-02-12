#include <GSM.h>
#include <TTOpenDataMapStorageCloudProto0.h>


// APN data
#define GPRS_APN       "m2mkit.telefonica.com" // replace your GPRS APN
#define GPRS_LOGIN     "" // replace with your GPRS login
#define GPRS_PASSWORD  "" // replace with your GPRS password
#define INTERNAL_ID    "ARi48"

// initialize the library instance
GPRS gprs;
GSM gsmAccess(true); // include a 'true' parameter for debug enabled

GSMClient theGSMClient;
//TTClient theClient(theGSMClient, INTERNAL_ID, "s1.tts01.net", "/Stack/Receive/", 80);

TTOpenDataMapStorageCloudProto0 DM(theGSMClient, INTERNAL_ID, "s1.tts01.net", "/Stack/Receive/", 80);




void setup()
{
  // initialize serial communications
  Serial.begin(9600);

  
  // connection state
  boolean notConnected = true;

  // Start GSM shield
  // If your SIM has PIN, pass it as a parameter of begin() in quotes
  while(notConnected)
  {
    if((gsmAccess.begin()==GSM_READY) &
        (gprs.attachGPRS(GPRS_APN, GPRS_LOGIN, GPRS_PASSWORD)==GPRS_READY))
      notConnected = false;
    else
    {
      Serial.println("Not connected");
      delay(1000);
    }
  }
  Serial.println("GPRS inicializado.");

  

  Serial.println(DM.add("sensor0", "30 min", "config"));
  Serial.println(DM.add("temperature", "25.8", "measure"));
  Serial.println(DM.add("location" , "4234.34234-2895.234", "measure"));
  Serial.println(DM.add("zulu" , "12:09", "measure"));
}




void loop() 
{
  Serial.println(DM.lookup("sensor0", "config"));
  Serial.println(DM.lookup("temperature", "measure"));
  Serial.println(DM.lookup("location", "measure"));
  Serial.println(DM.lookup("zulu", "measure"));
  
  
  Serial.println(DM.remove("temperature", "measure"));
  Serial.println(DM.lookup("temperature", "measure"));
  Serial.println(DM.lookup("zulu", "measure"));
  
  Serial.println("------------------------");
  delay(1000);
  
  String kind, key, value;
  Serial.println(DM.first());
  while(DM.next(&key, &value, &kind))
    Serial.println(key+" "+value+" "+kind);
  
  


  DM.synch();

  while(true);
}