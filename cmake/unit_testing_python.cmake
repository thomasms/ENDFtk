#######################################################################
# Setup
#######################################################################

enable_testing()

function( add_python_test name source )

  set( test_name "ENDFtk.python.${name}.test" )
  add_test( NAME ${test_name}
            COMMAND ${PYTHON_EXECUTABLE} -m unittest -v test/${source}
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/python )
  set_tests_properties( ${test_name}
                        PROPERTIES ENVIRONMENT
                        PYTHONPATH=${ENDFtk_PYTHONPATH}:$ENV{PYTHONPATH})

endfunction()

#######################################################################
# Python unit testing
#######################################################################

message( STATUS "Adding ENDFtk Python unit testing" )

# missing tests
#add_python_test( TextRecord          Test_ENDFtk_TextRecord.py )

add_python_test( ControlRecord       Test_ENDFtk_ControlRecord.py )
add_python_test( DirectoryRecord     Test_ENDFtk_DirectoryRecord.py )
add_python_test( InterpolationRecord Test_ENDFtk_InterpolationRecord.py )
add_python_test( ListRecord          Test_ENDFtk_ListRecord.py )
add_python_test( TabulationRecord    Test_ENDFtk_TabulationRecord.py )
add_python_test( TapeIdentification  Test_ENDFtk_TapeIdentification.py )

add_python_test( CovariancePairs   Test_ENDFtk_CovariancePairs.py )
add_python_test( RectangularMatrix Test_ENDFtk_RectangularMatrix.py )
add_python_test( SquareMatrix      Test_ENDFtk_SquareMatrix.py )

#add_python_test( MF1.MT451.Section                    MF1/Test_ENDFtk_MF1_MT451_Section.py )
#add_python_test( MF1.MT452.Section                    MF1/Test_ENDFtk_MF1_MT452_Section.py )
#add_python_test( MF1.MT455.Section                    MF1/Test_ENDFtk_MF1_MT455_Section.py )
add_python_test( MF1.MT455.DecayConstants             MF1/MT455/Test_ENDFtk_MF1_MT455_DecayConstants.py )
add_python_test( MF1.MT455.EnergyDependentConstants   MF1/MT455/Test_ENDFtk_MF1_MT455_EnergyDependentConstants.py )
add_python_test( MF1.MT455.EnergyIndependentConstants MF1/MT455/Test_ENDFtk_MF1_MT455_EnergyIndependentConstants.py )
#add_python_test( MF1.MT456.Section                    MF1/Test_ENDFtk_MF1_MT456_Section.py )
#add_python_test( MF1.MT458.Section                    MF1/Test_ENDFtk_MF1_MT458_Section.py )
add_python_test( MF1.MT458.EnergyReleaseComponent     MF1/MT458/Test_ENDFtk_MF1_MT458_EnergyReleaseComponent.py )
#add_python_test( MF1.MT458.PolynomialComponents       MF1/MT458/Test_ENDFtk_MF1_MT458_PolynomialComponents.py )
add_python_test( MF1.MT458.TabulatedComponents        MF1/MT458/Test_ENDFtk_MF1_MT458_TabulatedComponents.py )
add_python_test( MF1.MT458.ThermalPointComponents     MF1/MT458/Test_ENDFtk_MF1_MT458_ThermalPointComponents.py )
#add_python_test( MF1.MT460.Section                    MF1/Test_ENDFtk_MF1_MT460_Section.py )
add_python_test( MF1.MT460.ContinuousPhotons          MF1/MT460/Test_ENDFtk_MF1_MT460_ContinuousPhotons.py )
add_python_test( MF1.MT460.DiscretePhotonMultiplicity MF1/MT460/Test_ENDFtk_MF1_MT460_DiscretePhotonMultiplicity.py )
add_python_test( MF1.MT460.DiscretePhotons            MF1/MT460/Test_ENDFtk_MF1_MT460_DiscretePhotons.py )
add_python_test( MF1.PolynomialMultiplicity           MF1/Test_ENDFtk_MF1_PolynomialMultiplicity.py )
add_python_test( MF1.TabulatedMultiplicity            MF1/Test_ENDFtk_MF1_TabulatedMultiplicity.py )

#add_python_test( MF2.MT151.Section                                      MF2/Test_ENDFtk_MF2_MT151_Section.py )
#add_python_test( MF2.MT151.BackgroundChannels                           MF2/MT151/Test_ENDFtk_MF2_MT151_BackgroundChannels.py )
#add_python_test( MF2.MT151.BreitWignerLValue                            MF2/MT151/Test_ENDFtk_MF2_MT151_BreitWignerLValue.py )
#add_python_test( MF2.MT151.FrohnerBackgroundRMatrix                     MF2/MT151/Test_ENDFtk_MF2_MT151_FrohnerBackgroundRMatrix.py )
#add_python_test( MF2.MT151.Isotope                                      MF2/MT151/Test_ENDFtk_MF2_MT151_Isotope.py )
#add_python_test( MF2.MT151.MultiLevelBreitWigner                        MF2/MT151/Test_ENDFtk_MF2_MT151_MultiLevelBreitWigner.py )
#add_python_test( MF2.MT151.NoBackgroundRMatrix                          MF2/MT151/Test_ENDFtk_MF2_MT151_NoBackgroundRMatrix.py )
#add_python_test( MF2.MT151.ParticlePairs                                MF2/MT151/Test_ENDFtk_MF2_MT151_ParticlePairs.py )
#add_python_test( MF2.MT151.ReichMoore                                   MF2/MT151/Test_ENDFtk_MF2_MT151_ReichMoore.py )
#add_python_test( MF2.MT151.ReichMooreLValue                             MF2/MT151/Test_ENDFtk_MF2_MT151_ReichMooreLValue.py )
#add_python_test( MF2.MT151.ResonanceChannels                            MF2/MT151/Test_ENDFtk_MF2_MT151_ResonanceChannels.py )
#add_python_test( MF2.MT151.ResonanceParameters                          MF2/MT151/Test_ENDFtk_MF2_MT151_ResonanceParameters.py )
#add_python_test( MF2.MT151.RMatrixLimited                               MF2/MT151/Test_ENDFtk_MF2_MT151_RMatrixLimited.py )
#add_python_test( MF2.MT151.SammyBackgroundRMatrix                       MF2/MT151/Test_ENDFtk_MF2_MT151_SammyBackgroundRMatrix.py )
#add_python_test( MF2.MT151.ScatteringRadius                             MF2/MT151/Test_ENDFtk_MF2_MT151_ScatteringRadius.py )
#add_python_test( MF2.MT151.SingleLevelBreitWigner                       MF2/MT151/Test_ENDFtk_MF2_MT151_SingleLevelBreitWigner.py )
#add_python_test( MF2.MT151.SpecialCase                                  MF2/MT151/Test_ENDFtk_MF2_MT151_SpecialCase.py )
#add_python_test( MF2.MT151.SpinGroup                                    MF2/MT151/Test_ENDFtk_MF2_MT151_SpinGroup.py )
#add_python_test( MF2.MT151.TabulatedBackgroundRMatrix                   MF2/MT151/Test_ENDFtk_MF2_MT151_TabulatedBackgroundRMatrix.py )
#add_python_test( MF2.MT151.UnresolvedEnergyDependent                    MF2/MT151/Test_ENDFtk_MF2_MT151_UnresolvedEnergyDependent.py )
#add_python_test( MF2.MT151.UnresolvedEnergyDependentFissionWidths       MF2/MT151/Test_ENDFtk_MF2_MT151_UnresolvedEnergyDependentFissionWidths.py )
#add_python_test( MF2.MT151.UnresolvedEnergyDependentFissionWidthsJValue MF2/MT151/Test_ENDFtk_MF2_MT151_UnresolvedEnergyDependentFissionWidthsJValue.py )
#add_python_test( MF2.MT151.UnresolvedEnergyDependentFissionWidthsLValue MF2/MT151/Test_ENDFtk_MF2_MT151_UnresolvedEnergyDependentFissionWidthsLValue.py )
#add_python_test( MF2.MT151.UnresolvedEnergyDependentJValue              MF2/MT151/Test_ENDFtk_MF2_MT151_UnresolvedEnergyDependentJValue.py )
#add_python_test( MF2.MT151.UnresolvedEnergyDependentLValue              MF2/MT151/Test_ENDFtk_MF2_MT151_UnresolvedEnergyDependentLValue.py )
#add_python_test( MF2.MT151.UnresolvedEnergyIndependent                  MF2/MT151/Test_ENDFtk_MF2_MT151_UnresolvedEnergyIndependent.py )
#add_python_test( MF2.MT151.UnresolvedEnergyIndependentLValue            MF2/MT151/Test_ENDFtk_MF2_MT151_UnresolvedEnergyIndependentLValue.py )
#add_python_test( MF2.MT152.Section                                      MF2/Test_ENDFtk_MF2_MT152_Section.py )
#
#add_python_test( MF3.Section MF3/Test_ENDFtk_MF3_Section.py )
#add_python_test( MF3.File    MF3/Test_ENDFtk_MF3_File.py )
#
#add_python_test( MF4.Section                MF4/Test_ENDFtk_MF4_Section.py )
#add_python_test( MF4.Isotropic              MF4/Test_ENDFtk_MF4_Isotropic.py )
#add_python_test( MF4.LegendreCoefficients   MF4/Test_ENDFtk_MF4_LegendreCoefficients.py )
#add_python_test( MF4.LegendreDistributions  MF4/Test_ENDFtk_MF4_LegendreDistributions.py )
#add_python_test( MF4.MixedDistributions     MF4/Test_ENDFtk_MF4_MixedDistributions.py )
#add_python_test( MF4.TabulatedDistribution  MF4/Test_ENDFtk_MF4_TabulatedDistribution.py )
#add_python_test( MF4.TabulatedDistributions MF4/Test_ENDFtk_MF4_TabulatedDistributions.py )
#
#add_python_test( MF5.Section                    MF5/Test_ENDFtk_MF5_Section.py )
#add_python_test( MF5.DistributionFunction       MF5/Test_ENDFtk_MF5_DistributionFunction.py )
#add_python_test( MF5.EffectiveTemperature       MF5/Test_ENDFtk_MF5_EffectiveTemperature.py )
#add_python_test( MF5.EvaporationSpectrum        MF5/Test_ENDFtk_MF5_EvaporationSpectrum.py )
#add_python_test( MF5.GeneralEvaporationSpectrum MF5/Test_ENDFtk_MF5_GeneralEvaporationSpectrum.py )
#add_python_test( MF5.MadlandNixSpectrum         MF5/Test_ENDFtk_MF5_MadlandNixSpectrum.py )
#add_python_test( MF5.MaxwellianFissionSpectrum  MF5/Test_ENDFtk_MF5_MaxwellianFissionSpectrum.py )
#add_python_test( MF5.OutgoingEnergyDistribution MF5/Test_ENDFtk_MF5_OutgoingEnergyDistribution.py )
#add_python_test( MF5.Parameter                  MF5/Test_ENDFtk_MF5_Parameter.py )
#add_python_test( MF5.PartialDistribution        MF5/Test_ENDFtk_MF5_PartialDistribution.py )
#add_python_test( MF5.Probability                MF5/Test_ENDFtk_MF5_Probability.py )
#add_python_test( MF5.TabulatedSpectrum          MF5/Test_ENDFtk_MF5_TabulatedSpectrum.py )
#add_python_test( MF5.WattSpectrum               MF5/Test_ENDFtk_MF5_WattSpectrum.py )
#
#add_python_test( MF6.Section                          MF6/Test_ENDFtk_MF6_Section.py )
#add_python_test( MF6.ChargedParticleElasticScattering MF6/Test_ENDFtk_MF6_ChargedParticleElasticScattering.py )
#add_python_test( MF6.ContinuumEnergyAngle             MF6/Test_ENDFtk_MF6_ContinuumEnergyAngle.py )
#add_python_test( MF6.DefinedElsewhere                 MF6/Test_ENDFtk_MF6_DefinedElsewhere.py )
#add_python_test( MF6.DiscreteTwoBodyRecoils           MF6/Test_ENDFtk_MF6_DiscreteTwoBodyRecoils.py )
#add_python_test( MF6.DiscreteTwoBodyScattering        MF6/Test_ENDFtk_MF6_DiscreteTwoBodyScattering.py )
#add_python_test( MF6.IsotropicDiscreteEmission        MF6/Test_ENDFtk_MF6_IsotropicDiscreteEmission.py )
#add_python_test( MF6.LaboratoryAngleEnergy            MF6/Test_ENDFtk_MF6_LaboratoryAngleEnergy.py )
#add_python_test( MF6.LAW1.KalbachMann                 MF6/LAW1/Test_ENDFtk_MF6_LAW1_KalbachMann.py )
#add_python_test( MF6.LAW1.LegendreCoefficients        MF6/LAW1/Test_ENDFtk_MF6_LAW1_LegendreCoefficients.py )
#add_python_test( MF6.LAW1.TabulatedDistribution       MF6/LAW1/Test_ENDFtk_MF6_LAW1_TabulatedDistribution.py )
#add_python_test( MF6.LAW1.ThermalScatteringData       MF6/LAW1/Test_ENDFtk_MF6_LAW1_ThermalScatteringData.py )
#add_python_test( MF6.LAW2.LegendreCoefficients        MF6/LAW2/Test_ENDFtk_MF6_LAW2_LegendreCoefficients.py )
#add_python_test( MF6.LAW2.TabulatedDistribution       MF6/LAW2/Test_ENDFtk_MF6_LAW2_TabulatedDistribution.py )
#add_python_test( MF6.LAW5.LegendreCoefficients        MF6/LAW5/Test_ENDFtk_MF6_LAW5_LegendreCoefficients.py )
#add_python_test( MF6.LAW5.NuclearAmplitudeExpansion   MF6/LAW5/Test_ENDFtk_MF6_LAW5_NuclearAmplitudeExpansion.py )
#add_python_test( MF6.LAW5.NuclearPlusInterference     MF6/LAW5/Test_ENDFtk_MF6_LAW5_NuclearPlusInterference.py )
#add_python_test( MF6.LAW7.AngularDistribution         MF6/LAW7/Test_ENDFtk_MF6_LAW7_AngularDistribution.py )
#add_python_test( MF6.LAW7.EnergyDistribution          MF6/LAW7/Test_ENDFtk_MF6_LAW7_EnergyDistribution.py )
#add_python_test( MF6.Multiplicity                     MF6/Test_ENDFtk_MF6_Multiplicity.py )
#add_python_test( MF6.NBodyPhaseSpace                  MF6/Test_ENDFtk_MF6_NBodyPhaseSpace.py )
#add_python_test( MF6.ReactionProduct                  MF6/Test_ENDFtk_MF6_ReactionProduct.py )
#add_python_test( MF6.Unknown                          MF6/Test_ENDFtk_MF6_Unknown.py )
#
#add_python_test( MF7.MT2.Section                MF7/Test_ENDFtk_MF7_MT2_Section.py )
#add_python_test( MF7.MT2.CoherentElastic        MF7/MT2/Test_ENDFtk_MF7_MT2_CoherentElastic.py )
#add_python_test( MF7.MT2.IncoherentElastic      MF7/MT2/Test_ENDFtk_MF7_MT2_IncoherentElastic.py )
#add_python_test( MF7.MT2.MixedElastic           MF7/MT2/Test_ENDFtk_MF7_MT2_MixedElastic.py )
#add_python_test( MF7.MT4.Section                MF7/Test_ENDFtk_MF7_MT4_Section.py )
#add_python_test( MF7.MT4.AnalyticalFunctions    MF7/MT4/Test_ENDFtk_MF7_MT4_AnalyticalFunctions.py )
#add_python_test( MF7.MT4.EffectiveTemperature   MF7/MT4/Test_ENDFtk_MF7_MT4_EffectiveTemperature.py )
#add_python_test( MF7.MT4.ScatteringFunction     MF7/MT4/Test_ENDFtk_MF7_MT4_ScatteringFunction.py )
#add_python_test( MF7.MT4.ScatteringLawConstants MF7/MT4/Test_ENDFtk_MF7_MT4_ScatteringLawConstants.py )
#add_python_test( MF7.MT4.TabulatedFunctions     MF7/MT4/Test_ENDFtk_MF7_MT4_TabulatedFunctions.py )
#add_python_test( MF7.MT451.Section              MF7/Test_ENDFtk_MF7_MT451_Section.py )
#add_python_test( MF7.MT451.ElementInformation   MF7/MT451/Test_ENDFtk_MF7_MT451_ElementInformation.py )
#
#add_python_test( MF8.FissionYieldData           MF8/Test_ENDFtk_MF8_FissionYieldData.py )
#add_python_test( MF8.MT454.Section              MF8/Test_ENDFtk_MF8_MT454_Section.py )
#add_python_test( MF8.MT457.Section              MF8/Test_ENDFtk_MF8_MT457_Section.py )
#add_python_test( MF8.MT457.AverageDecayEnergies MF8/Test_ENDFtk_MF8_MT457_AverageDecayEnergies.py )
#add_python_test( MF8.MT457.ContinuousSpectrum   MF8/Test_ENDFtk_MF8_MT457_ContinuousSpectrum.py )
#add_python_test( MF8.MT457.DecayMode            MF8/Test_ENDFtk_MF8_MT457_DecayMode.py )
#add_python_test( MF8.MT457.DecayModes           MF8/Test_ENDFtk_MF8_MT457_DecayModes.py )
#add_python_test( MF8.MT457.DecaySpectrum        MF8/Test_ENDFtk_MF8_MT457_DecaySpectrum.py )
#add_python_test( MF8.MT457.DiscreteSpectrum     MF8/Test_ENDFtk_MF8_MT457_DiscreteSpectrum.py )
#add_python_test( MF8.MT459.Section              MF8/Test_ENDFtk_MF8_MT459_Section.py )
#
#add_python_test( MF9.Section         MF9/Test_ENDFtk_MF9_Section.py )
#add_python_test( MF9.ReactionProduct MF9/Test_ENDFtk_MF9_ReactionProduct.py )
#
#add_python_test( MF10.Section         MF10/Test_ENDFtk_MF10_Section.py )
#add_python_test( MF10.ReactionProduct MF10/Test_ENDFtk_MF10_ReactionProduct.py )
#
#add_python_test( MF12.Section                 MF12/Test_ENDFtk_MF12_Section.py )
#add_python_test( MF12.Multiplicities          MF12/Test_ENDFtk_MF12_Multiplicities.py )
#add_python_test( MF12.PartialMultiplicity     MF12/Test_ENDFtk_MF12_PartialMultiplicity.py )
#add_python_test( MF12.TotalMultiplicity       MF12/Test_ENDFtk_MF12_TotalMultiplicity.py )
#add_python_test( MF12.TransitionProbabilities MF12/Test_ENDFtk_MF12_TransitionProbabilities.py )
#
#add_python_test( MF13.Section             MF13/Test_ENDFtk_MF13_Section.py )
#add_python_test( MF13.PartialCrossSection MF13/Test_ENDFtk_MF13_PartialCrossSection.py )
#add_python_test( MF13.TotalCrossSection   MF13/Test_ENDFtk_MF13_TotalCrossSection.py )
#
#add_python_test( MF14.Section                 MF14/Test_ENDFtk_MF14_Section.py )
#add_python_test( MF14.IsotropicDiscretePhoton MF14/Test_ENDFtk_MF14_IsotropicDiscretePhoton.py )
#add_python_test( MF14.LegendreCoefficients    MF14/Test_ENDFtk_MF14_LegendreCoefficients.py )
#add_python_test( MF14.LegendreDistributions   MF14/Test_ENDFtk_MF14_LegendreDistributions.py )
#add_python_test( MF14.TabulatedDistribution   MF14/Test_ENDFtk_MF14_TabulatedDistribution.py )
#add_python_test( MF14.TabulatedDistributions  MF14/Test_ENDFtk_MF14_TabulatedDistributions.py )
#
#add_python_test( MF15.Section                    MF15/Test_ENDFtk_MF15_Section.py )
#add_python_test( MF15.OutgoingEnergyDistribution MF15/Test_ENDFtk_MF15_OutgoingEnergyDistribution.py )
#add_python_test( MF15.Probability                MF15/Test_ENDFtk_MF15_Probability.py )
#add_python_test( MF15.TabulatedSpectrum          MF15/Test_ENDFtk_MF15_TabulatedSpectrum.py )
#
#add_python_test( MF23.Section MF23/Test_ENDFtk_MF23_Section.py )
#add_python_test( MF23.File    MF23/Test_ENDFtk_MF23_File.py )
#
#add_python_test( MF26.Section                    MF26/Test_ENDFtk_MF26_Section.py )
#add_python_test( MF26.ContinuumEnergyAngle       MF26/Test_ENDFtk_MF26_ContinuumEnergyAngle.py )
#add_python_test( MF26.DiscreteTwoBodyScattering  MF26/Test_ENDFtk_MF26_DiscreteTwoBodyScattering.py )
#add_python_test( MF26.EnergyTransfer             MF26/Test_ENDFtk_MF26_EnergyTransfer.py )
#add_python_test( MF26.LAW1.LegendreCoefficients  MF26/LAW1/Test_ENDFtk_MF26_LAW1_LegendreCoefficients.py )
#add_python_test( MF26.LAW2.TabulatedDistribution MF26/LAW2/Test_ENDFtk_MF26_LAW2_TabulatedDistribution.py )
#add_python_test( MF26.Multiplicity               MF26/Test_ENDFtk_MF26_Multiplicity.py )
#add_python_test( MF26.ReactionProduct            MF26/Test_ENDFtk_MF26_ReactionProduct.py )
#
#add_python_test( MF27.Section MF27/Test_ENDFtk_MF27_Section.py )
#add_python_test( MF27.File    MF27/Test_ENDFtk_MF27_File.py )
#
#add_python_test( MF28.Section      MF28/Test_ENDFtk_MF28_Section.py )
#add_python_test( MF28.SubshellData MF28/Test_ENDFtk_MF28_SubshellData.py )
#
#add_python_test( MF31.Section MF31/Test_ENDFtk_MF31_Section.py )
#
#add_python_test( MF32.MT151.CompactBreitWignerUncertainties         MF32/MT151/Test_ENDFtk_MF32_MT151_CompactBreitWignerUncertainties.py )
#add_python_test( MF32.MT151.CompactCorrelationMatrix                MF32/MT151/Test_ENDFtk_MF32_MT151_CompactCorrelationMatrix.py )
#add_python_test( MF32.MT151.CompactMultiLevelBreitWigner            MF32/MT151/Test_ENDFtk_MF32_MT151_CompactMultiLevelBreitWigner.py )
#add_python_test( MF32.MT151.CompactReichMoore                       MF32/MT151/Test_ENDFtk_MF32_MT151_CompactReichMoore.py )
#add_python_test( MF32.MT151.CompactReichMooreUncertainties          MF32/MT151/Test_ENDFtk_MF32_MT151_CompactReichMooreUncertainties.py )
#add_python_test( MF32.MT151.CompactRMatrixLimited                   MF32/MT151/Test_ENDFtk_MF32_MT151_CompactRMatrixLimited.py )
#add_python_test( MF32.MT151.CompactRMatrixLimitedUncertainties      MF32/MT151/Test_ENDFtk_MF32_MT151_CompactRMatrixLimitedUncertainties.py )
#add_python_test( MF32.MT151.CompactSingleLevelBreitWigner           MF32/MT151/Test_ENDFtk_MF32_MT151_CompactSingleLevelBreitWigner.py )
#add_python_test( MF32.MT151.GeneralMultiLevelBreitWigner            MF32/MT151/Test_ENDFtk_MF32_MT151_GeneralMultiLevelBreitWigner.py )
#add_python_test( MF32.MT151.GeneralReichMoore                       MF32/MT151/Test_ENDFtk_MF32_MT151_GeneralReichMoore.py )
#add_python_test( MF32.MT151.GeneralRMatrixLimited                   MF32/MT151/Test_ENDFtk_MF32_MT151_GeneralRMatrixLimited.py )
#add_python_test( MF32.MT151.GeneralSingleLevelBreitWigner           MF32/MT151/Test_ENDFtk_MF32_MT151_GeneralSingleLevelBreitWigner.py )
#add_python_test( MF32.MT151.LCOMP1.CovarianceMatrix                 MF32/MT151/LCOMP1/Test_ENDFtk_MF32_MT151_LCOMP1_CovarianceMatrix.py )
#add_python_test( MF32.MT151.LCOMP1.ResonanceParameters              MF32/MT151/LCOMP1/Test_ENDFtk_MF32_MT151_LCOMP1_ResonanceParameters.py )
#add_python_test( MF32.MT151.LCOMP2.ParticlePairs                    MF32/MT151/LCOMP2/Test_ENDFtk_MF32_MT151_LCOMP2_ParticlePairs.py )
#add_python_test( MF32.MT151.LCOMP2.ResonanceChannels                MF32/MT151/LCOMP2/Test_ENDFtk_MF32_MT151_LCOMP2_ResonanceChannels.py )
#add_python_test( MF32.MT151.LCOMP2.ResonanceParameters              MF32/MT151/LCOMP2/Test_ENDFtk_MF32_MT151_LCOMP2_ResonanceParameters.py )
#add_python_test( MF32.MT151.LCOMP2.SpinGroup                        MF32/MT151/LCOMP2/Test_ENDFtk_MF32_MT151_LCOMP2_SpinGroup.py )
#add_python_test( MF32.MT151.LimitedBreitWignerLValue                MF32/MT151/Test_ENDFtk_MF32_MT151_LimitedBreitWignerLValue.py )
#add_python_test( MF32.MT151.LimitedMultiLevelBreitWigner            MF32/MT151/Test_ENDFtk_MF32_MT151_LimitedMultiLevelBreitWigner.py )
#add_python_test( MF32.MT151.LimitedSingleLevelBreitWigner           MF32/MT151/Test_ENDFtk_MF32_MT151_LimitedSingleLevelBreitWigner.py )
#add_python_test( MF32.MT151.ReichMooreScatteringRadiusUncertainties MF32/MT151/Test_ENDFtk_MF32_MT151_ReichMooreScatteringRadiusUncertainties.py )
#add_python_test( MF32.MT151.ScatteringRadiusCovariances             MF32/MT151/Test_ENDFtk_MF32_MT151_ScatteringRadiusCovariances.py )
#add_python_test( MF32.MT151.ShortRangeBreitWignerBlock              MF32/MT151/Test_ENDFtk_MF32_MT151_ShortRangeBreitWignerBlock.py )
#add_python_test( MF32.MT151.ShortRangeReichMooreBlock               MF32/MT151/Test_ENDFtk_MF32_MT151_ShortRangeReichMooreBlock.py )
#add_python_test( MF32.MT151.ShortRangeRMatrixLimitedBlock           MF32/MT151/Test_ENDFtk_MF32_MT151_ShortRangeRMatrixLimitedBlock.py )
#add_python_test( MF32.MT151.UnresolvedCovarianceMatrix              MF32/MT151/Test_ENDFtk_MF32_MT151_UnresolvedCovarianceMatrix.py )
#add_python_test( MF32.MT151.UnresolvedLValue                        MF32/MT151/Test_ENDFtk_MF32_MT151_UnresolvedLValue.py )
#add_python_test( MF32.MT151.UnresolvedRelativeCovariances           MF32/MT151/Test_ENDFtk_MF32_MT151_UnresolvedRelativeCovariances.py )
#
#add_python_test( MF33.Section MF33/Test_ENDFtk_MF33_Section.py )
#
#add_python_test( MF34.Section       MF34/Test_ENDFtk_MF34_Section.py )
#add_python_test( MF34.LegendreBlock MF34/Test_ENDFtk_MF34_LegendreBlock.py )
#add_python_test( MF34.ReactionBlock MF34/Test_ENDFtk_MF34_ReactionBlock.py )
#
#add_python_test( MF35.Section      MF35/Test_ENDFtk_MF35_Section.py )
#add_python_test( MF35.SquareMatrix MF35/Test_ENDFtk_MF35_SquareMatrix.py )
#
#add_python_test( MF40.Section    MF40/Test_ENDFtk_MF40_Section.py )
#add_python_test( MF40.LevelBlock MF40/Test_ENDFtk_MF40_LevelBlock.py )
#
#add_python_test( tree.File     tree/Test_ENDFtk_Tree_File.py )
#add_python_test( tree.Material tree/Test_ENDFtk_Tree_Material.py )
#add_python_test( tree.Tape     tree/Test_ENDFtk_Tree_Tape.py )
