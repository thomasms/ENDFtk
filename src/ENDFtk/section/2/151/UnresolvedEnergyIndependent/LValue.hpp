/**
 *  @class
 *  @brief The unresolved resonance parameters for a given l value in the SLBW
 *         representation for independent widths (with no fission given)
 *
 *  See ENDF102, section 2.3.1 for more information.
 */
class ENDFTK_PYTHON_EXPORT LValue : protected ListRecord {

  /* auxiliary functions */
  #include "ENDFtk/section/2/151/UnresolvedEnergyIndependent/LValue/src/verifySize.hpp"
  #include "ENDFtk/section/2/151/UnresolvedEnergyIndependent/LValue/src/generateList.hpp"

  /* workaround for the removal of range-v3 */

  // using std20::views::repeat in C++ works but causes issues on the Python side
  std::vector< double > zeros_;
  #include "ENDFtk/section/2/151/UnresolvedEnergyIndependent/LValue/src/generateZeros.hpp"

public:

  /* constructor */
  #include "ENDFtk/section/2/151/UnresolvedEnergyIndependent/LValue/src/ctor.hpp"

  /**
   *  @brief Return the atomic weight ratio of the current isotope to the
   *         neutron mass
   */
  double AWRI() const { return ListRecord::C1(); }

  /**
   *  @brief Return the atomic weight ratio of the current isotope to the
   *         neutron mass
   */
  double atomicWeightRatio() const { return this->AWRI(); }

  /**
   *  @brief Return the value of the orbital momentum l
   */
  int L() const { return ListRecord::L1(); }

  /**
   *  @brief Return the value of the orbital momentum l
   */
  int orbitalMomentum() const { return this->L(); }

  /**
   *  @brief Return the number of J values for this l value
   */
  int NJS() const { return ListRecord::N2(); }

  /**
   *  @brief Return the number of J values for this l value
   */
  int numberSpinValues() const { return this->NJS(); }

  /**
   *  @brief Return the data for each of the J values
   */
  auto jValues() const {

    using namespace njoy::tools;
    auto chunked = ListRecord::list() | std23::views::chunk( 6 );
    using Range = decltype( chunked[0] );
    return chunked | std20::views::transform(
                       [] ( Range&& chunk ) -> JValue< Range >
                          { return { std::move( chunk ) }; } );
  }

  /**
   *  @brief Return the average level spacing values
   */
  auto D() const {

    using namespace njoy::tools;
    return this->jValues()
             | std20::views::transform( [] ( const auto& jvalue )
                                           { return jvalue.D(); } );
  }

  /**
   *  @brief Return the average level spacing values
   */
  auto averageLevelSpacings() const { return this->D(); }

  /**
   *  @brief Return the spin values
   */
  auto AJ() const {

    using namespace njoy::tools;
    return this->jValues()
             | std20::views::transform( [] ( const auto& jvalue )
                                           { return jvalue.AJ(); } );
  }

  /**
  *  @brief Return the spin values
   */
  auto spinValues() const { return this->AJ(); }

  /**
   *  @brief Return the degrees of freedom for the neutron width
   */
  auto AMUN() const {

    using namespace njoy::tools;
    return this->jValues()
             | std20::views::transform( [] ( const auto& jvalue )
                                           { return jvalue.AMUN(); } );
  }

  /**
   *  @brief Return the degrees of freedom for the neutron width
   */
  auto neutronWidthDegreesFreedom() const { return this->AMUN(); }

  /**
   *  @brief Return the degrees of freedom for the gamma width
   */
  auto AMUG() const {

    // using namespace njoy::tools;
    // return std20::views::repeat_n( 0.0, this->NJS() );
    using namespace njoy::tools;
    return std20::views::all( this->zeros_ );
  }

  /**
   *  @brief Return the degrees of freedom for the gamma width
   */
  auto gammaWidthDegreesFreedom() const { return this->AMUG(); }

  /**
   *  @brief Return the degrees of freedom for the fission width
   */
  auto AMUF() const {

    // using namespace njoy::tools;
    // return std20::views::repeat_n( 0.0, this->NJS() );
    using namespace njoy::tools;
    return std20::views::all( this->zeros_ );
  }

  /**
   *  @brief Return the degrees of freedom for the fission width
   */
  auto fissionWidthDegreesFreedom() const { return this->AMUG(); }

  /**
   *  @brief Return the degrees of freedom for the competitive width
   */
  auto AMUX() const {

    // using namespace njoy::tools;
    // return std20::views::repeat_n( 0.0, this->NJS() );
    using namespace njoy::tools;
    return std20::views::all( this->zeros_ );
  }

  /**
   *  @brief Return the degrees of freedom for the competitive width
   */
  auto competitiveWidthDegreesFreedom() const { return this->AMUG(); }

  /**
   *  @brief Return the average neutron width values.
   */
  auto GN() const {

    using namespace njoy::tools;
    return this->jValues()
             | std20::views::transform( [] ( const auto& jvalue )
                                           { return jvalue.GN(); } );
  }

  /**
   *  @brief Return the average neutron width values.
   */
  auto averageNeutronWidths() const { return this->GN(); }

  /**
   *  @brief Return the average gamma width values.
   */
  auto GG() const {

    using namespace njoy::tools;
    return this->jValues()
             | std20::views::transform( [] ( const auto& jvalue )
                                           { return jvalue.GG(); } );
  }

  /**
   *  @brief Return the average gamma width values.
   */
  auto averageGammaWidths() const { return this->GG(); }

  /**
   *  @brief Return the average fission width values.
   */
  auto GF() const {

//    using namespace njoy::tools;
//    return std20::views::repeat_n( 0.0, this->NJS() );

    using namespace njoy::tools;
    return this->zeros_ | std20::views::all;
  }

  /**
   *  @brief Return the average fission width values.
   */
  auto averageFissionWidths() const { return this->GF(); }

  /**
   *  @brief Return the average competitive width values.
   */
  auto GX() const {

    // using namespace njoy::tools;
    // return std20::views::repeat_n( 0.0, this->NJS() );
    using namespace njoy::tools;
    return std20::views::all( this->zeros_ );
  }

  /**
   *  @brief Return the average competitive width values.
   */
  auto averageCompetitiveWidths() const { return this->GX(); }

  using ListRecord::NC;
  using ListRecord::print;
};
