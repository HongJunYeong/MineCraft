#pragma once

//class cCubePC;
class cCamera;
class cGrid;
class cPyramid;
class cCharacter;

class cMainGame
{
public:
	cMainGame();
	~cMainGame();

	// >> :
private:
	//cCubePC*	m_pCubePC;
	cCamera*	m_pCamera;
	cGrid*		m_pGrid;
	cPyramid*	m_pPyramid;
	cCharacter*   m_pCubeMan;


public:
	void Setup();
	void Update();
	void Render();

	void WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
	void Set_Light();
	
	// << :
};
