//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2012 - 2014 MetaScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_ARITHMETIC_FUNCTIONS_SIMD_COMMON_DIVFLOOR_HPP_INCLUDED
#define BOOST_SIMD_ARITHMETIC_FUNCTIONS_SIMD_COMMON_DIVFLOOR_HPP_INCLUDED

#include <boost/simd/arithmetic/functions/divfloor.hpp>
#include <boost/simd/include/functions/simd/floor.hpp>
#include <boost/simd/include/functions/simd/divides.hpp>
#include <boost/simd/include/functions/simd/touints.hpp>
#include <boost/simd/include/functions/simd/toints.hpp>
#include <boost/simd/include/functions/simd/tofloat.hpp>
#include <boost/simd/include/functions/simd/split.hpp>
#include <boost/simd/include/functions/simd/groups.hpp>
#include <boost/simd/sdk/meta/is_upgradable.hpp>
#include <boost/dispatch/meta/upgrade.hpp>
#include <boost/dispatch/attributes.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_DISPATCH_IMPLEMENT_IF          ( divfloor_, tag::cpu_, (A0)(X)
                                       , (simd::meta::is_upgradable_as_real_on_ext<A0, X>)
                                       , ((simd_< int_<A0>, X>))
                                         ((simd_< int_<A0>, X>))
                                       )
  {
    typedef A0 result_type;
    BOOST_FORCEINLINE BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      typedef typename dispatch::meta::upgrade<A0>::type ivtype;
      ivtype a0l, a0h, a1l, a1h;
      boost::simd::split(a0, a0l, a0h );
      boost::simd::split(a1, a1l, a1h );
      ivtype d0 = toints(divfloor(tofloat(a0l), tofloat(a1l)));
      ivtype d1 = toints(divfloor(tofloat(a0h), tofloat(a1h)));
      return groups(d0, d1);
    }
  };

 BOOST_DISPATCH_IMPLEMENT_IF          ( divfloor_, tag::cpu_, (A0)(X)
                                      , (simd::meta::is_upgradable_as_real_on_ext<A0, X>)
                                      , ((simd_< uint_<A0>, X>))
                                        ((simd_< uint_<A0>, X>))
                                      )
  {
    typedef A0 result_type;

    BOOST_FORCEINLINE BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      typedef typename dispatch::meta::upgrade<A0>::type ivtype;
      ivtype a0l, a0h, a1l, a1h;
      boost::simd::split(a0, a0l, a0h );
      boost::simd::split(a1, a1l, a1h );
      ivtype d0 = touints(divfloor(tofloat(a0l), tofloat(a1l)));
      ivtype d1 = touints(divfloor(tofloat(a0h), tofloat(a1h)));
      return groups(d0, d1);
    }
  };

  BOOST_DISPATCH_IMPLEMENT          ( divfloor_, tag::cpu_, (A0)(X)
                                    , ((simd_<ints8_<A0>,X>))
                                      ((simd_<ints8_<A0>,X>))
                                    )
  {
    typedef A0 result_type;

    BOOST_FORCEINLINE BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      typedef typename dispatch::meta::upgrade<A0>::type ivtype;
      ivtype a0l, a0h, a1l, a1h;
      boost::simd::split(a0, a0l, a0h);
      boost::simd::split(a1, a1l, a1h);
      ivtype d0 = divfloor(a0l, a1l);
      ivtype d1 = divfloor(a0h, a1h);
      return groups(d0, d1);
    }
  };

  BOOST_DISPATCH_IMPLEMENT          ( divfloor_, tag::cpu_, (A0)(X)
                                    , ((simd_<floating_<A0>,X>))
                                      ((simd_<floating_<A0>,X>))
                                    )
  {
    typedef A0 result_type;
    BOOST_FORCEINLINE BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return boost::simd::floor(a0/a1);
    }
  };
} } }

#endif
