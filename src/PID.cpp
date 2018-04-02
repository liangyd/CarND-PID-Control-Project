#include "PID.h"

using namespace std;

/*
*  PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp=Kp;
	this->Ki=Ki;
	this->Kd=Kd;
	this->p_error=0.0;
	this->d_error=0.0;
	this->i_error=0.0;
	this->prev_cte=0.0;
	
}

void PID::UpdateError(double cte) {
	this->p_error=cte;
	this->i_error+=cte;
	this->d_error=cte-prev_cte;
	this->prev_cte=cte;

	
	
}

double PID::TotalError() {
	return Kp*p_error+Ki*i_error+Kd*d_error;
}

