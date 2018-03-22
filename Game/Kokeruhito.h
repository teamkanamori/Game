#pragma once
class Kokeruhito
{
public:
	Kokeruhito();
	~Kokeruhito();
	bool Start();
	void Update();
	prefab::CSkinModelRender* m_skinModelRender = nullptr;

};

