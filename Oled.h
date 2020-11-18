/*

    Copyright 2020 Alcatraz
    Date: 2020-11-15 

*/

#include "Adafruit_SSD1306.h"

#define OLED_MOSI 11
#define OLED_CLK 13
#define OLED_DC 9
#define OLED_CS 10
#define OLED_RESET 8

class Oled {
private:
    Adafruit_SSD1306* mDisplay;
    char* mDisplayContent[4];

    bool mAvailable = false;
    bool mDisplayShows = false;

private:
    void updateScreen();

public:
    void init();
    void setTitle(char* str);
    void updateLine(uint8_t position, char* content);
    void updateLine(char* content);
    void println(char* content);
    void showContent();
    void clearContent();
    void clearDisplayContent();
    bool hasScreenContent() { return mDisplayShows; }
    char** getDisplayContent() { return mDisplayContent; }
    bool isAvailable() { return mAvailable; }
};

