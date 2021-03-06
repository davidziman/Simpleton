//=====================================================================================================================
//
//   Mutex.cpp
//
//   Implementation of class: Simpleton::Mutex
//
//   The lazy man's utility library
//   Joshua Barczak
//   Copyright 2010 Joshua Barczak
//
//   LICENSE:  See Doc\License.txt for terms and conditions
//
//=====================================================================================================================

#include "Mutex.h"
#include <windows.h>
#include <assert.h>


namespace Simpleton
{
    //=====================================================================================================================
    //
    //         Constructors/Destructors
    //
    //=====================================================================================================================

    //=====================================================================================================================
    //=====================================================================================================================
    Mutex::Mutex(  )
    {
        assert( sizeof(CRITICAL_SECTION) == SIZEOF_CRITICAL_SECTION ); // juuuust in case
        InitializeCriticalSection( (CRITICAL_SECTION*) m_criticalSection );
    }

    //=====================================================================================================================
    //=====================================================================================================================
    Mutex::~Mutex()
    {
        DeleteCriticalSection( (CRITICAL_SECTION*) m_criticalSection );
    }


    //=====================================================================================================================
    //
    //            Public Methods
    //
    //=====================================================================================================================

    //=====================================================================================================================
    //=====================================================================================================================
    void Mutex::Take()
    {
        EnterCriticalSection( (CRITICAL_SECTION*) m_criticalSection );
    }

    //=====================================================================================================================
    //=====================================================================================================================
    void Mutex::Release()
    {
        LeaveCriticalSection( (CRITICAL_SECTION*) m_criticalSection );
    }
}

