#pragma once
class Camera 
{
public:
	Camera();
	~Camera();
	bool Start();
	void Update();
	void Render(CRenderContext& rc);

	float time = 0;
	float timestanp[3];
	int shattercount = 0;
	CRenderTarget renderTargets[3];
	CSprite m_sprite;	//シーンをペタッと張り付けるためのスプライト
	int flag = 0;
};


