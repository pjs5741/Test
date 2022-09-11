#include "stdafx.h"
#include "Box.h"
#include "LineMgr.h"

CBox::CBox()
{
}


CBox::~CBox()
{
}

void CBox::Initialize()
{

	float fY = 0;

	if (CLineMgr::Get_Instance()->Collision_Line(m_tInfo.m_fX, &fY))
		m_tInfo.m_fY = fY - 100;

	srand(time(NULL));
	m_tInfo.m_fX=rand()%9000;
	m_tInfo.m_fY = 100;
	m_tInfo.m_fCX = 50;
	m_tInfo.m_fCY = 50;

	
	
}

void CBox::Update()
{
	Update_Rect();
}

void CBox::Late_Update()
{
	
}

void CBox::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}
