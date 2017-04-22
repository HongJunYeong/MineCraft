#include "stdafx.h"
#include "cMainGame.h"
#include "cDeviceManager.h"

// >> :

#include "cGrid.h"
#include "cCamera.h"
#include "cPyramid.h"
#include "cCubeMan.h"

// <<
cMainGame::cMainGame()
	:m_pCamera(NULL)
	,m_pGrid(NULL)
	,m_pPyramid(NULL)
	,m_pCubeMan(NULL)

{
}


cMainGame::~cMainGame()
{
	SAFE_DELETE(m_pCamera);
	SAFE_DELETE(m_pGrid);
	SAFE_DELETE(m_pPyramid);
	SAFE_DELETE(m_pCubeMan);
	g_pDeviceManager->Destroy();
}

// >> : 
void cMainGame::Setup()
{

	m_pGrid = new cGrid;
	m_pGrid->Setup();

	m_pCubeMan = new cCubeMan;
	m_pCubeMan->Setup();

	m_pCamera = new cCamera;
	m_pCamera->Setup(&m_pCubeMan->GetPosition());

	m_pPyramid = new cPyramid;
	m_pPyramid->Setup();

	Set_Light();

	g_pD3DDevice->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP);
	g_pD3DDevice->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP);

}

void cMainGame::Update()
{
	if (m_pCubeMan) m_pCubeMan->Update();

	if (m_pCamera) m_pCamera->Update();
}

void cMainGame::Render()
{
	g_pD3DDevice->Clear(0,
		0,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL,
		D3DCOLOR_XRGB(200, 200, 0),
		1.0f, 0L);

	g_pD3DDevice->SetRenderState(D3DRS_STENCILENABLE, FALSE);

	g_pD3DDevice->BeginScene();

	if (m_pCubeMan) m_pCubeMan->Render();
	if (m_pGrid) m_pGrid->Render();
	if (m_pPyramid) m_pPyramid->Render();

	g_pD3DDevice->EndScene();

	g_pD3DDevice->Present(0, 0, 0, 0);
}
void cMainGame::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	m_pCamera->WndProc(hwnd, message, wParam, lParam);
}
void cMainGame::Set_Light()
{
	D3DLIGHT9 stLight;
	ZeroMemory(&stLight, sizeof(D3DLIGHT9));
	stLight.Type = D3DLIGHT_DIRECTIONAL;
	stLight.Ambient = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
	stLight.Diffuse = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
	stLight.Specular = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
	D3DXVECTOR3 vDir(1.0f, -1.0f, 1.0f);
	D3DXVec3Normalize(&vDir, &vDir);
	stLight.Direction = vDir;
	g_pD3DDevice->SetLight(0, &stLight);
	g_pD3DDevice->LightEnable(0,true);

	g_pD3DDevice->SetRenderState(D3DRS_NORMALIZENORMALS, true);
	//g_pD3DDevice->SetRenderState(D3DRS_SPECULARENABLE, true);
}
// << : 