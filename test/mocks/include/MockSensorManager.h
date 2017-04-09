//
// Created by Tucker Haydon on 4/9/17.
//
#pragma once
#include "../../include/ISensorManager.h"
#include "../../include/ISensor.h"
#include "../../include/Hardware.h"
#include "../../include/Message.h"
#include <list>


class MockSensorManager : public ISensorManager{

public:
    MockSensorManager();
    ~MockSensorManager() override;

    void addSensor(Hardware hardware, ISensor* sensor) override;
    void updateSensors(std::list<Message*>* messages) override;


};


