#include "stdafx.h"
#include "cRightLeg.h"


cRightLeg::cRightLeg()
{
}


cRightLeg::~cRightLeg()
{
}

void cRightLeg::Setup()
{
	cCubeNode::Setup();

	D3DXMATRIXA16 matS, matT, mat;
	D3DXMatrixScaling(&matS, 0.2f, 0.6f, 0.2f);
	D3DXMatrixTranslation(&matT, 0.1f, -0.3f, 0);

	mat = matS*matT;

	for (size_t i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &mat);
	}

	m_vLocalPos.y = 0.6f;

	m_ePart = RIGHT_LEG;
	m_fRotSpeed = 0.1f;

	//텍스처 로딩
	D3DXCreateTextureFromFile(
		g_pD3DDevice,
		"Image/다리2.png",
		&m_pTexture
	);
}

