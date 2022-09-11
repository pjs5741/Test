#include "stdafx.h"
#include "Player.h"
#include "LineMgr.h"
#include "ObjMgr.h"

CPlayer::CPlayer()
	: m_bJump(false), m_fPower(0.f), m_fTime(0.f)
{
}


CPlayer::~CPlayer()
{
}

void CPlayer::Initialize()
{
	m_tInfo.m_fCX = 30;
	m_tInfo.m_fCY = 60;
	m_tInfo.m_fX = 400;
	m_tInfo.m_fY = 500;
	m_fSpeed = 5.f;

	m_fPower = 20.f;
}

void CPlayer::Update()
{
	
	Key_Input();
	Jump();
	Update_Rect();
}

void CPlayer::Late_Update()
{
}

void CPlayer::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CPlayer::Key_Input()
{
	float fY = 0;

	if (GetAsyncKeyState(VK_LEFT))
	{
		if(m_tInfo.m_fX>=10)
		m_tInfo.m_fX -= m_fSpeed;
	

		/*if (CLineMgr::Get_Instance()->Collision_Line(m_tInfo.m_fX, &fY))
			m_tInfo.m_fY = fY;*/
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (m_tInfo.m_fX <= 400)
			m_tInfo.m_fX += m_fSpeed;
		else
		{
			CLineMgr::Get_Instance()->Move_Map(m_fSpeed);
			for (auto& iter : CObjMgr::Get_Instance()->Set_ObjList(OBJ_OBJECT))
				iter->Set_Move(m_fSpeed);
			
		}

		/*if (CLineMgr::Get_Instance()->Collision_Line(m_tInfo.m_fX, &fY))
			m_tInfo.m_fY = fY;*/
	}
	if (GetAsyncKeyState(VK_SPACE))
	{
		if (!m_bJump)
			m_bJump = true;
	}
}

void CPlayer::Jump()
{
	float	fY = 0;

	bool	bLineCol = CLineMgr::Get_Instance()->Collision_Line(m_tInfo.m_fX, &fY);

	if (m_bJump)
	{
		m_tInfo.m_fY -= m_fPower * m_fTime - (9.8f * m_fTime * m_fTime) * 0.5f;
		m_fTime += 0.2f;

		if (bLineCol && fY < m_tInfo.m_fY)
		{
			m_bJump = false;
			m_fTime = 0.f;
			m_tInfo.m_fY = fY;
		}
	}
	else if (bLineCol)
		m_tInfo.m_fY = fY;
}
