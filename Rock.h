#pragma once

//project includes
#include "GridObject.h"

class Rock : public GridObject
{

public:
	Rock();
	void Update(sf::Time _FrameTime);

private:

	bool AttemptMove(sf::Vector2i _Direction);
	bool AttemptSlide(sf::Vector2i _Direction);

private:

	sf::Vector2i m_PendingMove;
}; 