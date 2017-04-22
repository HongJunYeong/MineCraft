#pragma once

class MCBody
{
public:
	MCBody();
	~MCBody();

private:
	vector<ST_PC_VERTEX> m_vecVertex;
	
public:
	void Setup();
	void Update();
	void Render();
};

