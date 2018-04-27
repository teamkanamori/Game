#include "stdafx.h"
#include "Camera.h"


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
	if (Pad(0).IsTrigger(enButtonRB1)) {
		if (shattercount < 3) {
			timestanp[shattercount] = time;
			shattercount++;
			flag = 1;
		}
		else {
			MessageBox(NULL, "もうシャッターは押せません！", "警告", MB_OK);
		}
		//シャッタが押されたフラグをtrueにする。
	}
	time += GameTime().GetFrameDeltaTime();
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
		}
	}

	//if (/*シャッターが押されていたフラグが立っていたら*/) {
	//	//シャッターが押されたフレームだけ、
	//	//renderTargetsにテクスチャをコピーする。
	//}
	/*シャッターが押されていたフラグを下す*/
}