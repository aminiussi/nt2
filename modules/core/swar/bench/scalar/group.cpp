//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_BENCH_MODULE "nt2 swar toolbox - group/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of swar components in scalar mode
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/swar/include/functions/group.hpp>
#include <nt2/sdk/bench/benchmark.hpp>
#include <nt2/sdk/bench/timing.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <cmath>


//////////////////////////////////////////////////////////////////////////////
// scalar runtime benchmark for functor<group_> from swar
//////////////////////////////////////////////////////////////////////////////
using nt2::tag::group_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, T(V1) ,T(V2))

namespace n1 {
  typedef nt2::int16_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(group_,(RS(T,0,100))(RS(T,0,100)))
}
namespace n2 {
  typedef nt2::uint16_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(group_,(RS(T,0,100))(RS(T,0,100)))
}
namespace n3 {
  typedef nt2::int32_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(group_,(RS(T,0,100))(RS(T,0,100)))
}
namespace n4 {
  typedef nt2::uint32_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(group_,(RS(T,0,100))(RS(T,0,100)))
}
namespace n5 {
  typedef nt2::int64_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(group_,(RS(T,0,100))(RS(T,0,100)))
}
namespace n6 {
  typedef nt2::uint64_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(group_,(RS(T,0,100))(RS(T,0,100)))
}
namespace n7 {
  typedef double T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(group_,(RS(T,0,100))(RS(T,0,100)))
}

#undef RS
