#include "stdafx.h"
#include "cCharacter.h"


cCharacter::cCharacter()
	:m_fRotY(0.0f)
	,m_vDirection(0,0,0.1f)
	,m_vPosition(0,0,0)
	,m_isWalk(false)
	,m_isJump(false)
	, m_isLand(true)
{
	D3DXMatrixIdentity(&m_matWorld);
}


cCharacter::~cCharacter()
{
}

void cCharacter::Setup()
{
}

void cCharacter::Update()
{
	m_isWalk = false;
	m_isIdle = true;

	if (GetKeyState('W') & 0x8000)
	{
		m_vPosition = m_vPosition + (m_vDirection * 0.1f);
		m_isWalk = true;
		m_isIdle = false;
	}
	if (GetKeyState('S') & 0x8000)
	{
		m_vPosition = m_vPosition - (m_vDirection * 0.1f);
		m_isWalk = true;
		m_isIdle = false;
	}
	if (GetKeyState('A') & 0x8000)
	{
		m_isWalk = true;
		m_isIdle = false;
		m_fRotY -= 0.05f;
	}
	if (GetKeyState('D') & 0x8000)
	{
		m_isWalk = true;
		m_isIdle = false;
		m_fRotY += 0.05f;
	}

	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		if (!m_isJump && m_isLand)
		{
			m_isIdle = false;
			m_isJump = true;
			m_isLand = false;
		}
	}

	if (m_isJump && !m_isLand)
	{
		m_vPosition.y += 0.1f;

		if (m_vPosition.y >= 2.0f)
			m_isLand = true;
	}

	if (m_isJump && m_isLand)
	{
		m_vPosition.y -= 0.1f;

		if (m_vPosition.y <= 0.0f)
			m_isJump = false;
	}

	D3DXMATRIXA16 matRY, matTr;

	D3DXMatrixRotationY(&matRY, m_fRotY);
	D3DXMatrixTranslation(&matTr, m_vPosition.x, m_vPosition.y, m_vPosition.z);

	m_vDirection = D3DXVECTOR3(0, 0, 1.0f);
	D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matRY);

	m_matWorld = matRY * matTr;
}

void cCharacter::Render()
{
}

D3DXVECTOR3 & cCharacter::GetPosition()
{
	// to do
	return m_vPosition;
}
