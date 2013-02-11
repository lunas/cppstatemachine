/*
 * State.cpp
 *
 *  Created on: Feb 9, 2013
 *      Author: dan
 */

#include "State.h"

State::State(): name("BASE") {
}
State::State(string n): name(n){
}

State::~State() {
  // TODO Auto-generated destructor stub
}

void State::handleInput(StateMachine* sm, std::vector<bool> buttons){

}

void State::set_leds(StateMachine* sm){ }

void State::changeState(StateMachine* sm, State* newState) {
  sm->changeState(newState);
}

std::string State::getName(){
  return name;
}
