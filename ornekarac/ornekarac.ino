
// Motor A
#define enA 9
#define in1 8
#define in2 7
// Motor B
#define enB 3
#define in3 5
#define in4 4
#define magnetReader 10

// 'en' is for controlling speed
// 'in' is for controlling direction

int okunandeger;
int magnetCount = 0;
int goSpeed = 200;

const int MAX_MAGNET_COUNT = 6;
const int COUNT_DELAY = 100; // ms
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
	
	git();

  analogWrite(enA, MAX_SPEED);
	analogWrite(enB, MAX_SPEED);
}

void loop() {
  okunandeger = digitalRead(magnetReader);
  Serial.println(okunandeger);
  if (okunandeger == MAGNET_FOUND && magnetCount <= MAX_MAGNET_COUNT) {
    magnetCount++;
    Serial.print("------ MIKNATIS SAYILDI, count:");
    Serial.print(magnetCount);
    Serial.println(" ------");
    git();
    delay(COUNT_DELAY);
  } else if(okunandeger == MAGNET_NOT_FOUND) {
    // Serial.println("------ Haven't found a magnet, continuing... ------");
    // nothing else ig?
  } if(okunandeger != MAGNET_FOUND && okunandeger != MAGNET_NOT_FOUND) {
    Serial.println("------ ERR! GOT AN UNEXPECTED VALUE FROM READER ------");
  }

  if(magnetCount >= MAX_MAGNET_COUNT) {
    Serial.println("------ REACHED DESTINATION ------");
    dur();
  }
}

void dur() {
  Serial.println("DURDU.");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(10);  //  hızlı durmak için 10ms geriye git
  
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void git() {
  Serial.println("------ GIDIYOR ------");
  digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
}
