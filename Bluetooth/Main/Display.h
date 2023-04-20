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

public:
  void Update_display();
  bool is_last_frame();
public:
  //Setter
  void set_text(String value);
  void set_interval(unsigned int value);
  //Getter
  int get_frame_no();
  int get_last_frame();

private:
  bool** stringToArray();
  bool** addWords(bool*** matrix_array);
  bool** CreateArray(int rows, int cols);
  void copyArray(bool **array1, bool** array2);
  void display(bool** matrix);
  void AllLow();
  void High(int num);
  void Low(int num);
};

#endif