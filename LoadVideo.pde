import processing.serial.*;
import processing.video.*;

int val1;
int val2;

Serial port1;
Serial port2;

Movie mov1;
Movie mov2;

void setup(){  
  
  size(1920,1080);
   mov1 = new Movie(this, "1.mov");
   mov1.loop();
   mov2 = new Movie(this, "2.mp4");
   mov2.loop();
   frameRate(30);

  port1 = new Serial(this,"/dev/cu.usbserial-14320",9600);
  port2 = new Serial(this,"/dev/cu.usbserial-143320",9600);
    
}

void draw(){
  
  if (port1.available()>0){
    val1 = port1.read();
    if(val1 >= 48 && val1<=57){
      val1=val1-48;
      LoadVideos(val1);
    }
  }
  
  if (port2.available()>0){
    val2 = port2.read();
    if(val2 >= 48 && val2<=57){
      val2=val2-48;
      LoadVideos(val2);
    }
  }  
  
}

void LoadVideos(int val){
  
  if (val==1){
    
    mov1.read();
   image(mov1,0,0);
   println("abc"); 
  
  }
  
    if (val==2){
      
      mov2.read();
      image(mov2,0,0);
      println("efg");
    
  
  }

}
