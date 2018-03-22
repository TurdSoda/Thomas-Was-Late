#include "stdafx.h"
#include "Engine.h"

void Engine::draw()
{

	//Erase the last frame
	m_Window.clear(Color::White);

	//Single screen
	if (!m_SplitScreen)
	{

		//switch to bakground view
		m_Window.setView(m_BGMainView);
		// Draw the background
		m_Window.draw(m_BackgroundSprite);
		//set main view
		m_Window.setView(m_MainView);
		//TODO: Draw all assets

		// draw the level
		m_Window.draw(m_VALevel, &m_TextureTiles);

		//draw Thomas and Bob
		m_Window.draw(m_Thomas.getSprite());
		m_Window.draw(m_Bob.getSprite());

	}//end single screen
	//split screen
	else
	{

		// draw Thomas' side of the screen
		//Switch to the background view
		m_Window.setView(m_BGLeftView);
		// Draw background
		m_Window.draw(m_BackgroundSprite);
		// Switch to the main view for left
		m_Window.setView(m_LeftView);

		// draw the level
		m_Window.draw(m_VALevel, &m_TextureTiles);

		//draw Thomas and Bob
	m_Window.draw(m_Thomas.getSprite());
	m_Window.draw(m_Bob.getSprite());

		// draw Bob's side of the screen
		//Switch to the background view
		m_Window.setView(m_BGRightView);
		// Draw background
		m_Window.draw(m_BackgroundSprite);
		// Switch to the main view for Right
		m_Window.setView(m_RightView);
		//TODO: Draw all assets

		// draw the level
		m_Window.draw(m_VALevel, &m_TextureTiles);

		//draw Thomas and Bob
		m_Window.draw(m_Thomas.getSprite());
		m_Window.draw(m_Bob.getSprite());

	}//end split screen

	//Draw HUD
	//Switch to hud
	m_Window.setView(m_HUDView);
	//TODO: Draw HUD


	//Show eveything drawn
	m_Window.display();

}//end of draw finction