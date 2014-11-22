//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_EULER_FUNCTIONS_EXPNI_HPP_INCLUDED
#define NT2_EULER_FUNCTIONS_EXPNI_HPP_INCLUDED
#include <nt2/include/functor.hpp>


namespace nt2 { namespace tag
  {
   /*!
     @brief expni generic tag

     Represents the expni function in generic contexts.

     @par Models:
        Hierarchy
   **/
    struct expni_ : ext::elementwise_<expni_> { typedef ext::elementwise_<expni_> parent;   template<class... Args>   static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)   BOOST_AUTO_DECLTYPE_BODY( dispatching_expni_( ext::adl_helper(), static_cast<Args&&>(args)... ) ) };
  }
  namespace ext
  {
   template<class Site, class... H>
   BOOST_FORCEINLINE generic_dispatcher<tag::expni_, Site> dispatching_expni_(adl_helper, boost::dispatch::meta::unknown_<Site>, boost::dispatch::meta::unknown_<H>...)
   {
     return generic_dispatcher<tag::expni_, Site>();
   }
   template<class... Args>
   struct impl_expni_;
  }
  /*!
    Computes the exponential integral function
    @par Semantic:

    For every parameters of scalar integer type I0 and
    floating type T1:

    @code
    T0 r = expni(a0,a1);
    @endcode

    Computes \f$ E_{a_0}(a_1)=\int_0^\infty \frac{e^{-a_1t}}{t^{a_0}} \mbox{d}t\f$


    @param a0 is a scalar positive integer

    @param a1 a floating value

    @return a value of the same type as the second parameter
  **/
  NT2_FUNCTION_IMPLEMENTATION(tag::expni_, expni, 2)
}

#endif

