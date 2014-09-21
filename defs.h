/*

  RealLib, a library for efficient exact real computation
  Copyright (C) 2006 Branimir Lambov

  This library is licensed under the Apache License, Version 2.0 (the "License");
  you may not use this library except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#ifndef FILE_DEFS_H
#define FILE_DEFS_H

namespace RealLib {

typedef long i32;
typedef unsigned long u32;

#define I32_MAX INT_MAX
#define I32_MIN INT_MIN

#if defined(__GNUC__) || defined(__MWERKS__)
// doesn't define NDEBUG in non-debug builds
// comment this if you want a debug build
#define NDEBUG

typedef long long i64;
typedef unsigned long long u64;

#define NAMESPACE_STD std

#else   // MS Visual C++
typedef __int64 i64;
typedef unsigned __int64 u64;

#define NAMESPACE_STD 
#endif

#if defined(__MWERKS__)
typedef i32 exp_type;
#define MINIMUM_EXPONENT (-(1<<28))
#else
typedef i64 exp_type;
#define MINIMUM_EXPONENT (-I32_MAX)
#endif
} // namespace

#if defined(__GNUC__) || defined(__MWERKS__)
#include "GCChelper.h"
#endif

#if defined(__MWERKS__)
#define FUNCTION(x) &x
#else
#define FUNCTION(x) &(x)
#endif

#define MULTIPLY_BY_CONVOLUTION

#ifdef MULTIPLY_BY_CONVOLUTION
#define CONVOLUTION_THRESHOLD 60
#else
#define CONVOLUTION_THRESHOLD INT_MAX
#endif

#define LIMIT_RECURSION

#ifdef LIMIT_RECURSION
// the size of the chunk that is processed recursively
#define EvaluationDepth 500
#else
#define EvaluationDepth INT_MAX
#endif

#define LOG_2_10 3.32192809488736234787031942948939017586483139

#if !defined(NDEBUG) && defined(_MSC_VER)
#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

#endif // file
