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

BOOST_AUTO_TEST_CASE( constructors_test ) {

  StateMachine state_machine;
  BOOST_CHECK( state_machine.currentState()->getName() == "Locked" );

}
