#include "stdafx.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;

void Engine::update(float dtAsSeconds)
{

	if (m_NewLevelRequired)
	{

		loadLevel();

	}

	if (m_Playing)
	{

		//update thomas and bob
		m_Thomas.update(dtAsSeconds);
		m_Bob.update(dtAsSeconds);

		// detect collisons and see if the characters have reached the goal
		if (detectCollisions(m_Thomas) && detectCollisions(m_Bob))
		{

			// new level required
			m_NewLevelRequired = true;

			//TODO: PLay spund for reaching goal

		}
		else
		{

			//run Bob collision detection
			detectCollisions(m_Bob);

		}

		//Let bob and thomas jump on each others heads
		if (m_Bob.getFeet().intersects(m_Thomas.getHead()))
		{

			m_Bob.stopFalling((m_Thomas.getHead().top));

		}
		if (m_Thomas.getFeet().intersects(m_Bob.getHead()))
		{

			m_Thomas.stopFalling((m_Bob.getHead().top));

		}

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