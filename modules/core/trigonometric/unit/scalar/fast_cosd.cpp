//==============================================================================
//         Copyright 2003 - 2013   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2013   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <nt2/trigonometric/include/functions/fast_cosd.hpp>

#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/unit/tests/type_expr.hpp>
#include <nt2/sdk/unit/tests/ulp.hpp>
#include <nt2/sdk/unit/tests/basic.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/sdk/config.hpp>

#include <nt2/include/constants/one.hpp>
#include <nt2/include/constants/sqrt_2.hpp>
#include <nt2/include/constants/sqrt_2o_2.hpp>
#include <nt2/include/constants/zero.hpp>
#include <nt2/include/constants/inf.hpp>
#include <nt2/include/constants/minf.hpp>
#include <nt2/include/constants/nan.hpp>

NT2_TEST_CASE_TPL ( fast_cosd_real,  NT2_REAL_TYPES)
{
  using nt2::fast_cosd;
  using nt2::tag::fast_cosd_;

  typedef typename nt2::meta::call<fast_cosd_(T)>::type r_t;
  typedef T wished_r_t;

  // return type conformity test
  NT2_TEST_TYPE_IS(r_t, wished_r_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  NT2_TEST_ULP_EQUAL(fast_cosd(-nt2::_180<T>()), nt2::Nan<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(fast_cosd(-nt2::_90<T>()), nt2::Nan<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(fast_cosd(nt2::Inf<T>()), nt2::Nan<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(fast_cosd(nt2::Minf<T>()), nt2::Nan<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(fast_cosd(nt2::Nan<T>()), nt2::Nan<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(fast_cosd(nt2::_180<T>()), nt2::Nan<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(fast_cosd(nt2::_90<T>()), nt2::Nan<r_t>(), 0.5);
#endif
  NT2_TEST_ULP_EQUAL(fast_cosd(-nt2::_45<T>()), nt2::Sqrt_2o_2<r_t>(), 1.0);
  NT2_TEST_ULP_EQUAL(fast_cosd(nt2::Zero<T>()), nt2::One<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(fast_cosd(nt2::_45<T>()), nt2::Sqrt_2o_2<r_t>(), 1.0);
}
