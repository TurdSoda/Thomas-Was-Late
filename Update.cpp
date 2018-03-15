#include "stdafx.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;

void Engine::update(float dtAsSeconds)
{

	if (m_NewLevelRequired)
	{

		// NOTE: This will be moved to loadLevel() later
		//Spawn Thomas and Bob

		m_Thomas.spawn(Vector2f(0, 0), GRAVITY);
		m_Bob.spawn(Vector2f(100, 0), GRAVITY);

		//Initialsise time and level boolean
		m_TimeRemaining = 10;
		m_NewLevelRequired = false;

	}

	if (m_Playing)
	{

		//update thomas and bob
		m_Thomas.update(dtAsSeconds);
		m_Bob.update(dtAsSeconds);

		//Count down time player has left
		m_TimeRemaining -= dtAsSeconds;

		//Has the player run out of time
		if (m_TimeRemaining <= 0)
		{

			m_NewLevelRequired = true;

		}

	}//End of if Playing

	//Set the view around the appropriate character
	if (m_SplitScreen)
	{

		m_LeftView.setCenter(m_Thomas.getCenter());
		m_RightView.setCenter(m_Bob.getCenter());

	}
	else
	{

		if (m_Character1)//if we should focus on Thomas
		{

			m_MainView.setCenter(m_Thomas.getCenter());

		}

	}

}//end of update function