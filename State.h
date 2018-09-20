#pragma once
#include <SFML\Graphics.hpp>
class State
{

public:
	State();
	virtual ~State();
	bool m_isStateFinished = false;
	virtual void Initialize() = 0;
	virtual void UpdateDisplay() = 0;
	virtual void UpdateEvents() = 0;
	virtual void HandleEvents() = 0;
};

