//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2013   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_LINALG_FUNCTIONS_MAGMA_GEQP3_HPP_INCLUDED
#define NT2_LINALG_FUNCTIONS_MAGMA_GEQP3_HPP_INCLUDED

#if defined(NT2_USE_MAGMA)

#include <nt2/linalg/functions/geqp3.hpp>
#include <nt2/include/functions/xerbla.hpp>
#include <nt2/sdk/magma/magma.hpp>

#include <nt2/dsl/functions/terminal.hpp>
#include <nt2/core/container/table/kind.hpp>
#include <nt2/linalg/details/utility/f77_wrapper.hpp>
#include <nt2/linalg/details/utility/options.hpp>
#include <nt2/linalg/details/utility/workspace.hpp>
#include <nt2/table.hpp>

#include <nt2/include/functions/of_size.hpp>
#include <nt2/include/functions/height.hpp>
#include <nt2/include/functions/width.hpp>
#include <nt2/include/functions/zeros.hpp>

#include <magma.h>

namespace nt2 { namespace ext
{
  /// INTERNAL ONLY - Compute the workspace
  BOOST_DISPATCH_IMPLEMENT  ( geqp3_, nt2::tag::magma_<site>
                            , (A0)(S0)(A1)(S1)(A2)(S2)(site)
                            , ((container_<nt2::tag::table_,  double_<A0>, S0 >))
                              ((container_<nt2::tag::table_,  integer_<A1>, S1 >))
                              ((container_<nt2::tag::table_,  double_<A2>, S2 >))
                            )
  {
     typedef nt2_la_int result_type;

     BOOST_FORCEINLINE result_type operator()(A0& a0, A1& a1, A2& a2) const
     {
        result_type that;
        details::workspace<typename A0::value_type> w;
        nt2_la_int  m  = nt2::height(a0);
        nt2_la_int  n  = nt2::width(a0);
        nt2_la_int  ld = a0.leading_size();
        nt2_la_int lwork_query = -1;

        magma_dgeqp3 ( m, n, 0, ld, 0, 0, w.main()
                            , lwork_query, &that
                            );

          w.prepare_main();
          nt2::geqp3(a0,a1,a2,w);

        return that;
     }
  };

  /// INTERNAL ONLY - Workspace is ready
  BOOST_DISPATCH_IMPLEMENT  ( geqp3_, nt2::tag::magma_<site>
                            , (A0)(S0)(A1)(S1)(A2)(S2)(A3)(site)
                            , ((container_<nt2::tag::table_,  double_<A0>, S0 >))
                              ((container_<nt2::tag::table_,  integer_<A1>, S1 >))
                              ((container_<nt2::tag::table_,  double_<A2>, S2 >))
                             (unspecified_<A3>)
                            )
  {
     typedef nt2_la_int result_type;

     BOOST_FORCEINLINE result_type operator()(A0& a0, A1& a1,A2& a2, A3& a3) const
     {
        result_type that;
        nt2_la_int  m  = nt2::height(a0);
        nt2_la_int  n  = nt2::width(a0);
        nt2_la_int  ld = a0.leading_size();
        nt2_la_int  wn = a3.main_size();

        a2.resize( nt2::of_size(std::min(n, m), 1) );

        magma_dgeqp3 (m, n, a0.data(), ld, a1.data(), a2.data(), a3.main()
                            , wn, &that
                            );
        return that;
     }
  };

  /// INTERNAL ONLY - Compute the workspace
  BOOST_DISPATCH_IMPLEMENT  ( geqp3_, nt2::tag::magma_<site>
                            , (A0)(S0)(A1)(S1)(A2)(S2)(site)
                            , ((container_<nt2::tag::table_,  single_<A0>, S0 >))
                              ((container_<nt2::tag::table_,  integer_<A1>, S1 >))
                              ((container_<nt2::tag::table_,  single_<A2>, S2 >))
                            )
  {
     typedef nt2_la_int result_type;

     BOOST_FORCEINLINE result_type operator()(A0& a0, A1& a1, A2& a2) const
     {
        result_type that;
        details::workspace<typename A0::value_type> w;
        nt2_la_int  m  = nt2::height(a0);
        nt2_la_int  n  = nt2::width(a0);
        nt2_la_int  ld = a0.leading_size();
        nt2_la_int lwork_query = -1;

        magma_sgeqp3 (m, n, 0, ld, 0, 0, w.main()
                            , lwork_query, &that
                            );
          w.prepare_main();
          nt2::geqp3(a0,a1,a2,w);

        return that;
     }
  };

  /// INTERNAL ONLY - Workspace is ready
  BOOST_DISPATCH_IMPLEMENT  ( geqp3_, nt2::tag::magma_<site>
                            , (A0)(S0)(A1)(S1)(A2)(S2)(A3)(site)
                            , ((container_<nt2::tag::table_,  single_<A0>, S0 >))
                              ((container_<nt2::tag::table_,  integer_<A1>, S1 >))
                              ((container_<nt2::tag::table_,  single_<A2>, S2 >))
                             (unspecified_<A3>)
                            )
  {
     typedef nt2_la_int result_type;

     BOOST_FORCEINLINE result_type operator()(A0& a0, A1& a1,A2& a2, A3& a3) const
     {
        result_type that;
        nt2_la_int  m  = nt2::height(a0);
        nt2_la_int  n  = nt2::width(a0);
        nt2_la_int  ld = a0.leading_size();
        nt2_la_int  wn = a3.main_size();

        a2.resize( nt2::of_size(std::min(n, m), 1) );

        magma_sgeqp3 (m, n, a0.data(), ld, a1.data(), a2.data(), a3.main()
                            , wn, &that
                            );
        return that;
     }
  };

//------------------------------------------Complex----------------------------------------//

  /// INTERNAL ONLY - Compute the workspace
  BOOST_DISPATCH_IMPLEMENT  ( geqp3_, nt2::tag::magma_<site>
                            , (A0)(S0)(A1)(S1)(A2)(S2)(site)
                            , ((container_< nt2::tag::table_, complex_<double_<A0> >, S0 >))
                              ((container_< nt2::tag::table_, integer_<A1>, S1 >))
                              ((container_< nt2::tag::table_, complex_<double_<A2> >, S2 >))
                            )
  {
     typedef nt2_la_int result_type;

     BOOST_FORCEINLINE result_type operator()(A0& a0, A1& a1, A2& a2) const
     {
        result_type that;
        details::workspace<typename A0::value_type> w;
        nt2_la_int  m  = nt2::height(a0);
        nt2_la_int  n  = nt2::width(a0);
        nt2_la_int  ld = a0.leading_size();
        nt2_la_int lwork_query = -1;

        magma_zgeqp3(m, n, 0, ld, 0, 0, (cuDoubleComplex*)w.main()
                            , lwork_query, 0, &that
                            );

          w.prepare_main();
          nt2::geqp3(a0,a1,a2,w);

        return that;
     }
  };

  /// INTERNAL ONLY - Workspace is ready
  BOOST_DISPATCH_IMPLEMENT  ( geqp3_, nt2::tag::magma_<site>
                            , (A0)(S0)(A1)(S1)(A2)(S2)(A3)(site)
                            , ((container_< nt2::tag::table_, complex_<double_<A0> >, S0 >))
                              ((container_< nt2::tag::table_, integer_<A1>, S1 >))
                              ((container_< nt2::tag::table_, complex_<double_<A2> >, S2 >))
                             (unspecified_<A3>)
                            )
  {
     typedef nt2_la_int result_type;

     BOOST_FORCEINLINE result_type operator()(A0& a0, A1& a1,A2& a2, A3& a3) const
     {
        result_type that;
        nt2_la_int  m  = nt2::height(a0);
        nt2_la_int  n  = nt2::width(a0);
        nt2_la_int  ld = a0.leading_size();
        nt2_la_int  wn = a3.main_size();

        nt2::container::table<double> rwork(nt2::of_size(2*n,1));
        a2.resize( nt2::of_size(std::min(n, m), 1) );

        magma_zgeqp3(m, n, (cuDoubleComplex*)a0.data(), ld, a1.data(), (cuDoubleComplex*)a2.data()
                    ,(cuDoubleComplex*) a3.main(), wn, rwork.data(), &that
                            );
        return that;
     }
  };

  /// INTERNAL ONLY - Compute the workspace
  BOOST_DISPATCH_IMPLEMENT  ( geqp3_, nt2::tag::magma_<site>
                            , (A0)(S0)(A1)(S1)(A2)(S2)(site)
                            , ((container_< nt2::tag::table_, complex_<single_<A0> >, S0 >))
                              ((container_< nt2::tag::table_, integer_<A1>, S1 >))
                              ((container_< nt2::tag::table_, complex_<single_<A2> >, S2 >))
                            )
  {
     typedef nt2_la_int result_type;

     BOOST_FORCEINLINE result_type operator()(A0& a0, A1& a1, A2& a2) const
     {
        result_type that;
        details::workspace<typename A0::value_type> w;
        nt2_la_int  m  = nt2::height(a0);
        nt2_la_int  n  = nt2::width(a0);
        nt2_la_int  ld = a0.leading_size();
        nt2_la_int lwork_query = -1;

        magma_cgeqp3(m, n, 0, ld, 0, 0, (cuFloatComplex*)w.main()
                            , lwork_query, 0, &that
                            );

          w.prepare_main();
          nt2::geqp3(a0,a1,a2,w);

        return that;
     }
  };

  /// INTERNAL ONLY - Workspace is ready
  BOOST_DISPATCH_IMPLEMENT  ( geqp3_, nt2::tag::magma_<site>
                            , (A0)(S0)(A1)(S1)(A2)(S2)(A3)(site)
                            , ((container_< nt2::tag::table_, complex_<single_<A0> >, S0 >))
                              ((container_< nt2::tag::table_, integer_<A1>, S1 >))
                              ((container_< nt2::tag::table_, complex_<single_<A2> >, S2 >))
                             (unspecified_<A3>)
                            )
  {
     typedef nt2_la_int result_type;

     BOOST_FORCEINLINE result_type operator()(A0& a0, A1& a1,A2& a2, A3& a3) const
     {
        result_type that;
        nt2_la_int  m  = nt2::height(a0);
        nt2_la_int  n  = nt2::width(a0);
        nt2_la_int  ld = a0.leading_size();
        nt2_la_int  wn = a3.main_size();

        nt2::container::table<float> rwork(nt2::of_size(2*n,1));
        a2.resize( nt2::of_size(std::min(n, m), 1) );

        magma_cgeqp3(m, n, (cuFloatComplex*)a0.data(), ld, a1.data(), (cuFloatComplex*)a2.data()
                    , (cuFloatComplex*)a3.main() , wn, rwork.data(), &that
                            );
        return that;
     }
  };
} }

#endif

#endif
