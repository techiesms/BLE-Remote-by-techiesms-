

#include <WiFi.h>
#include <HTTPClient.h>

#define USE_SERIAL Serial


#define U_BUT D1
#define L_BUT D3
#define C_BUT D5
#define R_BUT D7
#define D_BUT D9

String Auth_Token = "";

void setup()
{

  USE_SERIAL.begin(115200);

  pinMode(U_BUT, INPUT_PULLUP);
  pinMode(L_BUT, INPUT_PULLUP);
  pinMode(C_BUT, INPUT_PULLUP);
  pinMode(R_BUT, INPUT_PULLUP);
  pinMode(D_BUT, INPUT_PULLUP);

  WiFi.begin("SmS_jiofi", "sms123458956");

}

void loop() {
  // wait for WiFi connection

  if (digitalRead(U_BUT) == LOW)
  {
    if (WiFi.status() == WL_CONNECTED) {

      HTTPClient http;

      USE_SERIAL.print("[HTTP] begin...\n");
      // configure traged server and url
      //http.begin("https://www.howsmyssl.com/a/check", ca); //HTTPS
      http.begin("http://blr1.blynk.cloud/external/api/update?token=" + Auth_Token +"&V1=1"); //HTTP

      USE_SERIAL.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        USE_SERIAL.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK) {
          String payload = http.getString();
          USE_SERIAL.println(payload);
        }
      } else {
        USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    }
  }


  if (digitalRead(D_BUT) == LOW)
  {
    if (WiFi.status() == WL_CONNECTED) {

      HTTPClient http;

      USE_SERIAL.print("[HTTP] begin...\n");
      // configure traged server and url
      //http.begin("https://www.howsmyssl.com/a/check", ca); //HTTPS
      http.begin("http://blr1.blynk.cloud/external/api/update?token=" + Auth_Token +"&V1=0"); //HTTP

      USE_SERIAL.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        USE_SERIAL.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK) {
          String payload = http.getString();
          USE_SERIAL.println(payload);
        }
      } else {
        USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    }
  }

    if (digitalRead(L_BUT) == LOW)
  {
    if (WiFi.status() == WL_CONNECTED) {

      HTTPClient http;

      USE_SERIAL.print("[HTTP] begin...\n");
      // configure traged server and url
      //http.begin("https://www.howsmyssl.com/a/check", ca); //HTTPS
      http.begin("http://blr1.blynk.cloud/external/api/update?token=" + Auth_Token +"&V2=0"); //HTTP

      USE_SERIAL.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        USE_SERIAL.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK) {
          String payload = http.getString();
          USE_SERIAL.println(payload);
        }
      } else {
        USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    }
  }

    if (digitalRead(R_BUT) == LOW)
  {
    if (WiFi.status() == WL_CONNECTED) {

      HTTPClient http;

      USE_SERIAL.print("[HTTP] begin...\n");
      // configure traged server and url
      //http.begin("https://www.howsmyssl.com/a/check", ca); //HTTPS
      http.begin("http://blr1.blynk.cloud/external/api/update?token=" + Auth_Token +"&V2=1"); //HTTP

      USE_SERIAL.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        USE_SERIAL.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK) {
          String payload = http.getString();
          USE_SERIAL.println(payload);
        }
      } else {
        USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    }
  }
}
