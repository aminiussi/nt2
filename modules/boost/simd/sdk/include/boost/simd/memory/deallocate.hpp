//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_MEMORY_DEALLOCATE_HPP_INCLUDED
#define BOOST_SIMD_MEMORY_DEALLOCATE_HPP_INCLUDED

#include <boost/simd/memory/align_on.hpp>
#include <boost/simd/memory/aligned_free.hpp>
#include <boost/dispatch/attributes.hpp>
#include <boost/dispatch/meta/enable_if_type.hpp>
#include <cstddef>

namespace boost { namespace simd
{
  /*!
    @brief Aligned pointer deallocation

    Deallocate a raw buffer of aligned bytes using the current system aligned
    memory deallocation procedure.

    @param ptr Pointer to the memory to free.
  **/
  BOOST_FORCEINLINE void deallocate( void* ptr )
  {
    simd::aligned_free( ptr );
  }

  /*!
    @brief Allocator based aligned pointer deallocation

    Deallocate a raw buffer of aligned bytes using a custom allocator.

    @param alloc  Allocator performing the deallocation
    @param ptr    Pointer to the memory to free.
  **/
  template<class Allocator> BOOST_FORCEINLINE
  #if defined(DOXYGEN_ONLY)
  void
  #else
  typename dispatch::meta::enable_if_type<typename Allocator::pointer>::type
  #endif
  deallocate( Allocator& alloc, void* ptr )
  {
    // How many elements are needed to store proper number of bytes
    details::aligned_block_header const old( details::get_block_header( ptr ) );
    std::size_t const oldSize( old.userBlockSize );

    alloc.deallocate( static_cast<typename Allocator::pointer>(old.pBlockBase)
                    , oldSize
                    );
  }
} }

#endif