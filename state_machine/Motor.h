#ifndef MOTOR_H
#define MOTOR_H

#include "StateMachine.h"

struct MotorData : public EventData {
    int m_speed;
};

class Motor : public StateMachine {
public:
    Motor() : StateMachine(ST_MAX_STATES) {}

    void Halt();
    void SetSpeed(MotorData*);

private:
    static void ST_Idle(MotorData* );
    static void ST_Stop(MotorData* );
    static void ST_Start(MotorData*);
    static void ST_ChangeSpeed(MotorData*);

    BEGIN_STATE_MAP
        STATE_MAP_ENTRY(ST_Idle)
        STATE_MAP_ENTRY(ST_Stop)
        STATE_MAP_ENTRY(ST_Start)
        STATE_MAP_ENTRY(ST_ChangeSpeed)
    END_STATE_MAP

    enum E_States {
        ST_IDLE = 0,
        ST_STOP,
        ST_START,
        ST_CHANGE_SPEED,
        ST_MAX_STATES,
    };
};

#endif  // MOTOR_H

