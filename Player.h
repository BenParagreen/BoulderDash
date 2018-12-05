#pragma once

//project includes
#include "GridObject.h"

class Player : public GridObject
{

	//functions
public:
	Player();

	//Overriding methods
	void Input(sf::Event _GameEvent);
	void Update(sf::Time _FrameTime);

private:

	bool AttemptMove(sf::Vector2i _Direction);

	//Data
private:

	sf::Vector2i m_PendingMove;
	sf::Sound m_WalkSound;
	sf::Sound m_BumpSound;
};