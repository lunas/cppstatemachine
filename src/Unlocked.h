/*
 * Unlocked.h
 *
 *  Created on: Feb 10, 2013
 *      Author: dan
 */

#ifndef UNLOCKED_H_
#define UNLOCKED_H_

#include "State.h"

class Unlocked: public State {
public:

  static State* instance();

  virtual void handleInput(StateMachine*, vector<bool>);

  virtual void set_leds(StateMachine* sm);

protected:
  Unlocked();
  virtual ~Unlocked();

private:
  static Unlocked* the_instance;
};

#endif /* UNLOCKED_H_ */
