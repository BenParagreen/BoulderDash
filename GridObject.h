#pragma once

//project includes
#include "Framework/SpriteObject.h"

//Forward Declaration
//only works with pointers(*)/references(&)
class Level;

class GridObject : public SpriteObject
{

public:

	GridObject();

	void SetGridPosition(sf::Vector2i _NewPosition);
	//overloaded function
	void SetGridPosition(int _x,int _y);
	bool GetBlockedMovement();

	void SetLevel(Level* _NewLevel);

	sf::Vector2i GetGridPosition();

protected:

	sf::Vector2i m_GridPosition;
	Level* m_Level;
	bool m_BlocksMovement;

};