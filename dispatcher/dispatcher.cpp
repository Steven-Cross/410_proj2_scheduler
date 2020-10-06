/*
 * 		dispatcher.cpp
 *
 *  	Due on: Oct. 6, 2020
 *      Author: Steven Cross
 *
 */

#include "../includes/dispatcher.h"

// pull current process (if any) off CPU and return it
// if nothing on CPU returns an uninitialized PCB
PCB Dispatcher::get_from_CPU(){
	return cpu->get_process_off_core();
}

// place the current process on the CPU for execution
void Dispatcher::put_on_CPU(PCB &process){
	cpu->put_process_on_core(process);
	return;
}

// is CPU idle or working
// if there is not a valid job, the process will be uninitialized
bool Dispatcher::isValidJobOnCPU(){
	is_valid_job_on_cpu = (cpu->get_COPY_of_Current_Process().process_number != UNINITIALIZED);
	return is_valid_job_on_cpu;
}

