template < typename Derived >
class BaseWithoutMT {

  /* fields */
  int ZA_;
  double atomicWeightRatio_;

protected:

  /* constructor */
  #include "ENDFtk/section/BaseWithoutMT/src/ctor.hpp"

public:

  /* get methods */

  /**
   *  @brief Return the MT number of the section
   */
  constexpr int MT() const {

      return static_cast< const Derived* >( this )->sectionNumber();
  }

  /**
   *  @brief Return the ZA identifier of the section
   */
  constexpr int ZA() const { return this->ZA_; }

  /**
   *  @brief Return the atomic weight ratio
   */
  constexpr double AWR() const { return this->atomicWeightRatio_; }

  /**
   *  @brief Return the atomic weight ratio
   */
  constexpr double atomicWeightRatio() const { return this->AWR(); }

  #include "ENDFtk/section/BaseWithoutMT/src/readSEND.hpp"
};