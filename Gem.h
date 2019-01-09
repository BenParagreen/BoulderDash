#pragma once

//project includes
#include "GridObject.h"

class Gem : public GridObject
{

public:
	Gem();
	void Update(sf::Time _FrameTime);

private:

	bool AttemptMove(sf::Vector2i _Direction);

private:

	sf::Vector2i m_PendingMove;
};