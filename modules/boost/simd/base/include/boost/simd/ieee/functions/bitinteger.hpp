//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_IEEE_FUNCTIONS_BITINTEGER_HPP_INCLUDED
#define BOOST_SIMD_IEEE_FUNCTIONS_BITINTEGER_HPP_INCLUDED
#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>


namespace boost { namespace simd { namespace tag
  {
   /*!
     @brief bitinteger generic tag

     Represents the bitinteger function in generic contexts.

     @par Models:
        Hierarchy
   **/
    struct bitinteger_ : ext::elementwise_<bitinteger_>
    {
      /// @brief Parent hierarchy
      typedef ext::elementwise_<bitinteger_> parent;
      template<class... Args>
      static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)
      BOOST_AUTO_DECLTYPE_BODY( dispatching_bitinteger_( ext::adl_helper(), static_cast<Args&&>(args)... ) )
    };
  }
  namespace ext
  {
   template<class Site>
   BOOST_FORCEINLINE generic_dispatcher<tag::bitinteger_, Site> dispatching_bitinteger_(adl_helper, boost::dispatch::meta::unknown_<Site>, ...)
   {
     return generic_dispatcher<tag::bitinteger_, Site>();
   }
   template<class... Args>
   struct impl_bitinteger_;
  }
  /*!
    Transforms a floating point value in a pattern of bits
    stored in an integer with different formulas according to
    the floating point sign (the converse of bitfloating)

    @par Semantic:

    @code
     as_integer<T> r = bitinteger(a0);
    @endcode

    is similar to:

    @code
      as_integer<T> r =
         (is_positive(a0) ?
           bitwise_cast<as_integer<T>>(a0) :
           Signmask<as_integer<T>>()-bitwise_cast<as_integer<T>>(a0);
    @endcode

    @param a0

    @return a value of same type as the input
  **/
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::bitinteger_, bitinteger, 1)
} }

#endif
