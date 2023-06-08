
// Motor A
#define enA 9
#define in1 8
#define in2 7
// Motor B
#define enB 3
#define in3 5
#define in4 4
#define magnetReader 10

// en is for controlling speed
// in is for controlling direction

int okunandeger;
int magnetCount = 0;
int goSpeed = 200;

const int MAX_MAGNET_COUNT = 10;
const int COUNT_DELAY = 250; // ms

const int MAGNET_FOUND = 1;
const int MAGNET_NOT_FOUND = 0;

void setup() {
  Serial.begin(9600);
  pinMode(magnetReader, INPUT);
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
  delay(16);
  okunandeger = digitalRead(magnetReader);
  // Serial.println(okunandeger);
  if (okunandeger == MAGNET_FOUND && magnetCount >= MAX_MAGNET_COUNT) {
    magnetCount++;
    Serial.print("------ MIKNATIS SAYILDI, count:");
    Serial.print(magnetCount);
    Serial.println(" ------");
    git();
    delay(COUNT_DELAY);
  } else if(okunandeger == MAGNET_NOT_FOUND) {
    // Serial.println("------ Haven't found a magnet, continuing... ------");
    // nothing else ig?
  } else {
    Serial.println("------ ERR! GOT AN UNEXPECTED VALUE FROM READER ------");
  }
  calculateSpeed();
  setSpeed();
}

void calculateSpeed() {
  if (magnetCount <= MAX_MAGNET_COUNT * 0.5) {
    goSpeed = 255;
  } else if (magnetCount >= MAX_MAGNET_COUNT) {
    goSpeed = 0;
    Serial.println("------ REACHED DESTINATION ------");
  } else {
    // maybe get rid of /2
    goSpeed = 255 * (MAX_MAGNET_COUNT / 2 - magnetCount) / MAX_MAGNET_COUNT;
  }
}

void setSpeed() {
  analogWrite(enA, goSpeed);
  analogWrite(enB, goSpeed);
}

void git() {
  Serial.println("------ GIDIYOR ------");
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
}
