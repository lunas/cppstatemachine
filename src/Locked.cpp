/*
 * Locked.cpp
 *
 *  Created on: Feb 9, 2013
 *      Author: dan
 */

#include "Locked.h"

Locked* Locked::the_instance = 0;

State* Locked::instance(){
  if (the_instance == 0) {
    the_instance = new Locked();
  }
  return the_instance;
}

Locked::Locked(): State("Locked") {

}

Locked::~Locked() {
}

void Locked::handleInput(StateMachine* sm, vector<bool> buttons) {
  //;
}
