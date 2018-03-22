#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Thomas.h"
#include "Bob.h"
#include "Level Manager.h" 

using namespace sf;
//SARAH NOTE: don't use "using" in header files

class Engine
{

private:
	//The Texture Holder
	TextureHolder th;
	//SARAH NOTE: Don't name things like "th", no single letter abberviations

	// Our Playable characters, Thomas and Bob
	Thomas m_Thomas;
	Bob m_Bob;

	// Class to manage levels
	LevelManager m_LM;

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;
	const int GRAVITY = 300;

	//A regular RenderWindow
	RenderWindow m_Window;

	//The main Views
	View m_MainView;
	View m_LeftView;
	View m_RightView;

	//Background Views
	View m_BGMainView;
	View m_BGLeftView;
	View m_BGRightView;

	View m_HUDView;

	//Sprite and texture for Background
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

	//is game playing?
	bool m_Playing = false;

	//Which character is of current focus?
	bool m_Character1 = true;
	//SARAH NOTE: use enum instead, name better

	//Full or split screen
	bool m_SplitScreen = false;

	//Time left in current level
	float m_TimeRemaining = 10;
	Time m_GameTimeTotal;

	//Is it time for a new/first level
	bool m_NewLevelRequired = true;

	//The Vertex array for the level tiles
	VertexArray m_VALevel;
	//2D array with map for level data (0-3)
	//A point to a point (a.k.a. 2d array)
	int**m_ArrayLevel = NULL;
	//texture for level tiles
	Texture m_TextureTiles;


	//private functions for internal use
private:
	void input();
	void update(float dtAsSeconds);
	void draw();

	//load a new level
	void loadLevel();

	//detect collisions
	//POLYMORPHISM
	bool detectCollisions(PlayableCharacter& character);

public:
	Engine();
	void run();
};