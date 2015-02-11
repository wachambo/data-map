/*
	Muestra los tokens separados por comas dentro de una cadena
*/

void setup() {
	Serial.begin(9600);

	String prueba = "#3,GM,key,value,0$,#3,GC,uno,dos,0$,#3,GC,tres,cuatro,0$";
	String token;
	String key, value;

	do {
		parseData(&prueba, &key, &value);
		//Serial.println(key +"-"+ value);
		//delay(1000);
	} while (prueba.length());
}


void loop() {}


String getToken(String* str, const char delimiter) {
	String token;

	if (!str) 
		return "";

	int index = str->indexOf(delimiter, 0);
	if (index != -1) {
		token = str->substring(0, index);
		*str = str->substring(index+1);
		return token;
	}
	return "";
}


void parseData(String* str, String* key, String* value) {
	String split_sharp;
	String split_comma;

	split_sharp = getToken(str, '#');
	Serial.println(split_sharp);
	delay(1000);

	for (int pos = 0; pos < 5; pos++) {
		split_comma = getToken(&split_sharp, ',');
		Serial.println("  "+split_comma);

		switch(pos) {
			case 1: if (split_comma.equals("GM")) return;	// we're only interested in GC"
			case 2: *key = split_comma; break;
			case 3: *value = split_comma; break;
			default: break;
		}
	}
}
