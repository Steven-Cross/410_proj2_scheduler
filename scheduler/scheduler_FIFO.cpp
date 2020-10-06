/*
 * 		scheduler_FIFO.cpp
 *
 *  	Due on: Oct. 6, 2020
 *      Author: Steven Cross
 *
 *      implements FIFO scheduling algorithm
 *      not pre-emptive
 */

#include "../includes/scheduler_FIFO.h"


bool Scheduler_FIFO::time_to_switch_processes(int tick_count, PCB &p){
	return Scheduler::time_to_switch_processes(tick_count, p);
}

// No sorting needed for FIFO
void Scheduler_FIFO::sort(){
	return;
}
