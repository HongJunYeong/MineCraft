#pragma once
class cPyramid
{
public:
	cPyramid();
	~cPyramid();
private:
	vector<ST_PC_VERTEX> m_vecXVertex;
	vector<ST_PC_VERTEX> m_vecYVertex;
	vector<ST_PC_VERTEX> m_vecZVertex;

	D3DMATERIAL9		 m_stMtrl;
public:
	void Setup();
	void Render();
};

