/**
 * PURPOSE:
 * ()
 *
 * LIBRARY DEPENDENCIES:
 * ((inputAbstraction/src/ThrustMasterBase.cpp))
 */

#ifndef _THRUST_MASTER_BASE_HH_
#define _THRUST_MASTER_BASE_HH_

#include "SingleInput.hh"

namespace idf {

/**
 * represents the base input layout of a ThrustMaster hand controller
 *
 * @author Derek Bankieris
 */
class ThrustMasterBase {

/**
 * ICG doesn't support virtual inheritance,
 * which classes derived from this class use.
 */
#ifndef TRICK_ICG

    public:

    /**
     *  describes the pin-out of the translational hand controller.
     *  Male upDownTranslation is inverted with respect to female.
     *  */
    const bool male;

    /** forward-backward pivoting */
    SingleInput forwardBackwardPivot;

    /** left-right pivoting */
    SingleInput leftRightPivot;

    /** twisting */
    SingleInput twist;

    /** forward-backward translation */
    SingleInput forwardBackwardTranslation;

    /** left-right translation */
    SingleInput leftRightTranslation;

    /** up-down translation */
    SingleInput upDownTranslation;

    /** the trigger */
    SingleInput trigger;

#endif

    /** constructor */
    ThrustMasterBase(bool isMale = false);

    private:

    /** this class is not copy-assignable */
    ThrustMasterBase& operator=(const ThrustMasterBase&);

};

}

#endif