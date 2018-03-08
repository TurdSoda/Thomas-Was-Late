#include "stdafx.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;

void Engine::update(float dtAsSeconds)
{

	if (m_Playing)
	{

		//Count down time player has left
		m_TimeRemaining -= dtAsSeconds;

		//Has the player run out of time
		if (m_TimeRemaining <= 0)
		{

			m_NewLevelRequired = true;

		}

	}//End of if Playing

}//end of update function