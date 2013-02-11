/*
 * StateMachine.h
 *
 *  Created on: Feb 9, 2013
 *      Author: dan
 */

#include <vector>
#include "../../midiconv/gpiocontroller/GpioController.hpp"


#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

using namespace std;

class State;

class StateMachine {
public:
  StateMachine(GpioController*);
  virtual ~StateMachine();

  void handleInput(vector<bool>&);
  State* currentState();
  void set_leds(const vector<bool>&);

  void changeState(State*);

private:
  State* state;
  vector<State*> states;
  GpioController* gpio;

};

#endif /* STATEMACHINE_H_ */
