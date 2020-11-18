#define INCLUDING_FROM_MAIN_INO

#include "BasicSensors.h"
#include "TempSensor.h"
#include "Seg.h"
#include "Oled.h"
#include "TimeLib.h"

SegMain* mSegMain;
SegSecondary* mSegSecondary;
SegTrd* mSegTrd;

Oled* mDisplay;

TSensor* mTempSensor;
LaserSensor* mLaserSensor;
VibrationSensor* mVibrationSensor;
MicSensor* mMicSensor;

void setup() {
  Serial.begin(9600);
  initDisplay();
  initSegs();
  initSensors();
  mDisplay->clearContent();
  setTime(19, 7, 30, 18, 11, 2020);
}

void loop() {
  updateTemps();
  mDisplay->updateLine(0, updateTemps());
  mDisplay->updateLine(1, updateSensors());
  mDisplay->updateLine(2, updateMics());
  mDisplay->setTitle(updateTimeSegs());
}

char* updateTimeSegs() {
  time_t t = now();
  int hourVal = hour(t);
  int minVal = minute(t);
  int secVal = second(t);
  int dayVal = day(t);
  int monthVal = month(t);
  int weekDay = weekday(t) - 1;

  int hourTen = hourVal / 10;
  int hourSingle = hourVal - hourTen * 10;
  int minTen = minVal / 10;
  int minSingle = minVal - minTen * 10;
  int secTen = secVal / 10;
  int secSingle = secVal - secTen * 10;
  int dayTen = dayVal / 10;
  int daySingle = dayVal - dayTen * 10;
  int monthTen = monthVal / 10;
  int monthSingle = monthVal - monthTen * 10;

  uint8_t segmain_c[4] = {monthTen, monthSingle, dayTen, daySingle};
  uint8_t segsec_c[4] = {(uint8_t)13, weekDay, hourTen, hourSingle};
  uint8_t segtrd_c[4] = {minTen, minSingle, secTen, secSingle};

  mSegMain->setDisplayContent(segmain_c);
  mSegSecondary->setDisplayContent(segsec_c);
  mSegTrd->setDisplayContent(segtrd_c);

  char time_oled[24];
  sprintf(time_oled,
          "%s %d/%d %d:%d:%d",
          weekDays[weekDay], monthVal, dayVal, hourVal, minVal, secVal);
  return time_oled;
}

char* updateTemps() {
//    char temp[10];
//    float tempVal = mTempSensor->getTempC();
//    int8_t tempD = (tempVal - (int)tempVal) * 100;
//    sprintf(temp, "T0:%d.%dC", (int)tempVal, tempD);
//    return temp;
  mDisplay->updateLine(0, "T0:wait for serial\0");
}

char* updateSensors() {
  char laser[10];
  sprintf(laser,
          "L:%d V:%d",
          mLaserSensor->read() == HIGH ? 1 : 0,
          mVibrationSensor->read() == HIGH ? 0 : 1);
  return laser;
}

char* updateMics() {
  char mic[32];
  int micVal = mMicSensor->read();
  sprintf(mic, "Mic:%d\0", micVal);
  return mic;
}

void initSegs() {
#ifdef OLED_VERBOSE
  mDisplay->println("init seg_main...");
#endif
  mSegMain = new SegMain(PIN_SEG_MAIN_CLK, PIN_SEG_MAIN_DIO);
  mSegMain->displaySetup();
#ifdef OLED_VERBOSE
  mDisplay->updateLine("init seg_main...ok");
  mDisplay->println("init seg_secondary...");
#endif
  mSegSecondary = new SegSecondary(PIN_SEG_SEC_CLK, PIN_SEG_SEC_DIO);
  mSegSecondary->segInit();
  mSegTrd = new SegTrd(PIN_SEG_TRD_CLK, PIN_SEG_TRD_DIO);
  mSegTrd->segInit();
#ifdef OLED_VERBOSE
  mDisplay->updateLine("init seg_sec...ok");
#endif
  delay(1000);
}

void initDisplay() {
  mDisplay = new Oled();
  mDisplay->init();
  mDisplay->setTitle("sketch_nov14b - alc");
}

void initSensors() {
  mTempSensor = new TSensor(PIN_TEMPERATURE);
  mLaserSensor = new LaserSensor(PIN_LASER_RECEIVER_1);
  mVibrationSensor = new VibrationSensor(PIN_VIBRATION);
  mMicSensor = new MicSensor(PIN_MICROPHONE);
}
