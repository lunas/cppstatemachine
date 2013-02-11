/*
 * StateMachine.h
 *
 *  Created on: Feb 9, 2013
 *      Author: dan
 */

#include <vector>


#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

using namespace std;

class State;

class StateMachine {
public:
  StateMachine();
  virtual ~StateMachine();

  void handleInput(vector<bool>);
  State* currentState();

  void changeState(State*);

private:
  State* state;
  vector<State*> states;

};

#endif /* STATEMACHINE_H_ */
