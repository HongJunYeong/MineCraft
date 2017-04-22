#pragma once
#include "cCubeNode.h"

class cLeftPelvis : public cCubeNode
{
public:
	cLeftPelvis();

public:
	virtual ~cLeftPelvis();

	virtual void Setup() override;
	virtual void Update() override;
};

