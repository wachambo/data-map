#include <DataMap.h>
#include <LinkedList.h>
#include <Node.h>

LinkedList<int,char>* L;
Node<int,char>* p = new Node<int,char>(1, 'a');
Node<int,char>* q = new Node<int,char>(2, 'b');
Node<int,char>* r = new Node<int,char>(3, 'c');
  
  
void setup() {
  // initialize serial communications
  Serial.begin(9600);
  
  Serial.println("uno");

  
  Serial.println("dos");
  L = new LinkedList<int,char>();
  
  Serial.println("tres");
}

void loop() {
  Serial.println(L->getSize());
  L->add(p);
  char* c = L->getValue(1);
  if (c)
    Serial.println(*c);
  else Serial.println("ES NULL");
  
  Serial.println(L->getSize());
  
  
  L->add(q);
  c = L->getValue(2);
  if (c)
    Serial.println(*c);
  else Serial.println("ES NULL");
  
  Serial.println(L->getSize());
  
  
  
  L->add(r);
  
  
  delay(3000);
  
  
  //Serial.println(p->getValue());
  
  Serial.println(L->getSize());
  showall();
  
  
  L->remove(2);
  
  //showall();
  c = L->getValue(2);
  if (c)
    Serial.println(*c);
  else Serial.println("ES NULL");
  
  Serial.println(L->getSize());
  showall();
  
  while(true);
}


void showall() {
  for (int i = 1; i <= 3; i++) {
    char* c = L->getValue(i);
    if (c)
      Serial.println(*c);
    else Serial.println("ES NULL");
  }
}
