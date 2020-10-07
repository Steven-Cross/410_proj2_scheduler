/*
 * 		scheduler_rr.cpp
 *
 *  	Due on: Oct. 6, 2020
 *      Author: Steven Cross
 *
 *      implements round robin scheduling algorithm
 *      pre-emptive
 */

#include "../includes/scheduler_RR.h"

// uses parent function to see if its time to switch processes
bool Scheduler_RR::time_to_switch_processes(int tick_count, PCB &p){
	static int timeLeft = time_slice - 1;
	if (p.remaining_cpu_time <= 0){
		return true;
	}
	if (preemptive){
		if (timeLeft == 0){
			timeLeft = time_slice - 1;
			return true;
		}
		timeLeft--;
	}

	return false;
}

// No sorting needed for RR algorithm
void Scheduler_RR::sort(){
	return;
}


