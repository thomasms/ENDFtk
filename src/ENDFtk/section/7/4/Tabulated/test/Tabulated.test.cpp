#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "ENDFtk.hpp"

using namespace njoy::ENDFtk;

// convenience typedefs
using Tabulated = 
section::Type< 7, 4 >::Tabulated;

std::string chunkWithOnlyPrincipalScatterer();
std::string chunkWithBothPrincipalAndSecondaryScatterer();
std::string invalidSize();

/*SCENARIO( "Tabulated" ) {

  GIVEN( "valid data for a Tabulated with only a principal "
         "scatterer" ) {

    int lln = 0;
    int ns = 0;
    std::vector< double > values = { 6.153875e+0, 1.976285e+2, 8.934780e+0,
                                     5.000001e+0, 0.000000e+0, 1.000000e+0 };
    double epsilon = 1.976285e+2;
    double emax = 5.000001e+0;
    std::vector< double > crossSections = { 6.153875e+0 };
    std::vector< double > weightRatios = { 8.934780e+0 };
    std::vector< unsigned int > numberAtoms = { 1 };
    std::vector< unsigned int > functionTypes = {};
    double crossSection = 6.153875e+0;
    double weightRatio = 8.934780e+0;
    unsigned int numberAtom = 1;

    THEN( "a Tabulated can "
          "be constructed using a list and members can be tested" ) {
      Tabulated chunk( lln, ns, std::move( values ) );

      REQUIRE( 0 == chunk.LLN() );
      REQUIRE( 6 == chunk.NI() );
      REQUIRE( 0 == chunk.NS() );

      REQUIRE( 1.976285e+2 == Approx( chunk.epsilon() ) );
      REQUIRE( 5.000001e+0 == Approx( chunk.upperEnergyLimit() ) );
      REQUIRE( 1 == chunk.totalFreeCrossSections().size() );
      REQUIRE( 6.153875e+0 == Approx( chunk.totalFreeCrossSections()[0] ) );
      REQUIRE( 1 == chunk.atomicWeightRatios().size() );
      REQUIRE( 8.934780e+0 == Approx( chunk.atomicWeightRatios()[0] ) );
      REQUIRE( 1 == chunk.numberAtoms().size() );
      REQUIRE( 1. == Approx( chunk.numberAtoms()[0] ) );
      REQUIRE( 0 == chunk.analyticalFunctionTypes().size() );

      REQUIRE( 2 == chunk.NC() );
    }

    THEN( "a Tabulated can "
          "be constructed using separate arrays and members can be tested" ) {
      Tabulated chunk( lln, ns, epsilon, emax,
                                    std::move( crossSections ),
                                    std::move( weightRatios ),
                                    std::move( numberAtoms ),
                                    std::move( functionTypes ) );

      REQUIRE( 0 == chunk.LLN() );
      REQUIRE( 6 == chunk.NI() );
      REQUIRE( 0 == chunk.NS() );

      REQUIRE( 1.976285e+2 == Approx( chunk.epsilon() ) );
      REQUIRE( 5.000001e+0 == Approx( chunk.upperEnergyLimit() ) );
      REQUIRE( 1 == chunk.totalFreeCrossSections().size() );
      REQUIRE( 6.153875e+0 == Approx( chunk.totalFreeCrossSections()[0] ) );
      REQUIRE( 1 == chunk.atomicWeightRatios().size() );
      REQUIRE( 8.934780e+0 == Approx( chunk.atomicWeightRatios()[0] ) );
      REQUIRE( 1 == chunk.numberAtoms().size() );
      REQUIRE( 1. == Approx( chunk.numberAtoms()[0] ) );
      REQUIRE( 0 == chunk.analyticalFunctionTypes().size() );

      REQUIRE( 2 == chunk.NC() );
    }

    THEN( "a Tabulated can "
          "be constructed using individual values and members can be tested" ) {
      Tabulated chunk( lln, epsilon, emax, crossSection,
                                    weightRatio, numberAtom );

      REQUIRE( 0 == chunk.LLN() );
      REQUIRE( 6 == chunk.NI() );
      REQUIRE( 0 == chunk.NS() );

      REQUIRE( 1.976285e+2 == Approx( chunk.epsilon() ) );
      REQUIRE( 5.000001e+0 == Approx( chunk.upperEnergyLimit() ) );
      REQUIRE( 1 == chunk.totalFreeCrossSections().size() );
      REQUIRE( 6.153875e+0 == Approx( chunk.totalFreeCrossSections()[0] ) );
      REQUIRE( 1 == chunk.atomicWeightRatios().size() );
      REQUIRE( 8.934780e+0 == Approx( chunk.atomicWeightRatios()[0] ) );
      REQUIRE( 1 == chunk.numberAtoms().size() );
      REQUIRE( 1. == Approx( chunk.numberAtoms()[0] ) );
      REQUIRE( 0 == chunk.analyticalFunctionTypes().size() );

      REQUIRE( 2 == chunk.NC() );
    }
  } // GIVEN

  GIVEN( "a string representation of a valid Tabulated with "
         "only a principal scatterer" ) {

    std::string string = chunkWithOnlyPrincipalScatterer();
    auto begin = string.begin();
    auto end = string.end();
    long lineNumber = 1;

    THEN( "a Tabulated can "
          "be constructed and members can be tested" ) {
      Tabulated chunk( begin, end, lineNumber, 27, 7, 4 );

      REQUIRE( 0 == chunk.LLN() );
      REQUIRE( 6 == chunk.NI() );
      REQUIRE( 0 == chunk.NS() );

      REQUIRE( 1.976285e+2 == Approx( chunk.epsilon() ) );
      REQUIRE( 5.000001e+0 == Approx( chunk.upperEnergyLimit() ) );
      REQUIRE( 1 == chunk.totalFreeCrossSections().size() );
      REQUIRE( 6.153875e+0 == Approx( chunk.totalFreeCrossSections()[0] ) );
      REQUIRE( 1 == chunk.atomicWeightRatios().size() );
      REQUIRE( 8.934780e+0 == Approx( chunk.atomicWeightRatios()[0] ) );
      REQUIRE( 1 == chunk.numberAtoms().size() );
      REQUIRE( 1. == Approx( chunk.numberAtoms()[0] ) );
      REQUIRE( 0 == chunk.analyticalFunctionTypes().size() );

      REQUIRE( 2 == chunk.NC() );
    }
  } // GIVEN

  GIVEN( "valid data for a Tabulated with both principal and "
         "secondary scatterers" ) {

    int lln = 0;
    int ns = 1;
    std::vector< double > values = { 2.021000e+0, 9.750000e+1, 2.784423e+1,
                                     2.466750e+0, 0.000000e+0, 1.000000e+0,
                                     0.000000e+0, 3.748750e+0, 1.586200e+1,
                                     0.000000e+0, 0.000000e+0, 2.000000e+0 };
    double epsilon = 9.750000e+1;
    double emax = 2.466750e+0;
    std::vector< double > crossSections = { 2.021000e+0, 3.748750e+0 };
    std::vector< double > weightRatios = { 2.784423e+1, 1.586200e+1 };
    std::vector< unsigned int > numberAtoms = { 1, 2 };
    std::vector< unsigned int > functionTypes = { 0 };

    THEN( "a Tabulated can "
          "be constructed using a list and members can be tested" ) {
      Tabulated chunk( lln, ns, std::move( values ) );

      REQUIRE( 0 == chunk.LLN() );
      REQUIRE( 12 == chunk.NI() );
      REQUIRE( 1 == chunk.NS() );

      REQUIRE( 9.750000e+1 == Approx( chunk.epsilon() ) );
      REQUIRE( 2.466750e+0 == Approx( chunk.upperEnergyLimit() ) );
      REQUIRE( 2 == chunk.totalFreeCrossSections().size() );
      REQUIRE( 2.021000e+0 == Approx( chunk.totalFreeCrossSections()[0] ) );
      REQUIRE( 3.748750e+0 == Approx( chunk.totalFreeCrossSections()[1] ) );
      REQUIRE( 2 == chunk.atomicWeightRatios().size() );
      REQUIRE( 2.784423e+1 == Approx( chunk.atomicWeightRatios()[0] ) );
      REQUIRE( 1.586200e+1 == Approx( chunk.atomicWeightRatios()[1] ) );
      REQUIRE( 2 == chunk.numberAtoms().size() );
      REQUIRE( 1. == Approx( chunk.numberAtoms()[0] ) );
      REQUIRE( 2. == Approx( chunk.numberAtoms()[1] ) );
      REQUIRE( 1 == chunk.analyticalFunctionTypes().size() );
      REQUIRE( 0. == chunk.analyticalFunctionTypes()[0] );

      REQUIRE( 3 == chunk.NC() );
    }

    THEN( "a Tabulated can "
          "be constructed using separate arrays and members can be tested" ) {
      Tabulated chunk( lln, ns, epsilon, emax,
                                    std::move( crossSections ),
                                    std::move( weightRatios ),
                                    std::move( numberAtoms ),
                                    std::move( functionTypes ) );

      REQUIRE( 0 == chunk.LLN() );
      REQUIRE( 12 == chunk.NI() );
      REQUIRE( 1 == chunk.NS() );

      REQUIRE( 9.750000e+1 == Approx( chunk.epsilon() ) );
      REQUIRE( 2.466750e+0 == Approx( chunk.upperEnergyLimit() ) );
      REQUIRE( 2 == chunk.totalFreeCrossSections().size() );
      REQUIRE( 2.021000e+0 == Approx( chunk.totalFreeCrossSections()[0] ) );
      REQUIRE( 3.748750e+0 == Approx( chunk.totalFreeCrossSections()[1] ) );
      REQUIRE( 2 == chunk.atomicWeightRatios().size() );
      REQUIRE( 2.784423e+1 == Approx( chunk.atomicWeightRatios()[0] ) );
      REQUIRE( 1.586200e+1 == Approx( chunk.atomicWeightRatios()[1] ) );
      REQUIRE( 2 == chunk.numberAtoms().size() );
      REQUIRE( 1. == Approx( chunk.numberAtoms()[0] ) );
      REQUIRE( 2. == Approx( chunk.numberAtoms()[1] ) );
      REQUIRE( 1 == chunk.analyticalFunctionTypes().size() );
      REQUIRE( 0. == chunk.analyticalFunctionTypes()[0] );

      REQUIRE( 3 == chunk.NC() );
    }
  } // GIVEN

  GIVEN( "a string representation of a valid Tabulated with both "
         "principal and secondary scatterers" ) {

    std::string string = chunkWithBothPrincipalAndSecondaryScatterer();
    auto begin = string.begin();
    auto end = string.end();
    long lineNumber = 1;

    THEN( "a Tabulated can "
          "be constructed and members can be tested" ) {
      Tabulated chunk( begin, end, lineNumber, 27, 7, 4 );

      REQUIRE( 0 == chunk.LLN() );
      REQUIRE( 12 == chunk.NI() );
      REQUIRE( 1 == chunk.NS() );

      REQUIRE( 9.750000e+1 == Approx( chunk.epsilon() ) );
      REQUIRE( 2.466750e+0 == Approx( chunk.upperEnergyLimit() ) );
      REQUIRE( 2 == chunk.totalFreeCrossSections().size() );
      REQUIRE( 2.021000e+0 == Approx( chunk.totalFreeCrossSections()[0] ) );
      REQUIRE( 3.748750e+0 == Approx( chunk.totalFreeCrossSections()[1] ) );
      REQUIRE( 2 == chunk.atomicWeightRatios().size() );
      REQUIRE( 2.784423e+1 == Approx( chunk.atomicWeightRatios()[0] ) );
      REQUIRE( 1.586200e+1 == Approx( chunk.atomicWeightRatios()[1] ) );
      REQUIRE( 2 == chunk.numberAtoms().size() );
      REQUIRE( 1. == Approx( chunk.numberAtoms()[0] ) );
      REQUIRE( 2. == Approx( chunk.numberAtoms()[1] ) );
      REQUIRE( 1 == chunk.analyticalFunctionTypes().size() );
      REQUIRE( 0. == chunk.analyticalFunctionTypes()[0] );

      REQUIRE( 3 == chunk.NC() );
    }
  } // GIVEN

  GIVEN( "data with inconsistent sizes" ) {

    int lln = 0;
    int ns = 0;
    double epsilon = 1.976285e+2;
    double emax = 5.000001e+0;
    std::vector< double > crossSections = { 6.153875e+0 };
    std::vector< double > weightRatios = { 8.934780e+0 };
    std::vector< unsigned int > numberAtoms = { 1 };
    std::vector< unsigned int > functionTypes = {};

    THEN( "an exception is thrown" ) {

      REQUIRE_THROWS( Tabulated( lln, ns, epsilon, emax,
                                              {},
                                              std::move( weightRatios ),
                                              std::move( numberAtoms ),
                                              std::move( functionTypes ) ) );
      REQUIRE_THROWS( Tabulated( lln, ns, epsilon, emax,
                                              std::move( crossSections ),
                                              {},
                                              std::move( numberAtoms ),
                                              std::move( functionTypes ) ) );
      REQUIRE_THROWS( Tabulated( lln, ns, epsilon, emax,
                                              std::move( crossSections ),
                                              std::move( weightRatios ),
                                              {},
                                              std::move( functionTypes ) ) );
      REQUIRE_THROWS( Tabulated( lln, ns, epsilon, emax,
                                              std::move( crossSections ),
                                              std::move( weightRatios ),
                                              std::move( numberAtoms ),
                                              { 1 } ) );
    }
  } // GIVEN

  GIVEN( "data with inconsistent NI and NS" ) {

    int lln = 0;
    int ns = 0;
    std::vector< double > values = { 6.153875e+0, 1.976285e+2, 8.934780e+0,
                                     5.000001e+0, 0.000000e+0, 1.000000e+0 };

    THEN( "an exception is thrown" ) {

      REQUIRE_THROWS( Tabulated( lln, 1, std::move( values ) ) );
    }
  } // GIVEN

  GIVEN( "a string with inconsistent NI and NS" ) {

    std::string string = invalidSize();
    auto begin = string.begin();
    auto end = string.end();
    long lineNumber = 1;

    THEN( "an exception is thrown" ) {

      REQUIRE_THROWS( Tabulated( begin, end, lineNumber,
                                              27, 7, 4 ) );
    }
  } // GIVEN

  GIVEN( "a valid instance of Tabulated with only a principal "
         "scatterer" ) {

    std::string string = chunkWithOnlyPrincipalScatterer();
    auto begin = string.begin();
    auto end = string.end();
    long lineNumber = 1;
    Tabulated chunk(begin, end, lineNumber, 27, 7, 4 );

    THEN( "it can be printed" ) {
      std::string buffer;
      auto output = std::back_inserter( buffer );
      chunk.print( output, 27, 7, 4 );
      REQUIRE( buffer == string );
    }
  } // GIVEN

  GIVEN( "a valid instance of Tabulated with both principal "
         "and secondary scatterers" ) {

    std::string string = chunkWithBothPrincipalAndSecondaryScatterer();
    auto begin = string.begin();
    auto end = string.end();
    long lineNumber = 1;
    Tabulated chunk(begin, end, lineNumber, 27, 7, 4 );

    THEN( "it can be printed" ) {
      std::string buffer;
      auto output = std::back_inserter( buffer );
      chunk.print( output, 27, 7, 4 );
      REQUIRE( buffer == string );
    }
  } // GIVEN

  GIVEN( "a string representation of a valid Tabulated with "
         "only a principal scatterer" ) {

    std::string string = chunkWithOnlyPrincipalScatterer();
    auto begin = string.begin();
    auto end = string.end();
    long lineNumber = 1;

    THEN( "a Tabulated can "
          "be constructed and members can be tested" ) {
      Tabulated chunk( begin, end, lineNumber, 27, 7, 4 );

      REQUIRE( 0 == chunk.LLN() );
      REQUIRE( 6 == chunk.NI() );
      REQUIRE( 0 == chunk.NS() );

      REQUIRE( 1.976285e+2 == Approx( chunk.epsilon() ) );
      REQUIRE( 5.000001e+0 == Approx( chunk.upperEnergyLimit() ) );
      REQUIRE( 1 == chunk.totalFreeCrossSections().size() );
      REQUIRE( 6.153875e+0 == Approx( chunk.totalFreeCrossSections()[0] ) );
      REQUIRE( 1 == chunk.atomicWeightRatios().size() );
      REQUIRE( 8.934780e+0 == Approx( chunk.atomicWeightRatios()[0] ) );
      REQUIRE( 1 == chunk.numberAtoms().size() );
      REQUIRE( 1. == Approx( chunk.numberAtoms()[0] ) );
      REQUIRE( 0 == chunk.analyticalFunctionTypes().size() );

      REQUIRE( 2 == chunk.NC() );
    }
  } // GIVEN

  GIVEN( "valid data for a Tabulated with both principal and "
         "secondary scatterers" ) {

    int lln = 0;
    int ns = 1;
    std::vector< double > values = { 2.021000e+0, 9.750000e+1, 2.784423e+1,
                                     2.466750e+0, 0.000000e+0, 1.000000e+0,
                                     0.000000e+0, 3.748750e+0, 1.586200e+1,
                                     0.000000e+0, 0.000000e+0, 2.000000e+0 };
    double epsilon = 9.750000e+1;
    double emax = 2.466750e+0;
    std::vector< double > crossSections = { 2.021000e+0, 3.748750e+0 };
    std::vector< double > weightRatios = { 2.784423e+1, 1.586200e+1 };
    std::vector< unsigned int > numberAtoms = { 1, 2 };
    std::vector< unsigned int > functionTypes = { 0 };

    THEN( "a Tabulated can "
          "be constructed using a list and members can be tested" ) {
      Tabulated chunk( lln, ns, std::move( values ) );

      REQUIRE( 0 == chunk.LLN() );
      REQUIRE( 12 == chunk.NI() );
      REQUIRE( 1 == chunk.NS() );

      REQUIRE( 9.750000e+1 == Approx( chunk.epsilon() ) );
      REQUIRE( 2.466750e+0 == Approx( chunk.upperEnergyLimit() ) );
      REQUIRE( 2 == chunk.totalFreeCrossSections().size() );
      REQUIRE( 2.021000e+0 == Approx( chunk.totalFreeCrossSections()[0] ) );
      REQUIRE( 3.748750e+0 == Approx( chunk.totalFreeCrossSections()[1] ) );
      REQUIRE( 2 == chunk.atomicWeightRatios().size() );
      REQUIRE( 2.784423e+1 == Approx( chunk.atomicWeightRatios()[0] ) );
      REQUIRE( 1.586200e+1 == Approx( chunk.atomicWeightRatios()[1] ) );
      REQUIRE( 2 == chunk.numberAtoms().size() );
      REQUIRE( 1. == Approx( chunk.numberAtoms()[0] ) );
      REQUIRE( 2. == Approx( chunk.numberAtoms()[1] ) );
      REQUIRE( 1 == chunk.analyticalFunctionTypes().size() );
      REQUIRE( 0. == chunk.analyticalFunctionTypes()[0] );

      REQUIRE( 3 == chunk.NC() );
    }

    THEN( "a Tabulated can "
          "be constructed using separate arrays and members can be tested" ) {
      Tabulated chunk( lln, ns, epsilon, emax,
                                    std::move( crossSections ),
                                    std::move( weightRatios ),
                                    std::move( numberAtoms ),
                                    std::move( functionTypes ) );

      REQUIRE( 0 == chunk.LLN() );
      REQUIRE( 12 == chunk.NI() );
      REQUIRE( 1 == chunk.NS() );

      REQUIRE( 9.750000e+1 == Approx( chunk.epsilon() ) );
      REQUIRE( 2.466750e+0 == Approx( chunk.upperEnergyLimit() ) );
      REQUIRE( 2 == chunk.totalFreeCrossSections().size() );
      REQUIRE( 2.021000e+0 == Approx( chunk.totalFreeCrossSections()[0] ) );
      REQUIRE( 3.748750e+0 == Approx( chunk.totalFreeCrossSections()[1] ) );
      REQUIRE( 2 == chunk.atomicWeightRatios().size() );
      REQUIRE( 2.784423e+1 == Approx( chunk.atomicWeightRatios()[0] ) );
      REQUIRE( 1.586200e+1 == Approx( chunk.atomicWeightRatios()[1] ) );
      REQUIRE( 2 == chunk.numberAtoms().size() );
      REQUIRE( 1. == Approx( chunk.numberAtoms()[0] ) );
      REQUIRE( 2. == Approx( chunk.numberAtoms()[1] ) );
      REQUIRE( 1 == chunk.analyticalFunctionTypes().size() );
      REQUIRE( 0. == chunk.analyticalFunctionTypes()[0] );

      REQUIRE( 3 == chunk.NC() );
    }
  } // GIVEN

  GIVEN( "a string representation of a valid Tabulated with both "
         "principal and secondary scatterers" ) {

    std::string string = chunkWithBothPrincipalAndSecondaryScatterer();
    auto begin = string.begin();
    auto end = string.end();
    long lineNumber = 1;

    THEN( "a Tabulated can "
          "be constructed and members can be tested" ) {
      Tabulated chunk( begin, end, lineNumber, 27, 7, 4 );

      REQUIRE( 0 == chunk.LLN() );
      REQUIRE( 12 == chunk.NI() );
      REQUIRE( 1 == chunk.NS() );

      REQUIRE( 9.750000e+1 == Approx( chunk.epsilon() ) );
      REQUIRE( 2.466750e+0 == Approx( chunk.upperEnergyLimit() ) );
      REQUIRE( 2 == chunk.totalFreeCrossSections().size() );
      REQUIRE( 2.021000e+0 == Approx( chunk.totalFreeCrossSections()[0] ) );
      REQUIRE( 3.748750e+0 == Approx( chunk.totalFreeCrossSections()[1] ) );
      REQUIRE( 2 == chunk.atomicWeightRatios().size() );
      REQUIRE( 2.784423e+1 == Approx( chunk.atomicWeightRatios()[0] ) );
      REQUIRE( 1.586200e+1 == Approx( chunk.atomicWeightRatios()[1] ) );
      REQUIRE( 2 == chunk.numberAtoms().size() );
      REQUIRE( 1. == Approx( chunk.numberAtoms()[0] ) );
      REQUIRE( 2. == Approx( chunk.numberAtoms()[1] ) );
      REQUIRE( 1 == chunk.analyticalFunctionTypes().size() );
      REQUIRE( 0. == chunk.analyticalFunctionTypes()[0] );

      REQUIRE( 3 == chunk.NC() );
    }
  } // GIVEN
} // SCENARIO
*/
std::string chunkWithOnlyPrincipalScatterer() {
  return
    " 0.000000+0 0.000000+0          0          0          6          0  27 7  4     \n"
    " 6.153875+0 1.976285+2 8.934780+0 5.000001+0 0.000000+0 1.000000+0  27 7  4     \n";
}

std::string chunkWithBothPrincipalAndSecondaryScatterer() {
  return
    " 0.000000+0 0.000000+0          0          0         12          1  27 7  4     \n"
    " 2.021000+0 9.750000+1 2.784423+1 2.466750+0 0.000000+0 1.000000+0  27 7  4     \n"
    " 0.000000+0 3.748750+0 1.586200+1 0.000000+0 0.000000+0 2.000000+0  27 7  4     \n";
}

std::string invalidSize() {
  return
    " 0.000000+0 0.000000+0          0          0         12          0  27 7  4     \n"
    " 2.021000+0 9.750000+1 2.784423+1 2.466750+0 0.000000+0 1.000000+0  27 7  4     \n"
    " 0.000000+0 3.748750+0 1.586200+1 0.000000+0 0.000000+0 2.000000+0  27 7  4     \n";
}
