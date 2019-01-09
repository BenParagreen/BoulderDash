//project inlcude
#include "Gem.h"
#include "Framework/AssetManager.h"
#include "Level.h"
#include "Player.h"

Gem::Gem()
	: GridObject()
	, m_PendingMove(0, 1)
{
	m_Sprite.setTexture(AssetManager::GetTexture("graphics/Gem.png"));
	m_BlocksMovement = true;
}

void Gem::Update(sf::Time m_FrameTime)
{

	//if we have movement waiting to be processed,
	if (m_PendingMove.x != 0 || m_PendingMove.y != 0)
	{
		//TODO Wait a second

		//move in that direction
		bool MoveSuccessful = AttemptMove(m_PendingMove);
	}
}

bool Gem::AttemptMove(sf::Vector2i _Direction)
{
	// Attempt to move in the given direction

	//get the current position
	//calculate the target position
	sf::Vector2i TargetPos = m_GridPosition + _Direction;

	// check if the space is empty
	// get list of  objects in our target position
	std::vector<GridObject*> TargetCellContents = m_Level->GetObjectAt(TargetPos);

	// check if any of those objects block movement
	bool blocked = false;
	GridObject* blocker = nullptr;
	for (int i = 0; i < TargetCellContents.size(); ++i)
	{
		if (TargetCellContents[i]->GetBlockedMovement() == true)
		{
			blocked = true;
			blocker = TargetCellContents[i];
		}
	}


	//if empty, move there
	if (blocked == false)
	{
		return m_Level->MoveObjectTo(this, TargetPos);
	}

	else 
	{
		// We were blocked, Can we kill the thing blocking us
		// Do a dynamic cast to player to see if we can kill it
		Player* deadMan = dynamic_cast<Player*>(blocker);

		// If so Attempt to push
		if (deadMan != nullptr)
		{
			m_Level->CheckDeath();
		}
	}

	return false;
}
