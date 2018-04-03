#pragma once
class koneta2 : public IGameObject
{
public:
	koneta2();
	~koneta2();
	bool Start();
	void Update();
	void Render(CRenderContext& rc);
	enum EnAnimClip {
		//enAnimClip_idle,        //待機アニメーション。
		enAnimClip_slip,		//コケるモーション
		enAnimClip_wakeup,		//起き上がりモーション。
		enAnimClip_num,			//アニメーションデータの数。
	};
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー。
	CAnimationClip m_animClip[enAnimClip_num];				//アニメーションクリップ。
	CVector3 m_position = CVector3::Zero;	//座標。
	CQuaternion m_rotation = CQuaternion::Identity;
	int flag = 0;
};

