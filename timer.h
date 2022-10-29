#ifndef __TIMER_H
#define __TIMER_H

	#ifndef SYS_FREQ
	#define SYS_FREQ 120000000
	#endif /* SYS_FREQ */

void Timer23Gated_Init(void);
void Timer2_Init(unsigned int frequency);

#endif /* __TIMER_H */