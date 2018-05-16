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
	CVector3 m_position= CVector3::Zero;	//座標。
	int m_renderTargetNo = 0;
};

