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
#include <stdlib.h>

#include "movav.h"
#include "tests.h"

void print_test_status(const char* test, int result);

int main(int argc, char* argv[])
{
	int length;
	int status;

	printf("\r\n");

	if(argc<2)
	{
		printf("Please enter buffer size as argument\r\n");
		return 1;
	}

	length = atoi(argv[1]);
	if(length>10)
	{
		printf("Please enter a buffer size in the range [2,10]\r\n");
		return 1;
	}
	
	status = test_moving_average_init(length);
	print_test_status("Moving average init",status);

	status = test_moving_average();
	print_test_status("Moving average",status);

	return 0;
}

void print_test_status(const char* test, int result)
{
	char* status = "PASS";
	if(result != 0)
	{
		status = "FAIL";
	}

	printf("Test status for \"%s\": %s\r\n", test, status);

}