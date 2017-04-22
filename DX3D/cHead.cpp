#include "stdafx.h"
#include "cHead.h"


cHead::cHead()
{
}


cHead::~cHead()
{
}

void cHead::Setup()
{
	cCubeNode::Setup();

	D3DXMATRIXA16 matS, matT, mat;
	D3DXMatrixScaling(&matS, 0.4f, 0.4f, 0.4f);
	D3DXMatrixTranslation(&matT, 0, 0, 0);

	mat = matS*matT;


	for (size_t i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &mat);
	}

	m_vLocalPos.y = 1.4f;

	m_ePart = HEAD;
	m_fRotSpeed = 0.004f;

	//텍스처 로딩
	D3DXCreateTextureFromFile(
		g_pD3DDevice,
		"Image/얼굴2.png",
		&m_pTexture
	);
}
