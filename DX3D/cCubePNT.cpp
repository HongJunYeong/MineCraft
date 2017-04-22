#include "stdafx.h"
#include "cCubePNT.h"


cCubePNT::cCubePNT()
{
}


cCubePNT::~cCubePNT()
{
}

void cCubePNT::Setup()
{
	m_pTexture = NULL;
	
	ST_PNT_VERTEX v;
	//¾Õ¸é(¾ó±¼µÚ)
	v.p = D3DXVECTOR3(-0.5f, -0.5f, -0.5f); v.n = D3DXVECTOR3(0.0f, 0.0f, -1.0f); v.t = D3DXVECTOR2(0.5f, 1.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-0.5f, 0.5f, -0.5f); v.n = D3DXVECTOR3(0.0f, 0.0f, -1.0f); v.t = D3DXVECTOR2(0.5f, 0.25f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0.5f, 0.5f, -0.5f); v.n = D3DXVECTOR3(0.0f, 0.0f, -1.0f); v.t = D3DXVECTOR2(0.75f, 0.25f);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-0.5f, -0.5f, -0.5f); v.n = D3DXVECTOR3(0.0f, 0.0f, -1.0f); v.t = D3DXVECTOR2(0.5f, 1.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0.5f, 0.5f, -0.5f); v.n = D3DXVECTOR3(0.0f, 0.0f, -1.0f); v.t = D3DXVECTOR2(0.75f, 0.25f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0.5f, -0.5f, -0.5f); v.n = D3DXVECTOR3(0.0f, 0.0f, -1.0f); v.t = D3DXVECTOR2(0.75f, 1.0f);
	m_vecVertex.push_back(v);

	//µÞ¸é(¾ó±¼¾Õ)
	v.p = D3DXVECTOR3(0.5f, -0.5f, 0.5f); v.n = D3DXVECTOR3(0.0f, 0.0f, 1.0f); v.t = D3DXVECTOR2(0.25f, 1.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0.5f, 0.5f, 0.5f); v.n = D3DXVECTOR3(0.0f, 0.0f, 1.0f); v.t = D3DXVECTOR2(0.25f, 0.25f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-0.5f, 0.5f, 0.5f); v.n = D3DXVECTOR3(0.0f, 0.0f, 1.0f); v.t = D3DXVECTOR2(0.5f, 0.25f);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(0.5f, -0.5f, 0.5f); v.n = D3DXVECTOR3(0.0f, 0.0f, 1.0f); v.t = D3DXVECTOR2(0.25f, 1.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-0.5f, 0.5f, 0.5f); v.n = D3DXVECTOR3(0.0f, 0.0f, 1.0f); v.t = D3DXVECTOR2(0.5f, 0.25f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-0.5f, -0.5f, 0.5f); v.n = D3DXVECTOR3(0.0f, 0.0f, 1.0f); v.t = D3DXVECTOR2(0.5f, 1.0f);
	m_vecVertex.push_back(v);

	//¿ÞÂÊ¸é
	v.p = D3DXVECTOR3(-0.5f, -0.5f, 0.5f); v.n = D3DXVECTOR3(-1.0f, 0.0f, 0.0f); v.t = D3DXVECTOR2(0, 1.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-0.5f, 0.5f, 0.5f); v.n = D3DXVECTOR3(-1.0f, 0.0f, 0.0f); v.t = D3DXVECTOR2(0, 0.25f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-0.5f, 0.5f, -0.5f); v.n = D3DXVECTOR3(-1.0f, 0.0f, 0.0f); v.t = D3DXVECTOR2(0.25f, 0.25f);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-0.5f, -0.5f, 0.5f); v.n = D3DXVECTOR3(-1.0f, 0.0f, 0.0f); v.t = D3DXVECTOR2(0, 1.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-0.5f, 0.5f, -0.5f); v.n = D3DXVECTOR3(-1.0f, 0.0f, 0.0f); v.t = D3DXVECTOR2(0.25f, 0.25f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-0.5f, -0.5f, -0.5f); v.n = D3DXVECTOR3(-1.0f, 0.0f, 0.0f); v.t = D3DXVECTOR2(0.25f, 1.0f);
	m_vecVertex.push_back(v);

	//¿À¸¥ÂÊ¸é
	v.p = D3DXVECTOR3(0.5f, -0.5f, -0.5f); v.n = D3DXVECTOR3(1.0f, 0.0f, 0.0f); v.t = D3DXVECTOR2(0.75f, 1.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0.5f, 0.5f, -0.5f); v.n = D3DXVECTOR3(1.0f, 0.0f, 0.0f); v.t = D3DXVECTOR2(0.75f, 0.25f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0.5f, 0.5f, 0.5f); v.n = D3DXVECTOR3(1.0f, 0.0f, 0.0f); v.t = D3DXVECTOR2(1.0f, 0.25f);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(0.5f, -0.5f, -0.5f); v.n = D3DXVECTOR3(1.0f, 0.0f, 0.0f); v.t = D3DXVECTOR2(0.75f, 1.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0.5f, 0.5f, 0.5f); v.n = D3DXVECTOR3(1.0f, 0.0f, 0.0f); v.t = D3DXVECTOR2(1.0f, 0.25f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0.5f, -0.5f, 0.5f); v.n = D3DXVECTOR3(1.0f, 0.0f, 0.0f); v.t = D3DXVECTOR2(1.0f, 1.0f);
	m_vecVertex.push_back(v);

	//À­¸é
	v.p = D3DXVECTOR3(-0.5f, 0.5f, -0.5f); v.n = D3DXVECTOR3(0.0f, 1.0f, 0.0f); v.t = D3DXVECTOR2(0.25f, 0.25f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-0.5f, 0.5f, 0.5f); v.n = D3DXVECTOR3(0.0f, 1.0f, 0.0f); v.t = D3DXVECTOR2(0.25f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0.5f, 0.5f, 0.5f); v.n = D3DXVECTOR3(0.0f, 1.0f, 0.0f); v.t = D3DXVECTOR2(0.5f, 0.0f);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-0.5f, 0.5f, -0.5f); v.n = D3DXVECTOR3(0.0f, 1.0f, 0.0f); v.t = D3DXVECTOR2(0.25f, 0.25f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0.5f, 0.5f, 0.5f); v.n = D3DXVECTOR3(0.0f, 1.0f, 0.0f); v.t = D3DXVECTOR2(0.5f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0.5f, 0.5f, -0.5f); v.n = D3DXVECTOR3(0.0f, 1.0f, 0.0f); v.t = D3DXVECTOR2(0.5f, 0.25f);
	m_vecVertex.push_back(v);

	//¹Ø¸é
	v.p = D3DXVECTOR3(-0.5f, -0.5f, -0.5f); v.n = D3DXVECTOR3(0.0f, -1.0f, 0.0f); v.t = D3DXVECTOR2(0.5f, 0.25f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0.5f, -0.5f, 0.5f); v.n = D3DXVECTOR3(0.0f, -1.0f, 0.0f); v.t = D3DXVECTOR2(0.5f, 0.0f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-0.5f, -0.5f, 0.5f); v.n = D3DXVECTOR3(0.0f, -1.0f, 0.0f); v.t = D3DXVECTOR2(0.75f, 0);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-0.5f, -0.5f, -0.5f); v.n = D3DXVECTOR3(0.0f, -1.0f, 0.0f); v.t = D3DXVECTOR2(0.5f, 0.25f);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0.5f, -0.5f, -0.5f); v.n = D3DXVECTOR3(0.0f, -1.0f, 0.0f); v.t = D3DXVECTOR2(0.75f, 0);
	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0.5f, -0.5f, 0.5f); v.n = D3DXVECTOR3(0.0f, -1.0f, 0.0f); v.t = D3DXVECTOR2(0.75f, 0.25f);
	m_vecVertex.push_back(v);

	//vector<ST_PNT_VERTEX> vecVertex;

	//vecVertex.resize(8);

	//vecVertex[0].p.x = -0.5f;
	//vecVertex[0].p.y = -0.5f;
	//vecVertex[0].p.z = -0.5f;
	//
	//vecVertex[1].p.x = -0.5f;
	//vecVertex[1].p.y =  0.5f;
	//vecVertex[1].p.z = -0.5f;

	//vecVertex[2].p.x =  0.5f;
	//vecVertex[2].p.y =  0.5f;
	//vecVertex[2].p.z = -0.5f;

	//vecVertex[3].p.x =  0.5f;
	//vecVertex[3].p.y = -0.5f;
	//vecVertex[3].p.z = -0.5f;

	//vecVertex[4].p.x = -0.5f;
	//vecVertex[4].p.y = -0.5f;
	//vecVertex[4].p.z =  0.5f;

	//vecVertex[5].p.x = -0.5f;
	//vecVertex[5].p.y =  0.5f;
	//vecVertex[5].p.z =  0.5f;

	//vecVertex[6].p.x =  0.5f;
	//vecVertex[6].p.y =  0.5f;
	//vecVertex[6].p.z =  0.5f;

	//vecVertex[7].p.x =  0.5f;
	//vecVertex[7].p.y = -0.5f;
	//vecVertex[7].p.z =  0.5f;

	////
	//vector<DWORD> vecIndex;

	//vecIndex.push_back(0);
	//vecIndex.push_back(1);
	//vecIndex.push_back(2);

	//vecIndex.push_back(0);
	//vecIndex.push_back(2);
	//vecIndex.push_back(3);

	//vecIndex.push_back(7);
	//vecIndex.push_back(6);
	//vecIndex.push_back(5);

	//vecIndex.push_back(7);
	//vecIndex.push_back(5);
	//vecIndex.push_back(4);

	//vecIndex.push_back(4);
	//vecIndex.push_back(5);
	//vecIndex.push_back(1);

	//vecIndex.push_back(4);
	//vecIndex.push_back(1);
	//vecIndex.push_back(0);

	//vecIndex.push_back(3);
	//vecIndex.push_back(2);
	//vecIndex.push_back(6);

	//vecIndex.push_back(3);
	//vecIndex.push_back(6);
	//vecIndex.push_back(7);

	//vecIndex.push_back(1);
	//vecIndex.push_back(5);
	//vecIndex.push_back(6);

	//vecIndex.push_back(1);
	//vecIndex.push_back(6);
	//vecIndex.push_back(2);

	//vecIndex.push_back(0);
	//vecIndex.push_back(7);
	//vecIndex.push_back(4);

	//vecIndex.push_back(0);
	//vecIndex.push_back(3);
	//vecIndex.push_back(7);

	//m_vecVertex.resize(36);

	//for (size_t i = 0; i < vecIndex.size(); i += 3)
	//{
	//	m_vecVertex[i+0] = vecVertex[vecIndex[i+0]];
	//	m_vecVertex[i+1] = vecVertex[vecIndex[i+1]];
	//	m_vecVertex[i+2] = vecVertex[vecIndex[i+2]];
	//}

	//D3DXVECTOR3 u, v, n;
	//for (int i = 0; i < 36; i += 3)
	//{
	//	u = m_vecVertex[i + 1].p - m_vecVertex[i].p;
	//	v = m_vecVertex[i + 2].p - m_vecVertex[i].p;

	//	D3DXVec3Cross(&n, &u, &v);
	//	D3DXVec3Normalize(&n, &n);

	//	m_vecVertex[i + 0].n = n;
	//	m_vecVertex[i + 1].n = n;
	//	m_vecVertex[i + 2].n = n;
	//}

	//m_vecVertex[0].t.x = 0.5f; m_vecVertex[0].t.y = 1.0f;
	//m_vecVertex[1].t.x = 0.5f; m_vecVertex[1].t.y = 0.5f;
	//m_vecVertex[2].t.x = 0.75f; m_vecVertex[2].t.y = 0.5f;
	//m_vecVertex[3].t.x = 0.75f; m_vecVertex[3].t.y = 0.5f;
}

void cCubePNT::Update()
{
}


void cCubePNT::Render()
{
	if (m_vecVertex.size() > 0)
	{
		g_pD3DDevice->SetFVF(ST_PNT_VERTEX::FVF);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
			m_vecVertex.size() / 3,
			&m_vecVertex[0],
			sizeof(ST_PNT_VERTEX));
	}
}

void cCubePNT::ShadowRender()
{
}

void cCubePNT::Animation()
{
}
