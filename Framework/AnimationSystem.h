#pragma once

//library includes
#include <map>

//project includes
#include "Animation.h"

class AnimationSystem
{

public:

	AnimationSystem();

	// setup
	void SetSprite(sf::Sprite& _sprite);
	Animation& CreateAnimation(std::string _name);

	//TODO: add animation getter

	//controls
	void Play();
	void Play(std::string _newAnimation);
	void Pause();
	void Stop();

	//processing
	void Update(sf::Time _frameTime);
	   

private:
	
	//settings
	sf::Sprite* m_sprite;
	std::map<std::string, Animation> m_animations;
	

	//state
	Animation* m_currentAnimation;


};