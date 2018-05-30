#pragma once
class NetaBase : public IGameObject
{
public:
	NetaBase();
	~NetaBase();
	CVector3 GetPos()
	{
		return m_pos;
	}
protected:
	CVector3 m_pos;
};