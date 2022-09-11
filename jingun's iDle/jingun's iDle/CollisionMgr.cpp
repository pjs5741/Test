#include "stdafx.h"
#include "CollisionMgr.h"


CollisionMgr::CollisionMgr()
{
}


CollisionMgr::~CollisionMgr()
{
}

void CollisionMgr::Collision_Sphere(list<CObj*> _pDesc, list<CObj*> _pSrc)
{
	for (auto& pDesc : _pDesc)
	{
		for (auto& pSrc : _pSrc)
		{
			if (Collision_Check(pDesc, pSrc))
			{

				pSrc->Set_Dead();

			}
		}
	}
}

bool CollisionMgr::Collision_Check(CObj * _pDesc, CObj * _pSrc)
{
	float fWidth = (_pDesc->Get_Info().m_fX - _pSrc->Get_Info().m_fX);
	float fHeight = _pDesc->Get_Info().m_fY - _pSrc->Get_Info().m_fY;

	float fDiagonal = sqrt(fWidth*fWidth + fHeight * fHeight);
	float fRadius = (_pDesc->Get_Info().m_fCX + _pSrc->Get_Info().m_fCX) / 2;

	if (fDiagonal <= fRadius)
	{
		return true;
	}
	return false;
}

void CollisionMgr::Collision_RectEx(list<CObj*> _pDesc, list<CObj*> _pSrc)
{
	for (auto& Desc : _pDesc)
	{
		float	fX = 0.f, fY = 0.f;

		for (auto& Src : _pSrc)
		{
			if (Collision_RectCheck(Desc, Src, &fX, &fY))
			{
				// 상하 충돌
				if (fX > fY)
				{
					// 상 충돌
					if (Desc->Get_Info().m_fY < Src->Get_Info().m_fY)
					{
						Desc->Set_PosY(-fY);
					}
					// 하 충돌
					else
					{
						Desc->Set_PosY(fY);
					}
				}

				// 좌우 충돌
				else
				{
					// 좌 충돌
					if (Desc->Get_Info().m_fX < Src->Get_Info().m_fX)
					{
						Desc->Set_PosX(-fX);
					}
					// 우 충돌
					else
					{
						Desc->Set_PosX(fX);
					}
				}
			}
		}
	}
}

bool CollisionMgr::Collision_RectCheck(CObj* _pDesc, CObj* _pSrc, float * _pX, float * _pY)
{
	float	fWidth = fabs(_pDesc->Get_Info().m_fX - _pSrc->Get_Info().m_fX);
	float	fHeight = fabs(_pDesc->Get_Info().m_fY - _pSrc->Get_Info().m_fY);

	float	fRadiusX = (_pDesc->Get_Info().m_fCX + _pSrc->Get_Info().m_fCX) * 0.5f;
	float	fRadiusY = (_pDesc->Get_Info().m_fCY + _pSrc->Get_Info().m_fCY) * 0.5f;

	if (fRadiusX >= fWidth && fRadiusY >= fHeight)
	{
		*_pX = fRadiusX - fWidth;
		*_pY = fRadiusY - fHeight;

		return true;
	}

	return false;
}
