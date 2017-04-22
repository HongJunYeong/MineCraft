#include "stdafx.h"
#include "cGrid.h"


cGrid::cGrid()
{
}


cGrid::~cGrid()
{
}

void cGrid::Setup()
{
	int nNumHalfTile = 100;
	float fInterval = 1.0f;
	float fMax = nNumHalfTile * fInterval;
	float fMin = -nNumHalfTile * fInterval;

	//머터리얼 설정
	ZeroMemory(&m_stMtl, sizeof(D3DMATERIAL9));
	m_stMtl.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	m_stMtl.Ambient = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	m_stMtl.Specular = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	for (int i = 1; i <= nNumHalfTile; i++)
	{
		m_vecVertex.push_back(ST_PC_VERTEX(fMin, 0, i*fInterval));
		m_vecVertex.push_back(ST_PC_VERTEX(fMax, 0, i*fInterval));

		m_vecVertex.push_back(ST_PC_VERTEX(fMin, 0, -i*fInterval));
		m_vecVertex.push_back(ST_PC_VERTEX(fMax, 0, -i*fInterval));

		m_vecVertex.push_back(ST_PC_VERTEX(i*fInterval, 0, fMin));
		m_vecVertex.push_back(ST_PC_VERTEX(i*fInterval, 0, fMax));

		m_vecVertex.push_back(ST_PC_VERTEX(-i*fInterval, 0, fMin));
		m_vecVertex.push_back(ST_PC_VERTEX(-i*fInterval, 0, fMax));
	}

	m_vecVertex.push_back(ST_PC_VERTEX(0, 0, fMin));
	m_vecVertex.push_back(ST_PC_VERTEX(0, 0, fMax));

	m_vecVertex.push_back(ST_PC_VERTEX(fMin, 0, 0));
	m_vecVertex.push_back(ST_PC_VERTEX(fMax, 0, 0));

	ST_PC_VERTEX v(0,0,0);
	//y축
	v.c = D3DCOLOR_XRGB(255, 0, 0);
	v.p = D3DXVECTOR3(0, 100, 0); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0, -100, 0); m_vecVertex.push_back(v);

	//x축
	v.c = D3DCOLOR_XRGB(0, 0, 255);
	v.p = D3DXVECTOR3(-150, 0, 0); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(150, 0, 0); m_vecVertex.push_back(v);

	//z축
	v.c = D3DCOLOR_XRGB(0, 255, 0);
	v.p = D3DXVECTOR3(0, 0, -150); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0, 0, 150); m_vecVertex.push_back(v);
}

void cGrid::Render()
{
	D3DXMATRIXA16 mat;
	D3DXMatrixIdentity(&mat);

	g_pD3DDevice->SetMaterial(&m_stMtl);

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &mat);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);

	g_pD3DDevice->DrawPrimitiveUP(
		D3DPT_LINELIST,
		m_vecVertex.size() / 2,
		&m_vecVertex[0],
		sizeof(ST_PC_VERTEX)
	);
}
