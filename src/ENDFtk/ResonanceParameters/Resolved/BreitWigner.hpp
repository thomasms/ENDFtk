class BreitWigner {
protected:
  std::vector< LIST > lists;
  std::optional< TAB1 > ape;
  double el;
  double eh;
  int naps;
  double spi;
  double ap;
  
#include "ENDFtk/ResonanceParameters/Resolved/BreitWigner/src/readAPE.hpp"
#include "ENDFtk/ResonanceParameters/Resolved/BreitWigner/src/readLists.hpp"
#include "ENDFtk/ResonanceParameters/Resolved/BreitWigner/src/validate.hpp"
#include "ENDFtk/ResonanceParameters/Resolved/BreitWigner/src/ctor.hpp"

public:
  double EL() const { return this->el; }
  double EH() const { return this->eh; }
  int NRO() const { return bool(this->ape); }
  int NAPS() const { return this->naps; }
  
  const auto& APE() const { return *(this->ape); }

  double SPI() const { return this->spi; }
  double AP() const { return this->ap; }
  int NLS() const { return this->lists.size(); }

  auto LISTS() const {
    return ranges::make_iterator_range( this->lists.begin(), this->lists.end() );
  }
};
