//library include
#include <assert.h>

// prject includes
#include "AnimationSystem.h"


AnimationSystem::AnimationSystem()
	: m_sprite(nullptr)
	, m_animations()
	, m_currentAnimation(nullptr)
	
{

}

void AnimationSystem::SetSprite(sf::Sprite& _sprite)
{
	m_sprite = &_sprite;

	//update all sprites for the animations already in the map
	for (auto it = m_animations.begin();it !=m_animations.end(); ++it )
	{
		it->second.SetSprite(_sprite);
	}
}

Animation& AnimationSystem::CreateAnimation(std::string _name)
{
	//throw an error if this animation is already in our system
	//undefined behaviour
	assert(m_animations.find(_name) == m_animations.end());

	//create the animation using array notation
	Animation& newAnimation = m_animations[_name];

	//set the sprite for the animation
	if (m_sprite)
	{
		newAnimation.SetSprite(*m_sprite);
	}

	return newAnimation;
}

void AnimationSystem::Play()
{
	if (m_currentAnimation)
		m_currentAnimation->Play();
}

void AnimationSystem::Play(std::string _newAnimation)
{
	if (m_currentAnimation)
		m_currentAnimation->Stop();

	// Throw an error if this animation is NOT in our system
	assert(m_animations.find(_newAnimation) != m_animations.end());

	m_currentAnimation = &m_animations[_newAnimation];
	m_currentAnimation->Play();
}

void AnimationSystem::Pause()
{
	if (m_currentAnimation)
		m_currentAnimation->Pause();
}

void AnimationSystem::Stop()
{
	if (m_currentAnimation)
		m_currentAnimation->Stop();
}

void AnimationSystem::Update(sf::Time _frameTime)
{
	if (m_currentAnimation)
		m_currentAnimation->Update(_frameTime);
}
