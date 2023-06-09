
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

// 'en' is for controlling speed
// 'in' is for controlling direction

const int MAX_MAGNET_COUNT = 39;

const int MAGNET_OFFSET = 6; // Used for going high speed and start slowing down when necessary
const int STOP_DELAY = 20;
const int MAX_SPEED = 220;

const int COUNT_DELAY = 100; // ms

const int MAGNET_FOUND = 1;
const int MAGNET_NOT_FOUND = 0;

int okunandeger;
int magnetCount = 0;
int goSpeed = MAX_SPEED;

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

  analogWrite(enA, goSpeed);
	analogWrite(enB, goSpeed);
}

void loop() {
  okunandeger = digitalRead(magnetReader);
  Serial.println(okunandeger);
  if (okunandeger == MAGNET_FOUND && magnetCount <= (MAX_MAGNET_COUNT - MAGNET_OFFSET)) {
    magnetCount++;
    Serial.print("------ MIKNATIS SAYILDI, count:");
    Serial.print(magnetCount);
    Serial.println(" ------");
    digitalWrite(buzzer, HIGH);
    git();
    delay(COUNT_DELAY);
    digitalWrite(buzzer, LOW);
  }
  
  if(magnetCount >= (MAX_MAGNET_COUNT - MAGNET_OFFSET)) {
    Serial.println("------ REACHED DESTINATION ------");
    dur();
  }
}

void dur() {
  Serial.println("DURDU.");
  delay(STOP_DELAY);  //  hızlı durmak için X ms bekle
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void git() {
  Serial.println("------ GIDIYOR ------");
  analogWrite(enA, goSpeed);
  analogWrite(enB, goSpeed);
  digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
}
