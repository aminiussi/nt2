//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_PREDICATES_FUNCTIONS_IS_IMAG_HPP_INCLUDED
#define BOOST_SIMD_PREDICATES_FUNCTIONS_IS_IMAG_HPP_INCLUDED
#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>


namespace boost { namespace simd { namespace tag
  {
   /*!
     @brief is_imag generic tag

     Represents the is_imag function in generic contexts.

     @par Models:
        Hierarchy
   **/
    struct is_imag_ : BOOST_SIMD_EXT_NS::elementwise_<is_imag_>
    {
      /// @brief Parent hierarchy
      typedef BOOST_SIMD_EXT_NS::elementwise_<is_imag_> parent;
    };}
  /*!
    Returns True or False according a0 is pure imaginary or not.
    For non complex numbers it is same as to be zero

    @par Semantic:

    @code
    logical<T> r = is_imag(a0);
    @endcode

    is similar to:

    @code
    logical<T> r = a0 == 0;
    @endcode

    @param a0

    @return a logical value
  **/
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::is_imag_, is_imag,   1)
} }

#endif

