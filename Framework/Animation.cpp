//project includes
#include "Animation.h"

Animation::Animation()
	: m_frames ()
	, m_sprite (nullptr)
	, m_playbackSpeed(15)
	, m_loop(false)
	, m_playing(false)
	, m_nextFrameChange()
	, m_currentFrame(0)

{

}

void Animation::Update(sf::Time _frameTime)
{
	//only process the animation if it is playing
	if (m_playing)
	{

		//Is it time to change to a new frame?
		m_nextFrameChange -= _frameTime;

		if (m_nextFrameChange.asSeconds() <= 0)
		{
			//it's time to change the frame

			//change to the next frame
			++m_currentFrame;

			//Did we reach the end?
			if (m_currentFrame >= m_frames.size())
			{
				//we did reach the end

				//should we loop?
				if (m_loop)
				{	
					//we should loop

					//wrap around to the begining
					m_currentFrame = 0;
				}
				else
				{
					//we should not loop

					//set our frame as the last in the list
					m_currentFrame = m_frames.size() - 1;

					//stop playback
					m_playing = false;
				}
			
				
			}

			//update sprite's texture
			//check if m_sprite isn't = null/zero/nullpointer
			if (m_sprite)
			{
				m_sprite->setTexture(*m_frames[m_currentFrame]);
			}

			//determine time for next frame change
			//convert frames per second to seconds per frame
			float timeToChange = 1.0f / m_playbackSpeed;
			m_nextFrameChange = sf::seconds(timeToChange);
		}
	}

}

void Animation::Play()
{
	//update our sprite to the current frame immediately
	if (m_sprite)
	{
		m_sprite->setTexture(*m_frames[m_currentFrame]);
	}

	//only start playing and set next frame time if playback speed is non zero
	//prevents divide by zero error
	if(m_playbackSpeed!=0)
	{
		//set playback to true
		m_playing = true;

		//determine time for next frame change
		//convert frames per second to seconds per frame
		float timeToChange = 1.0f / m_playbackSpeed;
		m_nextFrameChange = sf::seconds(timeToChange);
	}

}
void Animation::Pause()
{
	//stop playback
	m_playing = false;
}

void Animation::Stop()
{
	//stop playback and reset to first frame
	m_playing = false;
	m_currentFrame = 0;
}

bool Animation::IsPlaying()
{
	//tell the calling code if the game is playing
	return m_playing;
}

void Animation::AddFrame(sf::Texture& _newFrame)
{
	m_frames.push_back(&_newFrame);
}

void Animation::SetSprite(sf::Sprite& _sprite)
{
	m_sprite = &_sprite;
}

void Animation::SetPlaybackSpeed(float _framesPerSecond)
{
	//set playback speed to passed in parameter
	m_playbackSpeed = _framesPerSecond;

	//if the playback speed is zero
	//pause to protect from divide by zero
	if (m_playbackSpeed == 0)
	{
		Pause();
	}
}

void Animation::SetLoop(bool _loop)
{
	//set m_loop to passed in parameter
	m_loop = _loop;
}