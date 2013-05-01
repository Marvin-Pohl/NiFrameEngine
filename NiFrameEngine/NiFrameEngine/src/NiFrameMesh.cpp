#include "NiFrameEnginePCH.h"
#include "NiFrameMesh.h"

namespace NiFrame
{

	Mesh::Mesh( VertexBuffer::type* vertexBuffer, IndexBuffer::type* indexBuffer ) :
		m_Indices( indexBuffer ),
		m_Vertices( vertexBuffer )
	{
		//Those vector normally don't grow so we can adjust the length to save memory
		m_Indices->shrink_to_fit();
		m_Vertices->shrink_to_fit();
	}

	Mesh::~Mesh( void )
	{
		Release();
	}

	void Mesh::Release( void )
	{
		SAFE_DELETE( m_Vertices )
		SAFE_DELETE( m_Indices )
	}

	NiFrame::NFSize Mesh::GetIndexCount( void ) const
	{
		return m_Indices->size();
	}

	NiFrame::NFSize Mesh::GetVertexCount( void ) const
	{
		return m_Vertices->size();
	}

}
