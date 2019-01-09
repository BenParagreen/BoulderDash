#pragma once

//library includes
#include <SFML/Graphics.hpp>

//project includes
#include "GridObject.h"

class Level
{

public:
	Level();

	void Draw(sf::RenderTarget& _Target);
	void Update(sf::Time _FrameTime);
	void Input(sf::Event _GameEvent);

	void LoadLevel(int _LevelToLoad);
	void ReloadLevel();
	void LoadNextLevel();
	float GetCellSize();
	bool MoveObjectTo(GridObject* _ToMove, sf::Vector2i _TargetPos);
	bool DeleteObject(GridObject* _ToDelete, sf::Vector2i _TargetPos);
	std::vector<GridObject* > GetObjectAt(sf::Vector2i _TargetPos);

	bool CheckComplete();

private:

	const float m_CellSize;
	int m_CurrentLevel;
	int m_pendingLevel;
	std::vector< std::vector < sf::Sprite > > m_Background;
	std::vector< std::vector < std::vector< GridObject* > > > m_Contents;
};