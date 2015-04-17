//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_FUNCTIONS_EXPR_EXTENT_HPP_INCLUDED
#define NT2_CORE_FUNCTIONS_EXPR_EXTENT_HPP_INCLUDED

#include <nt2/core/functions/extent.hpp>
#include <nt2/core/utility/of_size.hpp>
#include <nt2/core/container/dsl/forward.hpp>
#include <boost/fusion/include/transform.hpp>
#include <boost/fusion/include/fold.hpp>
#include <boost/fusion/include/io.hpp>
#include <boost/proto/fusion.hpp>
#include <boost/mpl/long.hpp>
#include <iostream>

namespace nt2 { namespace ext
{
  BOOST_DISPATCH_IMPLEMENT  ( extent_, tag::cpu_
                            , (A)(T)
                            , ((node_ < A, unspecified_<T>
                                      , boost::mpl::long_<0>
                                      , nt2::container::domain
                                      >
                              ))
                            )
  {
    BOOST_DISPATCH_RETURNS(1, (A const& a0),nt2::extent(boost::proto::value(a0)));
  };

  BOOST_DISPATCH_IMPLEMENT( extent_, tag::cpu_
                          , (A)(T)
                          , ((node_<A,elementwise_<T>,boost::mpl::long_<1>,nt2::container::domain>))
                          )
  {
    BOOST_DISPATCH_RETURNS(1, (A const& a0), nt2::extent(boost::proto::child_c<0>(a0)));
  };

  BOOST_DISPATCH_IMPLEMENT( extent_, tag::cpu_
                          , (A)(T)
                          , ((node_<A,elementwise_<T>,boost::mpl::long_<2>,nt2::container::domain>))
                          )
  {
    // TODO: [C++14] Remove this and use polymorphic lambda
    struct get_extent
    {
      template<typename X> BOOST_FORCEINLINE auto operator()(X const& x) const -> decltype(x.extent())
      {
        return x.extent();
      }
    };

    // TODO: [C++14] Remove this and use polymorphic lambda
    struct size_fold
    {
      template<typename A0, typename A1, typename Dummy = void>
      struct select;

/*      template<typename Sig>
      struct result;

      template<typename This, typename A0, typename A1>
      struct result<This(A0, A1)>
      {
        typedef typename
        select< typename meta::strip<A0>::type
              , typename meta::strip<A1>::type
              >::type type;
      };*/

      template<typename A1, typename Dummy>
      struct select<_0D, A1, Dummy>
      {
        typedef A1 type;
      };
      template<typename A1>
      BOOST_FORCEINLINE
      //typename result<size_fold(_0D const&, A1 const&)>::type
      A1 const& operator()(_0D const&, A1 const& a1) const
      {
        return a1;
      }

      template<typename A0, typename Dummy>
      struct select<A0, _0D, Dummy>
      {
        typedef A0 type;
      };
      template<typename A0>
      BOOST_FORCEINLINE
      A0 const&
      //typename result<size_fold(A0 const&, _0D const&)>::type
      operator()(A0 const& a0, _0D const&) const
      {
        return a0;
      }

      template<typename Dummy>
      struct select<_0D, _0D, Dummy>
      {
        typedef _0D type;
      };

      BOOST_FORCEINLINE
      //typename result<size_fold(_0D const&, _0D const&)>::type
      _0D operator()(_0D const& a0, _0D const&) const
      {
        return a0;
      }

      template<typename A0, typename A1, typename Dummy>
      struct select
      {
        typedef typename
        boost::mpl::if_c< A0::static_status,A0,A1>::type type;
      };

      template<typename A0, typename A1> BOOST_FORCEINLINE
      typename result<size_fold(A0 const&, A1 const&)>::type
      operator()(A0 const& a0, A1 const& a1) const
      {
        //BOOST_ASSERT_MSG(a0 == a1, "Sizes are not compatible");
        return selection(a0,a1,boost::mpl::bool_<A0::static_status>());
      }

      template<typename A0, typename A1> BOOST_FORCEINLINE
      typename result<size_fold(A0 const&, A1 const&)>::type
      selection(A0 const& a0, A1 const&, boost::mpl::true_ const&) const
      {
        return a0;
      }

      template<typename A0, typename A1> BOOST_FORCEINLINE
      typename result<size_fold(A0 const&, A1 const&)>::type
      selection(A0 const&, A1 const& a1, boost::mpl::false_ const&) const
      {
        return a1;
      }
    };

   BOOST_DISPATCH_RETURNS ( 1, (A const& a0)
                          , boost::fusion
                                 ::fold ( boost::fusion::transform(a0,get_extent{})
                                        , nt2::extent(boost::proto::child_c<0>(a0))
                                        , size_fold{}
                                        )
                          );
  };
/*
  BOOST_DISPATCH_IMPLEMENT  ( extent_, tag::cpu_
                            , (A0)
                            , ((ast_<A0, nt2::container::domain>))
                            )
  {
    //typedef typename A0::extent_type const& result_type;
    typedef _0D result_type;

    BOOST_FORCEINLINE _0D operator()(const A0& a0) const
    {
      return _0D{};//a0.extent();
    }
  };*/
} }

#endif
