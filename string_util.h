// Copyright (c) 2010 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// This file defines utility functions for working with strings.

#ifndef BASE_STRING_UTIL_H
#define BASE_STRING_UTIL_H

#include <stdarg.h>   // va_list
#include <stdio.h>   // va_list

#include <string>
#include <vector>
#include "util.h"

// Safe standard library wrappers for all platforms.

namespace base {


// Wrapper for vsnprintf that always null-terminates and always returns the
// number of characters that would be in an untruncated formatted
// string, even when truncation occurs.
int VsnPrintf(char* buffer, size_t size, const char* format, va_list arguments)
    PRINTF_FORMAT(3, 0);

inline int VsnPrintf(char* buffer, size_t size,
                     const char* format, va_list arguments) {
    return ::vsnprintf(buffer, size, format, arguments);
}

}  // namespace base

// Store result into a supplied string and return it
const std::string& SStringPrintf(std::string* dst, const char* format, ...)
    PRINTF_FORMAT(2, 3);

// Lower-level routine that takes a va_list and appends to a specified
// string.  All other routines are just convenience wrappers around it.
void StringAppendV(std::string* dst, const char* format, va_list ap)
    PRINTF_FORMAT(2, 0);
#endif
