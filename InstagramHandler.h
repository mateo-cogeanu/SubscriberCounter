// =======================================================================
// InstagramHandler.h
// Part of the ESP8266 Subscriber Counter Project
// Created by: Mateo Cogeanu
// Date: January 2025
// Description:
// This header file defines the InstagramHandler class, which is used to 
// handle Instagram functionality within the Subscriber Counter project.
// It interfaces with the InstagramStats library to fetch the number of
// followers for a specific Instagram account.
//
// YouTube Channel: https://www.youtube.com/@CogiArt
//
// How to Use:
// 1. Include this file in your main program by uncommenting the line:
//    #include "InstagramHandler.h"
// 2. Make sure to configure the InstagramStats library to work with your
//    Instagram account and access tokens.
//
// Note: Replace placeholders in your main file with appropriate API tokens.
// =======================================================================

#ifndef INSTAGRAM_HANDLER_H
#define INSTAGRAM_HANDLER_H

#include <WiFiClientSecure.h>
#include "InstagramStats.h"

// =======================================================================
// InstagramHandler Class
// =======================================================================
// This class encapsulates the functionality for fetching Instagram 
// follower counts. It uses the InstagramStats library and manages
// communication securely through the WiFiClientSecure client.
// =======================================================================
class InstagramHandler {
private:
    InstagramStats instaStats; // Instance of the InstagramStats library
    long followers;            // Stores the number of Instagram followers

public:
    // Constructor
    // Parameters:
    // - client: A WiFiClientSecure instance for secure communication
    InstagramHandler(WiFiClientSecure &client) 
        : instaStats(client), followers(0) {}

    // Fetch Followers
    // This method fetches and returns the number of Instagram followers
    // using the InstagramStats library.
    long getFollowers() {
        followers = instaStats.getFollowers(); // Adjust based on the library's function
        return followers;
    }
};

#endif