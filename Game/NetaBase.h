#pragma once
class NetaBase : public IGameObject
{
public:
	NetaBase();
	~NetaBase();
protected:
	CVector3 m_pos;
};