#include "sched.h"

u32 prev_cycle;
u64 cycles;

u64 read_cycles(void);

u64 read_cycles(){
	u32 current_cycle;
	u32 temp;

	asm volatile("mrc	p15, 0, %0, c9, c13, 0" : "=r"(current_cycle));

	if(prev_cycle > current_cycle){
		temp = 0xFFFFFFFF - prev_cycle;
		temp += current_cycle;
	}else{
		temp = cycles - prev_cycle;
	}

	cycles += temp;

	prev_cycle = current_cycle;

	return cycles;
}
