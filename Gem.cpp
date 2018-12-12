//project inlcude
#include "Gem.h"
#include "Framework/AssetManager.h"

Gem::Gem()
	: GridObject()
{
	m_Sprite.setTexture(AssetManager::GetTexture("graphics/Gem.png"));
	m_BlocksMovement = true;
}