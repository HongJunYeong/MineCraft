#pragma once
class cCharacter
{
public:
	cCharacter();

protected:
	float			m_fRotY;
	D3DXVECTOR3		m_vDirection;
	D3DXVECTOR3		m_vPosition;
	D3DXMATRIXA16	m_matWorld;

	bool			m_isIdle;
	bool			m_isWalk;
	bool			m_isJump;
	bool			m_isLand;
public:
	virtual ~cCharacter();

	virtual void Setup();
	virtual void Update();
	virtual void Render();

	virtual D3DXVECTOR3 & GetPosition();
};

