/*
 * StateMachine.cpp
 *
 *  Created on: Feb 9, 2013
 *      Author: dan
 */

#include "StateMachine.h"
#include "Locked.h"

//StateMachine::StateMachine(): state(new Locked()) {
StateMachine::StateMachine() {
  // create 5 states, pass self as param
  state = Locked::instance();
}

StateMachine::~StateMachine() {
  // TODO Auto-generated destructor stub
}

void StateMachine::handleInput(vector<bool> buttons){

}

void StateMachine::changeState(State* newState) {
   state = newState;
}

State* StateMachine::currentState() {
  return state;
}

