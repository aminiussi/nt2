//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/arithmetic/include/functions/muls.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/unit/tests/type_expr.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/include/constants/zero.hpp>
#include <boost/simd/include/constants/one.hpp>
#include <boost/simd/include/constants/mone.hpp>
#include <boost/simd/include/constants/two.hpp>
#include <boost/simd/include/constants/mtwo.hpp>
#include <boost/simd/include/constants/inf.hpp>
#include <boost/simd/include/constants/minf.hpp>
#include <boost/simd/include/constants/nan.hpp>
#include <boost/simd/sdk/config.hpp>

NT2_TEST_CASE_TPL ( muls_signed_int,  BOOST_SIMD_INTEGRAL_SIGNED_TYPES)
{

  using boost::simd::muls;
  using boost::simd::tag::muls_;
  typedef typename boost::dispatch::meta::call<muls_(T,T)>::type r_t;
  typedef T wished_r_t;

  // return type conformity test
  NT2_TEST_TYPE_IS(r_t, wished_r_t);

  // specific values tests
  NT2_TEST_EQUAL(muls(boost::simd::Mone<T>(), boost::simd::Mone<T>()), boost::simd::One<T>());
  NT2_TEST_EQUAL(muls(boost::simd::One<T>(), boost::simd::One<T>()), boost::simd::One<T>());
  NT2_TEST_EQUAL(muls(boost::simd::Valmax<T>(), boost::simd::Valmax<T>()), boost::simd::Valmax<T>());
  NT2_TEST_EQUAL(muls(boost::simd::Valmax<T>(),T(2)), boost::simd::Valmax<T>());
  NT2_TEST_EQUAL(muls(boost::simd::Valmax<T>(),boost::simd::Mone<T>()), boost::simd::Valmin<T>()+boost::simd::One<T>());
  NT2_TEST_EQUAL(muls(boost::simd::Valmax<T>(),boost::simd::One<T>()), boost::simd::Valmax<T>());
  NT2_TEST_EQUAL(muls(boost::simd::Valmin<T>(),boost::simd::Mone<T>()), boost::simd::Valmax<T>());
  NT2_TEST_EQUAL(muls(boost::simd::Zero<T>(), boost::simd::Zero<T>()), boost::simd::Zero<T>());
} // end of test for signed_int_

NT2_TEST_CASE_TPL ( muls_unsigned_int,  BOOST_SIMD_UNSIGNED_TYPES)
{

  using boost::simd::muls;
  using boost::simd::tag::muls_;
  typedef typename boost::dispatch::meta::call<muls_(T,T)>::type r_t;
  typedef T wished_r_t;

  // return type conformity test
  NT2_TEST_TYPE_IS(r_t, wished_r_t);

  // specific values tests
  NT2_TEST_EQUAL(muls(boost::simd::One<T>(), boost::simd::One<T>()), boost::simd::One<T>());
  NT2_TEST_EQUAL(muls(boost::simd::Valmax<T>(),T(2)), boost::simd::Valmax<T>());
  NT2_TEST_EQUAL(muls(boost::simd::Zero<T>(), boost::simd::Zero<T>()), boost::simd::Zero<T>());
} // end of test for unsigned_int_

NT2_TEST_CASE(muls_special)
{
  using boost::simd::muls;
  using boost::simd::splat;
  using boost::simd::Valmin;

  typedef short int T1;
  NT2_TEST_EQUAL(muls(splat<T1>(-5165), splat<T1>(23258)), Valmin<T1>());

  typedef int T2;
  NT2_TEST_EQUAL(muls(splat<T2>(-1306766858), splat<T2>(1550772331)), Valmin<T2>());
  NT2_TEST_EQUAL(muls(splat<T2>(1467238299), splat<T2>(-900961598)), Valmin<T2>());
}
