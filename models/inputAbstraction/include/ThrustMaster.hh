/**
 * PURPOSE:
 * ()
 *
 * LIBRARY DEPENDENCIES:
 * ((inputAbstraction/src/ThrustMaster.cpp))
 */

#ifndef _THRUST_MASTER_HH_
#define _THRUST_MASTER_HH_

#include "ThrustMasterBase.hh"
#include "SingleInput.hh"

namespace idf {

/**
 * represents a shuttle-style ThrustMaster hand controller's input layout
 *
 * @author Derek Bankieris
 */
class ThrustMaster : public virtual ThrustMasterBase {

    public:

    /** the switch */
    SingleInput topSwitch;

    /** the top button */
    SingleInput topButton;

    /** constructor */
    ThrustMaster(bool isMale = false);

    private:

    /** this class is not copy-assignable */
    ThrustMaster& operator=(const ThrustMaster&);

};

}

#endif