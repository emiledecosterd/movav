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

#ifndef _MOVAV_H_
#define _MOVAV_H_

#include <stdint.h>

#define MOVAV_BUFFER_SIZE 255 /* Number of words. Take care, length of the buffer depends on the memory width! */
#define MIN_BUFFER_SIZE 2

/** Error codes */
#define MOVAV_SUCCESS 0
#define MOVAV_ERR -1 /* Generic error */
#define MOVAV_ERR_LENGTH -2 /* Issued when the length is less than 2 or greater than the buffer size */
#define MOVAV_WARNING	1
#define MOVAV_WARNING_LENGTH 2 /* Issued when the average is computed on less samples than the specified length*/

/** (32 bits value) representing a data sample. Change to whatever type is used **/
typedef float sample_t;


/** Simple type definition for readability **/
typedef sample_t average_t;


/**
 * @brief 				initializes the moving average filter
 * @param	length		number of samples over which the average is computed. Max 255 samples
 * @return				status of the operation
 */
int moving_average_init(const uint8_t nsamples);


/**
 * @brief 				computes the average based on a new sample
 * @param	new_sample	last acquired sample
 * @param	average		a pointer to the variable where the new average will be written to
 * @return				status of the operation
 */
int moving_average(const sample_t* new_sample, average_t* average);

#endif