#pragma once

class cCharacter;

class cCubePNT
{
public:
	cCubePNT();

protected:
	vector<ST_PNT_VERTEX>	m_vecVertex;
	IDirect3DTexture9*		m_pTexture;
public:
	virtual	~cCubePNT();
	virtual	void Setup();
	virtual	void Update();
	virtual void Render();
	virtual void ShadowRender();
	virtual void Animation();
};

