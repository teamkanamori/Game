#pragma once
class zawa : public IGameObject
{
public:
	zawa();
	~zawa();
	bool Start();
	void Update();

	prefab::CSpriteRender* m_spriteRender;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー。

	float time = 0;
};

