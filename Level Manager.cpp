#include "stdafx.h"
#include "Level Manager.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TextureHolder.h"
#include <sstream>
#include <fstream>

using namespace sf;
using namespace std;

int** LevelManager::nextLevel(VertexArray&rVaLevel)
{

	m_LevelSize.x = 0;
	m_LevelSize.y = 0;

	//get next level

	m_CurrentLevel++;
	if (m_CurrentLevel > NUMLEVEL)
	{

		m_CurrentLevel = 1;
		m_TimeModifier -= 0.1f;

	}

	//load the appropriate level form a text file
	string levelToLoad;
	switch (m_CurrentLevel)
	{

	case 1:
		levelToLoad = "levels/level1l.txt";
		m_startPosition.x = 100;
		m_startPosition.y = 100;
		m_BaseTimeLimit = 30.0f;
		break;

	case 2:
		levelToLoad = "levels/level2l.txt";
		m_startPosition.x = 100;
		m_startPosition.y = 3600;
		m_BaseTimeLimit = 100.0f;
		break;

	case 3:
		levelToLoad = "levels/level3l.txt";
		m_startPosition.x = 1250;
		m_startPosition.y = 0;
		m_BaseTimeLimit = 30.0f;
		break;

	case 4:
		levelToLoad = "levels/level4l.txt";
		m_startPosition.x = 50;
		m_startPosition.y = 200;
		m_BaseTimeLimit = 50.0f;
		break;

	}// end Switch

	ifstream inputFile(levelToLoad);
	string s;

	//Count the number of rows in the file
	while (getline(inputFile, s))
	{

		++m_LevelSize.y;

	}

	//store the length of the rows
	m_LevelSize.x = s.length();

	//go back to the start of the file
	inputFile.clear();
	inputFile.seekg(0, ios::beg);

	//prepare the 2d array to hold the int values from the file
	int** arrayLevel = new int*[m_LevelSize.y];
	for (int i = 0; i < m_LevelSize.y; ++i)
	{

		arrayLevel[i] = new int[m_LevelSize.x];

	}

	//loop through file and store all the valuies in the 2d array
	string row;
	int y = 0;
	while (inputFile >> row)
	{

		for (int x = 0; x < row.length(); x++)
		{

			const char val = row[x];
			arrayLevel[y][x] = atoi(&val);

		}

		y++;

	}

	inputFile.close();

}//end function nextLevel()