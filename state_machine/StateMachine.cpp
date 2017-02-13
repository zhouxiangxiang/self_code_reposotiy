#include <cassert>
#include "StateMachine.h"

StateMachine::StateMachine(int maxStates) : m_maxStates(maxStates), 
                                            m_currentState(0), 
                                            m_eventGen(false), 
                                            m_pEvetdata(NULL) {
}

void StateMachine::ExternalState(unsigned char newState, EventData* pData) {
	if (newState == EVENT_IGNORED) {
		if (pData)
			delete pData;
	}
	else {
		InternalState(newState, pData);
		StateEngine();
	}
}

void StateMachine::InternalState(unsigned char newState, EventData* pData) {
	m_pEvetdata = pData;
	m_eventGen = true;
	m_currentState = newState;
}

void StateMachine::StateEngine(void) {
	EventData *pDataTmp = NULL;
    // fixme:
    // lock semaphore here
	while (m_eventGen) {
		pDataTmp = m_pEvetdata;
		m_pEvetdata = NULL;
		m_eventGen = false;

        assert(m_currentState < m_maxStates);

        const StateStruct* pStateMap = GetStateMap();
        this->*pStateMap[m_currentState].pStateFunc()(pDataTmp);
        
         if (pDataTmp) {
            delete pDataTmp;
            pDataTmp = NULL;
         }
	}
    // fixme:
    // unlock semaphore here
}
