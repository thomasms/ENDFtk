//! @todo pybind11 variant needs default constructor workaround
#ifdef PYBIND11
/**
 *  @brief Default constructor - only enabled for pybind11
 */
CompactRMatrixLimited() = default;
#endif

/**
 *  @brief Constructor with scattering radius uncertainty
 *
 *  @param[in] ifg           flag to indicate whether or not the widths are reduced
 *  @param[in] njs           the number of spin groups
 *  @param[in] dap           the scattering radius uncertainty data
 *  @param[in] parameters    the resonance parameters and uncertainties
 *  @param[in] matrix        the correlation matrix
 */
CompactRMatrixLimited( bool ifg, long njs,
                       ReichMooreScatteringRadiusUncertainties&& dap,
                       CompactRMatrixLimitedUncertainties&& parameters,
                       CompactCorrelationMatrix&& matrix )
  try : CompactCovarianceBase( 0., 0., std::move( dap ),
                               static_cast< long >( ifg ), njs,
                               std::move( parameters ), std::move( matrix ) ) {}
  catch ( std::exception& e ) {

    Log::info( "Encountered error while constructing resonance and covariance "
               "parameters in the R-Matrix limited representation for the compact "
               "covariance format (LCOMP = 2)" );
    throw;
  }

/**
 *  @brief Constructor without scattering radius uncertainty
 *
 *  @param[in] ifg       flag to indicate whether or not the widths are reduced
 *  @param[in] njs       the number of spin groups
 *  @param[in] cshort    the short range covariance blocks
 *  @param[in] clong     the long range covariance blocks
 */
CompactRMatrixLimited( bool ifg, long njs,
                       CompactRMatrixLimitedUncertainties&& parameters,
                       CompactCorrelationMatrix&& matrix )
  try : CompactCovarianceBase( 0., 0.,
                               static_cast< long >( ifg ), njs,
                               std::move( parameters ),
                               std::move( matrix ) ) {}
  catch ( std::exception& e ) {

    Log::info( "Encountered error while constructing resonance and covariance "
               "parameters in the R-Matrix limited representation for the compact "
               "covariance format (LCOMP = 2)" );
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
CompactRMatrixLimited( Iterator& it, const Iterator& end, long& lineNumber,
                       int MAT, int MF, int MT )
  try : CompactCovarianceBase( it, end, lineNumber, MAT, MF, MT ) {}
  catch ( std::exception& e ) {

    Log::info( "Encountered error while constructing resonance and covariance "
               "parameters in the R-Matrix limited representation for the compact "
               "covariance format (LCOMP = 2)" );
    throw;
  }
