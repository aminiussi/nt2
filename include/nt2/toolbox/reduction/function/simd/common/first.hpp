//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_REDUCTION_FUNCTION_SIMD_COMMON_FIRST_HPP_INCLUDED
#define NT2_TOOLBOX_REDUCTION_FUNCTION_SIMD_COMMON_FIRST_HPP_INCLUDED
#include <nt2/sdk/meta/strip.hpp>


namespace nt2 { namespace functors
{
  //  no special validate for first

  /////////////////////////////////////////////////////////////////////////////
  // Compute first(const A0& a0)
  /////////////////////////////////////////////////////////////////////////////
  template<class Extension,class Info>
  struct call<first_,
              tag::simd_(tag::arithmetic_,Extension),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)>
    { typedef typename meta::scalar_of<A0 > ::type type; };

    NT2_FUNCTOR_CALL(1)
    {
       return a0[0];
    }
  };
} }

      
#endif
