
// Motor A
#define enA 9
#define in1 8
#define in2 7
// Motor B
#define enB 3
#define in3 5
#define in4 4
#define magnetReader 10
#define buzzer 11

// en is for controlling speed
// in is for controlling direction

int okunandeger;
int magnetCount = 0;
int goSpeed = 200;

const int MAX_MAGNET_COUNT = 10;
const int COUNT_DELAY = 250; // ms
const int MAX_SPEED = 120;

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
  pinMode(buzzer, OUTPUT);
	
	git();

  analogWrite(enA, MAX_SPEED);
	analogWrite(enB, MAX_SPEED);
}

void loop() {
  delay(8);
  okunandeger = digitalRead(magnetReader);
  // Serial.println(okunandeger);
  if (okunandeger == MAGNET_FOUND && magnetCount <= MAX_MAGNET_COUNT) {
    magnetCount++;
    Serial.print("------ MIKNATIS SAYILDI, count:");
    Serial.print(magnetCount);
    Serial.println(" ------");
    digitalWrite(buzzer, HIGH);
    git();
    delay(COUNT_DELAY);
    digitalWrite(buzzer, LOW);
  } else if(okunandeger == MAGNET_NOT_FOUND) {
    // Serial.println("------ Haven't found a magnet, continuing... ------");
    // nothing else ig?
  } if(okunandeger != MAGNET_FOUND && okunandeger != MAGNET_NOT_FOUND) {
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
  digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
}
