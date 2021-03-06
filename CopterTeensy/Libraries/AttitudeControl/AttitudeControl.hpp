/*
 * AttitudeControler.hpp
 *
 *  Created on: 16.2.2015
 *      Author: Juraj
 */

#ifndef ATTITUDECONTROL_HPP_
#define ATTITUDECONTROL_HPP_

#include <IMU_MPU9150.h>
#include <PID.hpp>
#include <MotorsQuadX.hpp>


class AttitudeControl
{
public:
	AttitudeControl(IMU_MPU9150& imu,
									MotorsQuadX& motors,
									PID* rate_yaw,
									PID* rate_pitch,
									PID* rate_roll,
									PID* stab_yaw,
									PID* stab_pitch,
									PID* stab_roll) :
					_rate_pid(rate_yaw, rate_pitch, rate_roll),
					_stab_pid(stab_yaw, stab_pitch, stab_roll),
					_motors(motors),
					_imu(imu),
					_lastUpdatePid(0)
	{
		Mav_Param::setup_object_defaults(this, var_info);
	}

	AttitudeControl(IMU_MPU9150& imu, MotorsQuadX& motors, Vector3<PID>* stab, Vector3<PID>* rate) :
					_rate_pid(&rate->YAW, &rate->PITCH, &rate->ROLL),
					_stab_pid(&stab->YAW, &stab->PITCH, &stab->ROLL),
					_motors(motors),
					_imu(imu),
					_lastUpdatePid(0)
	{
		Mav_Param::setup_object_defaults(this, var_info);
	}

	void stab_roll_pitch_yaw(uint32_t dt);
	void rate_roll_pitch_yaw(uint32_t dt);

	float pid_stab(PID* pid, float target, float input, uint32_t dt, bool return_target = true);
	float pid_stab(PID* pid, float error, uint32_t dt, bool return_target = true);

	float pid_rate(PID* pid, float target, float input, float i_term_stab, uint32_t dt);

	void reset_pid();
	bool is_ready();

	void set_last_update_pid(uint32_t time);
	uint32_t get_last_update_pid();
	Vector3Float& get_rate_output();
	Vector3Float& get_stab_output();

	Vector3Float& get_target_angles();
	Vector3Float& get_actual_angles();
	Vector3Float& get_actual_rates();

	void handle_param_change();

	void something(float val){

	}
	Vector3<PID*> get_stab_pid()
	{
		return _stab_pid;
	}

	Vector3<PID*> get_rate_pid()
	{
		return _rate_pid;
	}


	static uint16_t _pid_frequency;
	static const struct Mav_Param::GroupInfo var_info[];
private:

	Vector3<PID*> _rate_pid;
	Vector3<PID*> _stab_pid;

	MotorsQuadX& _motors;
	IMU_MPU9150& _imu;

	Vector3Float _rate_output;
	Vector3Float _stab_output;

	Vector3Float _target_angles;
	Vector3Float _actual_angles;
	Vector3Float _actual_rates;


	uint32_t _lastUpdatePid;

	Mav_Float _rate_mode_radio_multi;
	Mav_Float _pid_d_lpf;

	Mav_ParamT<float,PARAM_FLOAT,AttitudeControl> s;
};

#endif /* ATTITUDECONTROL_HPP_ */
