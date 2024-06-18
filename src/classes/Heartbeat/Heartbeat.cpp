#include "Heartbeat.h"
#define USE_ARDUINO_INTERRUPTS true


Heartbeat::Heartbeat(int Analogpin_1, int Analogpin_2)
{
    pin_1 = Analogpin_1;
    pin_2 = Analogpin_2;
}

void Heartbeat::Initialize()
{
    pinMode(pin_1, INPUT);
    pinMode(pin_2, INPUT);
    Serial.println("Analog pins initialized");
}

int Heartbeat::GetHeartbeatSensor_1()
{
    return Check_The_HeartbeatSensor_1();
}

int Heartbeat::GetHeartbeatSensor_2()
{
    return Check_The_HeartbeatSensor_2();
}

int Heartbeat::Check_The_HeartbeatSensor_1()
{
    // Serial.println("Hello_World_1");
    int HeartbeatSensorRead = analogRead(pin_1);
    return HeartbeatSensorRead;
}

int Heartbeat::Check_The_HeartbeatSensor_2()
{
    // Serial.println("Hello_World_2");
    int HeartbeatSensorRead = analogRead(pin_2);
    return HeartbeatSensorRead;
}

