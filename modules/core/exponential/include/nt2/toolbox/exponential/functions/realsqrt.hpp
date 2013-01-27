//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
/*!
 * \file
**/
#ifndef NT2_TOOLBOX_EXPONENTIAL_FUNCTIONS_REALSQRT_HPP_INCLUDED
#define NT2_TOOLBOX_EXPONENTIAL_FUNCTIONS_REALSQRT_HPP_INCLUDED
#include <nt2/include/functor.hpp>

/*!
 * \ingroup exponential
 * \defgroup exponential_realsqrt realsqrt
 *
 * \par Description
 *  sqrt function which asserts if called with non real positive values.
 *
 * \par Header file
 *
 * \code
 * #include <nt2/include/functions/realsqrt.hpp>
 * \endcode
 *
 *
 * \synopsis
 *
 * \code
 * namespace nt2
 * {
 *   template <class A0>
 *     meta::call<tag::realsqrt_(A0)>::type
 *     realsqrt(const A0 & a0);
 * }
 * \endcode
 *
 * \param a0 the unique parameter of realsqrt
 *
 * \return a value of the same type as the parameter
 *
 * \par Notes
 * In SIMD mode, this function acts elementwise on the inputs vectors elements
 * \par
 *
**/

namespace nt2 { namespace tag
  {
    /*!
     * \brief Define the tag realsqrt_ of functor realsqrt
     *        in namespace nt2::tag for toolbox exponential
    **/
    struct realsqrt_ : ext::elementwise_<realsqrt_> { typedef ext::elementwise_<realsqrt_> parent; };
  }
  NT2_FUNCTION_IMPLEMENTATION(tag::realsqrt_, realsqrt, 1)
}

#endif
