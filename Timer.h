#pragma once
class Timer
{
	float m_value;
	static Timer *s_instance;
	Timer(float v = 1)
	{
		m_value = 1;
	}
public:
	float get_value()
	{
		return m_value;
	}
	void set_value(float v)
	{
		m_value = v;
	}
	static Timer *instance()
	{
		if (!s_instance)
			s_instance = new Timer;
		return s_instance;
	}
};
