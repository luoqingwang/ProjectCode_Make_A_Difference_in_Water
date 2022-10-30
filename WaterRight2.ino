//* Right water flow sensor

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
    
      Serial.print(2);
//      Serial.println("Right water");
      }
//  Serial.print("Right water sensor value:");
//  Serial.println(Calc);

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

 
  
  
  
  
