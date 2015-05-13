﻿#pragma once

#include "NFEnginePCH.hpp"
#include <Renderer/NFResolution.hpp>
#include "Memory/NFIAllocator.hpp"

namespace nfe
{
  class INativeModule;
  class NIFRAME_DLL_EXPORT IPlatform
  {
  public:
    IPlatform();
    virtual ~IPlatform() {}

    virtual INativeModule* LoadModule(const char* modulePath) = 0;
    virtual void ReleaseModule( INativeModule* module ) = 0;

    virtual IAllocator* GetDefaultAllocator() const = 0;
    /**
    @brief Gets a specific GPU allocator if the platform supports memory allocation specific for a GPU
    */
    virtual IAllocator* GetGPUAllocator() const = 0;

    /**
    @brief Gets a specific Debug Allocator which can be used for debug purpose, this alloctor will not be available in shipping builds

    @return IAllocator*
    */
    virtual IAllocator* GetDebugAllocator() const = 0;

    virtual Resolution GetNativeResolution( uint32 monitorIdx ) const = 0;

  private:

  };

  extern NIFRAME_DLL_EXPORT IPlatform* GPlatform;
}
