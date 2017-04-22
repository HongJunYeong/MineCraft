#include "stdafx.h"
#include "cCubeNode.h"


cCubeNode::cCubeNode()
	:m_vLocalPos(0, 0, 0)
	, m_fRotDeltaX(0.0f)
	, m_fRotDeltaY(0.0f)
	, m_fRotDeltaZ(0.0f)
	, m_pParentWorldTM(NULL)
	, m_fRotSpeed(0.0f)
	, m_isWalk(false)
	, m_isIdle(false)
{
	D3DXMatrixIdentity(&m_matLocalTM);
	D3DXMatrixIdentity(&m_matWorldTM);
}


cCubeNode::~cCubeNode()
{
}

void cCubeNode::AddChild(cCubeNode * pChild)
{
	pChild->m_pParentWorldTM = &m_matWorldTM;
	m_vecChild.push_back(pChild);
}

void cCubeNode::Destroy()
{
	for each(auto p in m_vecChild)
	{
		p->Destroy();
	}
	SAFE_RELEASE(m_pTexture);
	delete this;
}

void cCubeNode::Setup()
{
	cCubePNT::Setup();
}

void cCubeNode::Update()
{
	cCubePNT::Update();

	Animation();

	D3DXMATRIXA16 matRX, matRY , matRZ, matT;
	D3DXMatrixIdentity(&matRX);
	D3DXMatrixIdentity(&matRY);
	D3DXMatrixIdentity(&matRZ);
	D3DXMatrixIdentity(&matT);

	D3DXMatrixRotationX(&matRX, GetRotDeltaX());
	D3DXMatrixRotationY(&matRY, GetRotDeltaY());
	D3DXMatrixTranslation(&matT, m_vLocalPos.x, m_vLocalPos.y, m_vLocalPos.z);

	m_matLocalTM = matRX *matRY * matRZ * matT;

	m_matWorldTM = m_matLocalTM;

	if (m_pParentWorldTM)
		m_matWorldTM *= (*m_pParentWorldTM);

	for each(auto p in m_vecChild)
	{
		p->m_isIdle = m_isIdle;
		p->m_isWalk = m_isWalk;
		p->m_isJump = m_isJump;
		p->Update();
	}
}

void cCubeNode::Render()
{
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorldTM);

	g_pD3DDevice->SetTexture(0, m_pTexture);
	cCubePNT::Render();
	g_pD3DDevice->SetTexture(0, 0);

	ShadowRender();

	for each(auto p in m_vecChild)
	{
		p->Render();

	}

}

void cCubeNode::ShadowRender()
{
	//스텐실 설정
	g_pD3DDevice->SetRenderState(D3DRS_STENCILENABLE, true);
	g_pD3DDevice->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_EQUAL);
	g_pD3DDevice->SetRenderState(D3DRS_STENCILREF, 0x0);
	g_pD3DDevice->SetRenderState(D3DRS_STENCILMASK, 0xffffffff);
	g_pD3DDevice->SetRenderState(D3DRS_STENCILWRITEMASK, 0xffffffff);
	g_pD3DDevice->SetRenderState(D3DRS_STENCILZFAIL, D3DSTENCILOP_KEEP);
	g_pD3DDevice->SetRenderState(D3DRS_STENCILFAIL, D3DSTENCILOP_KEEP);
	g_pD3DDevice->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_INCR);

	//그림자 위치
	D3DXVECTOR4 lightDirection(1.0f, -1.0f, 1.0f,0.0f);
	D3DXPLANE groundPlane(0.0f, -1.0f, 0.0f, 0.0f);

	D3DXMATRIXA16 S;
	D3DXMatrixShadow(
		&S,
		&lightDirection,
		&groundPlane);

	D3DXMATRIXA16 W = m_matWorldTM * S;
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &W);

	// 그림자 알파 블렌딩 처리
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	D3DMATERIAL9 mtrl;
	//그림자 검은색으로 재질 설정
	mtrl.Ambient = D3DXCOLOR(D3DCOLOR_XRGB(0, 0, 0));
	mtrl.Diffuse = D3DXCOLOR(D3DCOLOR_XRGB(0, 0, 0));
	mtrl.Specular = D3DXCOLOR(D3DCOLOR_XRGB(0, 0, 0));
	mtrl.Emissive = D3DXCOLOR(D3DCOLOR_XRGB(0, 0, 0));
	mtrl.Diffuse.a = 0.5f; // 80% 알파블렌드

	g_pD3DDevice->SetMaterial(&mtrl);	//재질 설정

	//그림자 그리기
	cCubePNT::Render();

	//알파 블렌딩, 스텐실 끄기
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	g_pD3DDevice->SetRenderState(D3DRS_STENCILENABLE, false);

	//재질을 다시 설정(하얀색으로)
	mtrl.Ambient = D3DXCOLOR(D3DCOLOR_XRGB(255, 255, 255));
	mtrl.Diffuse = D3DXCOLOR(D3DCOLOR_XRGB(255, 255, 255));
	mtrl.Specular = D3DXCOLOR(D3DCOLOR_XRGB(255, 255, 255));
	mtrl.Emissive = D3DXCOLOR(D3DCOLOR_XRGB(255, 255, 255));

	//재질 설정
	g_pD3DDevice->SetMaterial(&mtrl);
}


void cCubeNode::Animation()
{
	//걷기
	if (m_isWalk)
	{
		float sin = 0.0f;
		switch (m_ePart)
		{
		case LEFT_ARM:
			if (GetRotDeltaX() > D3DX_PI / 4.0f) m_fRotSpeed *= -1.0f;
			else if(GetRotDeltaX() < -(D3DX_PI / 4.0f)) m_fRotSpeed *= -1.0f;
			SetRotDeltaX(GetRotDeltaX() + m_fRotSpeed);
			break;
		case RIGHT_ARM:
			if (GetRotDeltaX() > D3DX_PI / 4.0f) m_fRotSpeed *= -1.0f;
			else if(GetRotDeltaX() < -(D3DX_PI / 4.0f)) m_fRotSpeed *= -1.0f;
			SetRotDeltaX(GetRotDeltaX() - m_fRotSpeed);
			break;
		case LEFT_LEG:
			if (GetRotDeltaX() > D3DX_PI / 4.0f) m_fRotSpeed *= -1.0f;
			else if (GetRotDeltaX() < -(D3DX_PI / 4.0f)) m_fRotSpeed *= -1.0f;
			SetRotDeltaX(GetRotDeltaX() - m_fRotSpeed);
			break;
		case RIGHT_LEG:
			if (GetRotDeltaX() > D3DX_PI / 4.0f) m_fRotSpeed *= -1.0f;
			else if (GetRotDeltaX() < -(D3DX_PI / 4.0f)) m_fRotSpeed *= -1.0f;
			SetRotDeltaX(GetRotDeltaX() + m_fRotSpeed);
			break;
		}
	}
	else
	{
		if (!m_isIdle && !m_isJump)
		{
			SetRotDeltaX(0.0f);
			m_isIdle = true;
		}
	}

	//가만히 있기
	if (m_isIdle)
	{
		switch (m_ePart)
		{
		case HEAD:
			if (GetRotDeltaY() >= D3DX_PI / 4.0f) m_fRotSpeed *= -1.0f;
			else if (GetRotDeltaY() <= -(D3DX_PI / 4.0f)) m_fRotSpeed *= -1.0f;
			SetRotDeltaY(GetRotDeltaY() + m_fRotSpeed);
			break;
		}
	}
	else
	{
		SetRotDeltaY(0.0f);
	}

	//점프
	if (m_isJump)
	{
		if (m_isIdle)
			m_isIdle = false;

		if (!m_isWalk)
		{
			switch (m_ePart)
			{
			case LEFT_ARM:
				SetRotDeltaX(D3DX_PI / 4.0f);
				break;
			case RIGHT_ARM:
				SetRotDeltaX(-(D3DX_PI / 4.0f));
				break;
			case LEFT_LEG:
				SetRotDeltaX(-(D3DX_PI / 4.0f));
				break;
			case RIGHT_LEG:
				SetRotDeltaX(D3DX_PI / 4.0f);
				break;
			}
		}
	}
	else
	{
		if (!m_isWalk)
		{
			SetRotDeltaX(0.0f);
			m_isIdle = true;
		}
	}
}
