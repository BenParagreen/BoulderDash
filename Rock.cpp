//project inlcude
#include "Rock.h"
#include "Framework/AssetManager.h"

Rock::Rock()
	: GridObject()
{
	m_Sprite.setTexture(AssetManager::GetTexture("graphics/Rock.png"));
	m_BlocksMovement = true;
}