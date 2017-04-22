#include "stdafx.h"
#include "cPyramid.h"


cPyramid::cPyramid()
{
}


cPyramid::~cPyramid()
{
}

void cPyramid::Setup()
{
	ST_PC_VERTEX v(0,0,0);

	ZeroMemory(&m_stMtrl, sizeof(D3DMATERIAL9));

	//YÃà
	v.c = D3DCOLOR_XRGB(255, 0, 0);
	v.p = D3DXVECTOR3(-0.1f, 2.0f, -0.1f); m_vecYVertex.push_back(v);
	v.p = D3DXVECTOR3(-0.1f, 2.0f, 0.1f); m_vecYVertex.push_back(v);
	v.p = D3DXVECTOR3(0.1f, 2.0f, 0.1f); m_vecYVertex.push_back(v);

	v.p = D3DXVECTOR3(-0.1f, 2.0f, -0.1f); m_vecYVertex.push_back(v);
	v.p = D3DXVECTOR3(0.1f, 2.0f, 0.1f); m_vecYVertex.push_back(v);
	v.p = D3DXVECTOR3(0.1f, 2.0f, -0.1f); m_vecYVertex.push_back(v);

	v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f); m_vecYVertex.push_back(v);
	v.p = D3DXVECTOR3(-0.1f, 2.0f, -0.1f); m_vecYVertex.push_back(v);
	v.p = D3DXVECTOR3(0.1f, 2.0f, -0.1f); m_vecYVertex.push_back(v);

	v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f); m_vecYVertex.push_back(v);
	v.p = D3DXVECTOR3(0.1f, 2.0f, 0.1f); m_vecYVertex.push_back(v);
	v.p = D3DXVECTOR3(-0.1f, 2.0f, 0.1f); m_vecYVertex.push_back(v);

	v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f); m_vecYVertex.push_back(v);
	v.p = D3DXVECTOR3(-0.1f, 2.0f, 0.1f); m_vecYVertex.push_back(v);
	v.p = D3DXVECTOR3(-0.1f, 2.0f, -0.1f); m_vecYVertex.push_back(v);

	v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f); m_vecYVertex.push_back(v);
	v.p = D3DXVECTOR3(0.1f, 2.0f, -0.1f); m_vecYVertex.push_back(v);
	v.p = D3DXVECTOR3(0.1f, 2.0f, 0.1f); m_vecYVertex.push_back(v);

	//xÃà
	v.c = D3DCOLOR_XRGB(0, 0, 255);
	v.p = D3DXVECTOR3(2.0f, -0.1f, -0.1f); m_vecXVertex.push_back(v);
	v.p = D3DXVECTOR3(2.0f, 0.1f, -0.1f); m_vecXVertex.push_back(v);
	v.p = D3DXVECTOR3(2.0f, 0.1f, 0.1f); m_vecXVertex.push_back(v);

	v.p = D3DXVECTOR3(2.0f, -0.1f, -0.1f); m_vecXVertex.push_back(v);
	v.p = D3DXVECTOR3(2.0f, 0.1f, 0.1f); m_vecXVertex.push_back(v);
	v.p = D3DXVECTOR3(2.0f, -0.1f, 0.1f); m_vecXVertex.push_back(v);

	v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f); m_vecXVertex.push_back(v);
	v.p = D3DXVECTOR3(2.0f, 0.1f, -0.1f); m_vecXVertex.push_back(v);
	v.p = D3DXVECTOR3(2.0f, -0.1f, -0.1f); m_vecXVertex.push_back(v);

	v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f); m_vecXVertex.push_back(v);
	v.p = D3DXVECTOR3(2.0f, -0.1f, 0.1f); m_vecXVertex.push_back(v);
	v.p = D3DXVECTOR3(2.0f, 0.1f, 0.1f); m_vecXVertex.push_back(v);

	v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f); m_vecXVertex.push_back(v);
	v.p = D3DXVECTOR3(2.0f, 0.1f, 0.1f); m_vecXVertex.push_back(v);
	v.p = D3DXVECTOR3(2.0f, 0.1f, -0.1f); m_vecXVertex.push_back(v);

	v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f); m_vecXVertex.push_back(v);
	v.p = D3DXVECTOR3(2.0f, -0.1f, -0.1f); m_vecXVertex.push_back(v);
	v.p = D3DXVECTOR3(2.0f, -0.1f, 0.1f); m_vecXVertex.push_back(v);

	//zÃà
	v.c = D3DCOLOR_XRGB(0, 255, 0);
	v.p = D3DXVECTOR3(-0.1f, -0.1f, 2.0f); m_vecZVertex.push_back(v);
	v.p = D3DXVECTOR3(0.1f, 0.1f, 2.0f); m_vecZVertex.push_back(v);
	v.p = D3DXVECTOR3(-0.1f, 0.1f, 2.0f); m_vecZVertex.push_back(v);

	v.p = D3DXVECTOR3(-0.1f, -0.1f, 2.0f); m_vecZVertex.push_back(v);
	v.p = D3DXVECTOR3(0.1f, -0.1f, 2.0f); m_vecZVertex.push_back(v);
	v.p = D3DXVECTOR3(0.1f, 0.1f, 2.0f); m_vecZVertex.push_back(v);

	v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f); m_vecZVertex.push_back(v);
	v.p = D3DXVECTOR3(-0.1f, -0.1f, 2.0f); m_vecZVertex.push_back(v);
	v.p = D3DXVECTOR3(-0.1f, 0.1f, 2.0f); m_vecZVertex.push_back(v);

	v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f); m_vecZVertex.push_back(v);
	v.p = D3DXVECTOR3(0.1f, 0.1f, 2.0f); m_vecZVertex.push_back(v);
	v.p = D3DXVECTOR3(0.1f, -0.1f, 2.0f); m_vecZVertex.push_back(v);

	v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f); m_vecZVertex.push_back(v);
	v.p = D3DXVECTOR3(-0.1f, 0.1f, 2.0f); m_vecZVertex.push_back(v);
	v.p = D3DXVECTOR3(0.1f, 0.1f, 2.0f); m_vecZVertex.push_back(v);

	v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f); m_vecZVertex.push_back(v);
	v.p = D3DXVECTOR3(0.1f, -0.1f, 2.0f); m_vecZVertex.push_back(v);
	v.p = D3DXVECTOR3(-0.1f, -0.1f, 2.0f); m_vecZVertex.push_back(v);
}

void cPyramid::Render()
{

	D3DXMATRIXA16 mat;
	D3DXMatrixIdentity(&mat);



	g_pD3DDevice->SetTransform(D3DTS_WORLD, &mat);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);

	m_stMtrl.Ambient = D3DXCOLOR(D3DCOLOR_XRGB(255, 0, 0));
	m_stMtrl.Diffuse = D3DXCOLOR(D3DCOLOR_XRGB(255, 0, 0));
	m_stMtrl.Specular = D3DXCOLOR(D3DCOLOR_XRGB(255, 0, 0));

	g_pD3DDevice->SetMaterial(&m_stMtrl);

	g_pD3DDevice->DrawPrimitiveUP(
		D3DPT_TRIANGLELIST,
		m_vecYVertex.size() / 3,
		&m_vecYVertex[0],
		sizeof(ST_PC_VERTEX)
	);

	m_stMtrl.Ambient = D3DXCOLOR(D3DCOLOR_XRGB(0, 0, 255));
	m_stMtrl.Diffuse = D3DXCOLOR(D3DCOLOR_XRGB(0, 0, 255));
	m_stMtrl.Specular = D3DXCOLOR(D3DCOLOR_XRGB(0, 0, 255));

	g_pD3DDevice->SetMaterial(&m_stMtrl);

	g_pD3DDevice->DrawPrimitiveUP(
		D3DPT_TRIANGLELIST,
		m_vecXVertex.size() / 3,
		&m_vecXVertex[0],
		sizeof(ST_PC_VERTEX)
	);

	m_stMtrl.Ambient = D3DXCOLOR(D3DCOLOR_XRGB(0, 255, 0));
	m_stMtrl.Diffuse = D3DXCOLOR(D3DCOLOR_XRGB(0, 255, 0));
	m_stMtrl.Specular = D3DXCOLOR(D3DCOLOR_XRGB(0, 255, 0));

	g_pD3DDevice->SetMaterial(&m_stMtrl);

	g_pD3DDevice->DrawPrimitiveUP(
		D3DPT_TRIANGLELIST,
		m_vecZVertex.size() / 3,
		&m_vecZVertex[0],
		sizeof(ST_PC_VERTEX)
	);
}
