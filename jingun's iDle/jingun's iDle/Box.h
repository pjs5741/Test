#pragma once
#include "Obj.h"
class CBox :
	public CObj
{
public:
	CBox();
	~CBox();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;

public:
	void Set_X(float _X) { m_tInfo.m_fX -= _X; }
};

