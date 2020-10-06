/*
 * 		stats.cpp
 *
 *  	Due on: Oct. 6, 2020
 *      Author: Steven Cross
 *
 */

#include "../includes/stats.h"

Stats::Stats(std::vector<PCB> &finished_vector): vec(&finished_vector),
		av_wait_time(UNINITIALIZED), av_turnaround_time(UNINITIALIZED), av_response_time(UNINITIALIZED){}

// loops thru vec, prints 1 line for each process using the following format
// Process 1 Required CPU time:2  arrived:0 started:0 finished:2
// if there are 10 processes in vector, should print 10 lines
void Stats::showAllProcessInfo(){
	for (int i = 0; i < vec->size(); i++){
		std::cout<<"Process "<<vec->at(i).process_number<<" Required CPU time:"<<vec->at(i).required_cpu_time
				<<" arrived:"<<vec->at(i).arrival_time<<" started:"<<vec->at(i).start_time<<" finished:"
				<<vec->at(i).finish_time<<std::endl;
	}
	return;
}

// after a process is placed in the ready_q, how long does
// it take before its placed on the processor?
// response_time per process = start_time - arrival_time
// this function returns the average over all processes
float Stats::get_av_response_time(){
	float totalResponseTime = 0;
	float numberOfProcesses = 0;
	for (int i = 0; i < vec->size(); i++){
		totalResponseTime += vec->at(i).start_time - vec->at(i).arrival_time;
		numberOfProcesses++;
	}
	av_response_time = totalResponseTime / numberOfProcesses;
	return av_response_time;
}

// after a process is placed in the ready_q, how long does
// it take to complete?
// turnaround time per process = finish_time - arrival_time
// this funtion returns the average over all processes
float Stats::get_av_turnaround_time(){
	float totalTurnaroundTime = 0;
	float numberOfProcesses   = 0;
	for (int i = 0; i < vec->size(); i++){
		totalTurnaroundTime += vec->at(i).finish_time - vec->at(i).arrival_time;
		numberOfProcesses++;
	}
	av_turnaround_time = totalTurnaroundTime / numberOfProcesses;
	return av_turnaround_time;
}

// after a process is placed in the ready_q, how much time does it
// spend waiting for processor time?
// wait time per process = finish_time - arrival_time-required_CPU_time
// this funtion returns the average over all processes
float Stats::get_av_wait_time(){
	float totalWaitTime = 0;
	float numberOfProcesses   = 0;
	for (int i = 0; i < vec->size(); i++){
		totalWaitTime += vec->at(i).finish_time - vec->at(i).arrival_time - vec->at(i).required_cpu_time;
		numberOfProcesses++;
	}
	av_wait_time = totalWaitTime / numberOfProcesses;
	return av_wait_time;
}


