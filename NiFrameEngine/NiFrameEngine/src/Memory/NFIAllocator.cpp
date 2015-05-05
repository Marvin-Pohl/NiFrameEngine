#include "NFEnginePCH.hpp"
#include "Memory/NFIAllocator.hpp"
#include <NFEngine.hpp>

using namespace nfe;

const char* nfe::IAllocator::GetName() const
{
  return m_Name;
}

nfe::IAllocator::~IAllocator()
{
  m_Name = nullptr;
}

nfe::IAllocator::IAllocator( const char* name ) :
m_Name(name)
{

}

IAllocator* nfe::GetDefaultAllocator()
{
  return nfe::GEngine->GetDefaultAllocator();
}