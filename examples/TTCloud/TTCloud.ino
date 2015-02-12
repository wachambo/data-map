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

// instance the data map
TTOpenDataMapStorageCloudProto0 DM(theGSMClient, INTERNAL_ID, "s1.tts01.net", "/Stack/Receive/", 80);


const int b = 10;	// digital out pin
const int a = A1;  	// analog input pin
int aValue = 0;  	// variable to store the value coming from the analog input
int bValue = LOW;	// variable to store the digital output value

void setup() {
	// initialize serial communications at 9600 bps:
  	Serial.begin(9600);

  	// initialize digital pin 10 as an output.
  	pinMode(b, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
	// read the analog in value:
	aValue = analogRead(a);
	// map it to the range of the analog out:
	aValue = map(aValue, 0, 1023, 0, 255);

	Serial.println(aValue);
	delay(1000);


	DM.add("a", String(aValue), "measure");
 	DM.add("b", String(bValue), "config");

 	// synchronize with the cloud
	DM.synch();

	// update the digital pin with the new configuration
 	digitalWrite(b, String(bValue));
}
