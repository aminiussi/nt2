//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TRIGONOMETRIC_FUNCTIONS_GENERIC_INDEG_HPP_INCLUDED
#define NT2_TRIGONOMETRIC_FUNCTIONS_GENERIC_INDEG_HPP_INCLUDED
#include <nt2/trigonometric/functions/indeg.hpp>
#include <nt2/include/functions/simd/multiplies.hpp>
#include <nt2/include/functions/simd/tofloat.hpp>
#include <nt2/include/constants/radindeg.hpp>
#include <nt2/include/constants/radindegr.hpp>
#include <nt2/sdk/meta/as_floating.hpp>

namespace nt2 { namespace BOOST_SIMD_EXT_NS
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::indeg_, tag::cpu_
                            , (A0)
                            , (generic_< arithmetic_<A0> >)
                            )
  {
    typedef typename boost::dispatch::meta::as_floating<A0>::type result_type;
    NT2_FUNCTOR_CALL(1)
    {
      result_type z =  nt2::tofloat(a0);
      return (z*nt2::Radindeg<result_type>())-(z*nt2::Radindegr<result_type>());
    }
  };
} }


#endif
