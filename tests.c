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

#include "tests.h"
#include <stdio.h>

static uint8_t buffer_size;

int test_moving_average_init(uint8_t length)
{
	int status;

	// Test too small length
	status = moving_average_init(0);
	if(status!=MOVAV_ERR_LENGTH)
	{
		return FAIL;
	}

	// Test valid length
	status = moving_average_init(length);
	if(status!=MOVAV_SUCCESS)
	{
		return FAIL;
	}

	buffer_size = length;

	return PASS;
}

int test_moving_average()
{
	const sample_t samples[16] = {1.0, 1.2, 1.4, 1.6, 1.8, 2.0, 2.2, 2.4, 2.6, 2.8, 3.0, 3.2, 3.4, 3.6, 3.8, 4.0};
	int status;
	average_t av;

	// First fill the buffer
	int i;
	for(i=0;i<16;i++)
	{
		status = moving_average(&samples[i],&av);
		if(i<buffer_size)
		{
			if(status!=MOVAV_WARNING_LENGTH)
			{
				return FAIL;
			}
		} else {
			if(status!=MOVAV_SUCCESS)
			{
				return FAIL;
			}
		}
		printf("Moving average at iteration %i: %0.2f\r\n",i,av);
	}

	return PASS;
}