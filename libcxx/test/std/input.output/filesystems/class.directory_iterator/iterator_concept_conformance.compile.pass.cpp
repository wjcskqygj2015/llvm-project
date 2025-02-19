//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++03, c++11, c++14, c++17
// UNSUPPORTED: libcpp-no-concepts
// UNSUPPORTED: gcc-10
// XFAIL: msvc && clang

// directory_iterator, recursive_directory_iterator

#include "filesystem_include.h"

#include <iterator>

using value_type = fs::directory_entry;

static_assert(std::indirectly_readable<fs::directory_iterator>);
static_assert(!std::indirectly_writable<fs::directory_iterator, value_type>);
static_assert(std::weakly_incrementable<fs::directory_iterator>);
static_assert(!std::incrementable<fs::directory_iterator>);
static_assert(std::input_or_output_iterator<fs::directory_iterator>);
static_assert(std::sentinel_for<fs::directory_iterator, fs::directory_iterator>);
static_assert(!std::sized_sentinel_for<fs::directory_iterator, fs::directory_iterator>);

static_assert(std::indirectly_readable<fs::recursive_directory_iterator>);
static_assert(!std::indirectly_writable<fs::recursive_directory_iterator, value_type>);
static_assert(std::weakly_incrementable<fs::recursive_directory_iterator>);
static_assert(!std::incrementable<fs::recursive_directory_iterator>);
static_assert(std::input_or_output_iterator<fs::recursive_directory_iterator>);
static_assert(std::sentinel_for<fs::recursive_directory_iterator, fs::recursive_directory_iterator>);
static_assert(!std::sized_sentinel_for<fs::recursive_directory_iterator, fs::recursive_directory_iterator>);
