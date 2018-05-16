#pragma once
class ike : public IGameObject
{
public:
	ike();
	~ike();
	bool Start();
	void Update();
	void Render(CRenderContext& rc);

	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー。
	CVector3 m_position = CVector3::Zero;	//座標。
	CQuaternion m_rotation = CQuaternion::Identity;
};

