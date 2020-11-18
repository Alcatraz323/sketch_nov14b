#include "Seg.h"

SegBase::SegBase(uint8_t clk, uint8_t dio) : mCLKPin(clk), mDIOPin(dio) {
    mDisplay = new TM1637(mCLKPin, mDIOPin);
    mDisplay->init();
    mDisplay->set(BRIGHT_TYPICAL);   //BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
    mDisplay->point(POINT_ON);
}

void SegBase::setDisplayContent(uint8_t content[4], uint8_t brightness, bool enableDot) {
    mDisplayContent.mBrightness = brightness;
    mDisplayContent.mDotEnabled = enableDot;
    mDisplay->set(brightness);
    mDisplay->point(enableDot);
    for(uint8_t i = 0; i < 4; i++) {
        mDisplayContent.mContent[i] = content[i];
        mDisplay->display(i, content[i]);
    }
}

//----------------------------------------------------------------------------------

void SegMain::segInit() {
    uint8_t content[4] = {18, 18, 18, 18};
    setDisplayContent(content);
}

void SegMain::displaySetup() {
    uint8_t content[4] = {0, 0, 12, 1};
    setDisplayContent(content);
}

//----------------------------------------------------------------------------------

void SegSecondary::segInit() {
    uint8_t content[4] = {11, 12, 0, 1};
    setDisplayContent(content);
}

//----------------------------------------------------------------------------------

void SegTrd::segInit() {
    uint8_t content[4] = {11, 12, 0, 1};
    setDisplayContent(content);
}
