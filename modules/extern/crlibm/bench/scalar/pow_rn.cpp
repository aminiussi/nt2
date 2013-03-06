//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_BENCH_MODULE "nt2 crlibm toolbox - pow_rn/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of crlibm components in scalar mode
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/crlibm/include/functions/pow_rn.hpp>
#include <nt2/sdk/bench/benchmark.hpp>
#include <nt2/sdk/bench/timing.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <cmath>


//////////////////////////////////////////////////////////////////////////////
// scalar runtime benchmark for functor<pow_rn_> from crlibm
//////////////////////////////////////////////////////////////////////////////
using nt2::crlibm::tag::pow_rn_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, T(V1) ,T(V2))

namespace n1 {
  typedef float T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(pow_rn_,(RS(T,T(0),T(10)))(RS(T,T(0),T(10))))
}
namespace n2 {
  typedef double T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(pow_rn_,(RS(T,T(0),T(10)))(RS(T,T(0),T(10))))
}

#undef RS
