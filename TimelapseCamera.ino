#define cameraPin 14 //pa02, pin 3

const long pictureDelayNum = 20000; //picture every 20,000 ms = 20 s 
long pictureDelayStart;

unsigned long currentTs;

void setup() {

  pinMode(cameraPin, OUTPUT);
  digitalWrite(cameraPin, HIGH); 

  pictureDelayStart = millis();
}

void loop() {

  currentTs = millis();

  if ((currentTs - pictureDelayStart) >= pictureDelayNum){
    
    digitalWrite(cameraPin, LOW);   
  
    delay(50);               
   
    digitalWrite(cameraPin, HIGH);      
  }
 
  
}
