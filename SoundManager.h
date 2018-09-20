#pragma once
#include <string>
#include <memory>
#include <SFML/Audio.hpp>
#include <map>
#include <cassert>
namespace SFX
{
	enum ID
	{
		BALL_HIT_PADDLE,
		BALL_HIT_BRICK,
		FIREBALL_HIT_BRICK,
		PADDLE_BULLET_FIRE,
		BULLET_HIT_BRICK
	};
}

class SoundManager
{
public:
	SoundManager();
	~SoundManager();
	void addSound(SFX::ID t_effect,const std::string& t_filepath);
	sf::SoundBuffer& get(SFX::ID t_id);
private:
	std::map<SFX::ID, std::unique_ptr<sf::SoundBuffer>> m_soundMap;
};

