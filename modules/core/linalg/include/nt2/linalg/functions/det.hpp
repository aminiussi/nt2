//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_LINALG_FUNCTIONS_DET_HPP_INCLUDED
#define NT2_LINALG_FUNCTIONS_DET_HPP_INCLUDED
#include <nt2/include/functor.hpp>

/*!
 * \ingroup algebra
 * \defgroup algebra_trace trace
 *
 * \par Description
 * Elementary Least square
 *
 * \par Header file
 *
 * \code
 * #include <nt2/include/functions/trace.hpp>
 * \endcode
 *
 *
 * \param a the matrix a,  a must be square
 *
 * \par Notes
 *   Call the dedicated lapack routines available on the target.
 * \par
 *
**/
//==============================================================================
// trace actual class forward declaration
//==============================================================================

namespace nt2 { namespace tag
  {
    /*!
     * \brief Define the tag trace_ of functor trace
     *        in namespace nt2::tag for toolbox algebra
    **/
    struct det_ :  ext::abstract_<det_> { typedef ext::abstract_<det_> parent;   template<class... Args>   static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)   BOOST_AUTO_DECLTYPE_BODY( dispatching_det_( ext::adl_helper(), static_cast<Args&&>(args)... ) ) };
  }
  namespace ext
  {
    template<class Site, class... H>
    BOOST_FORCEINLINE generic_dispatcher<tag::det_, Site> dispatching_det_(adl_helper, boost::dispatch::meta::unknown_<Site>, boost::dispatch::meta::unknown_<H>...)
    {
      return generic_dispatcher<tag::det_, Site>();
    }
    template<class... Args>
    struct impl_det_;
  }

  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::det_, det, 1)
}

#endif
