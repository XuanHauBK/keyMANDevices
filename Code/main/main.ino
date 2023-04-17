#include <Arduino.h>
#include <Preferences.h>
#include <stdio.h>
#include <time.h>
#include <WiFi.h>
#include <HTTPClient.h>

//declare class Preferences
Preferences data_lab;

//declare get time to server
const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 25200;
const int daylightOffset_sec = 0;

//declare parameter WIFI
const char* ssid = "Xuan Hau";
const char* password = "0866091764";

typedef struct 
{
    String name;
    String id;
    String time;
    byte data_UID[4];
} Student_t;

Student_t student[3]=
            {
                {"Trinh Xuan Hau", "20191821","",{0x3A, 0xC9, 0x6A, 0xCB}},
                {"Nguyen Tien Thanh", "20192081","",{0x3A, 0xC9, 0x6A, 0xCB}},
                {"Nguyen Trong Phong", "20192017","",{0x3A, 0xC9, 0x6A, 0xCB}},
            };
//function connect to WiFi
void connectWifi()
{
    Serial.println();
    Serial.print("Connecting to Wifi: ");
    Serial.println(ssid);
    Serial.flush();
    WiFi.begin(ssid,password);
    while(WiFi.status()!=WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
}

//function getTime to Server 
String timeToServer()
{
    struct tm timeinfor;
    if(!getLocalTime(&timeinfor))
    {
        Serial.println("Failed to obtain time");
        return "";
    }
    char timeStringBuff[50];
    strftime(timeStringBuff, sizeof(timeStringBuff), "%A, %B %d %Y %H:%M:%S", &timeinfor);
    String asString(timeStringBuff);
    asString.replace(" ", "_");
    Serial.print("Time:");
    Serial.println(asString);
    return asString;
}

void writeDataToFlash(Student_t student)
{
    //String test = "student" + 1 ;
    String data_student = student.name; //+ "?" + student.id + "?" + student.time;
    data_lab.putString("test", data_student);
}

void handlerString(String string_data)
{
   String name, id, time;
   char index1, index2, flag=0;
   for(int i=0; i<string_data.length();i++)
   {
    if(string_data.charAt(i)=='?')
    {
        if(flag==0)
        {
            index1 = i;
            flag ++;
        }
        else 
        {
            index2 = i;
        }
    }
   }
   name = string_data.substring(0,index1);
   id = string_data.substring(index1+1, index2);
   time = string_data.substring(index2+1);
}

void sendDataToGooglesheet()
{
    String urlFinal = "";
    Serial.print("Post data to googlesheet: ");
    Serial.println(urlFinal);
    HTTPClient http;
    http.begin(urlFinal.c_str());
    http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
    int httpCode = http.GET();
    Serial.print("HTTP Status Code:");
    Serial.println(httpCode);
    String payload;
    if(httpCode>0)
    {
        payload = http.getString();
        Serial.println("Payload: "+payload);
    }
    http.end();
}


String compare_UID(Student_t *student, byte* data2_UID)
{
    char flag = 0;
    for(int i=0;i<4;i++)
    {
        if(student->data_UID[i]==data2_UID[i])
        {
            flag++;
        }
        else
        {
            return "faid";
            break;
        }
    }
    if(flag == 4)
    {
        student->time = timeToServer();
        return "pass";
    }
}
void setup()
{
    Serial.begin(115200);
    connectWifi();
    configTime(gmtOffset_sec,daylightOffset_sec,ntpServer);
    data_lab.begin("data_member", false);
    byte data_UID[4]= {0x3A, 0xC9, 0x6A, 0xCB};
    compare_UID(&student[0], data_UID);
    //writeDataToFlash(student[0]);
    String data_student = student[0].name; //+ "?" + student.id + "?" + student.time;
    data_lab.putString("test", data_student);
    
}   

void loop()
{
   Serial.println("test pass");
   String hau = data_lab.getString("test", "");
   Serial.println(hau);
   delay(1000);
}
