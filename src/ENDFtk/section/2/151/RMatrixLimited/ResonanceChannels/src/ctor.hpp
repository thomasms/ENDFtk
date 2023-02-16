private:
/**
 *  @brief Private intermediate constructor
 */
ResonanceChannels( ListRecord&& list ) : ListRecord( std::move( list ) ) {

  verifySize( this->NPL(), this->N2() );
}

public:
/**
 *  @brief Constructor (using different values for the true and effective
 *         scattering radius)
 *
 *  @param[in] spin     the spin group's spin value
 *  @param[in] parity   the associated parity
 *  @param[in] ppi      the particle pair indices (NCH values)
 *  @param[in] l        the orbital momentum values (NCH values)
 *  @param[in] s        the channel spin values (NCH values)
 *  @param[in] b        the boundary condition values (NCH values)
 *  @param[in] apt      the true scattering radius values for the calculation
 *                      of the penetrability and the shift factor (NCH values)
 *  @param[in] ape      the true scattering radius values for the calculation
 *                      of the phase shift (NCH values)
 *  @param[in] kbk      the number of channels with a background R-matrix
 *  @param[in] kps      the phase shift option
 */
ResonanceChannels( double spin, double parity,
                   std::vector< unsigned int >&& ppi,
                   std::vector< unsigned int >&& l,
                   std::vector< double >&& s,
                   std::vector< double >&& b,
                   std::vector< double >&& apt,
                   std::vector< double >&& ape,
                   int kbk = 0,
                   int kps = 0 )
  try : ResonanceChannels(
          ListRecord( spin, parity, kbk, kps, l.size(),
                      generateList( std::move( ppi ),
                                    std::move( l ),
                                    std::move( s ),
                                    std::move( b ),
                                    std::move( ape ),
                                    std::move( apt ) ) ) ) {}
  catch ( std::exception& e ) {

    Log::info( "Encountered error while constructing resonance channels" );
    throw;
  }

/**
 *  @brief Constructor (using the same values for the true and effective
 *         scattering radius)
 *
 *  @param[in] spin     the spin group's spin value
 *  @param[in] parity   the associated parity
 *  @param[in] ppi      the particle pair indices (NCH values)
 *  @param[in] l        the orbital momentum values (NCH values)
 *  @param[in] s        the channel spin values (NCH values)
 *  @param[in] b        the boundary condition values (NCH values)
 *  @param[in] ap       the scattering radius values (NCH values)
 *  @param[in] kbk      the number of channels with a background R-matrix
 *  @param[in] kps      the phase shift option
 */
ResonanceChannels( double spin, double parity,
                   std::vector< unsigned int >&& ppi,
                   std::vector< unsigned int >&& l,
                   std::vector< double >&& s,
                   std::vector< double >&& b,
                   std::vector< double >&& ap,
                   int kbk = 0,
                   int kps = 0 )
  try : ResonanceChannels(
          ListRecord( spin, parity, kbk, kps, l.size(),
                      generateList( std::move( ppi ),
                                    std::move( l ),
                                    std::move( s ),
                                    std::move( b ),
                                    std::move( ap ) ) ) ) {}
  catch ( std::exception& e ) {

    Log::info( "Encountered error while constructing resonance channels" );
    throw;
  }

/**
 *  @brief Constructor (from a buffer)
 *
 *  @tparam Iterator        a buffer iterator
 *
 *  @param[in] it           the current position in the buffer
 *  @param[in] end          the end of the buffer
 *  @param[in] lineNumber   the current line number
 *  @param[in] MAT          the expected MAT number
 *  @param[in] MF           the expected MF number
 *  @param[in] MT           the expected MT number
 */
template< typename Iterator >
ResonanceChannels( Iterator& it, const Iterator& end, long& lineNumber,
                   int MAT, int MF, int MT )
  try : ResonanceChannels( ListRecord( it, end, lineNumber, MAT, MF, MT ) ) {}
  catch ( std::exception& e ) {

    Log::info( "Encountered error while constructing resonance channels" );
    throw;
  }
