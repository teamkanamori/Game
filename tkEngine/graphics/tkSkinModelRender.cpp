/*!
* @brief	スキンモデルレンダラー
*/
#include "tkEngine/tkEnginePreCompile.h"
#include "tkEngine/graphics/tkSkinModelRender.h"


namespace tkEngine {
	namespace prefab {

		void CSkinModelRender::Init(
			const wchar_t* filePath,
			CAnimationClip* animationClips,
			int numAnimationClips,
			CSkinModel::EnFbxUpAxis fbxUpAxis)
		{
			m_enFbxUpAxis = fbxUpAxis;
			m_skinModelData.Load(filePath);
			m_skinModel.Init(m_skinModelData);
			InitAnimation(animationClips, numAnimationClips);
		}
		void CSkinModelRender::InitAnimation(CAnimationClip* animationClips, int numAnimationClips)
		{
			m_animationClips = animationClips;
			m_numAnimationClips = numAnimationClips;
			if (m_animationClips != nullptr) {
				m_animation.Init(m_skinModel, m_animationClips, m_numAnimationClips);
			}
		}
		/*!
		* @brief	更新前に呼ばれる関数。
		*/
		bool CSkinModelRender::Start()
		{
			return true;
		}
		/*!
		* @brief	更新。
		*/
		void CSkinModelRender::Update()
		{
			m_skinModel.Update(m_position, m_rotation, m_scale, m_enFbxUpAxis);
		}
		/*!
		* @brief	描画。
		*/

		void  CSkinModelRender::Render(CRenderContext& rc)
		{
			if (m_overrideDiffuseTexture != nullptr) {
				//ディフューズテクスチャを差し替え。
				m_skinModel.FindMaterial([&](auto material) {
					material->SetOverrideDiffuseTexture(m_overrideDiffuseTexture);
				});
			}
			m_skinModel.Draw(rc);

			if (m_isSkinModelDrawOnRenderFunction == true) {
				//モデルの描画はRender関数で行う。
				m_skinModel.Draw(rc);
			}
		}

		void CSkinModelRender::PostRender(CRenderContext& rc)
		{
			if (m_isSkinModelDrawOnRenderFunction == false) {
				//モデルの描画はPostRender関数で行う。
				m_skinModel.Draw(rc);
			}
		}
	}
}