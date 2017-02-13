#include <cassert>
#include "Motor.h"

void Motor::Halt(void) {
    BEGIN_TRANSITION_MAP                            // -- current state --
        TRANSITION_MAP_ENTRY(EVENT_IGNORED)         //  ST_Idle
        TRANSITION_MAP_ENTRY(EVENT_CANNOTHAPPEN)    //  ST_Stop
        TRANSITION_MAP_ENTRY(ST_STOP)               //  ST_Start
        TRANSITION_MAP_ENTRY(ST_STOP)               //  ST_ChangedSpeed
    END_TRANSITION_MAP(nullptr)                          
}                                                     

void Motor::SetSpeed(MotorData* pData) {              
    BEGIN_TRANSITION_MAP                            // -- current state --
        TRANSITION_MAP_ENTRY(ST_START)              //  ST_Idle  
        TRANSITION_MAP_ENTRY(EVENT_CANNOTHAPPEN)    //  ST_Stop  
        TRANSITION_MAP_ENTRY(ST_CHANGE_SPEED)       //  ST_Start 
        TRANSITION_MAP_ENTRY(ST_CHANGE_SPEED)       //  ST_ChangedSpeed          
    END_TRANSITION_MAP(pData)                          
}                                                      

void Motor::ST_Idle() {
}

void Motor::ST_Start() {
}

void Motor::ST_ChangeSpeed() {
}

void Motor::ST_Stop() {
    InternalState(ST_IDLE);
}

