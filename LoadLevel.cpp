#include "stdafx.h"
#include "Engine.h"

void Engine::loadLevel()
{

	m_Playing = false;

	//Delete the previously allocated memory
	for (int i = 0; i < m_LM.getLevelSize().y;++i)
	{

		delete[] m_ArrayLevel[i];

	}
	delete[] m_ArrayLevel;

	//load the next 2D array with the map for the level
	//repopulate the vertex array
	m_ArrayLevel = m_LM.nextLevel(m_VALevel);

	//how long is the new time limit
	m_TimeRemaining = m_LM.getTimeLimit();

	//spawn Thomas and bob
	m_Thomas.spawn(m_LM.getStartPosition(), GRAVITY);
	m_Bob.spawn(m_LM.getStartPosition(), GRAVITY);

	//make sure this isn't run twice
	m_NewLevelRequired = false;


}//end of loadLevel()