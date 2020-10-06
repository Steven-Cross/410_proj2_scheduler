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
	return Scheduler::time_to_switch_processes(tick_count, p);
}

// No sorting needed for RR algorithm
void Scheduler_RR::sort(){
	return;
}


