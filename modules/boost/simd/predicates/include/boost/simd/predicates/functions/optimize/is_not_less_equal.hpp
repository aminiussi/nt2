//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_PREDICATES_FUNCTIONS_OPTIMIZE_IS_NOT_LESS_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_PREDICATES_FUNCTIONS_OPTIMIZE_IS_NOT_LESS_EQUAL_HPP_INCLUDED

#include <boost/simd/predicates/functions/is_not_less_equal.hpp>
#include <boost/simd/operator/functions/is_less_equal.hpp>
#include <boost/simd/operator/functions/logical_not.hpp>
#include <boost/dispatch/dsl/category.hpp>
#include <boost/dispatch/functor/preprocessor/call.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::logical_not_
                                   , tag::formal_, (D)(A0)(Arity)
                                   , ((node_<A0, boost::simd::tag::is_less_equal_, Arity, D>))
                                   )
  {
    BOOST_DISPATCH_RETURNS(1, (A0 const& a0),
      is_not_less_equal(boost::proto::child_c<0>(a0))
    )
  };
} } }

#endif
