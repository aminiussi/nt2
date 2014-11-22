//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_LINALG_FUNCTIONS_FUNM_HPP_INCLUDED
#define NT2_LINALG_FUNCTIONS_FUNM_HPP_INCLUDED
#include <nt2/include/functor.hpp>

namespace nt2 { namespace tag
  {
    /*!
     * \brief Define the tag funm_ of functor funm
     *        in namespace nt2::tag for toolbox algebra
    **/
    struct funm_ :   ext::unspecified_<funm_>
    {
      typedef ext::unspecified_<funm_>  parent;
      template<class... Args>
      static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)
      BOOST_AUTO_DECLTYPE_BODY( dispatching_funm_( ext::adl_helper(), static_cast<Args&&>(args)... ) )
    };
  }
  namespace ext
  {
    template<class Site, class... H>
    BOOST_FORCEINLINE generic_dispatcher<tag::funm_, Site> dispatching_funm_(adl_helper, boost::dispatch::meta::unknown_<Site>, boost::dispatch::meta::unknown_<H>...)
    {
      return generic_dispatcher<tag::funm_, Site>();
    }
    template<class... Args>
    struct impl_funm_;
  }
  /**
   * @brief funm(f, a) evaluates the functor fun at the square
   * matrix expression a. f(x,k) must return the k'th derivative of the function
   * represented by f evaluated at the vector x.
   *
   * @return a matrix containing funm(f, a)
   **/


  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::funm_, funm, 2)

}

#endif
