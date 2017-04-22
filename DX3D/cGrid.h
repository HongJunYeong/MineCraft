#pragma once
class cGrid
{
public:
	cGrid();
	~cGrid();

private:
	vector<ST_PC_VERTEX>	m_vecVertex;

	D3DMATERIAL9	m_stMtl;
public:
	void Setup();
	void Render();

};

