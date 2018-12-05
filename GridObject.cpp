
//project includes
#include "GridObject.h"
#include "Level.h"

GridObject::GridObject()
	: SpriteObject()
	, m_GridPosition(0, 0)
	, m_Level(nullptr)
	, m_BlocksMovement(false)
{

}

void GridObject::SetGridPosition(sf::Vector2i _NewPosition)
{
	m_GridPosition = _NewPosition;
	m_Sprite.setPosition(m_GridPosition.x * m_Level->GetCellSize(), 
					     m_GridPosition.y * m_Level->GetCellSize());
}
void GridObject::SetGridPosition(int _x, int _y)
{
	SetGridPosition(sf::Vector2i(_x, _y));
}

void GridObject::SetLevel(Level* _NewLevel)
{
	m_Level = _NewLevel;
}

sf::Vector2i GridObject::GetGridPosition()
{
	return m_GridPosition;
}

bool GridObject::GetBlockedMovement() 
{
	return m_BlocksMovement;
}