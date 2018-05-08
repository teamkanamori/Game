#pragma once
class finish : public IGameObject
{
public:
	//////////////////////////////////////
	// メンバ関数。
	//////////////////////////////////////
	finish();
	~finish();
	bool Start();
	void Update();
	//////////////////////////////////////
	// メンバ変数。
	//////////////////////////////////////
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position = CVector3::Zero;	//座標。
};
