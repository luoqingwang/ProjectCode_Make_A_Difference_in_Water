//* Infrared control water pump + left water flow sensor

int ledPin = 13; //
int pirPin = 7;  // Infrared induction
int pirValue;
int sec = 0;

//Hall Sensor 
volatile int NbTopsFan; //Define function NbTopsFan
int Calc; //Define function Calc 
int hallsensor = 2; //Define hallsensor as Digital port 2

int flag; //Define flag 
void rpmLeft()
{
NbTopsFan++; //function automatically +1

}

void setup(){
  
  // Set the pump pin as an output
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);

  digitalWrite(ledPin, LOW);
  Serial.begin(9600);

  // Set the Hall water flow sensor as the input signal
  pinMode(hallsensor, INPUT); //Define hallsensor as input signal
  Serial.begin(9600); //Define the baud rate to 9600
//  Serial.print("Detect water flow"); 
  delay(1000);
  attachInterrupt(0, rpmLeft, RISING); 
  //attachInterrupt(0, rpmRight, RISING); 

}

void loop (){
  
  NbTopsFan = 0; //NbTops initial value is 0
  sei(); 
  delay (1000); //1 second delay
  cli(); 
  Calc = (NbTopsFan * 60 / 8.1); //(Pulse frequency×60)/ 8.1 Q,=flow L /hr 
  if(Calc > 0){
  
    Serial.print(1);
//    Serial.println("left water");
    }
    
  WaterPump();

  }

void WaterPump(){
  
  pirValue = digitalRead(pirPin);
//  Serial.println(pirValue);

  if (pirValue == 1){
    digitalWrite(ledPin, HIGH);
  
//    Serial.println("Motion detected");

        //Turn on water pump
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    delay(30000);
        
    }
    
    else{
      digitalWrite(ledPin,LOW);
//      Serial.println("Nothing Moved");
          //Turn off water pump
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      delay(10000);

       
      }
    
//  
//  digitalWrite(ledPin, pirValue);
//  // 以**释可以观察传感器输出状态
//   sec += 1;
//   Serial.print("Second: ");
//   Serial.print(sec);
//   Serial.print("PIR value: ");
//   Serial.print(pirValue);
//   Serial.print('\n');
//   delay(1000);

 
}
  
  
  
  
