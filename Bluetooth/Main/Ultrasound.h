#ifndef ULTRASOUND_H
#define ULTRASOUND_H

#include <Arduino.h>
#include "Display.h"
#include "Bluetooth.h"

struct Range {
  int start;
  int end;
};

class Sensor {
public:
  Sensor(int echo,int trig,Display* display,BluetoothModule* blue);
private:
  Display* MyDisplay;
  BluetoothModule* MyBlue;
  int echoPin;
  int trigPin;
  unsigned long startTime;
  long duration;
  float distance;
  float prevdistance;
  Range function_range;
  bool isSetting;
   bool isHolding;
  String current_track;

  /*
    "O" = default, none
    "N" = next track
    "P" = prev track
    "S" = pause track
    "V" = set volume
    "U" = volume up
    "D" = volume down
  */

public:
  void Update();
  bool In_range();

public:
  // Getter
  float get_distance();
  void get_run_command();
  // Setter
  void set_function_range();

private:
  void display_text(String text);

};

#endif