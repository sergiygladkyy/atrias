/*! \file controller_component.h
 *  \author Andrew Peekema
 *  \brief Orocos Component header for leg sin wave controller.
 */

// Orocos 
#include <rtt/os/main.h>
#include <rtt/RTT.hpp>
#include <rtt/Logger.hpp>
#include <rtt/TaskContext.hpp>
#include <rtt/OperationCaller.hpp>
#include <rtt/Component.hpp>
#include <rtt/Property.hpp>

// C
#include <stdlib.h>

#include <atrias_shared/GuiPublishTimer.h>
#include <atrias_shared/globals.h>

// Datatypes
#include <atrias_msgs/robot_state.h>
#include <atrias_msgs/controller_output.h>
#include <atc_leg_sin_wave/controller_input.h>
#include <atrias_shared/controller_structs.h>

using namespace RTT;
using namespace Orocos;
using namespace atc_leg_sin_wave;

namespace atrias {
using namespace shared;
namespace controller {

class ATCLegSinWave : public TaskContext {
private:
    atrias_msgs::robot_state        robotState;
    atrias_msgs::controller_output  controllerOutput;

    controller_input                guiIn;

    InputPort<controller_input>     guiDataIn;

    // This Operation is called by the RT Operations Manager.
    atrias_msgs::controller_output runController(atrias_msgs::robot_state);

    // Variables for subcontrollers
    std::string pd0Name;
    std::string pd1Name;
    std::string sin0Name;
    std::string sin1Name;

    TaskContext *pd0;
    TaskContext *pd1;
    TaskContext *sin0;
    TaskContext *sin1;

    Property<double> P0;
    Property<double> D0;
    Property<double> P1;
    Property<double> D1;

    OperationCaller<SinOut(double, double)> sin0Controller;
    OperationCaller<SinOut(double, double)> sin1Controller;
    OperationCaller<MotorAngle(double, double)> legToMotorPos;
    OperationCaller<MotorVelocity(SinOut, SinOut)> legToMotorVel;
    OperationCaller<double(double, double, double, double)> pd0Controller;
    OperationCaller<double(double, double, double, double)> pd1Controller;

    // Math variables
    double centerLength, centerAngle;
    double targetPos, currentPos, targetVel, currentVel;
    MotorAngle motorAngle;
    MotorVelocity motorVelocity;
    SinOut legLen;
    SinOut legAng;


public:
    // Constructor
    ATCLegSinWave(std::string name);

    // Standard Orocos hooks
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();
};
}
}