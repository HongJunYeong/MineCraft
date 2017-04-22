#pragma once
#include "cCubePNT.h"

enum PART { BODY = 0, HEAD, LEFT_ARM, RIGHT_ARM, LEFT_LEG,RIGHT_LEG };

class cCubeNode : public cCubePNT
{
public:
	cCubeNode();

protected:
	D3DXVECTOR3		m_vLocalPos;
	D3DXMATRIXA16	m_matLocalTM;
	D3DXMATRIXA16	m_matWorldTM;

	vector<cCubeNode*>	m_vecChild;

	PART			m_ePart;
	float           m_fRotSpeed;

	SYNTHESIZE(D3DXMATRIXA16*, m_pParentWorldTM, ParentWorldTM);
	SYNTHESIZE(float, m_fRotDeltaX, RotDeltaX);
	SYNTHESIZE(float, m_fRotDeltaY, RotDeltaY);
	SYNTHESIZE(float, m_fRotDeltaZ, RotDeltaZ);
public:
	virtual ~cCubeNode();

	bool m_isWalk;
	bool m_isIdle;
	bool m_isJump;

	virtual void AddChild(cCubeNode* pChild);
	virtual void Destroy();

	virtual void Setup() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void ShadowRender() override;
	virtual void Animation() override;
};

