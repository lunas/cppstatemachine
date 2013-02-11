//============================================================================
// Name        : StateMachine.cpp
// Author      : Lukas
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#define BOOST_TEST_MODULE StateMachine
#include <boost/test/included/unit_test.hpp>
#include "StateMachine.h"
#include "State.h"
#include <vector>
#include "../../midiconv/gpiocontroller/GpioController.cpp"

struct Fixture {
  Fixture() {
    BOOST_TEST_MESSAGE( "setup fixture" );
    vector<unsigned int> buttons;
    vector<unsigned int> leds;
    for (unsigned int p=0; p<4; p++) buttons.push_back(p);
    for (unsigned int p=0; p<4; p++) leds.push_back(p);
    gpio = new GpioController(buttons, leds);
  }

  ~Fixture()  {
    BOOST_TEST_MESSAGE( "teardown fixture" );
    delete gpio;
  }

  GpioController* gpio;
};

BOOST_FIXTURE_TEST_SUITE( StateMachineTest, Fixture )

BOOST_AUTO_TEST_CASE( constructors_test ) {

  StateMachine sm1(gpio);
  BOOST_CHECK( sm1.currentState()->getName() == "Locked" );

}
BOOST_AUTO_TEST_CASE( locked_and_all_buttons_false_test ) {
  StateMachine sm2(gpio);
  vector<bool> buttons;
  for (size_t i=0;i<4; i++) buttons.push_back(false);
  sm2.handleInput(buttons);
  BOOST_CHECK( sm2.currentState()->getName() == "Locked" );
}

BOOST_AUTO_TEST_CASE( locked_and_button_lock_play_blast_test ) {
  StateMachine sm3(gpio);
  for (size_t i=1; i<4; i++) {
    vector<bool> buttons;
    for (size_t b=0; b<4; b++) buttons.push_back(false);
    buttons[i] = true;
    sm3.handleInput(buttons);
    BOOST_CHECK( sm3.currentState()->getName() == "Locked" );
  }
}


BOOST_AUTO_TEST_CASE( locked_and_button_unlock_test ) {
  StateMachine sm4(gpio);
  vector<bool> buttons;
  for (size_t b=0; b<4; b++) buttons.push_back(false);
  buttons[0] = true;
  sm4.handleInput(buttons);
  BOOST_CHECK( sm4.currentState()->getName() == "Unlocked" );
}

BOOST_AUTO_TEST_SUITE_END()
