#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "ENDFtk/section/32/151.hpp"

// other includes

// convenience typedefs
using namespace njoy::ENDFtk;
using ResonanceChannels =
section::Type< 32, 151 >::CompactRMatrixLimitedUncertainties::ResonanceChannels;
using ResonanceParameters =
section::Type< 32, 151 >::CompactRMatrixLimitedUncertainties::ResonanceParameters;
using SpinGroup =
section::Type< 32, 151 >::CompactRMatrixLimitedUncertainties::SpinGroup;

std::string chunk();
void verifyChunk( const SpinGroup& );

SCENARIO( "SpinGroup" ) {

  GIVEN( "valid data for a SpinGroup" ) {

    std::string string = chunk();

    WHEN( "the data is given explicitly" ) {

      ResonanceChannels channels =
        { 0.5, 0., { 1, 2 }, { 0, 0 }, { 0., 0.5 }, { 0., 0. },
          { 0.,  0.54373 }, { 0.,  0.54373 } };
      ResonanceParameters parameters =
        { { -1.223300e+6, 7.788000e+3 },
          { { 1., 9.611086e+5 }, { 1.455, 1.187354e+3 } },
          { 2., 3. },
          { { 4., 5. }, { 6., 7. } } };

      SpinGroup chunk( std::move( channels ), std::move( parameters ) );

      THEN( "a SpinGroup can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN

      THEN( "it can be printed" ) {

        std::string buffer;
        auto output = std::back_inserter( buffer );
        chunk.print( output, 2625, 32, 151 );

        CHECK( buffer == string );
      } // THEN
    } // WHEN

    WHEN( "the data is read from a string/stream" ) {

      auto begin = string.begin();
      auto end = string.end();
      long lineNumber = 1;

      SpinGroup chunk( begin, end, lineNumber, 2625, 32, 151 );

      THEN( "a SpinGroup can be constructed and members can be "
            "tested" ) {

        verifyChunk( chunk );
      }

      THEN( "it can be printed" ) {

        std::string buffer;
        auto output = std::back_inserter( buffer );
        chunk.print( output, 2625, 32, 151 );

        CHECK( buffer == string );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

std::string chunk() {
  return
    " 5.000000-1 0.000000+0          0          0         12          2262532151     \n"
    " 1.000000+0 0.000000+0 0.000000+0 0.000000+0 0.000000+0 0.000000+0262532151     \n"
    " 2.000000+0 0.000000+0 5.000000-1 0.000000+0 5.437300-1 5.437300-1262532151     \n"
    " 0.000000+0 0.000000+0          0          2         24          2262532151     \n"
    "-1.223300+6 1.000000+0 9.611086+5 0.000000+0 0.000000+0 0.000000+0262532151     \n"
    " 2.000000+0 4.000000+0 5.000000+0 0.000000+0 0.000000+0 0.000000+0262532151     \n"
    " 7.788000+3 1.455000+0 1.187354+3 0.000000+0 0.000000+0 0.000000+0262532151     \n"
    " 3.000000+0 6.000000+0 7.000000+0 0.000000+0 0.000000+0 0.000000+0262532151     \n";
}

void verifyChunk( const SpinGroup& chunk ) {

  CHECK( 0.5 == Approx( chunk.AJ() ) );
  CHECK( 0.5 == Approx( chunk.spin() ) );
  CHECK( 0. == Approx( chunk.PJ() ) );
  CHECK( 0. == Approx( chunk.parity() ) );
  CHECK( 2 == chunk.NCH() );
  CHECK( 2 == chunk.numberChannels() );
  CHECK( 2 == chunk.NRSA() );
  CHECK( 2 == chunk.numberResonances() );

  decltype(auto) channels = chunk.channels();
  CHECK( 0.5 == Approx( channels.AJ() ) );
  CHECK( 0.5 == Approx( channels.spin() ) );
  CHECK( 0. == Approx( channels.PJ() ) );
  CHECK( 0. == Approx( channels.parity() ) );
  CHECK( 2 == channels.NCH() );
  CHECK( 2 == channels.numberChannels() );

  CHECK( 2 == channels.PPI().size() );
  CHECK( 2 == channels.particlePairNumbers().size() );
  CHECK( 2 == channels.L().size() );
  CHECK( 2 == channels.orbitalMomentumValues().size() );
  CHECK( 2 == channels.SCH().size() );
  CHECK( 2 == channels.channelSpinValues().size() );
  CHECK( 2 == channels.BND().size() );
  CHECK( 2 == channels.boundaryConditionValues().size() );
  CHECK( 2 == channels.APT().size() );
  CHECK( 2 == channels.trueChannelRadii().size() );
  CHECK( 2 == channels.APE().size() );
  CHECK( 2 == channels.effectiveChannelRadii().size() );

  CHECK( 1 == channels.PPI()[0] );
  CHECK( 2 == channels.PPI()[1] );
  CHECK( 1 == channels.particlePairNumbers()[0] );
  CHECK( 2 == channels.particlePairNumbers()[1] );
  CHECK( 0 == channels.L()[0] );
  CHECK( 0 == channels.L()[1] );
  CHECK( 0 == channels.orbitalMomentumValues()[0] );
  CHECK( 0 == channels.orbitalMomentumValues()[1] );
  CHECK( 0. == Approx( channels.SCH()[0] ) );
  CHECK( .5 == Approx( channels.SCH()[1] ) );
  CHECK( 0. == Approx( channels.channelSpinValues()[0] ) );
  CHECK( .5 == Approx( channels.channelSpinValues()[1] ) );
  CHECK( 0. == Approx( channels.BND()[0] ) );
  CHECK( 0. == Approx( channels.BND()[1] ) );
  CHECK( 0. == Approx( channels.boundaryConditionValues()[0] ) );
  CHECK( 0. == Approx( channels.boundaryConditionValues()[1] ) );
  CHECK( 0. == Approx( channels.APT()[0] ) );
  CHECK( 5.437300e-1 == Approx( channels.APT()[1] ) );
  CHECK( 0. == Approx( channels.trueChannelRadii()[0] ) );
  CHECK( 5.437300e-1 == Approx( channels.trueChannelRadii()[1] ) );
  CHECK( 0. == Approx( channels.APE()[0] ) );
  CHECK( 5.437300e-1 == Approx( channels.APE()[1] ) );
  CHECK( 0. == Approx( channels.effectiveChannelRadii()[0] ) );
  CHECK( 5.437300e-1 == Approx( channels.effectiveChannelRadii()[1] ) );

  decltype(auto) parameters = chunk.parameters();
  CHECK( 2 == parameters.NRSA() );
  CHECK( 2 == parameters.numberResonances() );
  CHECK( 2 == parameters.NX() );
  CHECK( 2 == parameters.numberLines() );

  CHECK( 2 == parameters.ER().size() );
  CHECK( 2 == parameters.resonanceEnergies().size() );
  CHECK( 2 == parameters.GAM().size() );
  CHECK( 2 == parameters.resonanceParameters().size() );

  CHECK( -1.223300e+6 == Approx( parameters.ER()[0] ) );
  CHECK(  7.788000e+3 == Approx( parameters.ER()[1] ) );
  CHECK( -1.223300e+6 == Approx( parameters.resonanceEnergies()[0] ) );
  CHECK(  7.788000e+3 == Approx( parameters.resonanceEnergies()[1] ) );
  CHECK( 5 == parameters.GAM()[0].size() );
  CHECK( 5 == parameters.GAM()[1].size() );
  CHECK( 1. == Approx( parameters.GAM()[0][0] ) );
  CHECK( 9.611086e+5 == Approx( parameters.GAM()[0][1] ) );
  CHECK( 0. == Approx( parameters.GAM()[0][2] ) );
  CHECK( 0. == Approx( parameters.GAM()[0][3] ) );
  CHECK( 0. == Approx( parameters.GAM()[0][4] ) );
  CHECK( 1.455 == Approx( parameters.GAM()[1][0] ) );
  CHECK( 1.187354e+3 == Approx( parameters.GAM()[1][1] ) );
  CHECK( 0. == Approx( parameters.GAM()[1][2] ) );
  CHECK( 0. == Approx( parameters.GAM()[1][3] ) );
  CHECK( 0. == Approx( parameters.GAM()[1][4] ) );
  CHECK( 5 == parameters.resonanceParameters()[0].size() );
  CHECK( 5 == parameters.resonanceParameters()[1].size() );
  CHECK( 1. == Approx( parameters.resonanceParameters()[0][0] ) );
  CHECK( 9.611086e+5 == Approx( parameters.resonanceParameters()[0][1] ) );
  CHECK( 0. == Approx( parameters.resonanceParameters()[0][2] ) );
  CHECK( 0. == Approx( parameters.resonanceParameters()[0][3] ) );
  CHECK( 0. == Approx( parameters.resonanceParameters()[0][4] ) );
  CHECK( 1.455 == Approx( parameters.resonanceParameters()[1][0] ) );
  CHECK( 1.187354e+3 == Approx( parameters.resonanceParameters()[1][1] ) );
  CHECK( 0. == Approx( parameters.resonanceParameters()[1][2] ) );
  CHECK( 0. == Approx( parameters.resonanceParameters()[1][3] ) );
  CHECK( 0. == Approx( parameters.resonanceParameters()[1][4] ) );

  CHECK( 2. == Approx( parameters.DER()[0] ) );
  CHECK( 3. == Approx( parameters.DER()[1] ) );
  CHECK( 2. == Approx( parameters.resonanceEnergyUncertainties()[0] ) );
  CHECK( 3. == Approx( parameters.resonanceEnergyUncertainties()[1] ) );
  CHECK( 5 == parameters.DGAM()[0].size() );
  CHECK( 5 == parameters.DGAM()[1].size() );
  CHECK( 4. == Approx( parameters.DGAM()[0][0] ) );
  CHECK( 5. == Approx( parameters.DGAM()[0][1] ) );
  CHECK( 0. == Approx( parameters.DGAM()[0][2] ) );
  CHECK( 0. == Approx( parameters.DGAM()[0][3] ) );
  CHECK( 0. == Approx( parameters.DGAM()[0][4] ) );
  CHECK( 6. == Approx( parameters.DGAM()[1][0] ) );
  CHECK( 7. == Approx( parameters.DGAM()[1][1] ) );
  CHECK( 0. == Approx( parameters.DGAM()[1][2] ) );
  CHECK( 0. == Approx( parameters.DGAM()[1][3] ) );
  CHECK( 0. == Approx( parameters.DGAM()[1][4] ) );
  CHECK( 5 == parameters.resonanceParameterUncertainties()[0].size() );
  CHECK( 5 == parameters.resonanceParameterUncertainties()[1].size() );
  CHECK( 4. == Approx( parameters.resonanceParameterUncertainties()[0][0] ) );
  CHECK( 5. == Approx( parameters.resonanceParameterUncertainties()[0][1] ) );
  CHECK( 0. == Approx( parameters.resonanceParameterUncertainties()[0][2] ) );
  CHECK( 0. == Approx( parameters.resonanceParameterUncertainties()[0][3] ) );
  CHECK( 0. == Approx( parameters.resonanceParameterUncertainties()[0][4] ) );
  CHECK( 6. == Approx( parameters.resonanceParameterUncertainties()[1][0] ) );
  CHECK( 7. == Approx( parameters.resonanceParameterUncertainties()[1][1] ) );
  CHECK( 0. == Approx( parameters.resonanceParameterUncertainties()[1][2] ) );
  CHECK( 0. == Approx( parameters.resonanceParameterUncertainties()[1][3] ) );
  CHECK( 0. == Approx( parameters.resonanceParameterUncertainties()[1][4] ) );

  CHECK( 8 == chunk.NC() );
}
