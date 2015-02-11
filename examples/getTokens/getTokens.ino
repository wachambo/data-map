/*
	Muestra los tokens separados por comas dentro de una cadena
*/

void setup() {
	Serial.begin(9600);

	String prueba = "#3,GM,key,value,0$";
	String token;

	do {
		token = getToken(&prueba, ',');
		Serial.println(token);
	} while (token.length());
}


void loop() {}


String getToken(String* str, const char delimiter) {
	String token;

	if (!str) 
		return "";

	int index = str->indexOf(delimiter, 0);
	//Serial.println(index);
	//delay(1000);
	if (index != -1) {
		token = str->substring(0, index);
		//Serial.println(token);
		*str = str->substring(index+1);
		//Serial.println(*str);
		return token;
	}
	return "";
}