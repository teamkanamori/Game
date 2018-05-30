#pragma once

class error : public IGameObject
{
public:
	error();
	~error();
	bool Start();
	void Update();

	prefab::CSpriteRender* m_spriteRender;
};

