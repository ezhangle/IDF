/**
 * PURPOSE:
 * ()
 *
 * LIBRARY DEPENDENCIES:
 * ((simulationInterface/src/SingleFlightController.cpp))
 */

#ifndef _SINGLE_FLIGHT_CONTROLLER_HH_
#define _SINGLE_FLIGHT_CONTROLLER_HH_

#include "FlightController.hh"

#include "inputAbstraction/include/Output.hh"
#include "inputAbstraction/include/Input.hh"
#include "inputAbstraction/include/CompositeInput.hh"

#include "inputAbstraction/include/DualShock3.hh"
#include "inputAbstraction/include/Gravis.hh"
#include "inputAbstraction/include/IndustrialProducts.hh"
#include "inputAbstraction/include/IndustrialProducts2.hh"
#include "inputAbstraction/include/SpaceBase.hh"
#include "inputAbstraction/include/ThrustMasterBase.hh"
#include "inputAbstraction/include/VirtualLayout.hh"
#include "inputAbstraction/include/WingMan.hh"

namespace idf {

/**
 * represents a single flight controller.
 *
 * Note: All <code>createInstance</code> functions return a controller whose
 * outputs are mapped to the inputs of the specified device following
 * conventional spatial mapping relationships when avaiable and reasonable
 * choices otherwise. The axes follow the right-handed convention and are
 * oriented as follows:
 *
 * +x points forward
 * +y points to the left
 * +z points up
 *
 * positive roll is measured from the +z axis towards the -x axis
 * positive pitch is measured from the +y axis towards the -z axis
 * positive yaw is measured from the +y axis towards the +x axis
 *
 * You may alter the polarity of any axis by inverting the appropriate output.
 * If this orientation is not appropriate for your application, you should
 * use the constructor instead, which allows you to fully customize the
 * mapping.
 *
 * @author Derek Bankieris
 */
class SingleFlightController : public FlightController {

    public:

    /** roll */
    Output roll;

    /** pitch */
    Output pitch;

    /** yaw */
    Output yaw;

    /** x */
    Output x;

    /** y */
    Output y;

    /** z */
    Output z;

    /**
     * constructs a new instance using the specified inputs
     *
     * @param roll the input to process as roll
     * @param pitch the input to process as pitch
     * @param yaw the input to process as yaw
     * @param x the input to process as x
     * @param y the input to process as y
     * @param z the input to process as z
     */
    SingleFlightController(
      const Input& roll, const Input& pitch, const Input& yaw,
      const Input& x, const Input& y, const Input& z);

    /**
     * adds <code>deadband</code> to all outputs
     *
     * @param deadband the deadband to add
     */
    void addDeadband(const Deadband& deadband);

    /**
     * removes all deadbands from all outputs
     */
    void clearDeadbands();

    /**
     * returns the commanded roll, normalized to [-1, 0, 1]
     *
     * @return the roll command
     */
    double getCommandedRoll() const;

    /**
     * returns the commanded pitch, normalized to [-1, 0, 1]
     *
     * @return the pitch command
     */
    double getCommandedPitch() const;

    /**
     * returns the commanded yaw, normalized to [-1, 0, 1]
     *
     * @return the yaw command
     */
    double getCommandedYaw() const;

    /**
     * returns the commanded x, normalized to [-1, 0, 1]
     *
     * @return the x command
     */
    double getCommandedX() const;

    /**
     * returns the commanded y, normalized to [-1, 0, 1]
     *
     * @return the y command
     */
    double getCommandedY() const;

    /**
     * returns the commanded z, normalized to [-1, 0, 1]
     *
     * @return the z command
     */
    double getCommandedZ() const;

    /**
     * creates a new <code>SingleFlightController</code> mapped to
     * <code>wingMan</code> using appropriate defaults
     *
     * @param wingMan the inputs to use in the default mapping
     *
     * @return a new WingMan-based flight controller
     */
    static SingleFlightController* createInstance(const WingMan& wingMan);

    /**
     * creates a new <code>SingleFlightController</code> mapped to
     * <code>spaceExplorer</code> using appropriate defaults
     *
     * @param spaceExplorer the inputs to use in the default mapping
     *
     * @return a new 3dconnexion-based flight controller
     */
    static SingleFlightController* createInstance(const SpaceBase& spaceBase);

    /**
     * creates a new <code>SingleFlightController</code> mapped to
     * <code>gravis</code> using appropriate defaults
     *
     * @param gravis the inputs to use in the default mapping
     *
     * @return a new Gravis-based flight controller
     */
    static SingleFlightController* createInstance(const Gravis& gravis);

    /*
     * creates a new <code>SingleFlightController</code> mapped to
     * <code>dualShock3</code> using appropriate defaults
     *
     * @param dualShock3 the inputs to use in the default mapping
     *
     * @return a new DualShock3-based flight controller
     */
    static SingleFlightController* createInstance(const DualShock3& dualShock3);

    /*
     * creates a new <code>SingleFlightController</code> mapped to
     * <code>virtualLayout</code> using appropriate defaults
     *
     * @param virtualLayout the inputs to use in the default mapping
     *
     * @return a new VirtualLayout-based flight controller
     */
    static SingleFlightController* createInstance(const VirtualLayout& virtualLayout);

    /*
     * creates a new <code>SingleFlightController</code> mapped to
     * <code>thrustMaster</code> using appropriate defaults
     *
     * @param thrustMaster the inputs to use in the default mapping
     *
     * @return a new ThrustMaster-based flight controller
     */
    static SingleFlightController* createInstance(const ThrustMasterBase& thrustMaster);

    /*
     * creates a new <code>SingleFlightController</code> mapped to
     * <code>industrialProducts</code> using appropriate defaults
     *
     * @param industrialProducts the inputs to use in the default mapping
     *
     * @return a new IndustrialProducts-based flight controller
     */
    static SingleFlightController* createInstance(const IndustrialProducts& industrialProducts);

    /*
     * creates a new <code>SingleFlightController</code> mapped to
     * <code>industrialProducts2</code> using appropriate defaults
     *
     * @param industrialProducts2 the inputs to use in the default mapping
     *
     * @return a new IndustrialProducts2-based flight controller
     */
    static SingleFlightController* createInstance(const IndustrialProducts2& industrialProducts2);

};

}

#endif