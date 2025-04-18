const int SEGMENT[] = {0,1,2,3,4,5,6};
const int PIN[] = {7,8,9,10,11,12,13};
const byte digitPatterns[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void tens(int digit)
{
  byte pattern = digitPatterns[digit];
  for(int i = 0; i < 7; i++ )
  {
  	digitalWrite(PIN[i], bitRead(pattern, i));
  }
}
                 
void ones(int digit)
{
  byte pattern = digitPatterns[digit];
  for(int i = 0; i < 7; i++ )
  {
  	digitalWrite(SEGMENT[i], bitRead(pattern, i));
  }
}
                 
void setup()
{
  for(int i = 0; i < 7; i++)
  {
    pinMode(SEGMENT[i], OUTPUT);
    pinMode(PIN[i], OUTPUT);
  }
}
             
void loop()
{
  for(int i = 0; i < 10; i++)
  {
    for(int j = 0; j < 10; j++)
    {
      tens(i);
      ones(j);
      delay(1000);
    }
  }
}
