#pragma once
#include "GameParameters.h"

#include <queue>
#include "MainMenuState.h"
#include "MainGameState.h"
class Game;
class StateManager
{
private:
	State* currentState;
	State* nextState;
	State* prevState;
	
public:
	StateManager();
	~StateManager();
	std::vector<State*> myGameStates;
	
	std::queue<std::unique_ptr<State>> m_stateQueue;

	void addState(States t_stateID)
	{
		switch (t_stateID)
		{
		case States::MAINMENU :
		{
			if (m_stateQueue.size() != 0)
			{
				m_stateQueue.pop();
			}
			m_stateQueue.push(std::unique_ptr<State>(new MainMenuState()));
			SetNextState(*m_stateQueue.front().get());
		}
		break;
		case States::GAME:
		{
			if (m_stateQueue.size() != 0)
			{
				m_stateQueue.pop();
			}
			m_stateQueue.push(std::unique_ptr<State>(new MainGameState()));
			SetNextState(*m_stateQueue.front().get());
		}
		break;
		default:
			break;
		}

	}


	void SetNextState(State& t_state)
	{
		nextState = & t_state;
	}
	void checkState()
	{
		if (currentState->m_isStateFinished)
		{
			std::cout << "Mainmenu finished count";
			addState(States::GAME);
		}
	}
	void HandleState()
	{
		if (currentState != nextState)
		{
			currentState = nextState;
		}
		else
			return;
	}
	State& GetCurrentState()
	{
		return *currentState;
	}


};

