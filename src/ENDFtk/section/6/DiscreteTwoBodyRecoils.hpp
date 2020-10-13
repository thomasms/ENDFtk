/**
 *  @class
 *  @brief The energy and angular distribution can be determined from
 *         kinematics and no data is given
 *
 *  See ENDF102, section 6.2.5 for more information.
 */
class DiscreteTwoBodyRecoils : protected NoLawDataGiven {

public:

  /* methods */
  static constexpr int LAW() { return 4; }

  using NoLawDataGiven::NC;
  using NoLawDataGiven::print;
};
