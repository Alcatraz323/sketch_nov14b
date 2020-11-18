/*

    Copyright 2020 Alcatraz
    Date: 2020-11-15 

*/

#include "TM1637.h"

class SegMain;
class SegSecondary;

class SegBase
{
    friend class SegMain;
    friend class SegSecondary;

public:
    SegBase(uint8_t clk, uint8_t dio);
    struct display_content
    {
        uint8_t mBrightness = BRIGHT_TYPICAL; //TYPICAL = 2, Darkest - Brightest | 0 - 7
        bool mDotEnabled = false;
        uint8_t mContent[4] = {0, 0, 0, 0};
    };

private:
    uint8_t mCLKPin = 0;
    uint8_t mDIOPin = 0;
    TM1637 *mDisplay;
    display_content mDisplayContent;

public:
    static uint8_t NumTab[19] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18}; //0~9,A,b,C,d,E,F,L,H,-

public:
    virtual void segInit() = 0;
    virtual void setDisplayContent(uint8_t content[4], uint8_t brightness = BRIGHT_TYPICAL, bool enableDot = true);
    display_content getDisplayContent() { return mDisplayContent; }
    TM1637 *getDisplay() { return mDisplay; }
};

class SegMain : SegBase
{
public:
    using SegBase::SegBase;
    using SegBase::setDisplayContent;
    using SegBase::getDisplayContent;
    void segInit();
    void displaySetup();
};

class SegSecondary : SegBase
{
public:
    using SegBase::SegBase;
    using SegBase::setDisplayContent;
    using SegBase::getDisplayContent;
    void segInit();
};

class SegTrd : SegBase
{
public:
    using SegBase::SegBase;
    using SegBase::setDisplayContent;
    using SegBase::getDisplayContent;
    void segInit();
};
