//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_POLYNOM_FUNCTIONS_POLYVAL_HPP_INCLUDED
#define NT2_POLYNOM_FUNCTIONS_POLYVAL_HPP_INCLUDED
#include <nt2/include/functor.hpp>
#include <nt2/sdk/meta/size_as.hpp>
#include <nt2/sdk/meta/value_as.hpp>
#include <nt2/core/container/dsl/size.hpp>
#include <nt2/sdk/meta/tieable_hierarchy.hpp>
#include <nt2/core/container/dsl/value_type.hpp>

namespace nt2 { namespace tag
  {
   /*!
     @brief polyval generic tag

     Represents the polyval function in generic contexts.

     @par Models:
        Hierarchy
   **/
    struct polyval_ : ext::tieable_<polyval_>
    {
      /// @brief Parent hierarchy
      typedef ext::tieable_<polyval_> parent;
      template<class... Args>
      static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)
      BOOST_AUTO_DECLTYPE_BODY( dispatching_polyval_( ext::adl_helper(), static_cast<Args&&>(args)... ) )
    };
  }
  namespace ext
  {
   template<class Site, class... H>
   BOOST_FORCEINLINE generic_dispatcher<tag::polyval_, Site> dispatching_polyval_(adl_helper, boost::dispatch::meta::unknown_<Site>, boost::dispatch::meta::unknown_<H>...)
   {
     return generic_dispatcher<tag::polyval_, Site>();
   }
   template<class... Args>
   struct impl_polyval_;
  }

  /// @overload
  NT2_FUNCTION_IMPLEMENTATION(tag::polyval_, polyval, 2)
  /// @overload
  NT2_FUNCTION_IMPLEMENTATION(tag::polyval_, polyval, 3)
  /// @overload
  NT2_FUNCTION_IMPLEMENTATION(tag::polyval_, polyval, 5)
  /*!
    computes the value of a polynomial p at x
    the polynomial is supposed to be given by an array coefficients
    in decreasing degrees order

    @par Semantic:

    For every polynom p and values x:

    @code
    tie(y, delta) = polyval(p, x, {r, df, normr}{, mu});
    @endcode


    returns the expression evaluating the polynom at all elements of x

    delta is an error estimate available if r, df and normr are provided. These are
    datas that can be generated by @funcref{polyfit}.

    if mu is provided p is evaluated at (x-mu(1))/mu(2) instead of x.

    @see @funcref{polyfit}
    @param a0 mandatory polynomial
    @param a1 mandatory points of evaluations
    @param a2 optional, can be mu or r
    @param a3 optional, mandatory  df if r is given
    @param a4 optional, mandatory normr if r is given
    @param a5 optional, can be mu if r is given

    @return an expression  or a pair of expressions
  **/  NT2_FUNCTION_IMPLEMENTATION(tag::polyval_, polyval, 6)
}

 namespace nt2 { namespace ext
{
  /// INTERNAL ONLY
  template<class Domain, int N, class Expr>
  struct  size_of<tag::polyval_,Domain,N,Expr>
  {
    typedef typename  boost::proto::result_of::child_c<Expr&,1>::value_type::extent_type result_type;

    BOOST_FORCEINLINE result_type operator()(Expr& e) const
    {
      return boost::proto::child_c<1>(e).extent();
    }
  };

  /// INTERNAL ONLY
  template<class Domain, int N, class Expr>
  struct  value_type<tag::polyval_,Domain,N,Expr>
        : meta::value_as<Expr,0>
  {};
} }
#endif
