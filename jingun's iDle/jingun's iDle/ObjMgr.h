#pragma once
#include "Obj.h"

class CObjMgr
{
private:
	CObjMgr();
	~CObjMgr();

public:
	void Add_Obj(OBJID _typeId, CObj* _pObj);
	void Update();
	void Late_Update();
	void Render(HDC hDC);
	void Release();
	list<CObj*> Set_ObjList(OBJID _typeId) {return  m_ObjList[_typeId]; }
public:
	list<CObj*> m_ObjList[OBJ_END];

public:
	static CObjMgr* Get_Instance()
	{
		if (!m_pInstance)
		{
			m_pInstance = new CObjMgr;
		}
		return m_pInstance;
	}

private:
	static CObjMgr* m_pInstance;

};

