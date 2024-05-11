#include <IRremote.h>
#define sagmotorhiz 11
#define solmotorhiz 6
#define sagmotoron 12
#define solmotoron 8
#define sagmotorarka 10
#define solmotorarka 9
#define IR_PIN 2 // Pin for IR receiver

IRrecv irrecv(IR_PIN);
decode_results results;

void setup()
{
  pinMode(sagmotorhiz, OUTPUT);
  pinMode(solmotorhiz, OUTPUT);
  pinMode(sagmotoron, OUTPUT);
  pinMode(solmotoron, OUTPUT);
  pinMode(sagmotorarka, OUTPUT);
  pinMode(solmotorarka, OUTPUT);
  irrecv.enableIRIn(); // Start the IR receiver
}

void loop()
{
 if (irrecv.decode(&results)) {
    switch(results.value) {
      case 0xE5139CA7: // Forward
        ileri();
        delay(400);
        dur();
        break;
      case 0xAD5163FB: // Backward
        geri();
        delay(400);
        dur();
        break;
      case 0x9912B99A: // Right
        sag();
        delay(400);
        dur();
        break;
      case 0xDB9D3097: // Left
        sol();
        delay(400);
        dur();
        break;
      case 0xB411F6DE:// stop
        dur();
        break;  
    }
    irrecv.resume(); // Receive the next value
  }
  delay(5); // Delay to avoid overwhelming the IR receiver
}

void ileri()
{
  analogWrite(sagmotorhiz, 255);
    digitalWrite(sagmotoron, 1);
  digitalWrite(sagmotorarka, 0);

  analogWrite(solmotorhiz, 255);
  digitalWrite(solmotoron, 1);
  digitalWrite(solmotorarka, 0);
}

void sag()
{
   analogWrite(sagmotorhiz, 255);
   digitalWrite(sagmotoron, 1);
   digitalWrite(sagmotorarka, 0);
  
  analogWrite(solmotorhiz, 0);
   digitalWrite(solmotoron, 0);
   digitalWrite(solmotorarka, 0);
}
void sol()
{
   analogWrite(sagmotorhiz, 0);
   digitalWrite(sagmotoron, 0);
   digitalWrite(sagmotorarka, 0);
  
  analogWrite(solmotorhiz, 255);
   digitalWrite(solmotoron, 1);
   digitalWrite(solmotorarka, 0);
}
void geri()
{
   analogWrite(sagmotorhiz, 255);
   digitalWrite(sagmotoron, 0);
   digitalWrite(sagmotorarka, 1);
  
  analogWrite(solmotorhiz, 255);
   digitalWrite(solmotoron,0);
   digitalWrite(solmotorarka, 1);
}
void dur()
{
   analogWrite(sagmotorhiz, 0);
   digitalWrite(sagmotoron, 0);
   digitalWrite(sagmotorarka, 0);
  
  analogWrite(solmotorhiz, 0);
   digitalWrite(solmotoron,0);
   digitalWrite(solmotorarka, 0);
}
