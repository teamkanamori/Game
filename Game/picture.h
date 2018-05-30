#pragma once
class picture : public IGameObject
{
public:
	picture();
	~picture();
	bool Start();
	void Update();
	void Render(CRenderContext& rc);

	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー。
	prefab::CSkinModelRender* m_skinModelRender2 = nullptr;	//スキンモデルレンダラー。
	prefab::CSkinModelRender* m_skinModelRender3 = nullptr;	//スキンモデルレンダラー。
	prefab::CSpriteRender* m_spriteRender = nullptr;
	CVector3 m_position= CVector3::Zero;	//座標。
	int m_renderTargetNo = 0;
	float time = 0;

	std::vector<picture*>	m_picList;
};

