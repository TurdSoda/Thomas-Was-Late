#include "stdafx.h"
#include "Engine.h"

Engine::Engine()
{

	//Get the screen resolution and create SFML window and view
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	m_Window.create(VideoMode(resolution.x, resolution.y),
		"Thomas was Late", Style::Fullscreen);

	//Initialise the fullscreen view
	m_MainView.setSize(resolution);
	m_HUDView.reset(FloatRect(0, 0, resolution.x, resolution.y));

	//Initialise Split Screen view
	m_LeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_RightView.setViewport(FloatRect(0.5f, 0.001f, 0.498f, 0.998f));

	//split screen backgrounds
	m_BGLeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_BGRightView.setViewport(FloatRect(0.5f, 0.001f, 0.498f, 0.998f));

	//Get backgorund texture
	m_BackgroundTexture = TextureHolder::GetTexture("graphics/background.png");

	//Associate the sprite with the texture
	m_BackgroundSprite.setTexture(m_BackgroundTexture);

}

void Engine::run()
{

	Clock clock;

	while (m_Window.isOpen())
	{

		Time dt = clock.restart();
		//Update the total game time
		m_GameTimeTotal += dt;

		//Make a decimal fraction from the delta time
		float dtAsSeconds = dt.asSeconds();

		//call each part of the game loop
	//	input();
	//	update(dtAsSeconds);
	//	draw();

	}

}