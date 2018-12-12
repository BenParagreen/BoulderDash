//project inlcude
#include "Dirt.h"
#include "Framework/AssetManager.h"


Dirt::Dirt()
	: GridObject()
{
	m_Sprite.setTexture(AssetManager::GetTexture("graphics/Dirt.png"));
	m_BlocksMovement = true;
}

