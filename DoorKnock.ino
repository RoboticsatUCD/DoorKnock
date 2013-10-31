const int TIMEOUT = 3000;
const int ARRSIZE = 100;
const int THRESHOLD = 5;

//PINS
const int pLED = 13;
const int pPROG = 4;
const int pKNOCK = A0;

int i = 0;
unsigned long pattern[ARRSIZE], input[ARRSIZE];
unsigned long startTime, len;

void setup() {
  pinMode(pLED, OUTPUT);
  Serial.begin(115200);
}

void blinkLED(int time)
{ 
  digitalWrite(pLED, HIGH);
  delay(time);
  digitalWrite(pLED, LOW);
}

bool getKnock(int timeout)
{
  startTime = millis();
  int k;
  unsigned long j = 0;
  while(j++ < timeout)
  {
    if(analogRead(pKNOCK) > THRESHOLD)
    {
      len = startTime - millis();
      blinkLED(50);
      return true;
    }
  } 
  return false;
}

void setPattern()
{
  i = 0;
  while(getKnock(TIMEOUT))
  {
    if(i == 0) //discard the time to the first knock, since that's what will trigger the start of our pattern
      i++;
    else
      pattern[i++] = len;
  }
}

bool comparePattern()
{
  i = 0;
  
}

void loop() {
  getKnock(TIMEOUT); 
}
