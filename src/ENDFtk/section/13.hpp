template<>
class Type< 13 > : protected Base {
public:
  using Base::MT;
  using Base::ZA;
  using Base::atomicWeightRatio;

  static constexpr auto MF(){ return 13; }

  #include "ENDFtk/section/13/Subsection.hpp"

protected:
  std::vector< TabulationRecord > subsections_;

  #include "ENDFtk/section/13/src/readSubsections.hpp"

public:
  #include "ENDFtk/section/13/src/ctor.hpp"

  int NK() const { return std::max( 1, int( this->subsections_.size() ) - 1 ); }

  auto energies() const { return subsections_.front().x(); }
  auto crossSections() const { return subsections_.front().y(); }
  auto subsections() const {
    return
      this->subsections_
      | ranges::view::drop_exactly( this->NK() > 1 )
      | ranges::view::transform
        ( []( const auto& tabulationRecord ) -> const Subsection&
          { return static_cast< const Subsection& >( tabulationRecord ); } );
  }

  #include "ENDFtk/section/13/src/NC.hpp"
  #include "ENDFtk/section/13/src/print.hpp"
};
