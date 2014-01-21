//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TRIGONOMETRIC_FUNCTIONS_GENERIC_SECD_HPP_INCLUDED
#define NT2_TRIGONOMETRIC_FUNCTIONS_GENERIC_SECD_HPP_INCLUDED

#include <nt2/trigonometric/functions/secd.hpp>
#include <nt2/include/functions/simd/rec.hpp>
#include <nt2/include/functions/simd/cosd.hpp>
#include <nt2/include/functions/simd/tofloat.hpp>
#include <nt2/include/functions/simd/is_eqz.hpp>
#include <nt2/include/functions/simd/if_allbits_else.hpp>
#include <nt2/sdk/meta/as_floating.hpp>
namespace nt2 { namespace BOOST_SIMD_EXT_NS
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::secd_, tag::cpu_
                            , (A0)
                            , (generic_< arithmetic_<A0> >)
                            )
  {
    typedef typename boost::dispatch::meta::as_floating<A0>::type result_type;
    NT2_FUNCTOR_CALL(1)
    {
      result_type r = cosd(tofloat(a0));
      return rec(if_nan_else(is_eqz(r), r));
    }
  };
} }


#endif
