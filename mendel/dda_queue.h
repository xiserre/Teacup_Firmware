#ifndef	_DDA_QUEUE
#define	_DDA_QUEUE

#include	"dda.h"

/*
	variables
*/

// this is the ringbuffer that holds the current and pending moves.
extern uint8_t	mb_head;
extern uint8_t	mb_tail;
extern DDA movebuffer[MOVEBUFFER_SIZE];

/*
	methods
*/

// queue status methods
uint8_t queue_full(void);
uint8_t queue_empty(void);

// add a new target to the queue
void enqueue(TARGET *t);

// called from step timer when current move is complete
void next_move(void);

// print queue status
void print_queue(void);

#endif	/* _DDA_QUEUE */
