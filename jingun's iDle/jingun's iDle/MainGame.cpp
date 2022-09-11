#include "stdafx.h"
#include "MainGame.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "LineMgr.h"
#include "Box.h"
CMainGame::CMainGame()
{
}


CMainGame::~CMainGame()
{
}

void CMainGame::Initialize()
{
	m_DC = GetDC(g_hWnd);

	/*if (!m_pPlayer)
	{
		m_pPlayer = new CPlayer;
		m_pPlayer->Initialize();
	}*/
	CObjMgr::Get_Instance()->Add_Obj(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create());
	//CObjMgr::Get_Instance()->Add_Obj(OBJ_MONSTER, CAbstractFactory<CMonster>::Create());
	CLineMgr::Get_Instance()->Initialize();
	
	CObjMgr::Get_Instance()->Add_Obj(OBJ_OBJECT, CAbstractFactory<CBox>::Create());
	

}

void CMainGame::Update()
{
	CObjMgr::Get_Instance()->Update();
	
	
}

void CMainGame::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CMainGame::Render()
{
	Rectangle(m_DC, 0, 0, WINCX, WINCY);
	CObjMgr::Get_Instance()->Render(m_DC);
	CLineMgr::Get_Instance()->Render(m_DC);
}
