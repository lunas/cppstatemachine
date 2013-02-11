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

void State::unlock(){}
void State::lock(){}
void State::play(){}
void State::start_blast(){}
void State::stop_blast(){}

bool State::unlock_pressed(vector<bool>& buttons){
  return buttons[0];  //TODO use constant
}
bool State::lock_pressed(vector<bool>& buttons){
  return buttons[1];  //TODO use constant
}
bool State::play_stop_pressed(vector<bool>& buttons){
  return buttons[2];  //TODO use constant
}
bool State::blast_pressed(vector<bool>& buttons){
  return buttons[3];  //TODO use constant
}
