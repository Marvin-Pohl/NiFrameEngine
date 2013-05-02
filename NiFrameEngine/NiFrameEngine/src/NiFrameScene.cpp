#include "NiFrameEnginePCH.h"
#include "NiFrameScene.h"

namespace NiFrame
{
	Scene::Scene( const String& sceneName ) :
		m_RootSceneNode( SceneNodePtr( new SceneNode( sceneName ) ) )
	{

	}

	Scene::~Scene()
	{

	}

	NiFrame::SceneNodePtr Scene::GetRootSceneNode( void ) const
	{
		return m_RootSceneNode;
	}

}

