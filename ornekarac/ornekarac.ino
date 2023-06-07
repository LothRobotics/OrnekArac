// analogRead values go from 0 to 1023, analogWrite values from 0 to 255

// cpp doesnt have ; or type declaration for '#define' for some reason
// this is why I'll use anything other than c/cpp
#define magnetReader 8
#define motor1 A0
#define motor2 A1

int okunandeger;
int magnetCount = 0;

const int MAX_MAGNET_COUNT = 10;
const int COUNT_DELAY = 250; // ms

const int MIKNATIS_VAR = 1;
const int MIKNATIS_YOK = 0;

void setup() {
  pinMode(magnetReader, INPUT);
  pinMode(A0, OUTPUT);  // analog
  Serial.begin(9600);
  analogWrite(motor1, 255);
  analogWrite(motor2, 255);
}

void loop() {
  okunandeger = digitalRead(magnetReader);
  Serial.println(okunandeger);
  if (okunandeger == MIKNATIS_VAR && magnetCount >= MAX_MAGNET_COUNT) {
    magnetCount++;
    Serial.print("------ MIKNATIS SAYILDI, count:");
    Serial.print(magnetCount);
    Serial.println(" ------");
    git();
    delay(COUNT_DELAY);
  } else if(okunandeger == MIKNATIS_YOK) {
    // Serial.println("------ Haven't found a magnet, continuing... ------");
    // nothing else ig?
  } else {
    Serial.println("------ ERR! GOT AN UNEXPECTED VALUE FROM READER ------");
  }

  if(magnetCount >= MAX_MAGNET_COUNT) {
    Serial.println("------ REACHED DESTINATION ------");
    dur();
  }
}

void dur() {
  Serial.println("DURDU.");
  analogWrite(motor1, 0);
  analogWrite(motor2, 0);
}

void git() {
  Serial.println("------ GIDIYOR ------");
  analogWrite(motor1, 255);
  analogWrite(motor2, 255);
}

// kodu türkçe yazmaya başlayıp ing bitirdim lol
