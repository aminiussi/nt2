//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_FUZZY_FUNCTIONS_ALMOST_EQUAL_HPP_INCLUDED
#define NT2_FUZZY_FUNCTIONS_ALMOST_EQUAL_HPP_INCLUDED
#include <nt2/include/functor.hpp>


namespace nt2 { namespace tag
  {
   /*!
     @brief almost_equal generic tag

     Represents the almost_equal function in generic contexts.

     @par Models:
        Hierarchy
   **/
    struct almost_equal_ : ext::elementwise_<almost_equal_>
    {
      /// @brief Parent hierarchy
      typedef ext::elementwise_<almost_equal_> parent;
      template<class... Args>
      static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)
      BOOST_AUTO_DECLTYPE_BODY( dispatching_almost_equal_( ext::adl_helper(), static_cast<Args&&>(args)... ) )
    };
  }
  namespace ext
  {
   template<class Site, class... H>
   BOOST_FORCEINLINE generic_dispatcher<tag::almost_equal_, Site> dispatching_almost_equal_(adl_helper, boost::dispatch::meta::unknown_<Site>, boost::dispatch::meta::unknown_<H>...)
   {
     return generic_dispatcher<tag::almost_equal_, Site>();
   }
   template<class... Args>
   struct impl_almost_equal_;
  }
  /*!
    \f$ a0 \in \quad ]a_1-\mathop{\mbox{predecessor}}(a_1,|a_2|),a_1-\mathop{\mbox{successor}}(a_1,|a_2|)[\f$

    @par Semantic:

    For every parameters of floating types respectively T0, T1, T2:

    @code
    T0 r = almost_equal(a0,a1,a2);
    @endcode

    is similar to:

    @code
    T0 r = a0 <= successor(a0, n) &&  a0 >=  predecessor(a0, n);
    @endcode

    see @funcref{predecessor}, @funcref{successor}
    @param a0

    @param a1

    @param a2

    see @funcref{predecessor}, @funcref{successor}
    @return a logical value  of the type associated the first parameter
  **/
  NT2_FUNCTION_IMPLEMENTATION(tag::almost_equal_, almost_equal, 3)
}

#endif

