#include "NFEnginePCH.hpp"
#include "Memory/NFStackAllocator.hpp"
#include "NFEngine.hpp"


nfe::StackAllocator::StackAllocator(
  uint64 size,
  uint32 alignment /*= sizeof(void*)*/,
  IAllocator* parentAllocator /*= nullptr*/,
  const char* name /*= "NFStackAllocator"*/ ) :
  IAllocator(name),
  m_Size( size),
  m_Alignment( alignment ),
  m_ParentAllocator(parentAllocator),
  m_Memory(nullptr),
  m_CurrentMarker(nullptr)
{
  if (m_ParentAllocator == nullptr)
  {
    m_ParentAllocator = GEngine->GetDefaultAllocator();
  }

  uint64 alignedSize = ( ( size + alignment - 1 ) / alignment ) * alignment;

  m_Memory = static_cast< uint8* >( m_ParentAllocator->Allocate( alignedSize ) );

  uint8 offset = static_cast< uint8 >( alignment - reinterpret_cast< uintptr_t >( m_Memory ) % alignment );
  m_Memory += offset;
  m_Memory[ -1 ] = offset;

  m_CurrentMarker = m_Memory;
}

nfe::StackAllocator::~StackAllocator()
{
  uint8 offset = m_Memory[ -1 ];
  m_Memory -= offset;
  m_ParentAllocator->Deallocate( m_Memory );

  m_Memory = nullptr;
  m_CurrentMarker = nullptr;
}

void* nfe::StackAllocator::Allocate( uint64 size )
{
  NF_ASSERT( m_CurrentMarker + size < m_Memory + m_Size, "Tried to allocate more than the StackAllocator holds" );
  uint64 alignedSize = size + ( m_Alignment - ( size % m_Alignment ) );
  void* allocatedAddress = m_CurrentMarker;
  m_CurrentMarker += alignedSize;
  return allocatedAddress;
}

void nfe::StackAllocator::Deallocate( void* address )
{
  NF_ASSERT( address > m_Memory && address < m_Memory + m_Size,
    "Tried to Deallocate pointer out of this allocator range" );
  // TODO: Check if skip other allocations ?
  m_CurrentMarker = static_cast< uint8* >( address );
}
