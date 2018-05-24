#include "stdafx.h"
#include "Camera.h"
#include "error.h"


Camera::Camera()
{
}


Camera::~Camera()
{
}


bool Camera::Start()
{
	m_sprite.Init(
		GraphicsEngine().GetMainRenderTarget().GetRenderTargetSRV(),
		1280.0f,
		720.0f
	);
	DXGI_SAMPLE_DESC sampleDesc;
	ZeroMemory(&sampleDesc, sizeof(sampleDesc));
	sampleDesc.Count = 1;
	sampleDesc.Quality = 0;
	
	for (int i = 0; i < 3; i++) {
		renderTargets[i].Create(
			1280,
			720,
			1,
			1,
			DXGI_FORMAT_R8G8B8A8_UNORM,
			DXGI_FORMAT_UNKNOWN,
			sampleDesc
		);
	}
	return true;
}

void Camera::Update()
{
	prefab::CSoundSource* ss;

	if (Pad(0).IsTrigger(enButtonRB1)) {
		if (shattercount < 3) {
			timestanp[shattercount] = time;
			shattercount++;
			flag = 1;

			ss = NewGO<prefab::CSoundSource>(0);
			ss->Init("sound/Shutter.mp3");
			ss->Play(false);

			//エフェクトを作成。
			prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
			//エフェクトを再生。
			effect->Play(L"effect/test.efk");
			CVector3 emitPos = m_pos;
			emitPos.x += 23.0f;
			emitPos.y += 10.0f;
			emitPos.z -= 30.0f;
			effect->SetPosition(emitPos);
		}
		else {
			NewGO<error>(0, "error");
					
			ss = NewGO<prefab::CSoundSource>(0);
			ss->Init("sound/error_1.wav");
			ss->Play(false);
			//MessageBox(NULL, "もうシャッターは押せません！", "警告", MB_OK);
		}
		//シャッタが押されたフラグをtrueにする。
	}
	time += GameTime().GetFrameDeltaTime();
	//シーンプレイヤーを使うとき、
	//timeに　＝＝の文は使えない
	// if(time > 1 &&  一度も再生されていないというflgが必要)
}

void Camera::Render(CRenderContext& rc)
{


	if (flag == 1) {
		//これが撮影したテクスチャ。こいつをCSpriteのInit関数に渡してやればかけるはず
		//renderTargets[0].GetRenderTargetSRV();
		{
			CGraphicsEngine& ge = Engine().GetGraphicsEngine();
			ge.BeginGPUEvent(L"Camera::Render");

			//レンダリングターゲットを記憶しておく。
			CRenderTarget* rtsBackup[8];
			unsigned int numView;
			rc.OMGetRenderTargets(numView, rtsBackup);

			//レンダリングターゲットの切り替え。
			CRenderTarget* rts[] = {
				&renderTargets[shattercount - 1]
			};
			rc.OMSetRenderTargets(1, rts);

			m_sprite.Draw(rc, MainCamera2D().GetViewMatrix(), MainCamera2D().GetProjectionMatrix());

			//コピーが終わったら元に戻す。
			rc.OMSetRenderTargets(numView, rtsBackup);

			ge.EndGPUEvent();

			flag = 0;
		}
	}

	//if (/*シャッターが押されていたフラグが立っていたら*/) {
	//	//シャッターが押されたフレームだけ、
	//	//renderTargetsにテクスチャをコピーする。
	//}
	/*シャッターが押されていたフラグを下す*/
}