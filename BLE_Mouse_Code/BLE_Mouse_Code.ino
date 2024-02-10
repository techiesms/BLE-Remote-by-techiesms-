// Include BLE Mouse library
#include <BleMouse.h>


// RBG led pin definition
#define G D0
#define R D2
#define B D4

// definition for button connected to XIAO C3
#define U_BUT D1
#define L_BUT D3
#define C_BUT D5
#define R_BUT D7
#define D_BUT D9

// BLEMOUSE gloal declaration
BleMouse bleMouse;

bool status = true;

void setup()
{
  Serial.begin(115200);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);

  pinMode(U_BUT, INPUT_PULLUP);
  pinMode(L_BUT, INPUT_PULLUP);
  pinMode(C_BUT, INPUT_PULLUP);
  pinMode(R_BUT, INPUT_PULLUP);
  pinMode(D_BUT, INPUT_PULLUP);

  bleMouse.begin();
}

void loop()
{
  if (bleMouse.isConnected())
  {
    if (status == true)
    {
      digitalWrite(G,HIGH);
      delay(3000);
      status = false;
    }
    digitalWrite(G,LOW);
    mouseconnected();
  }

  else
  {
    not_connected();
  }
}

// when bluetooth is not connected
void not_connected()
{
  digitalWrite(R,HIGH);
  delay(500);
  digitalWrite(R,LOW);
  delay(500);

  digitalWrite(G,LOW);
  digitalWrite(B,LOW);
  status = true;
}
// when bluetooth is connected and but is presses led
void but_pressed()
{
  digitalWrite(B,HIGH);
}
// delay between data
void ScrollDelay()
{
  delay(50);
}
// to read button value and transmit data
void mouseconnected()
{
  if (digitalRead(U_BUT) == 0) {
    bleMouse.move(0, 0, 1);
    but_pressed();
    Serial.println("Scrolling UP");
    ScrollDelay();
  }
  if (digitalRead(D_BUT) == 0) {
    bleMouse.move(0, 0, -1);
    but_pressed();
    Serial.println("Scrolling DOWN");
    ScrollDelay();
  }
  if (digitalRead(C_BUT) == 0)
  {
    bleMouse.click(MOUSE_LEFT);
    but_pressed();
    Serial.println("Centre Click");
    delay(250);
  }
  if (digitalRead(L_BUT) == 0)
  {
    bleMouse.click(MOUSE_LEFT);
    but_pressed();
    Serial.println("Left Click");
    delay(250);
  }
  if (digitalRead(R_BUT) == 0) {
    bleMouse.click(MOUSE_RIGHT);
    but_pressed();
    Serial.println("Right Click");
    delay(250);
  }
  else
  {
    digitalWrite(B,LOW);
  }
}
