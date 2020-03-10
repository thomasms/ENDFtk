#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "ENDFtk.hpp"

using namespace njoy::ENDFtk;

SCENARIO( "Isotope" ){
  WHEN( "Negative NER" ){
    std::string ENDF =
      " 1.001000+3 9.991673-1          0          0         -1          0 125 2151    1\n";

    auto begin = ENDF.begin();
    auto end = ENDF.end();
    long lineNumber = 0;

    int MAT = 125;
    int MF = 2;
    int MT = 151;

    CHECK_THROWS(
      resonanceParameters::Isotope( begin, end, lineNumber, MAT, MF, MT )
    );
  }

  WHEN( "LRU=0" ){
    std::string ENDF =
      " 1.001000+3 1.000000+0          0          0          1          0 125 2151    2\n"
      " 1.000000-5 1.000000+5          0          0          0          0 125 2151    3\n"
      " 5.000000-1 1.276553+0          0          0          0          0 125 2151    4\n";

    auto begin = ENDF.begin();
    auto end = ENDF.end();
    long lineNumber = 0;

    int MAT = 125;
    int MF = 2;
    int MT = 151;

    THEN( "a SpecialCase can be constructed" ){
      resonanceParameters::Isotope iso( begin, end, lineNumber, MAT, MF, MT );

      CHECK( 1 == iso.resonanceRanges().size() );

      const auto& range = iso.resonanceRanges().back();
      CHECK( 1E-5 == Approx( range.EL() ) );
      CHECK( 1E-5 == Approx( range.lowerEnergy() ) );
      CHECK( 1E+5 == Approx( range.EH() ) );
      CHECK( 1E+5 == Approx( range.upperEnergy() ) );

      CHECK( 0 == range.LRU() );
      CHECK( 0 == range.type() );
      CHECK( 0 == range.LRF() );
      CHECK( 0 == range.representation() );
      CHECK( 0 == range.NRO() );
      CHECK( 0 == range.energyDependentScatteringRadius() );
      CHECK( 0 == range.NAPS() );
      CHECK( 0 == range.scatteringRadiusCalculationOption() );

      CHECK_NOTHROW( std::get< resonanceParameters::SpecialCase >
                       ( range.parameters() ) );
    }
  }
  WHEN( "LRU=1" ){
    WHEN( "there is only one SLBW range in the Isotope" ){
      std::string ENDF =
        " 6.114800E4 1.000000+0          0          0          1          06153 2151    2\n"
        " 1.000000-5 1.000000+0          1          1          0          06153 2151    3\n"
        " 6.000000+0 6.380900-1          0          0          1          06153 2151    4\n"
        " 1.466470+2 0.000000+0          0          0          6          16153 2151    5\n"
        " 1.690000-1 6.000000+0 8.018800-2 5.880000-4 7.960000-2 0.000000+06153 2151    6\n";

      auto begin = ENDF.begin();
      auto end = ENDF.end();
      long lineNumber = 0;
      int MAT = 6153;
      int MF = 2;
      int MT = 151;

      resonanceParameters::Isotope iso( begin, end, lineNumber, MAT, MF, MT );

      CHECK( 1 == iso.resonanceRanges().size() );

      const auto& range = iso.resonanceRanges().back();
      CHECK( 1E-5 == Approx( range.EL() ) );
      CHECK( 1E-5 == Approx( range.lowerEnergy() ) );
      CHECK( 1. == Approx( range.EH() ) );
      CHECK( 1. == Approx( range.upperEnergy() ) );

      CHECK( 1 == range.LRU() );
      CHECK( 1 == range.type() );
      CHECK( 1 == range.LRF() );
      CHECK( 1 == range.representation() );
      CHECK( 0 == range.NRO() );
      CHECK( 0 == range.energyDependentScatteringRadius() );
      CHECK( 0 == range.NAPS() );
      CHECK( 0 == range.scatteringRadiusCalculationOption() );

      CHECK_NOTHROW( std::get< resonanceParameters::resolved::SingleLevelBreitWigner >
                       ( range.parameters() ) );
    }

    WHEN( "there is only one MLBW range in the Isotope" ){
      std::string ENDF =
        " 6.114800E4 1.000000+0          0          0          1          06153 2151    2\n"
        " 1.000000-5 1.000000+0          1          2          0          06153 2151    3\n"
        " 6.000000+0 6.380900-1          0          0          1          06153 2151    4\n"
        " 1.466470+2 0.000000+0          0          0          6          16153 2151    5\n"
        " 1.690000-1 6.000000+0 8.018800-2 5.880000-4 7.960000-2 0.000000+06153 2151    6\n";

      auto begin = ENDF.begin();
      auto end = ENDF.end();
      long lineNumber = 0;
      int MAT = 6153;
      int MF = 2;
      int MT = 151;

      resonanceParameters::Isotope iso( begin, end, lineNumber, MAT, MF, MT );

      CHECK( 1 == iso.resonanceRanges().size() );

      const auto& range = iso.resonanceRanges().back();
      CHECK( 1E-5 == Approx( range.EL() ) );
      CHECK( 1E-5 == Approx( range.lowerEnergy() ) );
      CHECK( 1. == Approx( range.EH() ) );
      CHECK( 1. == Approx( range.upperEnergy() ) );

      CHECK( 1 == range.LRU() );
      CHECK( 1 == range.type() );
      CHECK( 2 == range.LRF() );
      CHECK( 2 == range.representation() );
      CHECK( 0 == range.NRO() );
      CHECK( 0 == range.energyDependentScatteringRadius() );
      CHECK( 0 == range.NAPS() );
      CHECK( 0 == range.scatteringRadiusCalculationOption() );

      CHECK_NOTHROW( std::get< resonanceParameters::resolved::MultiLevelBreitWigner >
                       ( range.parameters() ) );
    }

    WHEN( "there is only one Reich-Moore range in the Isotope" ){
      std::string ENDF =
        " 6.114800E4 1.000000+0          0          0          1          06153 2151    2\n"
        " 1.000000-5 1.000000+0          1          3          0          06153 2151    3\n"
        " 6.000000+0 6.380900-1          0          0          1          16153 2151    4\n"
        " 1.466470+2 0.000000+0          0          0          6          16153 2151    5\n"
        " 1.690000-1 6.000000+0 8.018800-2 5.880000-4 7.960000-2 0.000000+06153 2151    6\n";

      auto begin = ENDF.begin();
      auto end = ENDF.end();
      long lineNumber = 0;
      int MAT = 6153;
      int MF = 2;
      int MT = 151;

      resonanceParameters::Isotope iso( begin, end, lineNumber, MAT, MF, MT );

      CHECK( 1 == iso.resonanceRanges().size() );

      const auto& range = iso.resonanceRanges().back();
      CHECK( 1E-5 == Approx( range.EL() ) );
      CHECK( 1E-5 == Approx( range.lowerEnergy() ) );
      CHECK( 1. == Approx( range.EH() ) );
      CHECK( 1. == Approx( range.upperEnergy() ) );

      CHECK( 1 == range.LRU() );
      CHECK( 1 == range.type() );
      CHECK( 3 == range.LRF() );
      CHECK( 3 == range.representation() );
      CHECK( 0 == range.NRO() );
      CHECK( 0 == range.energyDependentScatteringRadius() );
      CHECK( 0 == range.NAPS() );
      CHECK( 0 == range.scatteringRadiusCalculationOption() );

      CHECK_NOTHROW( std::get< resonanceParameters::resolved::ReichMoore >
                       ( range.parameters() ) );
    }

    WHEN( "there is only one Adler-Adler range in the Isotope" ){
      std::string ENDF =
        " 6.114800E4 1.000000+0          0          0          1          06153 2151    2\n"
        " 1.000000-5 1.000000+0          1          4          0          06153 2151    3\n";

      auto begin = ENDF.begin();
      auto end = ENDF.end();
      long lineNumber = 0;
      int MAT = 6153;
      int MF = 2;
      int MT = 151;

      CHECK_THROWS(
        resonanceParameters::Isotope( begin, end, lineNumber, MAT, MF, MT )
      );
    }

    WHEN( "there is one Rmatrix-Limited range in the Isotope" ){
/*      std::string ENDF =
        " 6.114800E4 1.000000+0          0          0          1          06153 2151    2\n"
        " 1.000000-5 1.000000+0          1          7          0          06153 2151    3\n";

      auto begin = ENDF.begin();
      auto end = ENDF.end();
      long lineNumber = 0;
      int MAT = 6153;
      int MF = 2;
      int MT = 151;

      CHECK_THROWS(
        resonanceParameters::Isotope( begin, end, lineNumber, MAT, MF, MT )
      );*/
    }

    WHEN( "there is more than one range in the Isotope" ){
      std::string ENDF =
        " 6.114800E4 1.000000+0          0          0          2          06153 2151    2\n"
        " 1.000000-5 1.000000+0          1          1          0          06153 2151    3\n"
        " 6.000000+0 6.380900-1          0          0          1          06153 2151    4\n"
        " 1.466470+2 0.000000+0          0          0          6          16153 2151    5\n"
        " 1.690000-1 6.000000+0 8.018800-2 5.880000-4 7.960000-2 0.000000+06153 2151    6\n"
        " 1.000000-5 1.000000+0          1          3          0          06153 2151    7\n"
        " 6.000000+0 6.380900-1          0          0          1          16153 2151    8\n"
        " 1.466470+2 0.000000+0          0          0          6          16153 2151    9\n"
        " 1.690000-1 6.000000+0 8.018800-2 5.880000-4 7.960000-2 0.000000+06153 2151   10\n";

      auto begin = ENDF.begin();
      auto end = ENDF.end();
      long lineNumber = 0;
      int MAT = 6153;
      int MF = 2;
      int MT = 151;

      resonanceParameters::Isotope iso( begin, end, lineNumber, MAT, MF, MT );
      CHECK( 2 == iso.resonanceRanges().size() );

      CHECK_NOTHROW(
        std::get< resonanceParameters::resolved::SLBW >
                       ( iso.resonanceRanges().front().parameters() ) );
      CHECK_NOTHROW(
          std::get< resonanceParameters::resolved::ReichMoore >
                       ( iso.resonanceRanges().back().parameters() ) );
    }

    WHEN( "invalid LRF values" ){
      njoy::Log::info( "Testing invalid LRF with LRU=1" );
      int MAT = 125;
      int MF = 2;
      int MT = 151;
      THEN( "LRF=0, an exception is thrown" ){
        std::string ENDF =
          " 1.001000+3 1.000000+0          0          0          1          0 125 2151    2\n"
          " 1.000000-5 1.000000+5          1          0          0          0 125 2151    3\n";
        auto begin = ENDF.begin();
        auto end = ENDF.end();
        long lineNumber = 0;

        CHECK_THROWS(
          resonanceParameters::Isotope( begin, end, lineNumber, MAT, MF, MT ) );
      }
      THEN( "LRF=5, an exception is thrown" ){
        std::string ENDF =
          " 1.001000+3 1.000000+0          0          0          1          0 125 2151    2\n"
          " 1.000000-5 1.000000+5          1          5          0          0 125 2151    3\n";
        auto begin = ENDF.begin();
        auto end = ENDF.end();
        long lineNumber = 0;

        CHECK_THROWS(
          resonanceParameters::Isotope( begin, end, lineNumber, MAT, MF, MT ) );
      }
      THEN( "LRF=6, an exception is thrown" ){
        std::string ENDF =
          " 1.001000+3 1.000000+0          0          0          1          0 125 2151    2\n"
          " 1.000000-5 1.000000+5          1          6          0          0 125 2151    3\n";
        auto begin = ENDF.begin();
        auto end = ENDF.end();
        long lineNumber = 0;

        CHECK_THROWS(
          resonanceParameters::Isotope( begin, end, lineNumber, MAT, MF, MT ) );
      }

      THEN( "LRF=8, an exception is thrown" ){
        std::string ENDF =
          " 1.001000+3 1.000000+0          0          0          1          0 125 2151    2\n"
          " 1.000000-5 1.000000+5          1          8          0          0 125 2151    3\n";
        auto begin = ENDF.begin();
        auto end = ENDF.end();
        long lineNumber = 0;

        CHECK_THROWS(
          resonanceParameters::Isotope( begin, end, lineNumber, MAT, MF, MT ) );
      }
    }
  }
  WHEN( "LRU=2" ){
    WHEN( "LRF=1" ){
      WHEN( "LFW=0, energy-independent" ){
        std::string ENDF =
          " 6.816700+4 1.000000+0          0          0          1          05655 2151\n"
          // base
          " 2.300000+4 1.000000+5          2          1          0          05655 2151\n"
          // range CONT
          " 0.000000+0 6.233000-1          0          0          3          05655 2151\n"
          // L=0 LIST
          " 1.387090+2 0.000000+0          0          0          6          15655 2151\n"
          " 4.400000+3 5.000000-1 1.000000+0 4.400000-1 5.000000-2 0.000000+05655 2151\n"
          // L=1 LIST
          " 1.387090+2 0.000000+0          1          0         12          25655 2151\n"
          " 4.400000+3 5.000000-1 1.000000+0 5.280000-1 9.000000-2 0.000000+05655 2151\n"
          " 2.200000+3 1.500000+0 1.000000+0 2.640000-1 9.000000-2 0.000000+05655 2151\n"
          // L=2 LIST
          " 1.387090+2 0.000000+0          2          0         12          25655 2151\n"
          " 2.200000+3 1.500000+0 1.000000+0 3.300000-2 5.000000-2 0.000000+05655 2151\n"
          " 1.466670+3 2.500000+0 1.000000+0 2.200000-2 5.000000-2 0.000000+05655 2151\n"
          " 0.000000+0 0.000000+0          0          0          0          05655 2  0\n"
          " 0.000000+0 0.000000+0          0          0          0          05655 0  0\n";

        auto begin = ENDF.begin();
        auto end = ENDF.end();
        long lineNumber = 0;

        int MAT = 5655;
        int MF = 2;
        int MT = 151;

        THEN( "the parameters can be extracted and verified" ){
          resonanceParameters::Isotope iso( begin, end, lineNumber, MAT, MF, MT );
          CHECK_NOTHROW(
            std::get<
              resonanceParameters::unresolved::EnergyIndependent >
              ( iso.resonanceRanges().front().parameters() )
          );
        }
      }
      WHEN( "LFW=1, fission widths given" ){
        std::string ENDF =
          " 6.816700+4 1.000000+0          0          1          1          09440 2151\n"
          " 5.700000+3 4.000000+4          2          1          0          09440 2151\n"
          // LIST
          " 0.000000+0 8.880000-1          0          0         14          39440 2151\n"
          " 5.700000+3 7.000000+3 8.000000+3 9.000000+3 1.000000+4 1.200000+49440 2151\n"
          " 1.400000+4 1.600000+4 1.800000+4 2.000000+4 2.500000+4 3.000000+49440 2151\n"
          " 3.500000+4 4.000000+4                                            9440 2151\n"
          // L=0 CONT
          " 2.379920+2 0.000000+0          0          0          1          09440 2151\n"
          // L=0 LIST
          " 0.000000+0 0.000000+0          0          1         20          09440 2151\n"
          " 1.310000+1 5.000000-1 1.000000+0 1.572000-3 3.100000-2 0.000000+09440 2151\n"
          " 1.256000-3 1.544000-3 1.825000-3 2.025000-3 2.119000-3 2.051000-39440 2151\n"
          " 1.992000-3 1.879000-3 1.860000-3 1.838000-3 1.694000-3 1.581000-39440 2151\n"
          " 1.481000-3 1.403000-3                                            9440 2151\n"
          // L=1 CONT
          " 2.379920+2 0.000000+0          1          0          2          09440 2151\n"
          // L=1,J=0 LIST
          " 0.000000+0 0.000000+0          1          1         20          09440 2151\n"
          " 1.310000+1 5.000000-1 1.000000+0 3.013000-3 3.100000-2 0.000000+09440 2151\n"
          " 4.314000-3 4.572000-3 4.740000-3 5.000000-3 5.520000-3 7.057000-39440 2151\n"
          " 8.251000-3 9.276000-3 9.930000-3 1.035000-2 1.210000-2 1.341000-29440 2151\n"
          " 1.456000-2 1.542000-2                                            9440 2151\n"
          // L=1,J=1 LIST
          " 0.000000+0 0.000000+0          1          2         20          09440 2151\n"
          " 6.697000+0 1.500000+0 1.000000+0 1.540000-3 3.100000-2 0.000000+09440 2151\n"
          " 1.207000-3 1.299000-3 1.326000-3 1.397000-3 1.544000-3 1.973000-39440 2151\n"
          " 2.317000-3 2.581000-3 2.811000-3 3.075000-3 3.494000-3 3.887000-39440 2151\n"
          " 4.290000-3 4.586000-3                                            9440 2151\n"
          // L=2 CONT
          " 2.379920+2 0.000000+0          2          0          2          09440 2151\n"
          // L=2,J=0 LIST
          " 0.000000+0 0.000000+0          2          1         20          09440 2151\n"
          " 6.697000+0 1.500000+0 1.000000+0 8.304300-4 3.100000-2 0.000000+09440 2151\n"
          " 1.000000-9 1.000000-9 1.000000-9 1.000000-9 1.000000-9 1.000000-99440 2151\n"
          " 1.000000-9 1.000000-9 1.000000-9 1.000000-9 1.000000-9 1.000000-99440 2151\n"
          " 1.000000-9 1.000000-9                                            9440 2151\n"
          // L=2,J=1 LIST
          " 0.000000+0 0.000000+0          2          2         20          09440 2151\n"
          " 4.633000+0 2.500000+0 1.000000+0 5.744900-4 3.100000-2 0.000000+09440 2151\n"
          " 1.000000-9 1.000000-9 1.000000-9 1.000000-9 1.000000-9 1.000000-99440 2151\n"
          " 1.000000-9 1.000000-9 1.000000-9 1.000000-9 1.000000-9 1.000000-99440 2151\n"
          " 1.000000-9 1.000000-9                                            9440 2151\n"
          " 0.000000+0 0.000000+0          0          0          0          09440 2  0\n"
          " 0.000000+0 0.000000+0          0          0          0          09440 0  0\n";
        auto begin = ENDF.begin();
        auto end = ENDF.end();
        long lineNumber = 0;

        int MAT = 9440;
        int MF = 2;
        int MT = 151;

        THEN( "the parameters can be extracted and verified" ){
          resonanceParameters::Isotope iso( begin, end, lineNumber, MAT, MF, MT );
          CHECK_NOTHROW(
            std::get<
              resonanceParameters::unresolved::EnergyDependentFissionWidths >
              ( iso.resonanceRanges().front().parameters() )
          );
        }
        WHEN( "LFW is invalid" ){
          njoy::Log::info( "Testing invalid LFW" );
          int MAT = 125;
          int MF = 2;
          int MT = 151;
          THEN( "an exception is thrown" ){
            std::string ENDF =
              " 1.001000+3 1.000000+0          0         -1          1          0 125 2151    2\n"
              " 1.000000-5 1.000000+5          2          1          0          0 125 2151    3\n";
            auto begin = ENDF.begin();
            auto end = ENDF.end();
            long lineNumber = 0;

            CHECK_THROWS(
              resonanceParameters::Isotope( begin, end, lineNumber, MAT, MF, MT ) );
          }

          THEN( "an exception is thrown" ){
            std::string ENDF =
              " 1.001000+3 1.000000+0          0          2          1          0 125 2151    2\n"
              " 1.000000-5 1.000000+5          2          1          0          0 125 2151    3\n";
            auto begin = ENDF.begin();
            auto end = ENDF.end();
            long lineNumber = 0;

            CHECK_THROWS(
              resonanceParameters::Isotope( begin, end, lineNumber, MAT, MF, MT ) );
          }
        }
      }
    }
    WHEN( "LRF=2, all energy-dependent parameters" ){
      std::string ENDF =
        // " 3.809000+4 8.913540+1          0          0          1          03843 2151    1\n"
        " 3.809000+4 1.000000+0          0          1          1          03843 2151    2\n"
        " 6.000000+3 1.000000+5          2          2          0          03843 2151    3\n"
        " 0.000000+0 6.795900-1          0          0          3          03843 2151    4\n"
        " 8.913540+1 0.000000+0          0          0          1          03843 2151    5\n"
        " 5.000000-1 0.000000+0          5          0         84         133843 2151    6\n"
        " 0.000000+0 0.000000+0 0.000000+0 1.000000+0 0.000000+0 0.000000+03843 2151    7\n"
        " 6.000000+3 1.240600+4 0.000000+0 4.590100-1 2.050000-1 0.000000+03843 2151    8\n"
        " 7.000000+3 1.240600+4 0.000000+0 4.590100-1 2.050000-1 0.000000+03843 2151    9\n"
        " 8.000000+3 1.240600+4 0.000000+0 4.590100-1 2.050000-1 0.000000+03843 2151   10\n"
        " 1.000000+4 1.231300+4 0.000000+0 4.555800-1 2.050000-1 0.000000+03843 2151   11\n"
        " 1.500000+4 1.226300+4 0.000000+0 4.537400-1 2.050000-1 0.000000+03843 2151   12\n"
        " 2.500000+4 1.212200+4 0.000000+0 4.485000-1 2.050000-1 0.000000+03843 2151   13\n"
        " 3.000000+4 1.205400+4 0.000000+0 4.460100-1 2.050000-1 0.000000+03843 2151   14\n"
        " 4.000000+4 1.191800+4 0.000000+0 4.409700-1 2.050000-1 0.000000+03843 2151   15\n"
        " 5.000000+4 1.181000+4 0.000000+0 4.369800-1 2.050000-1 0.000000+03843 2151   16\n"
        " 6.000000+4 1.113000+4 0.000000+0 4.118100-1 2.050000-1 0.000000+03843 2151   17\n"
        " 7.000000+4 1.077400+4 0.000000+0 3.986200-1 2.050000-1 0.000000+03843 2151   18\n"
        " 8.000000+4 1.039500+4 0.000000+0 3.846100-1 2.050000-1 0.000000+03843 2151   19\n"
        " 1.000000+5 9.669700+3 0.000000+0 3.577800-1 2.050000-1 0.000000+03843 2151   20\n"
        " 8.913540+1 0.000000+0          1          0          2          03843 2151   21\n"
        " 5.000000-1 0.000000+0          5          0         84         133843 2151   22\n"
        " 0.000000+0 0.000000+0 0.000000+0 1.000000+0 0.000000+0 0.000000+03843 2151   23\n"
        " 6.000000+3 1.240600+4 0.000000+0 6.723800+0 2.050000-1 0.000000+03843 2151   24\n"
        " 7.000000+3 1.240600+4 0.000000+0 6.723800+0 2.050000-1 0.000000+03843 2151   25\n"
        " 8.000000+3 1.240600+4 0.000000+0 6.723800+0 2.050000-1 0.000000+03843 2151   26\n"
        " 1.000000+4 1.231300+4 0.000000+0 6.673600+0 2.050000-1 0.000000+03843 2151   27\n"
        " 1.500000+4 1.226300+4 0.000000+0 6.646600+0 2.050000-1 0.000000+03843 2151   28\n"
        " 2.500000+4 1.212200+4 0.000000+0 6.569900+0 2.050000-1 0.000000+03843 2151   29\n"
        " 3.000000+4 1.205400+4 0.000000+0 6.533500+0 2.050000-1 0.000000+03843 2151   30\n"
        " 4.000000+4 1.191800+4 0.000000+0 6.459600+0 2.050000-1 0.000000+03843 2151   31\n"
        " 5.000000+4 1.181000+4 0.000000+0 6.401200+0 2.050000-1 0.000000+03843 2151   32\n"
        " 6.000000+4 1.113000+4 0.000000+0 6.032400+0 2.050000-1 0.000000+03843 2151   33\n"
        " 7.000000+4 1.077400+4 0.000000+0 5.839300+0 2.050000-1 0.000000+03843 2151   34\n"
        " 8.000000+4 1.039500+4 0.000000+0 5.634100+0 2.050000-1 0.000000+03843 2151   35\n"
        " 1.000000+5 9.669700+3 0.000000+0 5.241000+0 2.050000-1 0.000000+03843 2151   36\n"
        " 1.500000+0 0.000000+0          5          0         84         133843 2151   37\n"
        " 0.000000+0 0.000000+0 0.000000+0 1.000000+0 0.000000+0 0.000000+03843 2151   38\n"
        " 6.000000+3 6.202800+3 0.000000+0 3.361900+0 2.050000-1 0.000000+03843 2151   39\n"
        " 7.000000+3 6.202800+3 0.000000+0 3.361900+0 2.050000-1 0.000000+03843 2151   40\n"
        " 8.000000+3 6.202800+3 0.000000+0 3.361900+0 2.050000-1 0.000000+03843 2151   41\n"
        " 1.000000+4 6.156500+3 0.000000+0 3.336800+0 2.050000-1 0.000000+03843 2151   42\n"
        " 1.500000+4 6.131600+3 0.000000+0 3.323300+0 2.050000-1 0.000000+03843 2151   43\n"
        " 2.500000+4 6.060800+3 0.000000+0 3.285000+0 2.050000-1 0.000000+03843 2151   44\n"
        " 3.000000+4 6.027200+3 0.000000+0 3.266800+0 2.050000-1 0.000000+03843 2151   45\n"
        " 4.000000+4 5.959100+3 0.000000+0 3.229800+0 2.050000-1 0.000000+03843 2151   46\n"
        " 5.000000+4 5.905100+3 0.000000+0 3.200600+0 2.050000-1 0.000000+03843 2151   47\n"
        " 6.000000+4 5.564900+3 0.000000+0 3.016200+0 2.050000-1 0.000000+03843 2151   48\n"
        " 7.000000+4 5.386800+3 0.000000+0 2.919600+0 2.050000-1 0.000000+03843 2151   49\n"
        " 8.000000+4 5.197500+3 0.000000+0 2.817000+0 2.050000-1 0.000000+03843 2151   50\n"
        " 1.000000+5 4.834900+3 0.000000+0 2.620500+0 2.050000-1 0.000000+03843 2151   51\n"
        " 8.913540+1 0.000000+0          2          0          2          03843 2151   52\n"
        " 1.500000+0 0.000000+0          5          0         84         133843 2151   53\n"
        " 0.000000+0 0.000000+0 0.000000+0 1.000000+0 0.000000+0 0.000000+03843 2151   54\n"
        " 6.000000+3 6.202800+3 0.000000+0 2.233000-1 2.050000-1 0.000000+03843 2151   55\n"
        " 7.000000+3 6.202800+3 0.000000+0 2.233000-1 2.050000-1 0.000000+03843 2151   56\n"
        " 8.000000+3 6.202800+3 0.000000+0 2.233000-1 2.050000-1 0.000000+03843 2151   57\n"
        " 1.000000+4 6.156500+3 0.000000+0 2.216300-1 2.050000-1 0.000000+03843 2151   58\n"
        " 1.500000+4 6.131600+3 0.000000+0 2.207400-1 2.050000-1 0.000000+03843 2151   59\n"
        " 2.500000+4 6.060800+3 0.000000+0 2.181900-1 2.050000-1 0.000000+03843 2151   60\n"
        " 3.000000+4 6.027200+3 0.000000+0 2.169800-1 2.050000-1 0.000000+03843 2151   61\n"
        " 4.000000+4 5.959100+3 0.000000+0 2.145300-1 2.050000-1 0.000000+03843 2151   62\n"
        " 5.000000+4 5.905100+3 0.000000+0 2.125900-1 2.050000-1 0.000000+03843 2151   63\n"
        " 6.000000+4 5.564900+3 0.000000+0 2.003400-1 2.050000-1 0.000000+03843 2151   64\n"
        " 7.000000+4 5.386800+3 0.000000+0 1.939200-1 2.050000-1 0.000000+03843 2151   65\n"
        " 8.000000+4 5.197500+3 0.000000+0 1.871100-1 2.050000-1 0.000000+03843 2151   66\n"
        " 1.000000+5 4.834900+3 0.000000+0 1.740500-1 2.050000-1 0.000000+03843 2151   67\n"
        " 2.500000+0 0.000000+0          5          0         84         133843 2151   68\n"
        " 0.000000+0 0.000000+0 0.000000+0 1.000000+0 0.000000+0 0.000000+03843 2151   69\n"
        " 6.000000+3 4.135200+3 0.000000+0 1.488700-1 2.050000-1 0.000000+03843 2151   70\n"
        " 7.000000+3 4.135200+3 0.000000+0 1.488700-1 2.050000-1 0.000000+03843 2151   71\n"
        " 8.000000+3 4.135200+3 0.000000+0 1.488700-1 2.050000-1 0.000000+03843 2151   72\n"
        " 1.000000+4 4.104300+3 0.000000+0 1.477600-1 2.050000-1 0.000000+03843 2151   73\n"
        " 1.500000+4 4.087700+3 0.000000+0 1.471600-1 2.050000-1 0.000000+03843 2151   74\n"
        " 2.500000+4 4.040500+3 0.000000+0 1.454600-1 2.050000-1 0.000000+03843 2151   75\n"
        " 3.000000+4 4.018100+3 0.000000+0 1.446500-1 2.050000-1 0.000000+03843 2151   76\n"
        " 4.000000+4 3.972700+3 0.000000+0 1.430200-1 2.050000-1 0.000000+03843 2151   77\n"
        " 5.000000+4 3.936800+3 0.000000+0 1.417200-1 2.050000-1 0.000000+03843 2151   78\n"
        " 6.000000+4 3.710000+3 0.000000+0 1.335600-1 2.050000-1 0.000000+03843 2151   79\n"
        " 7.000000+4 3.591200+3 0.000000+0 1.292800-1 2.050000-1 0.000000+03843 2151   80\n"
        " 8.000000+4 3.465000+3 0.000000+0 1.247400-1 2.050000-1 0.000000+03843 2151   81\n"
        " 1.000000+5 3.223200+3 0.000000+0 1.160400-1 2.050000-1 0.000000+03843 2151   82\n"
        " 0.000000+0 0.000000+0          0          0          0          03843 2  099999\n"
        " 0.000000+0 0.000000+0          0          0          0          03843 0  0    0\n";
      auto begin = ENDF.begin();
      auto end = ENDF.end();
      long lineNumber = 0;

      int MAT = 3843;
      int MF = 2;
      int MT = 151;

      THEN( "no exception is thrown" ){
        resonanceParameters::Isotope iso( begin, end, lineNumber, MAT, MF, MT );
        CHECK( 1 == iso.resonanceRanges().size() );
        CHECK_NOTHROW( std::get<
                          resonanceParameters::unresolved::EnergyDependent >
                         ( iso.resonanceRanges().front().parameters() ) );
      }
    }
    WHEN( "LRF is invalid" ){
      int MAT = 125;
      int MF = 2;
      int MT = 151;
      THEN( "an exception is thrown" ){
        std::string ENDF =
          " 1.001000+3 1.000000+0          0          0          1          0 125 2151    2\n"
          " 1.000000-5 1.000000+5          2         -1          0          0 125 2151    3\n";
        auto begin = ENDF.begin();
        auto end = ENDF.end();
        long lineNumber = 0;

        CHECK_THROWS(
          resonanceParameters::Isotope( begin, end, lineNumber, MAT, MF, MT )
        );
      }

      THEN( "an exception is thrown" ){
        std::string ENDF =
          " 1.001000+3 1.000000+0          0          0          1          0 125 2151    2\n"
          " 1.000000-5 1.000000+5          2          3          0          0 125 2151    3\n";
        auto begin = ENDF.begin();
        auto end = ENDF.end();
        long lineNumber = 0;

        CHECK_THROWS(
          resonanceParameters::Isotope( begin, end, lineNumber, MAT, MF, MT ) );
      }
    }
  }
}
