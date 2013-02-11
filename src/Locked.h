/*
 * Locked.h
 *
 *  Created on: Feb 9, 2013
 *      Author: Lukas
 */

#ifndef LOCKED_H_
#define LOCKED_H_

#include "State.h"

class Locked: public State {
public:

  static State* instance();

  virtual void handleInput(StateMachine*, vector<bool>);

  virtual void set_leds(StateMachine* sm);

//protected:
  Locked();
  virtual ~Locked();

private:
  static Locked* the_instance;

};

#endif /* LOCKED_H_ */
