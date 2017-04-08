//
// Created by Arthur Lockman on 4/5/17.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <commands/SimpleIteratorCommand.h>
#include "../include/CommandManager.h"
#include "../catch/catch.hpp"

unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
}


TEST_CASE("Command subsystem tests", "[CommandManager]") {
    SECTION("Command manager can be killed.") {
        CommandManager *commandManager = new CommandManager();
        REQUIRE(commandManager->kill() == 0);
    }
    SECTION("Simple commands run to completion.") {
        CommandManager *commandManager1 = new CommandManager();
        SimpleIteratorCommand *sc1 = new SimpleIteratorCommand(10);
        SimpleIteratorCommand *sc2 = new SimpleIteratorCommand(20);
        commandManager1->runCommand(sc1);
        commandManager1->runCommand(sc2);
        while (!sc1->isFinished() && !sc2->isFinished()) {}
        REQUIRE(sc1->getCount() == 10);
        REQUIRE(sc2->getCount() == 20);
        commandManager1->kill();
    }
}