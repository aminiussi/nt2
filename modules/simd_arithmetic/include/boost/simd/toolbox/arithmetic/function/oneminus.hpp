//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTION_ONEMINUS_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTION_ONEMINUS_HPP_INCLUDED
#include <boost/simd/include/simd.hpp>
#include <boost/dispatch/include/functor.hpp>
#include <boost/simd/toolbox/arithmetic/include.hpp>

namespace boost { namespace dispatch { namespace tag
  {         
    struct oneminus_ {};
  }
} }

namespace boost { namespace simd
{
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(boost::dispatch::tag::oneminus_, oneminus, 1)
} }
 
#include <boost/simd/toolbox/operator.hpp>
#include <boost/simd/toolbox/arithmetic/function/scalar/oneminus.hpp>
#include <boost/simd/toolbox/arithmetic/function/simd/all/oneminus.hpp> 

 
#endif

// modified by jt the 25/12/2010
