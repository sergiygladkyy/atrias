/*
 * controller_gui.cpp
 *
 * Leg Position Controller
 *
 *  Created on: May 5, 2012
 *      Author: Michael Anderson
 */

#include <ac_leg_position/controller_gui.h>

ControllerInitResult guiInit(Glib::RefPtr<Gtk::Builder> gui) {
	ControllerInitResult cir;
    cir.error = true;

    gui->get_widget("p_hscale", p_leg_position_hscale);
    gui->get_widget("d_hscale", d_leg_position_hscale);
    gui->get_widget("hip_position_ang", hip_position_ang);
    gui->get_widget("hip_position_p", hip_position_p);
    gui->get_widget("hip_position_d", hip_position_d);
    gui->get_widget("length_hscale", leg_length_hscale);
    gui->get_widget("angle_hscale", leg_angle_hscale);
    gui->get_widget("update_checkbutton", update_checkbutton);

    if (p_leg_position_hscale && d_leg_position_hscale && hip_position_ang &&
            hip_position_p && hip_position_d && leg_length_hscale &&
            leg_angle_hscale && update_checkbutton) {
        leg_length_hscale->set_range(0.5, 1.);
        leg_angle_hscale->set_range(0.29, 2.85);
        p_leg_position_hscale->set_range(0., 10000.);
        d_leg_position_hscale->set_range(0., 300.);
        hip_position_ang->set_range(-0.209, 0.209);
        hip_position_p->set_range(0., 10000.);
        hip_position_d->set_range(0., 300.);
        cir.error = false;
    }
    cir.controllerInputSize = sizeof(InputData);
    cir.controllerStatusSize = 0;
    return cir;
}

void guiUpdate(robot_state state, ByteArray controllerStatus, ByteArray &controllerInput) {
    InputData out;

    out.leg_ang = leg_angle_hscale->get_value();
    out.leg_len = leg_length_hscale->get_value();
    out.hip_ang = hip_position_ang->get_value();
    out.p_gain = p_leg_position_hscale->get_value();
    out.d_gain = d_leg_position_hscale->get_value();
    out.hip_p_gain = hip_position_p->get_value();
    out.hip_d_gain = hip_position_d->get_value();

    structToByteArray(out, controllerInput);
}

void guiStandby(robot_state state) {
	if (update_checkbutton->get_active()) {
		leg_length_hscale->set_value(LEG_LENGTH(state.motor_angleA, state.motor_angleB));
		leg_angle_hscale->set_value(LEG_ANGLE(state.motor_angleA, state.motor_angleB));
	}
}

void guiTakedown() {

}
