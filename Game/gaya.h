#pragma once
class gaya : public IGameObject
{
public:
	gaya();
	~gaya();
	bool Start();
	
	void Update();

	float time = 0;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー
	prefab::CSkinModelRender* m_skinModelRender2 = nullptr;	//スキンモデルレンダラー
	prefab::CSkinModelRender* m_skinModelRender3 = nullptr;	//スキンモデルレンダラー
	CVector3 m_position = CVector3::Zero;
	CVector3 m_position2 = CVector3::Zero;
	CVector3 m_position3 = CVector3::Zero;
	CQuaternion m_rotation = CQuaternion::Identity;	//回転。
	CQuaternion m_rotation2 = CQuaternion::Identity;	//回転。
	CQuaternion m_rotation3 = CQuaternion::Identity;	//回転。
	int returnFlag = 0;
};

