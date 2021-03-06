#include <iostream>
#include <nt2/table.hpp>
#include <nt2/include/functions/cic.hpp>
#include <nt2/core/numeric_class.hpp>

int main()
{
  nt2::table<double> I;

  // Creates a @c 4x4 column indices matrix.
  I = nt2::cic(4);
  NT2_DISPLAY(I);

  // Create a 2-by-3 column indices matrix.
  I = nt2::cic(2,3);
  NT2_DISPLAY(I);

  // Create a 3-by-1 column indices vector.
  I = nt2::cic( nt2::of_size(3,1) );
  NT2_DISPLAY(I);

  // Create a 3-by-3 column indices matrix whose elements are 32-bit
  nt2::table<unsigned int> U;
  U = nt2::cic( 3, nt2::uint32_ );
  NT2_DISPLAY(U);
}
