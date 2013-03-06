//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
/*!
 * \file
**/
#ifndef NT2_TOOLBOX_CEPHES_FUNCTIONS_JN_HPP_INCLUDED
#define NT2_TOOLBOX_CEPHES_FUNCTIONS_JN_HPP_INCLUDED
#include <nt2/include/functor.hpp>

/*!
 * \ingroup cephes
 * \defgroup cephes_jn jn
 *
 * \par Description
 * Please for details consult the proper documentation of the external
 * library cephes.
 *
 * \par Header file
 *
 * \code
 * #include <nt2/toolbox/cephes/include/functions/jn.hpp>
 * \endcode
 *
 *
 * \synopsis
 *
 * \code
 * namespace nt2
 * {
 *   namespace cephes
 *   {
 *     template <class A0>
 *       meta::call<tag::jn_(A0,A0)>::type
 *       jn(const A0 & a0,const A0 & a1);
 *   }
 * }
 * \endcode
 *
 * \param a0 the first parameter of jn
 * \param a1 the second parameter of jn
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
 * cephes library defines functions for float and double entries.
 * \par
 * As they are written in C the original name of the float version is
 * generally terminated by and extra 'f',
 * this is not the case for the nt2 version which dispatch to
 * the correct function according to the inputs types.
 *
**/

namespace nt2 { namespace cephes { namespace tag
  {
    /*!
     * \brief Define the tag jn_ of functor jn
     *        in namespace nt2::cephes::tag for toolbox cephes
    **/
    struct jn_ : ext::elementwise_<jn_> { typedef ext::elementwise_<jn_> parent; };
  }
  NT2_FUNCTION_IMPLEMENTATION(cephes::tag::jn_, jn, 2)
  } }

#include <nt2/toolbox/cephes/functions/scalar/jn.hpp>
// #include <nt2/toolbox/cephes/functions/simd/all/jn.hpp>

#endif

// modified by jt the 29/12/2010
