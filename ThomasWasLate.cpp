// ThomasWasLate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "Engine.h"

int main()
{
	
	//declare an instance of engine
	Engine engine;

	//Start the engine
	engine.run();

	//Quit once eninge has stopped
	return 0;

}

