/*
 * StateMachine.cpp
 *
 *  Created on: Feb 9, 2013
 *      Author: dan
 */

#include "StateMachine.h"
#include "Locked.h"

//StateMachine::StateMachine(): state(new Locked()) {
StateMachine::StateMachine(GpioController* gpio): gpio(gpio) {
  // create 5 states, pass self as param
  state = Locked::instance();
}

StateMachine::~StateMachine() {
  // TODO Auto-generated destructor stub
}

void StateMachine::handleInput(vector<bool> &buttons){
  currentState()->handleInput(this, buttons);
}

void StateMachine::changeState(State* newState) {
   state = newState;
   state->set_leds(this);
}

State* StateMachine::currentState() {
  return state;
}

void StateMachine::set_leds(const vector<bool>& leds) {
  gpio->set_leds(leds);
}

