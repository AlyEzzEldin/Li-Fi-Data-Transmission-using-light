bool previous_state;
bool current_state;
#define PERIOD 15
#define buzzerPin 2

void blink_lol(String morseCode);
void print_morse_code(char Byte);

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
//  pinMode(7, OUTPUT);
  pinMode(buzzerPin,OUTPUT);
}


// the loop function runs over and over again forever
void loop() {

  current_state = get_ldr();
  if(!current_state && previous_state)
  {
    print_morse_code(get_byte());
    
  }
  previous_state = current_state;  
}

bool get_ldr()
{
  int voltage=analogRead(A2);
//  Serial.println(voltage);
  if (voltage>100){return true;}
  else{return false;}
}

char get_byte()
{
  char  ret=0;
  delay(PERIOD*1.5);
  for(int i=0;i<8;i++)
  {
    ret=ret | get_ldr()<<i;
    delay(PERIOD);
  }
  return ret;
}

void print_byte(char Byte){
  char buff[2];
  sprintf(buff,"%c",Byte);
//  Serial.print(buff);

}

void blink_lol(String morseCode) {
  for (int i = 0; i < morseCode.length(); i++) {
    char dotDash = morseCode.charAt(i);
//    char dotDash = morseCode[i];

    if (dotDash == '.') {
      digitalWrite(buzzerPin, HIGH);
      delay(50); // Length of a dot
//      Serial.print(dotDash);
    } else if (dotDash == '-') {
      digitalWrite(buzzerPin, HIGH);
      delay(200); // Length of a dash
//      Serial.print(dotDash);
    }
    else{
//      Serial.print(" ");
    }
    digitalWrite(buzzerPin, LOW);
    delay(50); // Gap between dots and dashes
  }
}


// Morse code representations for each letter
const char* morseCode[] = {
  ".-",   // A
  "-...", // B
  "-.-.", // C
  "-..",  // D
  ".",    // E
  "..-.", // F
  "--.",  // G
  "....", // H
  "..",   // I
  ".---", // J
  "-.-",  // K
  ".-..", // L
  "--",   // M
  "-.",   // N
  "---",  // O
  ".--.", // P
  "--.-", // Q
  ".-.",  // R
  "...",  // S
  "-",    // T
  "..-",  // U
  "...-", // V
  ".--",  // W
  "-..-", // X
  "-.--", // Y
  "--.."  // Z
};


void print_morse_code(char Byte) {
  if (Byte >= 'A' && Byte <= 'Z') {
    int index = Byte - 'A';
    Serial.println(Byte);
    Serial.println(morseCode[index]);
    blink_lol(morseCode[index]);
  } 
  else if(Byte >= 'a' && Byte <= 'z')
  {
    
    int index = Byte - 'a';
    Serial.println(Byte);
    Serial.println(morseCode[index]);
    blink_lol(morseCode[index]);

  }
  else {
    Serial.println("Space");
  }
}
