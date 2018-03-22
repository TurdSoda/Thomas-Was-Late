#include "stdafx.h"
#include "Engine.h"

bool Engine::detectCollisions(PlayableCharacter& character)
{

	bool reachedGoal = false;

	//Make a rectangle for the character's collision
	FloatRect detectionZone = character.getPosition();

	//Make a floatRect to test each block
	FloatRect block;
	block.width = TILE_SIZE;
	block.height = TILE_SIZE;

	//build a zone around the character to detect collision
	int startX = (int)(detectionZone.left / TILE_SIZE) - 1;
	int startY = (int)(detectionZone.top / TILE_SIZE) - 1;
	int endX = (int)(detectionZone.left / TILE_SIZE) + 2;
	int endY = (int)(detectionZone.top / TILE_SIZE) + 3; //Thomas is quite tall

	//Make sure we don't testy positions lower than zero
	if (startX < 0) startX = 0;
	if (startY < 0) startY = 0;

	//make sure we don't test positions greater than our level size
	if (endX > m_LM.getLevelSize().x)
		endX = m_LM.getLevelSize().x;
	if (endY > m_LM.getLevelSize().y)
		endY = m_LM.getLevelSize().y;

	//handle player falling
	FloatRect level(0, 0, m_LM.getLevelSize().x*TILE_SIZE, m_LM.getLevelSize().y*TILE_SIZE);

	if (!detectionZone.intersects(level))
	{

		//respawn
		character.spawn(m_LM.getStartPosition(), GRAVITY);

	}
	
	//loop through all nearby blocks
	for (int x = startX; x < endX; ++x)
	{

		for (int y = startY; x < endY; ++y)
		{

			//set up our current block
			block.left = x*TILE_SIZE;
			block.top = y*TILE_SIZE;

			//have we hit lava or water?
			//use head collision, to allow the character to sink
			if (m_ArrayLevel[y][x] == 2 || m_ArrayLevel[y][x] == 3)
			{

				if (character.getHead().intersects(block))
				{

					//they are in the water/lava
					character.spawn(m_LM.getStartPosition(), GRAVITY);

					//play a sound
					if (m_ArrayLevel[y][x] == 2)//FIRE
					{

						//TODO;play sound

					}
					else//Water
					{

						//TODO;playsound

					}

				}//end block collison fire/water

			}//end water/lava test

			//Is character colliding with a regualer block?
			if (m_ArrayLevel[y][x] == 1)
			{

				if (character.getRight().intersects(block))
				{

					character.stopRight(block.left);

				}
				else if (character.getLeft().intersects(block))
				{

					character.stopLeft(block.left);

				}

				if (character.getFeet().intersects(block))
				{

					character.stopFalling(block.top);

				}
				else if (character.getHead().intersects(block))
				{

					character.stopJump();

				}

			}//end normal block collision

			//more collisions, once particle effects are added

			//have we reached goal?
			if (m_ArrayLevel[y][x] == 4)
			{
				//character has reached the goal
				reachedGoal = true;

			}

		}//end y loop

	}// end x loop

	//return whether or not the characters have completed this level
	return reachedGoal;

}//end of detectCollisions() 