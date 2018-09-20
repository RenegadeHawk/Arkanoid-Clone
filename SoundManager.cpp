#include "SoundManager.h"



SoundManager::SoundManager()
{
}


SoundManager::~SoundManager()
{
}

void SoundManager::addSound(SFX::ID t_effect, const std::string & t_filepath)
{
	std::unique_ptr<sf::SoundBuffer> soundBuffer(new sf::SoundBuffer());
	if (!soundBuffer->loadFromFile(t_filepath))
	{
		//error
	}
	m_soundMap.insert(std::make_pair(t_effect,std::move(soundBuffer)));

}

sf::SoundBuffer & SoundManager::get(SFX::ID t_id)
{
	auto found = m_soundMap.find(t_id);
	assert(found != m_soundMap.end());

	return *found->second;
}


