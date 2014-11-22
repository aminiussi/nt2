//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2011 - 2012   MetaScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_FUNCTIONS_EXTENT_HPP_INCLUDED
#define NT2_CORE_FUNCTIONS_EXTENT_HPP_INCLUDED

/*!
  @file
  @brief Defines the extent function
**/

#include <nt2/include/functor.hpp>

namespace nt2
{
  namespace tag
  {
    /*!
      @brief Tag for the extent functor
    **/
    struct extent_ : ext::abstract_<extent_>
    {
      typedef ext::abstract_<extent_> parent;
      template<class... Args>
      static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)
      BOOST_AUTO_DECLTYPE_BODY( dispatching_extent_( ext::adl_helper(), static_cast<Args&&>(args)... ) )
    };
  }
  namespace ext
  {
    template<class Site, class... H>
    BOOST_FORCEINLINE generic_dispatcher<tag::extent_, Site> dispatching_extent_(adl_helper, boost::dispatch::meta::unknown_<Site>, boost::dispatch::meta::unknown_<H>...)
    {
      return generic_dispatcher<tag::extent_, Site>();
    }
    template<class... Args>
    struct impl_extent_;
  }

  /*!
    @brief Return the extent of an expression

    Return the extent, ie the internally optimized representation of an
    expression dimensions set.

    @param a0 Expression to inspect
    @return The extent of a0
  **/
  NT2_FUNCTION_IMPLEMENTATION(nt2::tag::extent_, extent, 1)
}

#endif
