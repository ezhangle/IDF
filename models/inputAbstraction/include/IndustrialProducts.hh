/**
 * PURPOSE:
 * ()
 *
 * LIBRARY DEPENDENCIES:
 * ((inputAbstraction/src/IndustrialProducts.cpp))
 */

#ifndef _INDUSTRIAL_PRODUCTS_HH_
#define _INDUSTRIAL_PRODUCTS_HH_

#include "SingleInput.hh"

namespace idf {

/**
 * represents an IndustrialProducts hand controller's input layout
 *
 * @author Derek Bankieris
 */
class IndustrialProducts {

    public:

    /** constructor */
    IndustrialProducts();

    /** forward-backward pivoting */
    SingleInput forwardBackwardPivot;

    /** left-right pivoting */
    SingleInput leftRightPivot;

    /** twisting */
    SingleInput twist;

    /** the trigger button */
    SingleInput trigger;

    /** the digital hat's northern trigger */
    SingleInput hatNorth;

    /** the digital hat's eastern trigger */
    SingleInput hatEast;

    /** the digital hat's southern trigger */
    SingleInput hatSouth;

    /** the digital hat's western trigger */
    SingleInput hatWest;

    /** the upper trigger of the switch */
    SingleInput switchUp;

    /** the lower trigger of the switch */
    SingleInput switchDown;

    /** up-down pivoting of the analog hat */
    SingleInput hatUpDownPivot;

    /** left-right pivoting of the analog hat */
    SingleInput hatLeftRightPivot;

};

}

#endif