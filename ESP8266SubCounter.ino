// =======================================================================
// ESP8266 Subscriber Counter
// Created by: Mateo Cogeanu (CogiArt)
// Date: January 2025
// Description:
// This project displays YouTube and Instagram subscriber/follower counts
// on a MAX7219 LED matrix using an ESP8266 microcontroller. It fetches
// real-time data via the YouTube Data API and Instagram API, providing a
// sleek visual representation of subscriber statistics.
//
// YouTube Channel: https://www.youtube.com/@CogiArt
//
// How to Use:
// 1. Replace placeholders with your WiFi credentials, YouTube API key,
//    channel ID, and (optionally) Instagram API details.
// 2. Configure hardware connections as per the pin definitions.
// 3. Upload the code to your ESP8266 using the Arduino IDE.
// 4. Enjoy your real-time subscriber counter!
// =======================================================================

// Libraries included
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include "Arduino.h"
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h> // JSON parsing library
#include <YoutubeApi.h>  // Library to fetch YouTube stats
#include "CogiArt.h"     // Font or custom library for display

// Uncomment the next line to enable Instagram functionality
//#include "InstagramHandler.h"

// =======================================================================
// Global Variables and Definitions
// =======================================================================

// Time interval between fetching data
const uint16_t WAIT_TIME = 60000; 

// Define the type of hardware and the pins used
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4

// Define pins for MAX7219
#define CLK_PIN   5 // Clock pin for MAX7219
#define DATA_PIN  7 // Data pin for MAX7219
#define CS_PIN    8 // Chip select pin for MAX7219

// WiFi configuration
const char* ssid = "YOUR_WIFI_SSID";      // Replace with your WiFi SSID
const char* password = "YOUR_WIFI_PASSWORD"; // Replace with your WiFi password

// API credentials for YouTube
#define API_KEY "YOUR_YOUTUBE_API_KEY"      // Replace with your YouTube API key
#define CHANNEL_ID "YOUR_CHANNEL_ID"        // Replace with your YouTube channel ID

// Toggle to enable/disable Instagram functionality
bool enableInstagram = true;

// Initialize the Parola library for text display
MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

// Initialize WiFi and API clients
WiFiClientSecure client; // For HTTPS communication
YoutubeApi api(API_KEY, client); // Initialize YouTube API object

#ifdef INSTAGRAM_HANDLER_H
InstagramHandler instaHandler(client); // Create an InstagramHandler instance if enabled
#endif

// =======================================================================
// Setup Function
// =======================================================================
void setup() 
{
  P.begin();                     // Initialize the LED matrix
  P.setFont(fontSubs);           // Set the font for displaying text
  
  // Connecting to WiFi
  Serial.begin(115200);          // Start serial communication for debugging
  Serial.print("Connecting WiFi ");
  WiFi.begin(ssid, password);    // Start WiFi connection
  P.print(" WiFi...");           // Show "WiFi..." on the matrix
  while (WiFi.status() != WL_CONNECTED) { // Wait until WiFi connects
    Serial.print("."); 
    delay(500);
  }
  Serial.println("");
  Serial.print("Connected: "); 
  Serial.println(WiFi.localIP()); // Display local IP address

  client.setInsecure(); // Bypass SSL certificate validation
}

// =======================================================================
// Loop Function
// =======================================================================
void loop(void)
{
  Serial.println("Getting data ...");
  P.print("fetching");           // Display "fetching" on the matrix
  int cnt = 0;                   // Counter for fetching data
  long yt1 = 0, yt2 = 0, insta = 0; // Variables to store stats (YouTube subs, views, Instagram followers)

  while (1) {                    // Infinite loop for repeatedly fetching data
    if (!cnt--) {                // Fetch data every 50 iterations
      cnt = 50;

      // Fetch YouTube subscriber count and view count
      if (api.getChannelStatistics(CHANNEL_ID)) {
        yt1 = api.channelStats.subscriberCount; 
        yt2 = api.channelStats.viewCount;
      }

#ifdef INSTAGRAM_HANDLER_H
      // Fetch Instagram follower count if enabled
      if (enableInstagram) {
        insta = instaHandler.getFollowers(); // Fetch Instagram followers
        Serial.println("Instagram followers: " + String(insta));
      }
#endif
    }
    
    // Format numbers for display
    String subsCount = num_format(yt1);
    String viewCount = num_format(yt2);

#ifdef INSTAGRAM_HANDLER_H
    String instaFollowers = num_format(insta);
#endif

    // Display formatted numbers on the matrix
    Serial.println("YouTube Subscribers: " + subsCount);
    P.print("*" + subsCount); 
    delay(3500);

    // Uncomment below if you want to show YouTube view count as well
    // P.print("*" + viewCount);
    // delay(3500);

#ifdef INSTAGRAM_HANDLER_H
    // Display Instagram followers only if enabled
    if (enableInstagram) {
      Serial.println("Instagram Followers: " + instaFollowers);
      P.print("&" + instaFollowers); 
      delay(5000);
    }
#endif
  }
}

// =======================================================================
// Helper Function: Format Numbers
// =======================================================================
String num_format(long num) {
  String num_s;
  long num_original = num;
  if (num > 99999 && num <= 999999) {
    num = num / 1000;
    long fraction = num_original % 1000;
    String num_fraction = String(fraction);
    String decimal = num_fraction.substring(0, 1);
    num_s = String(num) + "." + decimal + "K";          
  }
  else if (num > 999999) {
    num = num / 1000000;
    long fraction = num_original % 1000000;
    String num_fraction = String(fraction);
    String decimal = num_fraction.substring(0, 1);
    if (num_original < 100000000) {
      num_s = " " + String(num) + "." + decimal + "M";      
    } else {
      num_s = String(num) + "." + decimal + "M";
    }
  }
  else {
    int num_l = String(num).length();
    char num_f[15];
    int blankDigits = 6 - num_l;
    for (int i = 0; i < blankDigits; i++) {
      num_f[i] = ' '; 
    }
    num_f[blankDigits] = '\0';
    num_s = num_f + String(num);
  }
  return num_s;
}