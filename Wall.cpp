//project inlcude
#include "Wall.h"
#include "Framework/AssetManager.h"

Wall::Wall()
	: GridObject()
{
	m_Sprite.setTexture(AssetManager::GetTexture("graphics/wall.png"));
	m_BlocksMovement = true;
}