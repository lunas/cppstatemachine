/*
 * Playing.cpp
 *
 *  Created on: Feb 11, 2013
 *      Author: Lukas
 */

#include "Playing.h"

Playing* Playing::the_instance = 0;

State* Playing::instance(){
  if (the_instance == 0) {
    the_instance = new Playing();
  }
  return the_instance;
}

Playing::Playing(): State("Playing") {
}

Playing::~Playing() {
}

void Playing::handleInput(StateMachine* sm, vector<bool> buttons) {
  sm->changeState(Playing::instance());
}

void Playing::set_leds(StateMachine* sm) {
  vector<bool> leds;
  leds.push_back(false);
  leds.push_back(true);
  leds.push_back(true);
  leds.push_back(true);
  sm->set_leds(leds);
}
