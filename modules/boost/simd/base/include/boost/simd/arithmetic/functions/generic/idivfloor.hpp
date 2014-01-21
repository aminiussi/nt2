//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_ARITHMETIC_FUNCTIONS_GENERIC_IDIVFLOOR_HPP_INCLUDED
#define BOOST_SIMD_ARITHMETIC_FUNCTIONS_GENERIC_IDIVFLOOR_HPP_INCLUDED

#include <boost/simd/arithmetic/functions/idivfloor.hpp>
#include <boost/simd/include/functions/simd/ifloor.hpp>
#include <boost/simd/include/functions/simd/divides.hpp>
#include <boost/simd/include/functions/simd/divfloor.hpp>
#include <boost/dispatch/meta/as_integer.hpp>

namespace boost { namespace simd { namespace BOOST_SIMD_EXT_NS
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::idivfloor_, tag::cpu_
                                   , (A0)
                                   , (generic_< arithmetic_<A0> >)
                                     (generic_< arithmetic_<A0> >)
                                   )
  {
    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return divfloor(a0, a1);
    }
  };

#ifdef BOOST_MSVC
  #pragma warning(push)
  #pragma warning(disable: 4723) // potential divide by 0
#endif

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::idivfloor_, tag::cpu_
                                   , (A0)
                                   , (generic_< floating_<A0> >)
                                     (generic_< floating_<A0> >)
                                   )
  {
    typedef typename dispatch::meta::as_integer<A0>::type result_type;

    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return ifloor(a0/a1);
    }
  };

#ifdef BOOST_MSVC
  #pragma warning(pop)
#endif

} } }

#endif
