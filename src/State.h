/*
 * State.h
 *
 *  Created on: Feb 9, 2013
 *      Author: dan
 */

#include <string>
#include "StateMachine.h"

#ifndef STATE_H_
#define STATE_H_

class State {
public:
  State();
  State(string name);
  virtual ~State();

  virtual void handleInput(StateMachine*, std::vector<bool>);
  std::string getName();

  virtual void set_leds(StateMachine* sm);

protected:
  void changeState(StateMachine* sm, State* newState);

  void unlock();
  void lock();
  void play();
  void start_blast();
  void stop_blast();

  bool unlock_pressed(vector<bool>&);
  bool lock_pressed(vector<bool>&);
  bool play_stop_pressed(vector<bool>&);
  bool blast_pressed(vector<bool>&);

private:
  string name;
};

#endif /* STATE_H_ */
