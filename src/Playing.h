/*
 * Playing.h
 *
 *  Created on: Feb 11, 2013
 *      Author: Lukas
 */

#ifndef PLAYING_H_
#define PLAYING_H_

#include "State.h"

class Playing: public State {
public:

  static State* instance();

  virtual void handleInput(StateMachine*, vector<bool>);

  virtual void set_leds(StateMachine* sm);

//protected:
  Playing();
  virtual ~Playing();

private:
  static Playing* the_instance;
};

#endif /* PLAYING_H_ */
