#pragma once


//library includes
#include <vector>
#include<SFML/Graphics.hpp>


class Animation
{

public:

	Animation();

	void Update(sf::Time _frameTime);
	
	void Play();
	void Pause();
	void Stop();

	bool IsPlaying();

	void AddFrame(sf::Texture& _newFrame);
	void SetSprite(sf::Sprite& _sprite);
	void SetPlaybackSpeed(float _framesPerSecond);
	void SetLoop(bool _loop);


private:

	//settings
	std::vector<sf::Texture*>m_frames;
	sf::Sprite*m_sprite;
	float m_playbackSpeed;
	bool m_loop;

	//state
	bool m_playing;
	sf::Time m_nextFrameChange;
	int m_currentFrame;

};