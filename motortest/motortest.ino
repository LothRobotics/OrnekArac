
// Motor A
#define enA 9
#define in1 8
#define in2 7
// Motor B
#define enB 3
#define in3 5
#define in4 4


void setup() {
    Serial.begin(9600);
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);

    // Turn off motors
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);

    analogWrite(enA, 255);
	analogWrite(enB, 255);
}

void loop() {
  git();
  delay(500);
  dur();
  delay(500);
}

void dur() {
  Serial.println("DURDU.");
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}

void git() {
  Serial.println("------ GIDIYOR ------");
  analogWrite(enA, 255);
  analogWrite(enB, 255);

  	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
}
