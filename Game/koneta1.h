#pragma once
class koneta1 : public IGameObject
{
public:
	koneta1();
	~koneta1();
	bool Start();
	void Update();
	void Render(CRenderContext& rc);
	enum EnAnimClip {
		enAnimClip_slip,		//コケるモーション
		enAnimClip_wakeup,		//起き上がりモーション。
		enAnimClip_num,			//アニメーションデータの数。
	};
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー。
	CAnimationClip m_animClip[enAnimClip_num];				//アニメーションクリップ。
	CVector3 m_pos = CVector3::Zero;
};

