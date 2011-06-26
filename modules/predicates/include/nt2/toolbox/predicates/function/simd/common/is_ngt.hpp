//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_PREDICATES_FUNCTION_SIMD_COMMON_IS_NGT_HPP_INCLUDED
#define NT2_TOOLBOX_PREDICATES_FUNCTION_SIMD_COMMON_IS_NGT_HPP_INCLUDED
#include <nt2/sdk/meta/strip.hpp>


/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::is_ngt_, tag::cpu_,
                         (A0)(X),
                         ((simd_<arithmetic_<A0>,X>))
                         ((simd_<arithmetic_<A0>,X>))
                        );

namespace nt2 { namespace ext
{
  template<class X, class Dummy>
  struct call<tag::is_ngt_(tag::simd_<tag::arithmetic_, X> ,
                           tag::simd_<tag::arithmetic_, X> ),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0, A1)> : meta::strip<A0>{};

    NT2_FUNCTOR_CALL(2)
    {
      return b_not(gt(a0,a1));
    }

  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is integer_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::is_ngt_, tag::cpu_,
                         (A0)(X),
                         ((simd_<integer_<A0>,X>))
                         ((simd_<integer_<A0>,X>))
                        );

namespace nt2 { namespace ext
{
  template<class X, class Dummy>
  struct call<tag::is_ngt_(tag::simd_<tag::integer_, X> ,
                           tag::simd_<tag::integer_, X> ),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0, A1)> : meta::strip<A0>{};//

    NT2_FUNCTOR_CALL(2)
    {
      return le(a0,a1);
    }
  };
} }

#endif
// modified by mg the 04/04/2011
