#include "SoundPlayer.h"



SoundPlayer::SoundPlayer() : m_soundManager()
{
	m_soundManager.addSound(SFX::BALL_HIT_BRICK, "sfx_hit_brick_1.wav");
	m_soundManager.addSound(SFX::BALL_HIT_PADDLE, "sfx_hit_paddle.wav");
}


SoundPlayer::~SoundPlayer()
{
}


void SoundPlayer::playEffect(SFX::ID t_effect)
{
	m_soundQueue.push(sf::Sound(m_soundManager.get(t_effect)));
	m_soundQueue.front().play();
}
