//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/operator/include/functions/shift_left.hpp>

#include <boost/dispatch/functor/meta/call.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/unit/tests/type_expr.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/sdk/config.hpp>
#include <boost/simd/sdk/simd/io.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/include/functions/splat.hpp>
#include <boost/simd/include/constants/one.hpp>
#include <boost/simd/include/constants/two.hpp>
#include <boost/simd/include/constants/zero.hpp>

NT2_TEST_CASE_TPL ( shift_left_integer,  BOOST_SIMD_SIMD_INTEGRAL_TYPES)
{
  using boost::simd::shift_left;
  using boost::simd::tag::shift_left_;
  using boost::simd::native;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef native<T,ext_t>                  vT;
  typedef typename boost::dispatch::meta::as_integer<vT>::type ivT;
  typedef typename boost::dispatch::meta::call<shift_left_(vT,ivT)>::type r_t;

  // specific values tests
  NT2_TEST_EQUAL(shift_left(boost::simd::One<vT>(),boost::simd::One<ivT>()), boost::simd::Two<r_t>());
  NT2_TEST_EQUAL(shift_left(boost::simd::One<vT>(),boost::simd::Zero<ivT>()), boost::simd::One<r_t>());
  NT2_TEST_EQUAL(shift_left(boost::simd::splat<vT>(17),boost::simd::splat<ivT>(2)), boost::simd::splat<r_t>(68));
  NT2_TEST_EQUAL(shift_left(boost::simd::Zero<vT>(),boost::simd::One<ivT>()), boost::simd::Zero<r_t>());
} // end of test for integer_

NT2_TEST_CASE_TPL ( shift_left_real,  BOOST_SIMD_SIMD_REAL_TYPES)
{
  using boost::simd::shift_left;
  using boost::simd::tag::shift_left_;
  using boost::simd::native;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef native<T,ext_t>                  vT;
  typedef typename boost::dispatch::meta::as_integer<vT>::type ivT;
  typedef typename boost::dispatch::meta::call<shift_left_(vT,ivT)>::type r_t;

  // specific values tests
  NT2_TEST_EQUAL(shift_left(boost::simd::One<vT>(),boost::simd::Zero<ivT>()), boost::simd::One<r_t>());
  NT2_TEST_EQUAL(shift_left(boost::simd::Zero<vT>(),boost::simd::One<ivT>()), boost::simd::Zero<r_t>());
} // end of test for floating_

NT2_TEST_CASE_TPL ( shift_left_integer_scalar,  BOOST_SIMD_SIMD_INTEGRAL_TYPES)
{
  using boost::simd::shift_left;
  using boost::simd::tag::shift_left_;
  using boost::simd::native;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef native<T,ext_t>                  vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef typename boost::dispatch::meta::call<shift_left_(vT,iT)>::type r_t;

  // specific values tests
  NT2_TEST_EQUAL(shift_left(boost::simd::One<vT>(),boost::simd::One<iT>()), boost::simd::Two<r_t>());
  NT2_TEST_EQUAL(shift_left(boost::simd::One<vT>(),boost::simd::Zero<iT>()), boost::simd::One<r_t>());
  NT2_TEST_EQUAL(shift_left(boost::simd::splat<vT>(17),boost::simd::splat<iT>(2)), boost::simd::splat<r_t>(68));
  NT2_TEST_EQUAL(shift_left(boost::simd::Zero<vT>(),boost::simd::One<iT>()), boost::simd::Zero<r_t>());
} // end of test for integer_

NT2_TEST_CASE_TPL ( shift_left_real_scalar,  BOOST_SIMD_SIMD_REAL_TYPES)
{
  using boost::simd::shift_left;
  using boost::simd::tag::shift_left_;
  using boost::simd::native;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef native<T,ext_t>                  vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef typename boost::dispatch::meta::call<shift_left_(vT,iT)>::type r_t;


  // specific values tests
  NT2_TEST_EQUAL(shift_left(boost::simd::One<vT>(),boost::simd::Zero<iT>()), boost::simd::One<r_t>());
  NT2_TEST_EQUAL(shift_left(boost::simd::Zero<vT>(),boost::simd::One<iT>()), boost::simd::Zero<r_t>());
} // end of test for floating_
