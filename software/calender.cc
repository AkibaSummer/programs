#include <IRremote.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x20,16,2);
#define RECV_PIN 10
#define ALARM_PIN 4 
#define DHT_PIN 6
DHT dht(DHT_PIN,11);
IRrecv irrecv(RECV_PIN);
decode_results results;

int year,month,day,hour,minute,second,date;
const char* A[7]={"Mon","Tue","Wes","Thu","Fri","Sat","Sun"};
const int DayOfMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};

void print(int n,int width){
    int temp=n;
    for (int i=0;i<width;i++){
        temp==0?lcd.print(0):0;
        temp/=10;
    }
    lcd.print(n);
}

void calendarShow(){
    lcd.setCursor(3,0);
    print(year,4);
    lcd.print('/');
    print(month,2);
    lcd.print('/');
    print(day,2);
    lcd.setCursor(1,1);
    print(hour,2);
    lcd.print(':');
    print(minute,2);
    lcd.print(':');
    print(second,2);
    lcd.print(' ');
    lcd.print(A[date-1]);    
}

void temperatureShow(){
    
}

inline bool isR(int x){
    return x%400?x%100?x%4?0:1:0:1;
}

void tita(){
    delay(1000);
    minute+= ++second==60?1,second=0:0;
    hour+= minute==60?(minute=0),1:0;
    day+= hour==24?date=((date+1)%7),(hour=0),1:0;
    month+= day==DayOfMonth[month]+(month==2&&isR(year)?1:0)+1?day=1:0;
    year+= month==13?month=1:0;
}

void setup() {
    // put your setup code here, to run once:
  Serial.begin(9600);
    irrecv.enableIRIn();
    pinMode(ALARM_PIN,OUTPUT);
    lcd.init();
    lcd.backlight();
    year=1999;
    month=12;
    day=31;
    hour=23;
    minute=58;
    second=50;
    date=2;
}

void loop() {
    // put your main code here, to run repeatedly:
    calendarShow();
    tita();
}