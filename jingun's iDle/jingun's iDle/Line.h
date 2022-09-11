#pragma once
class CLine
{
public:
	CLine();
	CLine(MYPOINT& tLeft, MYPOINT& tRight);
	~CLine();

public:
	const LINE&  Get_Info()const { return m_tInfo; }
	void Set_Info(float _fSpeed) { m_tInfo.tLPoint.fX -= _fSpeed; m_tInfo.tRPoint.fX -= _fSpeed;}

public:
	void Render(HDC hDC);
private:
	LINE m_tInfo;
};

