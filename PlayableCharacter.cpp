#include "stdafx.h"
#include "PlayableCharacter.h"

void PlayableCharacter::spawn(Vector2f startPosition, float gravity)
{

	//place player at starting point
	m_Position.x = startPosition.x;
	m_Position.y = startPosition.y;

	//intialize the gravity
	m_Gravity = gravity;

	//Move the sprite to the position
	m_Sprite.setPosition(m_Position);

}//end spawn

void PlayableCharacter::update(float elapsedTime)
{

	//check if we should be moving left or right
	if (m_RightPressed)
	{

		m_Position.x += m_Speed*elapsedTime;

	}
	if (m_LeftPressed)
	{

		m_Position.x -= m_Speed*elapsedTime;

	}

	//handle jumping
	if (m_IsJumping)
	{

		//update how long the jump has been going
		m_TimeThisJump += elapsedTime;

		//if we are still jumping upwards
		if (m_TimeThisJump < m_JumpDuration)
		{

			//move up at twice the speed of gravity
			m_Position.y -= m_Gravity * 2 * elapsedTime;

		}
		//if jump duration has ended
		else
		{

			m_IsJumping = false;
			m_IsFalling = true;

		}
	}// end if(m_IsJumping)

		//apply gravity
		if (m_IsFalling)
		{

			m_Position.y += m_Gravity*elapsedTime;

		}

	//update rect position for all body parts
		FloatRect r = getPosition();

		//feet
		m_Feet.left = r.left + 3;
		m_Feet.top = r.top + r.height - 1;
		m_Feet.width = r.width - 6;
		m_Feet.height = 1;

		//head
		m_Head.left = r.left;
		m_Head.top = r.top + (r.height*0.3f);
		m_Head.width = r.width;
		m_Head.height = 1;

		//Right
		m_Right.left = r.left+r.width - 2;
		m_Right.top = r.top + r.height*0.35f;
		m_Right.width = 1;
		m_Right.height = r.height*0.3f;

		//left
		m_Left.left = r.left;
		m_Left.top = r.top + r.height*0.35f;
		m_Left.width = 1;
		m_Left.height = r.height*0.3f;

		//Move the sprite into position
		m_Sprite.setPosition(m_Position);

}//end update()

FloatRect PlayableCharacter::getPosition()
{

	return m_Sprite.getGlobalBounds();

}

Vector2f PlayableCharacter::getCenter()
{

	return Vector2f(m_Position.x + m_Sprite.getGlobalBounds().width / 2,
		m_Position.y + m_Sprite.getGlobalBounds().height / 2, );

}

FloatRect PlayableCharacter::getFeet()
{

	return m_Feet;

}

FloatRect PlayableCharacter::getHead()
{

	return m_Head;

}

FloatRect PlayableCharacter::getLeft()
{

	return m_Left;

}

FloatRect PlayableCharacter::getRight()
{

	return m_Right;

}

Sprite PlayableCharacter::getSprite()
{
	return m_Sprite;

}

void PlayableCharacter::stopFalling(float position)
{

	m_Position.y = position - getPosition().height;
	m_Sprite.setPosition(m_Position);
	m_IsFalling = false;

}

void PlayableCharacter::stopRight(float position)
{

	m_Position.y = position - getGlobalBounds().width;
	m_Sprite.setPosition(m_Position);


}


void PlayableCharacter::stopLeft(float position)
{

	m_Position.y = position - getGlobalBounds().width;
	m_Sprite.setPosition(m_Position);

}

void PlayableCharacter::stopJump()
{

	m_IsJumping = false;
	m_IsFalling = true;

}
