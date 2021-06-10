#define trigPin 12
#define echoPin 13
#define buzzer 11
int frequency = 0;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}


int calculateDistance() {
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  return distance; 
}


void loop() {
  int distance = calculateDistance(); 
  
  frequency = (distance * 50);

  Serial.println(frequency);

    if (distance <= 80) { 
      tone(buzzer, distance * 50);
    }
    
    else {
      noTone(buzzer);
    }
    
    delay(50);
 }

