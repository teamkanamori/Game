#pragma once
class Title :public IGameObject
{
public:
	Title();
	~Title();
	bool Start();
	void Update();

	enum EnAnimClip {
		enAnimClip_jj,   //タイトルのアニメーション
		enAnimClip_num,
	};
	CSkinModel m_skinModel;			//スキンモデル
	CSkinModelData m_skinModelData;	//スキンモデルデータ
	CAnimationClip m_animClip[enAnimClip_num];	//アニメーションクリップ
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position = CVector3::Zero;	//JJモデルの座標
	CQuaternion m_rotation = CQuaternion::Identity;	//回転
};

