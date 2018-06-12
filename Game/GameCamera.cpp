#include "stdafx.h"
#include "GameCamera.h"


GameCamera::GameCamera()
{
}

GameCamera::~GameCamera()
{
}
bool GameCamera::Start()
{
	//カメラのニアクリップとファークリップを設定する。
	MainCamera().SetNear(1.0f);
	MainCamera().SetFar(10000.0f);

	MainCamera().SetPosition({ 0,5,0});
	MainCamera().SetTarget({ 0,5,-10 });

	return true;
}
void GameCamera::Update()
{
	MainCamera().Update();

	CVector3 Pos = MainCamera().GetPosition();
	CVector3 Target = MainCamera().GetTarget();
	//視点から注視点に向かって伸びるベクトルVを求める。
	CVector3 V = Target - Pos;

	//パッドの入力を使ってカメラを回す。
	float x = Pad(0).GetRStickXF();
	//Y軸周りの回転クォータニオンを求める。
	CQuaternion qRot;
	qRot.SetRotationDeg(CVector3::AxisY, 6.0f * x);
	//V = V * qRot
	qRot.Multiply(V);

	//VをX軸周りに回転

	//パッドの入力を使ってカメラを回す。
	float y = Pad(0).GetRStickYF();
	//X軸周りの回転。
	CVector3 axisX;
	axisX.Cross(CVector3::Up, V);
	axisX.Normalize();
	qRot.SetRotationDeg(axisX, -6.0f * y);

	CVector3 vBackup = V;

	qRot.Multiply(V);

	CVector3 vNorm = V;
	vNorm.Normalize();

	if (vNorm.y > 0.2f) {
		V = vBackup;
	}
	else if (vNorm.y < -0.2f) {
		V = vBackup;
	}
	//新しい視点を求める。
	Target = Pos + V;

	MainCamera().SetTarget(Target);
}