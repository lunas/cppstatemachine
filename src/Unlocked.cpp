/*
 * Unlocked.cpp
 *
 *  Created on: Feb 10, 2013
 *      Author: dan
 */

#include "Unlocked.h"

State* Unlocked::instance(){
  if (the_instance == 0) {
    the_instance = new Unlocked();
  }
  return the_instance;
}

Unlocked::Unlocked(): State("Unlocked") { }
Unlocked::~Unlocked() { }


void Locked::handleInput(StateMachine* sm, vector<bool> buttons) {
  if (lock_pressed(buttons)){
    lock();
    sm->changeState(Locked::instance());
  }
  else if (play_stop_pressed(buttons)){
    play();
    sm->changeState(Playing::instance());
  }
  else if (blast_pressed(buttons)){
    start_blast();
    sm->changeState(PlayingWithoutMusic::instance());
  }
}

void Locked::set_leds(StateMachine* sm) {
  vector<bool> leds;
  leds.push_back(false);
  leds.push_back(true);
  leds.push_back(true);
  leds.push_back(true);
  sm->set_leds(leds);
}
