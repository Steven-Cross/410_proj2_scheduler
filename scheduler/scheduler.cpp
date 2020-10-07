/*
 * 		scheduler.cpp
 *
 *  	Due on: Oct. 6, 2020
 *      Author: Steven Cross
 *
 */

#include "../includes/scheduler.h"

// adds a process, either new or one that has been running on
// the CPU and has been preempted
void Scheduler::add(PCB p) {
	ready_q->push(p);
	sort();
	return;
}

// get next process
PCB Scheduler::getNext(){
	PCB nextPCB = ready_q->front();
	ready_q->pop();
	return nextPCB;
}

// returns true if there are no jobs in the ready_q, otherwise false
bool Scheduler::isEmpty(){
	return ready_q->empty();
}

// if process has completed (used all its remaining_cpu_time) or
// if we are using a preemptive scheduling algorithm and the
// timeslice is over then its time to switch processes
// returns:
// true - switch processes
// false - do not switch
bool Scheduler::time_to_switch_processes(int tick_count, PCB &p){
	sort();
	if (p.remaining_cpu_time <= 0){
		return true;
	}

	return false;
}
