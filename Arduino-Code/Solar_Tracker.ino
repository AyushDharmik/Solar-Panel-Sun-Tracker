#include <Servo.h>

Servo servo_7;

int left_value = 0;
int right_value = 0;

int pos = 90;   // start at center

void setup()
{
  servo_7.attach(4);      // servo on pin 4
  servo_7.write(pos);     
  Serial.begin(9600);     
}

void loop()
{
  left_value = analogRead(A1);   // left LDR
  right_value = analogRead(A0);  // right LDR

  int threshold = 50;   // sensitivity (adjust if needed)

  // Debug values
  Serial.print("Left: ");
  Serial.print(left_value);
  Serial.print("  Right: ");
  Serial.println(right_value);

  // Movement logic
  if (left_value > right_value + threshold) {
    pos = pos + 3;   // move fast right
  } 
  else if (right_value > left_value + threshold) {
    pos = pos - 3;   // move fast left
  }

  // Limit to 0–180 degrees
  pos = constrain(pos, 0, 150);

  servo_7.write(pos);

  delay(10);   // small delay = faster response
}
