#pragma once
#include "PlayableCharacter.h"

class Bob : public PlayableCharacter
{

public:
	//Constructor
	Bob();

	//this will implement the pure virtual function from PlayableCharacter
	bool virtual handleInput();

};//end of Thomas Class#pragma once
