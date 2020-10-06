/*
 * 		scheduler_SRTF.cpp
 *
 *  	Due on: Oct. 6, 2020
 *      Author: Steven Cross
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */
#include <algorithm>
#include <vector>
#include "../includes/scheduler_SRTF.h"
#include "../includes/file_io.h"

// a sort function ripped straight from file_io.cpp
// used in this class to sort the ready_q
bool sortHelper(PCB &first, PCB &second){
	PCB *firstPCB, *secondPCB;
	firstPCB = &first;
	secondPCB = &second;
	return firstPCB->required_cpu_time < secondPCB->required_cpu_time;
}


bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p){
	Scheduler_SRTF::sort();
	return Scheduler::time_to_switch_processes(tick_count, p);
}

// Sorts ready_q by remaining CPU time
void Scheduler_SRTF::sort(){
	// make a vector out of the queue content, sort it, then push it pack to the queue
	std::vector<PCB> sorter;
	while (!ready_q->empty()) {
		sorter.push_back(ready_q->front());
		ready_q->pop();
	}

	std::sort(sorter.begin(), sorter.end(), sortHelper);

	for (int i = 0; i < sorter.size(); i++) {
		ready_q->push(sorter.at(i));
	}
	sorter.clear();
	return;
}

