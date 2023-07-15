#include <dht.h>
//import processing.serial.*;
//Serial mySerial;
//PrintWriter output;
dht DHT;

#define dht_apin A0 // Analog Pin sensor is connected to
int photoTran = A1;
int reading = 0;
int sensor_pin = A2;
float sensorVals[] = {0,0,0};

int output_value ;

 
void setup(){
    pinMode(photoTran,INPUT);
 
  Serial.begin(9600);
  delay(300);//Delay to let system boot
  //Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  
  delay(1000);//Wait before accessing Sensor
//  mySerial = new Serial( this, Serial.list()[0], 9600 );
//   output = createWriter( "data.txt" );
 
}//end "setup()"
// void draw() {
//    if (mySerial.available() > 0 ) {
//         String value = mySerial.readString();
//         if ( value != null ) {
//              output.println( value );
//         }
//    }
//}
void loop(){
  //Start of Program 
 
    DHT.read11(dht_apin);
    reading = analogRead(photoTran);
        //Serial.print("Current Light = ");

   
    //Serial.print(DHT.temperature); 
    //Serial.println("C  ");
    output_value= analogRead(sensor_pin);

   //output_value = map(output_value,550,0,0,100);

   //Serial.print("Mositure : ");

   //Serial.print(output_value);

   //Serial.println("%");
  sensorVals[0] = reading;
sensorVals[1] = DHT.temperature;
sensorVals[2] = output_value;
//Serial.print(reading);
//Serial.print(",");
//Serial.print(DHT.temperature); 
//Serial.print(",");
//Serial.print(output_value);
//Serial.print("\n");
Serial.println("Light");
Serial.print(reading);
Serial.print(",");
Serial.println("Temperature");
Serial.print(DHT.temperature);
Serial.print(",");
Serial.println("Moisture");
Serial.println(output_value);

    
    delay(1000);//Wait 5 seconds before accessing sensor again.
 
  //Fastest should be once every two seconds.
 
}// end loop() 

