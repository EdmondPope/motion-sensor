const int pirPin = 14;
int state = 0;
unsigned long startTime;  // Variable to store the start time


void setup() {
  // put your setup code here, to run once:
pinMode(pirPin, INPUT);
  Serial.begin(115200);
    startTime = millis();    // Record the time when the program starts

}

void loop() {
  // put your main code here, to run repeatedly:
  state = digitalRead(pirPin);
  if (state == HIGH) {
    Serial.println("Somebody here!");
    Serial.println(" ");
  }   

  unsigned long currentTime = millis();            // Get the current time
  unsigned long elapsedTime = currentTime - startTime;  // Calculate elapsed time

  // Convert elapsed time to seconds, minutes, and hours
  unsigned long seconds = elapsedTime / 1000;
  unsigned long minutes = seconds / 60;
  unsigned long hours = minutes / 60;
  seconds = seconds % 60;
  minutes = minutes % 60;

  // Print the elapsed time to the Serial Monitor
  Serial.print("Elapsed Time: ");
  Serial.print(hours);
  Serial.print(" hours ");
  Serial.print(minutes);
  Serial.print(" minutes ");
  Serial.print(seconds);
  Serial.println(" seconds");

  delay(1000);  // Wait for 1 second before printing again
}
