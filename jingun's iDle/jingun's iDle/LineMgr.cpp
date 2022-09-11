#include "stdafx.h"
#include "LineMgr.h"

CLineMgr*		CLineMgr::m_pInstance = nullptr;
CLineMgr::CLineMgr()
{
}


CLineMgr::~CLineMgr()
{
	Release();
}

void CLineMgr::Initialize(void)
{
	srand(time(NULL));

	for (int i = 0; i < 100; ++i)
	{
		tPoint[i]={float(0 + 100 * i),float( rand() % 400+100)};

		
	}

	/*MYPOINT	tPoint[7] = { 
	{0.f,350.f},
	{ 100.f, 450.f },
	{ 250.f, 450.f },
	{ 450.f, 250.f },
	{ 600.f, 250.f },
	{ 700.f, 350.f },
	{ 800.f, 550.f } 
	};*/

	for(int i=0;i<100;++i)
	m_LineList.push_back(new CLine(tPoint[i], tPoint[i+1]));
	/*m_LineList.push_back(new CLine(tPoint[1], tPoint[2]));
	m_LineList.push_back(new CLine(tPoint[2], tPoint[3]));
	m_LineList.push_back(new CLine(tPoint[3], tPoint[4]));
	m_LineList.push_back(new CLine(tPoint[4], tPoint[5]));*/
}

void CLineMgr::Render(HDC _hDC)
{
	for (auto& iter : m_LineList)
		iter->Render(_hDC);
}

void CLineMgr::Release(void)
{
	for_each(m_LineList.begin(), m_LineList.end(), Safe_Delete<CLine*>);
	m_LineList.clear();
}

void CLineMgr::Move_Map(float _fSpeed)
{
	
	for (auto& iter:m_LineList)
	{
		iter->Set_Info(_fSpeed);
	}
}

bool CLineMgr::Collision_Line(float & _fX, float * _pfY)
{
	if (m_LineList.empty())
		return false;

	CLine*		pTargetLine = nullptr;

	for (auto& iter : m_LineList)
	{
		if (_fX >= iter->Get_Info().tLPoint.fX &&
			_fX <= iter->Get_Info().tRPoint.fX)
			pTargetLine = iter;
	}

	if (nullptr == pTargetLine)
		return false;

	// Y  = ((y2 - y1) / (x2 - x1)) * (X - x1) + y1

	float	x1 = pTargetLine->Get_Info().tLPoint.fX;
	float	y1 = pTargetLine->Get_Info().tLPoint.fY;

	float	x2 = pTargetLine->Get_Info().tRPoint.fX;
	float	y2 = pTargetLine->Get_Info().tRPoint.fY;

	*_pfY = ((y2 - y1) / (x2 - x1)) * (_fX - x1) + y1;
	//*_pfY -= 30;

	return true;
}
