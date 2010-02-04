#ifndef	_DDA_H
#define	_DDA_H

#include	<stdint.h>

#include	"pinout.h"
#include	"machine.h"

/*
	types
*/

// target is simply a point in space/time
typedef struct {
	int32_t						X;
	int32_t						Y;
	int32_t						Z;
	int32_t						E;
	uint32_t					F;
} TARGET;

// this is a digital differential analyser data struct, holding both the initial values and the counters as it progresses
typedef struct {
	TARGET						endpoint;

	uint8_t						x_direction		:1;
	uint8_t						y_direction		:1;
	uint8_t						z_direction		:1;
	uint8_t						e_direction		:1;
	uint8_t						f_direction		:1;
	uint8_t						nullmove			:1;
	uint8_t						live					:1;

	uint32_t					x_delta;
	uint32_t					y_delta;
	uint32_t					z_delta;
	uint32_t					e_delta;
	uint32_t					f_delta;

	int32_t						x_counter;
	int32_t						y_counter;
	int32_t						z_counter;
	int32_t						e_counter;
	int32_t						f_counter;

	uint32_t					total_steps;

	uint32_t					move_duration;
} DDA;

/*
	variables
*/

// steptimeout is set to zero when we step, and increases over time so we can turn the motors off when they've been idle for a while
extern uint8_t	steptimeout;

// startpoint holds the end position of the most recently created DDA, so we know where the next one starts
extern TARGET startpoint;

// current_position holds the machine's current position. this is only updated when we step, or when G92 (set home) is received.
extern TARGET current_position;

/*
	methods
*/

uint32_t approx_distance( uint32_t dx, uint32_t dy );
uint32_t approx_distance_3( uint32_t dx, uint32_t dy, uint32_t dz );

void dda_create(DDA *dda, TARGET *target);
void dda_start(DDA *dda);
void dda_step(DDA *dda);

#endif	/* _DDA_H */
