/*
 *	Moving Average Filter for Embedded Applications
 *	Copyright (C) 2018  Emile Décosterd
 *
 *	This file is part of movav
 *
 *	linalg is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	linalg is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include "movav.h"

static uint32_t movav_iter;
static average_t movav_average;

static uint8_t movav_buffer_pos;
static uint8_t movav_buffer_length;
static sample_t movav_buffer[MOVAV_BUFFER_SIZE];
static sample_t *movav_buffer_ptr;

// Do not call before moving_average_init has been called!
void print_buffer()
{
    int i;
    if(movav_iter>movav_buffer_length)
    {
		printf("\r\nIter = %i, Buffer pos = %i\r\n",movav_iter,movav_buffer_pos);
		printf("Buffer = [");
		for(i = 0;i<movav_buffer_length-1;i++)
		{
			printf("%0.2f, ",movav_buffer[i]);
        }
		printf("%0.2f]\r\n",movav_buffer[movav_buffer_length-1]);

	} else {
		 printf("Buffer not full yet...");
	}
    
}

int moving_average_init(const uint8_t nsamples)
{
	movav_iter = 0;
	movav_average = 0;

	if(nsamples<MIN_BUFFER_SIZE)
	{
		return MOVAV_ERR_LENGTH;
	}
	
	movav_buffer_pos = 0;
	movav_buffer_length = nsamples;
	movav_buffer_ptr = (sample_t*)&movav_buffer[0];

	return MOVAV_SUCCESS;
}

int moving_average(const sample_t* new_sample, average_t* average)
{	
	sample_t oldest_sample;
	movav_iter++;

	// Check the new position
	if(movav_buffer_pos==movav_buffer_length)
	{
		movav_buffer_pos = 0;
		oldest_sample = movav_buffer[0];
	} else 
	{
		oldest_sample = movav_buffer[movav_buffer_pos];
	}

	// Add new sample to buffer
	movav_buffer[movav_buffer_pos++] = *new_sample;
	
	// Check for first iteration
	if(movav_iter==1)
	{
		movav_average = *new_sample;
		*average = movav_average;
		return MOVAV_WARNING_LENGTH;
	}

	// Check for number of samples and compute cummulative mean if less than buffer size
	if(movav_iter<=movav_buffer_length)
	{
		movav_average = ((movav_iter-1)*movav_average + *new_sample)/movav_iter;
		*average = movav_average;
		if(movav_iter==movav_buffer_length)
		{
			movav_buffer_pos = 0;
		}
		return MOVAV_WARNING_LENGTH;
	}

	// Compute moving average
	movav_average = movav_average +(*new_sample-oldest_sample)/movav_buffer_length;
	*average = movav_average;

	//print_buffer();

	return MOVAV_SUCCESS;
}
