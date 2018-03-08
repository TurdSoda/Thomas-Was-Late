#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class PlayableCharacter
{

protected:

	Sprite m_Sprite;

	//How long does a jump last
	float m_JumpDuration;

	//is the character currently jumping or falling
	bool m_IsJumping;
	bool m_IsFalling;

	//which direction is the charatcer currently moving in 
	bool m_LeftPressed;
	bool m_RightPressed;

	//How long has the jump lasted
	float m_TimeThisJump;

	bool m_JustJumped = false;

	//These variables can only be changed in this class
private:

	//What is the gravity
	float m_Gravity;

	//How fast is the character
	float m_Speed = 400;

	//Where is the player
	Vector2f m_Position;

	//Where are the character various body parts
	FloatRect m_Feet;
	FloatRect m_Head;
	FloatRect m_Left;
	FloatRect m_Right;

	Texture m_texture;

	//public functions avaiable to ALL classes
public:

	void spawn(Vector2f startPosition, float gravity);

	//this is a pure virtual function
	//This means this class becomes an abstract class
	//meaning we cannot create an instance of this class, only sub classes
	// sub classes MUST implement this function in order to create instances
	bool virtual handleInput() = 0;

	//where is the player
	FloatRect getPosition();

	//A rectangle representing the position of different body parts
	FloatRect GetFeet();
	FloatRect GetHead();
	FloatRect GetRight();
	FloatRect GetLeft();

	//Get a copy to the sprite
	Sprite getSprite();

	//make character stop moving
	void stopFalling(float position);
	void stopRight(float position);
	void stopLeft(float position);
	void stopJump();

	//Where is the center of the character
	Vector2f getCenter();

	//We will call this function once every frame
	void update(float elaspsedTime);

};//end of playable character class
