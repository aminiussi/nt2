//==============================================================================
//         Copyright 2003 - 2013   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2013   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/ieee/include/functions/exponent.hpp>
#include <boost/simd/sdk/simd/logical.hpp>

#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/unit/tests/type_expr.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/sdk/config.hpp>
#include <boost/dispatch/meta/as_integer.hpp>

#include <boost/simd/include/constants/mone.hpp>
#include <boost/simd/include/constants/one.hpp>
#include <boost/simd/include/constants/two.hpp>
#include <boost/simd/include/constants/zero.hpp>
#include <boost/simd/include/constants/minf.hpp>
#include <boost/simd/include/constants/inf.hpp>
#include <boost/simd/include/constants/nan.hpp>

NT2_TEST_CASE_TPL ( exponent_real,  BOOST_SIMD_REAL_TYPES)
{
  using boost::simd::exponent;
  using boost::simd::tag::exponent_;
  typedef typename boost::dispatch::meta::call<exponent_(T)>::type r_t;
  typedef typename boost::dispatch::meta::as_integer<T>::type  wished_r_t;

  // return type conformity test
  NT2_TEST_TYPE_IS(r_t, wished_r_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  NT2_TEST_EQUAL(exponent(boost::simd::Minf<T>()), boost::simd::Zero<r_t>());
  NT2_TEST_EQUAL(exponent(boost::simd::Inf <T>()), boost::simd::Zero<r_t>());
  NT2_TEST_EQUAL(exponent(boost::simd::Nan <T>()), boost::simd::Zero<r_t>());
#endif
  NT2_TEST_EQUAL(exponent(boost::simd::Mone<T>()), boost::simd::Zero<r_t>());
  NT2_TEST_EQUAL(exponent(boost::simd::One<T>()),  boost::simd::Zero<r_t>());
  NT2_TEST_EQUAL(exponent(boost::simd::Zero<T>()), boost::simd::Zero<r_t>());
  NT2_TEST_EQUAL(exponent(boost::simd::Two<T>()),  boost::simd::One<r_t>() );
  NT2_TEST_EQUAL(exponent(T(1.5)),                 boost::simd::Zero<r_t>() );
}
NT2_TEST_CASE_TPL ( exponent_i,  BOOST_SIMD_INTEGRAL_TYPES)
{
  using boost::simd::exponent;
  using boost::simd::tag::exponent_;
  typedef typename boost::dispatch::meta::call<exponent_(T)>::type r_t;
  typedef typename boost::dispatch::meta::as_integer<T, signed>::type  wished_r_t;

  // return type conformity test
  NT2_TEST_TYPE_IS(r_t, wished_r_t);

  // specific values tests
  NT2_TEST_EQUAL(exponent(boost::simd::Mone<T>()), boost::simd::Zero<r_t>());
  NT2_TEST_EQUAL(exponent(boost::simd::One<T>()),  boost::simd::Zero<r_t>());
  NT2_TEST_EQUAL(exponent(boost::simd::Zero<T>()), boost::simd::Zero<r_t>());
  NT2_TEST_EQUAL(exponent(boost::simd::Two<T>()),  boost::simd::Zero<r_t>() );

}
