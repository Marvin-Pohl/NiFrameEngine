#pragma once
#ifndef NiFrameMultiSampleQuality_h__
#define NiFrameMultiSampleQuality_h__
#include "NFRendererPCH.hpp"
#include "NFStringableObject.hpp"

namespace nfe
{
  class D3DMultiSampleQuality : public IStringableObject
  {
  public:
    D3DMultiSampleQuality( DWORD multiSampleQuality );
    ~D3DMultiSampleQuality();

    virtual String ToString() const;

  private:

    DWORD m_MultiSampleQuality;

  };
}

#endif // NiFrameMultiSampleQuality_h__
