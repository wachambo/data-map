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
		Serial.println(key +"-"+ value);
	} while (prueba.length());
}


void loop() {}


String getToken(String* str, const char delimiter) {
	String token;

	if (!str) 
		return "";

	int index = str->indexOf(delimiter, 0);
	//Serial.print(index);

	switch (index) {
	    case -1:	// delimiter was not found
	    	token = *str;  
			*str = "";
	      	break;
	    case 0:
	    	token = "";
	      	*str = str->substring(index+1);
	      	break;
	    default:
	    	token = str->substring(0, index);
	    	*str = str->substring(index+1);
	}
	return token;
}


void parseData(String* str, String* key, String* value) {
	String split_sharp;
	String split_comma;

	split_sharp = getToken(str, '#');
	//Serial.println(split_sharp +"--->");
	//Serial.println(" +++ " + *str);
	delay(1000);

	// check the 5 elements of each token GM/GC
	for (int pos = 0; pos < 5; pos++) {
		split_comma = getToken(&split_sharp, ',');
		//Serial.println("  "+split_comma);

		switch(pos) {
			case 1: if (split_comma.equals("GM")) return;	// we're only interested in GC"
			case 2: *key = split_comma; break;
			case 3: *value = split_comma; break;
		}
	}
}



/*
void setup() {
	Serial.begin(9600);

	String *prueba = new String("#3,GM,key,value,0$,#3,GC,uno,dos,0$,#3,GC,tres,cuatro,0$");
	String *token;
	String *key, *value;

	do {
		Serial.println("~~~~~~~~~~"+ *prueba +"~~~~~~~~~");
		parseData(prueba, key, value);
		//if (key && value)
			//Serial.println(*key +"-"+ *value);
	} while (prueba);
}


void loop() {}


String* getToken(String* str, const char delimiter) {
	String *token;

	if (!str) 
		return NULL;

	int index = str->indexOf(delimiter, 0);
	//Serial.print(index);

	switch (index) {
	    case -1:	// delimiter was not found
	    	token = str;  
			str = NULL;
	      	break;
	    case 0:
	    	token = NULL;
	      	*str = str->substring(index+1);
	      	break;
	    default:
	    	Serial.println("entra aqui");
	    	Serial.println(*str);
	    	Serial.println("----");
	    	*token = str->substring(0, index);
	    	*str = str->substring(index+1);
	    	Serial.println(*token);
	    	Serial.println(*str);
	}
	return token;
}


void parseData(String* str, String* key, String* value) {
	String *split_sharp;
	String *split_comma;

	split_sharp = getToken(str, '#');
	if (split_sharp) Serial.println(*split_sharp +"--->");
	else return;
	delay(1000);

	// check the 5 elements of each token GM/GC
	for (int pos = 0; pos < 5; pos++) {
		split_comma = getToken(split_sharp, ',');
		//Serial.println("  "+split_comma);

		switch(pos) {
			case 1: if (split_comma->equals("GM")) return;	// we're only interested in GC"
			case 2: *key = *split_comma; break;
			case 3: *value = *split_comma; break;
		}
	}
}
*/