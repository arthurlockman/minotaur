#pragma once

#if __linux__
    #include <wiringPi.h>
#elif __unix__
    #include <wiringPi.h>
#else
    #include "../wiringPiMock/wiringPi.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "thread.h"
#include "ISensorManager.h"
#include "Communicator.h"
#include "Message.h"
#include "CommandManager.h"