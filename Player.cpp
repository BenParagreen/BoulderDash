//project inlcude
#include "Player.h"
#include "Framework/AssetManager.h"
#include "Level.h"

Player::Player()
	: GridObject()
	, m_PendingMove(0,0)
	, m_WalkSound()
	, m_BumpSound()
{
	m_Sprite.setTexture(AssetManager::GetTexture("graphics/player/playerStandDown.png"));
	m_WalkSound.setBuffer(AssetManager::GetSoundBuffer("audio/footstep1.ogg"));
	m_BumpSound.setBuffer(AssetManager::GetSoundBuffer("audio/bump.wav"));

}

void Player::Input(sf::Event _GameEvent)
{
	//read the input from the keyboard
	//convert it to a direction to move in
	//the move

	//was the _GameEvent a keypress?
	if (_GameEvent.type == sf::Event::KeyPressed)
	{
		//yes, it was a keypress

		//what key was pressed?
		if (_GameEvent.key.code == sf::Keyboard::W || _GameEvent.key.code == sf::Keyboard::Up)
		{
			// it was W that was pressed
			//move up
			m_PendingMove = sf::Vector2i(0, -1);
			m_Sprite.setTexture(AssetManager::GetTexture("graphics/player/playerStandUp.png"));

		}
		else if (_GameEvent.key.code == sf::Keyboard::A || _GameEvent.key.code == sf::Keyboard::Left)
		{
			// it was A that was pressed
			//move left
			m_PendingMove = sf::Vector2i(-1, 0);
			m_Sprite.setTexture(AssetManager::GetTexture("graphics/player/playerStandLeft.png"));

		}
		else if (_GameEvent.key.code == sf::Keyboard::S || _GameEvent.key.code == sf::Keyboard::Down)
		{
			// it was S that was pressed
			//move down
			m_PendingMove = sf::Vector2i(0, 1);
			m_Sprite.setTexture(AssetManager::GetTexture("graphics/player/playerStandDown.png"));

		}
		else if (_GameEvent.key.code == sf::Keyboard::D || _GameEvent.key.code == sf::Keyboard::Right)
		{
			// it was D that was pressed
			//move Right
			m_PendingMove = sf::Vector2i(1, 0);
			m_Sprite.setTexture(AssetManager::GetTexture("graphics/player/playerStandRight.png"));
		}
	}
}

void Player::Update(sf::Time _FrameTime)
{

	//if we have movement waiting to be processed,
	if (m_PendingMove.x != 0 || m_PendingMove.y != 0)
	{
		//move in that direction
		bool MoveSuccessful = AttemptMove(m_PendingMove);

		//play movements sound if we move position
		if (MoveSuccessful = true)
		{
			//play sound
			m_WalkSound.play();
		}

		//clear the pending movement
		m_PendingMove = sf::Vector2i(0, 0);
	}

}

bool Player::AttemptMove(sf::Vector2i _Direction)
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
	for (int i = 0; i < TargetCellContents.size(); ++i)
	{
		if (TargetCellContents[i]->GetBlockedMovement() == true)
		{
			blocked = true;
		}
	}

	if (blocked == true)
	{
		m_BumpSound.play();
	}

	//if empty, move there
	if (blocked == false)
	{
		return m_Level->MoveObjectTo(this, TargetPos);
	}
	//if movement is blocked, do nothing, return false
	return false;
}