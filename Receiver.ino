bool previous_state;
bool current_state;
#define PERIOD 15
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(7, OUTPUT);
}


// the loop function runs over and over again forever
void loop() {
  current_state = get_ldr();
  if(!current_state && previous_state)
  {
    print_byte(get_byte());
    
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
  Serial.print(buff);
}
