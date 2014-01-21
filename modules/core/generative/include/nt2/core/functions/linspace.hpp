//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2011 - 2012   MetaScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_FUNCTIONS_LINSPACE_HPP_INCLUDED
#define NT2_CORE_FUNCTIONS_LINSPACE_HPP_INCLUDED

#include <nt2/include/functor.hpp>
#include <nt2/sdk/meta/generative_hierarchy.hpp>
#include <nt2/core/container/dsl/generative.hpp>
#include <nt2/core/functions/common/generative.hpp>

namespace nt2
{
  namespace tag
  {
    struct linspace_ : BOOST_SIMD_EXT_NS::state_constant_<linspace_>
    {
      typedef BOOST_SIMD_EXT_NS::state_constant_<linspace_> parent;
    };
  }

  NT2_FUNCTION_IMPLEMENTATION(nt2::tag::linspace_, linspace, 2)
  NT2_FUNCTION_IMPLEMENTATION(nt2::tag::linspace_, linspace, 3)
}

namespace nt2 { namespace BOOST_SIMD_EXT_NS
{
  /// INTERNAL ONLY
  template<class Domain, class Expr, int N>
  struct  value_type<tag::linspace_,Domain,N,Expr>
        : meta::generative_value<Expr>
  {};

  /// INTERNAL ONLY
  template<class Domain, class Expr, int N>
  struct  size_of<tag::linspace_,Domain,N,Expr>
        : meta::generative_size<Expr>
  {};
} }

#endif
