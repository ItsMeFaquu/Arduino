#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include "alphabet.h"

/*
    connect pin 1 to 10
    SAMPLE CODE:
    Display MyDisplay("Hello World!");
    void setup() {
    }; 
    void loop() {
      MyDisplay.Update_display();
    }
  */

/*
  MAX CHARACTER:43
*/
class Display {
public:
  Display(String text);

private:
  unsigned long startTime;
  unsigned int interval;
  int frame_no;
  int last_frame;
  int spacing;
  String text;
  String prev_text;
  int length;
  bool** wordArray;
  int rows = 5;
  int cols;
  int prevcols;
  // for LED pin ,eg:1~10 increment=0
  const short increment = 29;

  bool** tempArray;
  String tempWord = "";

public:
  void Update_display();
  bool is_last_frame();
public:
  //Setter
  void set_text(String value);
  void set_text(int volume);
  void set_text(String value,bool optimised);
  void set_interval(unsigned int value);
  //Getter
  int get_frame_no();
  int get_last_frame();

private:
  bool** stringToArray();
  void display(bool** matrix);
  void AllLow();
};

#endif