//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_PREDICATES_FUNCTIONS_SCALAR_IS_INVALID_HPP_INCLUDED
#define BOOST_SIMD_PREDICATES_FUNCTIONS_SCALAR_IS_INVALID_HPP_INCLUDED

#include <boost/simd/predicates/functions/is_invalid.hpp>
#include <boost/simd/include/functions/scalar/is_nan.hpp>
#include <boost/simd/sdk/meta/as_logical.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_DISPATCH_IMPLEMENT( is_invalid_, tag::cpu_
                            , (A0)
                            , (scalar_< bool_<A0> >)
                            )
  {
    typedef bool result_type;
    inline result_type operator()(A0 const&) const
    {
      return false;
    }
  };
  BOOST_DISPATCH_IMPLEMENT( is_invalid_, tag::cpu_
                            , (A0)
                            , (scalar_< arithmetic_<A0> >)
                            )
  {
    typedef typename meta::as_logical<A0>::type result_type;
    inline result_type operator()(A0 const&) const
    {
      return boost::simd::False<result_type>();
    }
  };

  BOOST_DISPATCH_IMPLEMENT( is_invalid_, tag::cpu_
                            , (A0)
                            , (scalar_< floating_<A0> >)
                            )
  {
    typedef typename meta::as_logical<A0>::type result_type;
    BOOST_SIMD_FUNCTOR_CALL(1) { return is_nan(a0-a0); }
  };
} } }


#endif
