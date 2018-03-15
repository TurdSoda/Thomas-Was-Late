#include "stdafx.h"
#include "Bob.h"
#include "TextureHolder.h"

//=========================================================================
Bob::Bob()
{

	//Associate a texture with the sprite
	m_Sprite = Sprite(TextureHolder::GetTexture("graphics/bob.png"));

	m_JumpDuration = 0.25f;

}//End Thomas()

 //=========================================================================

bool Bob::handleInput()
{

	m_JustJumped = false;

	if (Keyboard::isKeyPressed(Keyboard::Up))
	{

		//start a jump, if not already jumping
		//but only is standing on a black, not falling
		if (!m_IsJumping&&!m_IsFalling)
		{

			//perform jump
			m_IsJumping = true;
			m_TimeThisJump = 0;
			m_JustJumped = true;

		}

	}//end if keyboard pressed Up
	else
	{
		//Stop jump early if W not held down
		m_IsJumping = false;
		m_IsFalling = true;

	}//end if W released
	 //----------------------------------------------
	 //Check left
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{

		m_LeftPressed = true;

	}
	else
	{

		m_LeftPressed = false;

	}
	//----------------------------------------------
	//Check right
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{

		m_RightPressed = true;

	}
	else
	{

		m_RightPressed = false;

	}
	//----------------------------------------------
	return m_JustJumped;

}//end handleinput()