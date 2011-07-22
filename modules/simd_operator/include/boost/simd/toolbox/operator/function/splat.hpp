//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//============================================================================== 
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SPLAT_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SPLAT_HPP_INCLUDED
#include <boost/simd/include/simd.hpp>
#include <boost/simd/toolbox/operator/include.hpp>
#include <boost/dispatch/meta/as.hpp>

namespace boost { namespace dispatch
{
  namespace tag
  {
    struct splat_  {};
  }
} }


namespace boost { namespace simd
{  
  template<class T, class A0> inline
  typename boost::dispatch::meta::call<boost::dispatch::tag::splat_(A0,
                                       boost::dispatch::meta::as_<T>)>::type
  splat(A0 const& a0)
  {
    typename boost::dispatch::make_functor<boost::dispatch::tag::splat_, A0>::type callee;
    return callee(a0, boost::dispatch::meta::as_<T>() );
  }
} }

#include <boost/simd/toolbox/operator/function/scalar/splat.hpp>
#include <boost/simd/toolbox/operator/function/simd/all/splat.hpp>

#endif
