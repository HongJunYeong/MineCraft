#include "stdafx.h"
#include "cCamera.h"


cCamera::cCamera()
	:m_vEye(0,0,-5.0f)
	,m_vLookAt(0,0,0)
	,m_vUp(0,1.0f,0)
	,m_pvTarget(NULL)
	,m_fCameraDistance(5.0f)
	,m_isButtonDown(false)
	,m_vCamRotAngle(0,0,0)
{
	m_ptPrevMouse.x = 0;
	m_ptPrevMouse.y = 0;
}


cCamera::~cCamera()
{
	m_pvTarget = NULL;
}

void cCamera::Setup(D3DXVECTOR3 * pvTarget)
{
	m_pvTarget = pvTarget;

	RECT rc;
	GetClientRect(g_hWnd, &rc);

	D3DXMATRIXA16 matProj;
	D3DXMatrixPerspectiveFovLH(
		&matProj,
		D3DX_PI / 4.0f,
		rc.right / (float)rc.bottom,
		1.0f,
		1000.0f);

	g_pD3DDevice->SetTransform(D3DTS_PROJECTION, &matProj);
}

void cCamera::Update()
{

	RECT rc;
	GetClientRect(g_hWnd, &rc);

	D3DXMATRIXA16 matR, matRX, matRY;
	D3DXMatrixRotationX(&matRX, m_vCamRotAngle.x);
	D3DXMatrixRotationY(&matRY, m_vCamRotAngle.y);

	matR = matRX*matRY;

	m_vEye = D3DXVECTOR3(0, 3, -m_fCameraDistance);
	D3DXVec3TransformCoord(&m_vEye, &m_vEye, &matR);

	if (m_pvTarget)
	{
		m_vLookAt = *m_pvTarget;
		m_vEye = m_vEye + *m_pvTarget;
	}

	D3DXMATRIXA16 matView;
	D3DXMatrixLookAtLH(&matView, &m_vEye, &m_vLookAt, &m_vUp);

	g_pD3DDevice->SetTransform(D3DTS_VIEW, &matView);

}

void cCamera::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
		m_isButtonDown = true;
		m_ptPrevMouse.x = LOWORD(lParam);
		m_ptPrevMouse.y = HIWORD(lParam);
		break;
	case WM_LBUTTONUP:
		m_isButtonDown = false;
		break;
	case WM_MOUSEMOVE:
		if (m_isButtonDown)
		{
			POINT ptCurrMosue;
			ptCurrMosue.x = LOWORD(lParam);
			ptCurrMosue.y = HIWORD(lParam);

			float fDeltaX = (float)ptCurrMosue.x - m_ptPrevMouse.x;
			float fDeltaY = (float)ptCurrMosue.y - m_ptPrevMouse.y;

			m_vCamRotAngle.y += (fDeltaX / 100.0f);
			m_vCamRotAngle.x += (fDeltaY / 100.0f);

			m_ptPrevMouse = ptCurrMosue;
		}
		break;
	case WM_MOUSEWHEEL:
		if ((SHORT)HIWORD(wParam) > 0)
			m_fCameraDistance -= 0.3f;
		else
			m_fCameraDistance += 0.3f;
		break;
	}
}
