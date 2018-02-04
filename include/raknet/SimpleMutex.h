/*
 *  Copyright (c) 2014, Oculus VR, Inc.
 *  Copyright (c) 2016-2018, TES3MP Team
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant 
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */

/// \file
/// \brief \b [Internal] Encapsulates a mutex
///



#ifndef __SIMPLE_MUTEX_H
#define __SIMPLE_MUTEX_H



#if   defined(_WIN32)
#include "WindowsIncludes.h"
#else
#include <sys/types.h>
#endif
#include "Export.h"
#include <mutex>
namespace RakNet
{

/// \brief An easy to use mutex.
/// 
/// I wrote this because the version that comes with Windows is too complicated and requires too much code to use.
/// @remark Previously I used this everywhere, and in fact for a year or two RakNet was totally threadsafe.
/// While doing profiling, I saw that this function was incredibly slow compared to the blazing performance of
/// everything else, so switched to single producer / consumer everywhere.
/// Now the user thread of RakNet is not threadsafe, but it's 100X faster than before.
class RAK_DLL_EXPORT SimpleMutex
{
public:

    // Constructor
    SimpleMutex();

    // Destructor
    ~SimpleMutex();

    // Locks the mutex.  Slow!
    void lock();

    // Unlocks the mutex.
    void unlock();

private:
    std::mutex mutex;
};

} // namespace RakNet

#endif

