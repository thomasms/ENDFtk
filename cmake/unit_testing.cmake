#######################################################################
# Setup
#######################################################################

message( STATUS "Adding ENDFtk unit testing" )
enable_testing()


#######################################################################
# Unit testing directories
#######################################################################

add_subdirectory( src/ENDFtk/ControlRecord/test )
add_subdirectory( src/ENDFtk/DirectoryRecord/test )
add_subdirectory( src/ENDFtk/HeadRecord/test )
add_subdirectory( src/ENDFtk/InterpolationRecord/test )
add_subdirectory( src/ENDFtk/InterpolationSequenceRecord/test )
add_subdirectory( src/ENDFtk/ListRecord/test )
add_subdirectory( src/ENDFtk/StructureDivision/test )
add_subdirectory( src/ENDFtk/TabulationRecord/test )
add_subdirectory( src/ENDFtk/TapeIdentification/test )
add_subdirectory( src/ENDFtk/TextRecord/test )
add_subdirectory( src/ENDFtk/file/1/test )
add_subdirectory( src/ENDFtk/file/2/test )
add_subdirectory( src/ENDFtk/file/7/test )
add_subdirectory( src/ENDFtk/file/8/test )
add_subdirectory( src/ENDFtk/file/Type/test )
add_subdirectory( src/ENDFtk/record/Base/test )
add_subdirectory( src/ENDFtk/record/InterpolationBase/test )
add_subdirectory( src/ENDFtk/record/Sequence/test )
add_subdirectory( src/ENDFtk/record/Tail/test )
add_subdirectory( src/ENDFtk/record/Zipper/test )
add_subdirectory( src/ENDFtk/record/test )
add_subdirectory( src/ENDFtk/section/1/PolynomialMultiplicity/test )
add_subdirectory( src/ENDFtk/section/1/TabulatedMultiplicity/test )
add_subdirectory( src/ENDFtk/section/1/451/test )
add_subdirectory( src/ENDFtk/section/1/452/test )
add_subdirectory( src/ENDFtk/section/1/455/test )
add_subdirectory( src/ENDFtk/section/1/455/Constant/test )
add_subdirectory( src/ENDFtk/section/1/455/DecayConstant/test )
add_subdirectory( src/ENDFtk/section/1/455/EnergyDependent/test )
add_subdirectory( src/ENDFtk/section/1/456/test )
add_subdirectory( src/ENDFtk/section/1/458/test )
add_subdirectory( src/ENDFtk/section/1/458/EnergyReleaseComponent/test )
add_subdirectory( src/ENDFtk/section/1/458/Polynomial/test )
add_subdirectory( src/ENDFtk/section/1/458/Tabulated/test )
add_subdirectory( src/ENDFtk/section/1/458/ThermalPoint/test )
add_subdirectory( src/ENDFtk/section/1/460/test )
add_subdirectory( src/ENDFtk/section/1/460/Continuous/test )
add_subdirectory( src/ENDFtk/section/1/460/Discrete/test )
add_subdirectory( src/ENDFtk/section/1/460/DiscretePhoton/test )
add_subdirectory( src/ENDFtk/section/12/Multiplicities/test )
add_subdirectory( src/ENDFtk/section/12/PartialMultiplicity/test )
add_subdirectory( src/ENDFtk/section/12/TotalMultiplicity/test )
add_subdirectory( src/ENDFtk/section/12/TransitionProbabilities/Transition/test )
add_subdirectory( src/ENDFtk/section/12/TransitionProbabilities/test )
add_subdirectory( src/ENDFtk/section/12/test )
add_subdirectory( src/ENDFtk/section/13/PartialCrossSection/test )
add_subdirectory( src/ENDFtk/section/13/TotalCrossSection/test )
add_subdirectory( src/ENDFtk/section/13/test )
add_subdirectory( src/ENDFtk/section/2/151/BreitWignerLValue/Resonance/test )
add_subdirectory( src/ENDFtk/section/2/151/BreitWignerLValue/test )
add_subdirectory( src/ENDFtk/section/2/151/Isotope/test )
add_subdirectory( src/ENDFtk/section/2/151/MultiLevelBreitWigner/test )
add_subdirectory( src/ENDFtk/section/2/151/RMatrixLimited/ParticlePairs/test )
add_subdirectory( src/ENDFtk/section/2/151/RMatrixLimited/ResonanceChannels/test )
add_subdirectory( src/ENDFtk/section/2/151/RMatrixLimited/ResonanceParameters/test )
add_subdirectory( src/ENDFtk/section/2/151/RMatrixLimited/SpinGroup/test )
add_subdirectory( src/ENDFtk/section/2/151/RMatrixLimited/test )
add_subdirectory( src/ENDFtk/section/2/151/ReichMoore/test )
add_subdirectory( src/ENDFtk/section/2/151/ReichMooreLValue/Resonance/test )
add_subdirectory( src/ENDFtk/section/2/151/ReichMooreLValue/test )
add_subdirectory( src/ENDFtk/section/2/151/ScatteringRadius/test )
add_subdirectory( src/ENDFtk/section/2/151/SingleLevelBreitWigner/test )
add_subdirectory( src/ENDFtk/section/2/151/SpecialCase/test )
add_subdirectory( src/ENDFtk/section/2/151/UnresolvedEnergyDependent/JValue/test )
add_subdirectory( src/ENDFtk/section/2/151/UnresolvedEnergyDependent/LValue/test )
add_subdirectory( src/ENDFtk/section/2/151/UnresolvedEnergyDependent/test )
add_subdirectory( src/ENDFtk/section/2/151/UnresolvedEnergyDependentFissionWidths/JValue/test )
add_subdirectory( src/ENDFtk/section/2/151/UnresolvedEnergyDependentFissionWidths/LValue/test )
add_subdirectory( src/ENDFtk/section/2/151/UnresolvedEnergyDependentFissionWidths/test )
add_subdirectory( src/ENDFtk/section/2/151/UnresolvedEnergyIndependent/JValue/test )
add_subdirectory( src/ENDFtk/section/2/151/UnresolvedEnergyIndependent/LValue/test )
add_subdirectory( src/ENDFtk/section/2/151/UnresolvedEnergyIndependent/test )
add_subdirectory( src/ENDFtk/section/2/151/test )
add_subdirectory( src/ENDFtk/section/2/152/test )
add_subdirectory( src/ENDFtk/section/3/test )
add_subdirectory( src/ENDFtk/section/4/Isotropic/test )
add_subdirectory( src/ENDFtk/section/4/LegendreCoefficients/test )
add_subdirectory( src/ENDFtk/section/4/LegendreDistributions/test )
add_subdirectory( src/ENDFtk/section/4/MixedDistributions/test )
add_subdirectory( src/ENDFtk/section/4/TabulatedDistribution/test )
add_subdirectory( src/ENDFtk/section/4/TabulatedDistributions/test )
add_subdirectory( src/ENDFtk/section/4/test )
add_subdirectory( src/ENDFtk/section/5/DistributionFunction/test )
add_subdirectory( src/ENDFtk/section/5/EffectiveTemperature/test )
add_subdirectory( src/ENDFtk/section/5/EvaporationSpectrum/test )
add_subdirectory( src/ENDFtk/section/5/GeneralEvaporationSpectrum/test )
add_subdirectory( src/ENDFtk/section/5/MadlandNixSpectrum/test )
add_subdirectory( src/ENDFtk/section/5/MaxwellianFissionSpectrum/test )
add_subdirectory( src/ENDFtk/section/5/Parameter/test )
add_subdirectory( src/ENDFtk/section/5/Probability/test )
add_subdirectory( src/ENDFtk/section/5/PartialDistribution/test )
add_subdirectory( src/ENDFtk/section/5/TabulatedSpectrum/OutgoingEnergyDistribution/test )
add_subdirectory( src/ENDFtk/section/5/TabulatedSpectrum/test )
add_subdirectory( src/ENDFtk/section/5/WattSpectrum/test )
add_subdirectory( src/ENDFtk/section/5/test )
add_subdirectory( src/ENDFtk/section/6/ChargedParticleElasticScattering/LegendreCoefficients/test )
add_subdirectory( src/ENDFtk/section/6/ChargedParticleElasticScattering/NuclearAmplitudeExpansion/test )
add_subdirectory( src/ENDFtk/section/6/ChargedParticleElasticScattering/NuclearPlusInterference/test )
add_subdirectory( src/ENDFtk/section/6/ChargedParticleElasticScattering/test )
add_subdirectory( src/ENDFtk/section/6/ContinuumEnergyAngle/Base/test )
add_subdirectory( src/ENDFtk/section/6/ContinuumEnergyAngle/KalbachMann/test )
add_subdirectory( src/ENDFtk/section/6/ContinuumEnergyAngle/LegendreCoefficients/test )
add_subdirectory( src/ENDFtk/section/6/ContinuumEnergyAngle/TabulatedDistribution/test )
add_subdirectory( src/ENDFtk/section/6/ContinuumEnergyAngle/ThermalScatteringData/test )
add_subdirectory( src/ENDFtk/section/6/ContinuumEnergyAngle/test )
add_subdirectory( src/ENDFtk/section/6/DefinedElsewhere/test )
add_subdirectory( src/ENDFtk/section/6/DiscreteTwoBodyRecoils/test )
add_subdirectory( src/ENDFtk/section/6/DiscreteTwoBodyScattering/LegendreCoefficients/test )
add_subdirectory( src/ENDFtk/section/6/DiscreteTwoBodyScattering/TabulatedDistribution/test )
add_subdirectory( src/ENDFtk/section/6/DiscreteTwoBodyScattering/test )
add_subdirectory( src/ENDFtk/section/6/IsotropicDiscreteEmission/test )
add_subdirectory( src/ENDFtk/section/6/LaboratoryAngleEnergy/AngularDistribution/test )
add_subdirectory( src/ENDFtk/section/6/LaboratoryAngleEnergy/EnergyDistribution/test )
add_subdirectory( src/ENDFtk/section/6/LaboratoryAngleEnergy/test )
add_subdirectory( src/ENDFtk/section/6/Multiplicity/test )
add_subdirectory( src/ENDFtk/section/6/NBodyPhaseSpace/test )
add_subdirectory( src/ENDFtk/section/6/NoLawDataGiven/test )
add_subdirectory( src/ENDFtk/section/6/ReactionProduct/test )
add_subdirectory( src/ENDFtk/section/6/Unknown/test )
add_subdirectory( src/ENDFtk/section/6/test )
add_subdirectory( src/ENDFtk/section/7/2/CoherentElastic/test )
add_subdirectory( src/ENDFtk/section/7/2/IncoherentElastic/test )
add_subdirectory( src/ENDFtk/section/7/2/test )
add_subdirectory( src/ENDFtk/section/7/4/AnalyticalFunctions/test )
add_subdirectory( src/ENDFtk/section/7/4/EffectiveTemperature/test )
add_subdirectory( src/ENDFtk/section/7/4/ScatteringLawConstants/test )
add_subdirectory( src/ENDFtk/section/7/4/Tabulated/ScatteringFunction/test )
add_subdirectory( src/ENDFtk/section/7/4/Tabulated/test )
add_subdirectory( src/ENDFtk/section/7/4/test )
add_subdirectory( src/ENDFtk/section/8/457/AverageDecayEnergies/test )
add_subdirectory( src/ENDFtk/section/8/457/ContinuousSpectrum/test )
add_subdirectory( src/ENDFtk/section/8/457/DecayMode/test )
add_subdirectory( src/ENDFtk/section/8/457/DecayModes/test )
add_subdirectory( src/ENDFtk/section/8/457/DecaySpectrum/test )
add_subdirectory( src/ENDFtk/section/8/457/DiscreteSpectrum/test )
add_subdirectory( src/ENDFtk/section/8/457/test )
add_subdirectory( src/ENDFtk/section/Base/test )
add_subdirectory( src/ENDFtk/section/BaseWithoutMT/test )
add_subdirectory( src/ENDFtk/test )
add_subdirectory( src/ENDFtk/tree/File/test )
add_subdirectory( src/ENDFtk/tree/Material/test )
add_subdirectory( src/ENDFtk/tree/Section/test )
add_subdirectory( src/ENDFtk/tree/Tape/test )
