#include <Servo.h>

// C++ code
//
// Pin tanımlamalarının yapılması 
//#define echoPin 6
//#define trigPin 7
const int trigPin = 7;
const int echoPin = 6;
Servo servo1;


// Uzaklık sensörü için süre ve mesafe değişkenleri oluşturuldu. 
long duration, distance;
long servoAngle = 0; // Servo motorun açısı
int maxDistance1 = 100;  // 100cm 
int maxDistance2 = 200;  // 200cm
int maxDistance3 = 300;  // 300cm
int maxDistance4 = 400;  // 400cm 

void setup()
{
  Serial.begin (9600);       // Seri haberleşme için baud rate değeri 9600 olarak girildi.
  pinMode(trigPin, OUTPUT);  // HC-SR04 sensörü trig pini çıkıştan alındı.
  pinMode(echoPin, INPUT);	 // HC-SR04 sensörü echo pini girişten alındı .
  servo1.attach(9);   // Servo motorun pini seçildi.
}

// HC-SR04 mesafe ölçümü için fonksiyon oluşturuluyor.
int mesafeOlcum(){
  digitalWrite(trigPin , LOW);  //trig pini low statüsüne getirilir.
  delayMicroseconds(2);  // bekleme
  digitalWrite(trigPin , HIGH);  // trig pini high statüsüne getirilir ve sinyal gönderilmeye başlanır
  delayMicroseconds(10); // bekleme
  digitalWrite(trigPin , LOW); // trig pini tekrardan low getirilerek sinyal gönderimi durdurulur.
  duration = pulseIn(echoPin , HIGH); // Oluşturduğumuz dalgaların süresini ölçüyor 
  distance = duration*0.034/2; // Hesaplanan süreden uzaklık ölçümü yapılır.
  return distance;
}

//Servo motor hareketi sağlama 
void loop()
{
  distance = mesafeOlcum();   //distance değişkeni fonksiyona eşitlenir
  
  //Uzaklık 100'e eşit veya 100'den küçükse servo motor açısı 45 olur.
  if(distance <= maxDistance1){
    servoAngle = 45;
    delay(15);
  }
  
  //Uzaklık 100-200 aralığında ise servo motor açısı 90 olur.
  else if(distance> maxDistance1 && distance <= maxDistance2){
    servoAngle = 90;
    delay(15);
  }
  
  //Uzaklık 200-300 aralığında ise servo motor açısı 135 olur.
  else if(distance > maxDistance2 && distance <= maxDistance3){
    servoAngle = 135;
    delay(15);
  }
  
  //Uzaklık 300-400 aralığında ise servo motor açısı 180 olur.
  else if(distance > maxDistance3 && distance <= maxDistance4){
    servoAngle = 180; 
    delay(15);
  }
  
  //Ekrana Ölçülerin yazdırılması 
  Serial.print("distance = ");
  Serial.print(distance);
  Serial.print("\n");
  Serial.print("Servo Angle = ");
  Serial.print(servoAngle);
  Serial.println("\n");
  Serial.println(".............");
    
  servo1.write(servoAngle);  //Servo motorun açısının ayarlanarak çalıştırılması
  
  delay(1000); 
  
} 

  
  

  
