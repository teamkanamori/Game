#pragma once
class Fade;


class title : public IGameObject
{
public:
	/////////////////////////////////////////////
	//メンバ関数。
	/////////////////////////////////////////////
	title();
	~title();
	bool Start()override;
	void Update()override;

	/////////////////////////////////////////////
	//メンバ変数とか。
	/////////////////////////////////////////////
	
	prefab::CSpriteRender* m_spriteRender;
	CVector3	m_position;		//座標。
	CQuaternion m_rotation;	//回転。
private:
	bool m_isWaitFadeout = false;
	Fade* m_fade = nullptr;
	CFont m_font;
};