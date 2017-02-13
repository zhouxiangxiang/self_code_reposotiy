#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "./EventData.h"

class StateMachine;

typedef void (*StateFunc)(EventData* pEventData);

struct StateStruct {
	StateFunc pStateFunc;
};

class StateMachine {
public:
	StateMachine(int MaxStates);
	virtual ~StateMachine() {}

protected:
	enum {
	    EVENT_IGNORED = 0xFE,
	    EVENT_CANNOTHAPPEN, 
	};

	unsigned m_currentState;

	void ExternalState(unsigned char, EventData* pEvent=nullptr);	
	void InternalState(unsigned char, EventData* pEvent=nullptr);	

	virtual const StateStruct* GetStateMap() = 0;

private:
	const int   m_maxStates;
	bool 	    m_eventGen;
	EventData  *m_pEvetdata;

	void 	 StateEngine(void);	
};



#define BEGIN_STATE_MAP					\
public:							\
const StateStruct* GetStateMap()  { 			\
	static const StateStruct StateMap[] = {		\

#define STATE_MAP_ENTRY(entry)				\
	{ reinterpret_cast<StateFunc>(entry)	},	

#define END_STATE_MAP  					\
	{ reinterpret_cast<StateFunc>(0) 	}	\
	};						\
	return &StateMap[0];				\
    }

#define BEGIN_TRANSITION_MAP				\
	static const unsigned char TRANSITIONS[] = {    \

#define TRANSITION_MAP_ENTRY(entry) 			\
	entry,

#define END_TRANSITION_MAP(data)			       \
	0 };						       \
	ExternalEvent(TRANSITIONS[m_currentState], data);
 
#endif
