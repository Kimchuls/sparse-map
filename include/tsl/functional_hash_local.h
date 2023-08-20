// functional_hash.h header -*- C++ -*-

// Copyright (C) 2007-2021 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

/** @file bits/functional_hash.h
 *  This is an internal header file, included by other library headers.
 *  Do not attempt to use it directly. @headername{functional}
 */
#pragma once
#ifndef _FUNCTIONAL_HASH_H
#define _FUNCTIONAL_HASH_H 1

#endif // _FUNCTIONAL_HASH_H
#pragma GCC system_header

#include <boost/container/pmr/polymorphic_allocator.hpp>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  /// Specialization for float_array.
  template <typename T>
  using PolymorphicAllocator = boost::container::pmr::polymorphic_allocator<T>;
  using float_array = std::basic_string<float, std::char_traits<float>, PolymorphicAllocator<float>>;
  template<>
    struct hash<float_array> : public __hash_base<size_t, float_array>
    {
      size_t
      operator()(float_array __val) const noexcept
      {return std::_Hash_impl::hash(__val.data(), __val.length());}
    };

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
