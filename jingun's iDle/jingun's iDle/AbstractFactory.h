#pragma once

template<typename T>
class CAbstractFactory
{
public:
	CAbstractFactory() {}
	~CAbstractFactory() {}

public:
	static CObj*  Create()
	{
		CObj* m_pObj = new T;

		m_pObj->Initialize();

		return m_pObj;
	}
};