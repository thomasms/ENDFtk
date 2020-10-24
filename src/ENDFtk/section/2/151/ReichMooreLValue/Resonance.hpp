/**
 *  @class
 *  @brief Convenience interface for Reich-Moore resonances
 *
 *  See ENDF102, section 2.2.1.2 for more information.
 */
template< typename Range >
class Resonance {

  /* fields */
  Range chunk;

public:

  /* constructor */
  Resonance( Range&& chunk ) : chunk( std::move(chunk) ) {}

  /**
   *  @brief Return the resonance energy
   */
  double ER() const { return this->chunk[0]; }

  /**
   *  @brief Return the resonance energy
   */
  double resonanceEnergy() const { return this->ER(); }

  /**
   *  @brief Return the spin value
   */
  double AJ() const { return this->chunk[1]; }

  /**
   *  @brief Return the spin value
   */
  double spin() const { return this->AJ(); }

  /**
   *  @brief Return the neutron width
   */
  double GN() const { return this->chunk[2]; }

  /**
   *  @brief Return the neutron width
   */
  double neutronWidth() const { return this->GN(); }

  /**
   *  @brief Return the gamma width
   */
  double GG() const { return this->chunk[3]; }

  /**
   *  @brief Return the gamma width
   */
  double gammaWidth() const { return this->GG(); }

  /**
   *  @brief Return the first fission width
   */
  double GFA() const { return this->chunk[4]; }

  /**
   *  @brief Return the first fission width
   */
  double firstFissionWidth() const { return this->GFA(); }

  /**
   *  @brief Return the second fission width
   */
  double GFB() const { return this->chunk[5]; }

  /**
   *  @brief Return the second fission width
   */
  double secondFissionWidth() const { return this->GFB(); }
};
