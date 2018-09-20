#include "StateManager.h"


StateManager::StateManager()
{
	currentState = nullptr;
	nextState = nullptr;
	prevState = nullptr;
}

StateManager::~StateManager()
{
}
