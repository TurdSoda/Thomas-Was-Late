#include "stdafx.h"
#include "Thomas.h"
#include "TextureHolder.h"

//=========================================================================
Thomas::Thomas()
{

	//Associate a texture with the sprite
	m_Sprite = Sprite(TextureHolder::GetTexture("graphics/thomas.png"));

	m_JumpDuration = 0.45f;

}//End Thomas()

//=========================================================================

bool Thomas::handleInput()
{

	m_JustJumped = false;

	if (Keyboard::isKeyPressed(Keyboard::W))
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

	}//end if keyboard pressed W
	else
	{
		//Stop jump early if W not held down
		m_IsJumping = false;
		m_IsFalling = true;

	}//end if W released
//----------------------------------------------
	//Check left
	if (Keyboard::isKeyPressed(Keyboard::A))
	{

		m_LeftPressed = true;

	}
	else
	{

		m_LeftPressed = false;

	}
//----------------------------------------------
	//Check right
	if (Keyboard::isKeyPressed(Keyboard::D))
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