//project inlcude
#include "Rock.h"
#include "Framework/AssetManager.h"
#include "Level.h"
#include "Player.h"

Rock::Rock()
	: GridObject()
	, m_PendingMove(0, 1)
{
	m_Sprite.setTexture(AssetManager::GetTexture("graphics/Rock.png"));
	m_BlocksMovement = true;
}

void Rock::Update(sf::Time _FrameTime)
{

	//if we have movement waiting to be processed,
	if (m_PendingMove.x != 0 || m_PendingMove.y != 0)
	{
		//TODO Wait a second

		//move in that direction
		bool MoveSuccessful = AttemptMove(m_PendingMove);
	}
}

bool Rock::AttemptMove(sf::Vector2i _Direction)
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
		// We were blocked, Can we slide off the thing blocking us
		// Do a dynamic cast to rock to see if we can slide off
		Rock* slideTime = dynamic_cast<Rock*>(blocker);

		// If so Attempt to slide
		if (slideTime != nullptr)
		{

	        m_PendingMove = m_PendingMove + sf::Vector2i(1, 0);
			AttemptMove(m_PendingMove);


		}

		// We were blocked, Can we kill the thing blocking us
		// Do a dynamic cast to player to see if we can kill it
		Player* deadMan = dynamic_cast<Player*>(blocker);

		// If so Attempt to push
		if (deadMan != nullptr)
		{
			m_Level->ReloadLevel();
		}
		
	}
	//if movement is blocked, reset Movement, return false
	m_PendingMove = sf::Vector2i(0, 1);
		return false;
}

