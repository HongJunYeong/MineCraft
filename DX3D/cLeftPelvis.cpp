#include "stdafx.h"
#include "cLeftPelvis.h"


cLeftPelvis::cLeftPelvis()
{
}


cLeftPelvis::~cLeftPelvis()
{
}

void cLeftPelvis::Setup()
{
	cCubeNode::Setup();

	m_vLocalPos = D3DXVECTOR3(-0.15f, -0.5f, 0);

}

void cLeftPelvis::Update()
{
}
