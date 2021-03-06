//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++98, c++03, c++11, c++14
// UNSUPPORTED: windows
// UNSUPPORTED: libcpp-no-if-constexpr
// MODULES_DEFINES: _LIBCUDACXX_DEBUG=1

// Can't test the system lib because this test enables debug mode
// UNSUPPORTED: with_system_cxx_lib

// test container debugging

#define _LIBCUDACXX_DEBUG 1
#include <string_view>

#include "test_macros.h"
#include "debug_mode_helper.h"

void test_null_argument() {
  EXPECT_DEATH(std::string_view(nullptr));
  EXPECT_DEATH(std::string_view(NULL));
  EXPECT_DEATH(std::string_view(static_cast<const char*>(0)));
  {
    std::string_view v;
    EXPECT_DEATH(((void)(v == nullptr)));
    EXPECT_DEATH(((void)(nullptr == v)));
  }
}

int main(int, char**)
{
  test_null_argument();

  return 0;
}
