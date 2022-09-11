#pragma once
#include "Obj.h"
class CPlayer :
	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;

private:
	void Key_Input();
	void Jump();

private:
	bool m_bJump;
	float		m_fPower;	// 점프 힘의 크기
	float		m_fTime;
};

