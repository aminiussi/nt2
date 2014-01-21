//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_OPERATOR_FUNCTIONS_SCALAR_IS_LESS_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_OPERATOR_FUNCTIONS_SCALAR_IS_LESS_EQUAL_HPP_INCLUDED
#include <boost/simd/operator/functions/is_less_equal.hpp>
#include <boost/simd/sdk/meta/as_logical.hpp>

namespace boost { namespace simd { namespace BOOST_SIMD_EXT_NS
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::is_less_equal_, tag::cpu_
                            , (A0)
                            , (scalar_< arithmetic_<A0> >)
                              (scalar_< arithmetic_<A0> >)
                            )
  {
    typedef typename meta::as_logical<A0>::type result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2) { return result_type(a0 <= a1); }
  };
} } }


#endif
