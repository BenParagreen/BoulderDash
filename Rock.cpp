//project inlcude
#include "Rock.h"
#include "Framework/AssetManager.h"
#include "Level.h"
#include "Player.h"

Rock::Rock()
	: GridObject()
	, m_PendingMove(0, 1)
	, m_falltime(1.0f)
{
	m_Sprite.setTexture(AssetManager::GetTexture("graphics/Rock.png"));
	m_BlocksMovement = true;
}

void Rock::Update(sf::Time m_falltime)
{
	
	//if we have movement waiting to be processed,
	if (m_PendingMove.x != 0 || m_PendingMove.y != 0)
	{
		//TODO Wait a second

		//move in that direction
		bool MoveSuccessful = AttemptMove(m_PendingMove);
	}
}

bool Rock::AttemptPush(sf::Vector2i _Direction)
{
	//attempt to move the Rock in the given direction
		//get the current position
		//calculate the target position
	sf::Vector2i TargetPos = m_GridPosition + _Direction;
	// check if the space is empty
	// get list of  objects in our target position
	std::vector<GridObject*> TargetCellContents = m_Level->GetObjectAt(TargetPos);
	// check if any of those objects block movement
	bool blocked = false;
	for (int i = 0; i < TargetCellContents.size(); ++i)
	{
		if (TargetCellContents[i]->GetBlockedMovement() == true)
		{
			blocked = true;
		}
	}
	//if empty, move there
	if (blocked == false)
	{
		bool moveSucceded = m_Level->MoveObjectTo(this, TargetPos);

		return moveSucceded;
	}
	//if movement is blocked, do nothing, return false
	return false;
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
		// If we were trying to move straight down (not yet sliding)
		if (_Direction.x == 0)
		{
			// Check if the thing blocking us is a rock
			Rock* slideTime = dynamic_cast<Rock*>(blocker);
			if (slideTime != nullptr)
			{
				// If so, try sliding right
				AttemptMove(_Direction + sf::Vector2i(1, 0));
			}
		}
		// If we were trying to move down right (already sliding)
		if (_Direction.x == 1)
		{
			// Regardless of what is NOW blocking us, try sliding left
			AttemptMove(_Direction + sf::Vector2i(-2, 0));
		}

		// If we were trying to move down left (already sliding)
		if (_Direction.x == -1)
		{
			// We've tried everyting and were blocked again, stop
			return false;
		}


		// We were blocked, Can we kill the thing blocking us
		// Do a dynamic cast to player to see if we can kill it
		Player* deadMan = dynamic_cast<Player*>(blocker);

		// If so Attempt to push
		if (deadMan != nullptr)
		{
			m_Level->CheckDeath();
		}
		
	}
	//if movement is blocked, reset Movement, return false
	return false;
}

