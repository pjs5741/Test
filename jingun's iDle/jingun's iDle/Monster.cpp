#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
{
}


CMonster::~CMonster()
{
}

void CMonster::Initialize()
{
	m_tInfo.m_fX = 600;
	m_tInfo.m_fY = 200;
	m_tInfo.m_fCX = 30;
	m_tInfo.m_fCY = 60;
}

void CMonster::Update()
{
	Update_Rect();
}

void CMonster::Late_Update()
{
}

void CMonster::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}
