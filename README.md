# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

##PID Controller

PID controllers are simple close-loop controllers. The difference between the measured and the reference value (setpoint) of a process variable of a system is fed into the PID controller as an error signal. Depending on the PID parameters a control output is generated. In the current project, a car simulator produces the error signal as the distance between the actual car position on the road and a reference trajectory, known as cross-track error. The PID controller is designed to minimize the distance to this reference trajectory. The primary control output of the PID controller here is the steering angle.

### P control
The proportional term computes an output proportional to the cross-track error. A pure P controller is unstable and  oscillates about the setpoint. 

### D control
The oscillations caused by purely P control can be reduced by a D term proportional to the derivative of the cross-track error. 

### I control
This term is used to reduce the systematic bias. 


##Parameter Tuning

The parameters were tuned manually. I started with a purely P control with K_p=1. It caused a large oscillation. Then, I increased the D term and reduced P term to reduce the overshoot. In the end, I reduced K_p to 0.13 and increased K_D to 0.95. I did not use any I term.

I also used a P control the speed. The throttle input depends on the P control based on the difference between reference speed and actual speed. Also, we want to have a small speed when the cross track error is very large, which can give the vehicle more time to steer back to the track. Thus, I also added a term with the absolute value of the cte into the throttle equation. 

Additionally, the throttle value should also be limited when the steering angle or the cross-track error is very large. 

In general, the vehicle with a speed control and throttle control performs better than the one with only throttle control.
