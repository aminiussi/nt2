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
#ifndef NT2_TOOLBOX_FDLIBM_FUNCTIONS_LDEXP_HPP_INCLUDED
#define NT2_TOOLBOX_FDLIBM_FUNCTIONS_LDEXP_HPP_INCLUDED
#include <nt2/include/functor.hpp>

/*!
 * \ingroup fdlibm
 * \defgroup fdlibm_ldexp ldexp
 *
 * \par Description
 * Please for details consult the proper documentation of the external
 * library fdlibm.
 *
 * \par Header file
 *
 * \code
 * #include <nt2/toolbox/fdlibm/include/functions/ldexp.hpp>
 * \endcode
 *
 *
 * \synopsis
 *
 * \code
 * namespace nt2
 * {
 *   namespace fdlibm
 *   {
 *     template <class A0>
 *       meta::call<tag::ldexp_(A0,A0)>::type
 *       ldexp(const A0 & a0,const A0 & a1);
 *   }
 * }
 * \endcode
 *
 * \param a0 the first parameter of ldexp
 * \param a1 the second parameter of ldexp
 *
 * \return a value of the common type of the parameters
 *
 * \par Notes
 * In SIMD mode, this function acts elementwise on the inputs vectors elements
 * \par
 * When calling external library, nt2 simply encapsulates the
 * original proper call to provide easy use.
 * \par
 * Remenber that SIMD implementation is therefore merely
 * mapping the scalar function to each SIMD vectors elements
 * and will not provide acceleration, but ease.
 * \par
 * fdlibm library defines functions for double entries only.
 * Nevertheless, they can be called with float entries under nt2 calls
 * to return float outputs.
 *
**/

namespace nt2 { namespace fdlibm { namespace tag
  {
    /*!
     * \brief Define the tag ldexp_ of functor ldexp
     *        in namespace nt2::fdlibm::tag for toolbox fdlibm
    **/
    struct ldexp_ : ext::elementwise_<ldexp_> { typedef ext::elementwise_<ldexp_> parent; };
  }
  NT2_FUNCTION_IMPLEMENTATION(fdlibm::tag::ldexp_, ldexp, 2)
  } }

#include <nt2/toolbox/fdlibm/functions/scalar/ldexp.hpp>
// #include <nt2/toolbox/fdlibm/functions/simd/all/ldexp.hpp>

#endif

// modified by jt the 29/12/2010
