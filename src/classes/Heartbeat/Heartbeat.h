#ifndef HEARTBEAT_H
#define HEARTBEAT_H
#include <Arduino.h>

class Heartbeat
{
    public:
        Heartbeat(int Analogpin_1, int Analogpin_2);
        void Initialize();
        int GetHeartbeatSensor_1();
        int GetHeartbeatSensor_2();
        int Check_The_HeartbeatSensor_1();
        int Check_The_HeartbeatSensor_2();

    private:
        int pin_1;
        int pin_2;


};
#endif