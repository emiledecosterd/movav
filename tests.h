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

#ifndef _TESTS_H_
#define _TESTS_H_

#include "movav.h"

#define PASS 0
#define FAIL 1

int test_moving_average_init(uint8_t length);
int test_moving_average();

#endif