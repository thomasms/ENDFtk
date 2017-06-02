#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "ENDFtk.hpp"

using namespace njoy::ENDFtk;

std::function< UnivariateTabulation() > makeTAB1 = [](){
  auto metadata = std::make_tuple( 1.0, 2.0, 3ul, 4ul );
  auto regionPairs = std::make_tuple( std::vector< long >{ 4, 5, 6 },
				      std::vector< long >{ 1, 2, 3 } );
  auto orderedPairs =
    std::make_tuple( std::vector< double >{ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 },
                     std::vector< double >{ 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 } );
  
  return UnivariateTabulation
  ( std::get< 0 >( metadata ), std::get< 1 >( metadata ),
    std::get< 2 >( metadata ), std::get< 3 >( metadata ),
    njoy::utility::copy( regionPairs ), njoy::utility::copy( orderedPairs ) );
};

SCENARIO( "UnivariateTabulation ctor",
          "[ENDFtk], [UnivariateTabulation]" ){

  UnivariateTabulation::Base metadata{ 1.0, 2.0, 3ul, 4ul, 3, 6 };

  std::vector< long > regions{ 4, 5, 6 };
  std::vector< long > interpolation{ 1, 2, 3 };
  std::vector< double > x{ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 };
  std::vector< double > y{ 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 };
  
  UnivariateTabulation tab1( njoy::utility::copy( metadata ),
			     std::make_tuple( regions, interpolation ),
			     std::make_tuple( x, y ) );

  THEN( "TAB1 objects can be copied" ){ auto copy = tab1; }
  
  GIVEN( "mismatched x and y lengths" ){
    std::vector< double > x{ 1.0, 2.0, 3.0, 4.0, 5.0 };
    
    REQUIRE_THROWS( UnivariateTabulation
		    ( njoy::utility::copy( metadata ),
		      std::make_tuple( regions, interpolation ),
		      std::make_tuple( x, y ) ) );
  }

  GIVEN( "out of order x values" ){
    std::vector< double > x{ 1.0, 3.0, 2.0, 4.0, 5.0 };

    REQUIRE_THROWS( UnivariateTabulation
		    ( njoy::utility::copy( metadata ),
		      std::make_tuple( regions, interpolation ),
		      std::make_tuple( x, y ) ) );
  }

  GIVEN( "mismatched region and interpolation arrays" ){
    std::vector< long > interpolation{ 1, 2, 3, 4 };

    REQUIRE_THROWS( UnivariateTabulation
		    ( njoy::utility::copy( metadata ),
		      std::make_tuple( regions, interpolation ),
		      std::make_tuple( x, y ) ) );
  }
  
  GIVEN( "out of order region" ){
    std::vector< long > regions{ 5, 4, 6 };

    REQUIRE_THROWS( UnivariateTabulation
		    ( njoy::utility::copy( metadata ),
		      std::make_tuple( regions, interpolation ),
		      std::make_tuple( x, y ) ) );
  }

  {
    std::string tab1 = 
      " 0.000000+0 0.000000+0         33          0          1          49228 1460  438\n"
      "          4          4                                            9228 1460  439\n"
      " 1.000000+1 1.725000+1 1.500000+1 1.850000+1 1.900000+1 1.975000+09228 1460  440\n"
      " 2.700000+1 1.605000+1                                            9228 1460  441\n";
    {
      auto begin = tab1.begin();
      auto end = tab1.end();
      auto lineNumber = 438l;
      int MAT = 9228;
      int MF = 1;
      int MT = 460;
    
      UnivariateTabulation tab1_1( begin, end, lineNumber, MAT, MF, MT );
      REQUIRE( tab1_1.NR() == 1 );
      REQUIRE( tab1_1.NP() == 4 );

    } {
      auto begin = tab1.begin();
      auto end = tab1.end();
      auto lineNumber = 438l;
      int MF = 1;
      int MT = 460;
      REQUIRE_THROWS( UnivariateTabulation( begin, end, lineNumber, 9225, MF, MT ) );
    }
  }
  /*
  {
    std::string tab1 = 
      " 0.000000+0 0.000000+0         33          0         -1          49228 1460  438\n"
      "          4          4                                            9228 1460  439\n"
      " 1.000000+1 1.725000+1 1.500000+1 1.850000+1 1.900000+1 1.975000+09228 1460  440\n"
      " 2.700000+1 1.605000+1                                            9228 1460  441\n";
    auto begin = tab1.begin();
    auto end = tab1.end();
    auto lineNumber = 438l;
    int MAT = 9228;
    int MF = 1;
    int MT = 460;
   
    REQUIRE_THROWS( UnivariateTabulation( begin, end, lineNumber, MAT, MF, MT ) );
  }
  */
  {
    {
      std::string tab1 = 
	" 0.000000+0 0.000000+0         33          0          1         -19228 1460  438\n"
	"          4          4                                            9228 1460  439\n"
	" 1.000000+1 1.725000+1 1.500000+1 1.850000+1 1.900000+1 1.975000+09228 1460  440\n"
	" 2.700000+1 1.605000+1                                            9228 1460  441\n";
      auto begin = tab1.begin();
      auto end = tab1.end();
      auto lineNumber = 438l;
      int MAT = 9228;
      int MF = 1;
      int MT = 460;
   
      REQUIRE_THROWS( UnivariateTabulation( begin, end, lineNumber, MAT, MF, MT ) );
    }
    {
      std::string tab1 = 
	" 0.000000+0 0.000000+0         33          0          1          49228 1460  438\n"
	"          4          4                                            9228 1460  439\n"
	" 1.000000+1 1.725000+1 1.500000+1 1.850000+1 1.400000+1 1.975000+09228 1460  440\n"
	" 2.700000+1 1.605000+1                                            9228 1460  441\n";
      auto begin = tab1.begin();
      auto end = tab1.end();
      auto lineNumber = 438l;
      int MAT = 9228;
      int MF = 1;
      int MT = 460;
   
      REQUIRE_THROWS( UnivariateTabulation( begin, end, lineNumber, MAT, MF, MT ) );
    }
    {
      std::string tab1 = 
	" 0.000000+0 0.000000+0         33          0          2          49228 1460  438\n"
	"          4          4          2          1                      9228 1460  439\n"
	" 1.000000+1 1.725000+1 1.500000+1 1.850000+1 1.400000+1 1.975000+09228 1460  440\n"
	" 2.700000+1 1.605000+1                                            9228 1460  441\n";
      auto begin = tab1.begin();
      auto end = tab1.end();
      auto lineNumber = 438l;
      int MAT = 9228;
      int MF = 1;
      int MT = 460;
   
      REQUIRE_THROWS( UnivariateTabulation( begin, end, lineNumber, MAT, MF, MT ) );
    }
  }
}