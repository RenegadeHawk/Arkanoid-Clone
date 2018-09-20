#pragma once
#include "SoundManager.h"
#include <queue>
class SoundPlayer
{
public:
	SoundPlayer();
	~SoundPlayer();
	void playEffect(SFX::ID t_effect);
private:
	SoundManager m_soundManager;
	std::vector<sf::Sound> m_sounds;
	std::queue <sf::Sound> m_soundQueue;
	sf::Sound m_sound;
};

