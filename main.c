/*****************************************************************************
 * String or not
 *
 * Author: Anthony Papillon (2016)
 *****************************************************************************/

/*****************************************************************************
 * Header inclusion
 *****************************************************************************/
#include <stdio.h>
#include <string.h>

/*****************************************************************************
 * Macros definitions
 *****************************************************************************/
#define STRING1 "\x3123toto"
#define STRING2 "\x31" "23toto"
#define STRING3 (unsigned char*)"\x3123toto"

/*****************************************************************************
 * Main function
 *****************************************************************************/
int main(int argc, char **argv) {

	// Variables definitions
	char buffer[10];
	int rmc, rsc;

	char ultimate[] = "\x3123toto";

	// Hexa, Octal and char
	printf("\x31 \061 1\n");

	// Preconditions
	printf("'\\x31' == '1' ? %s\n", '\x31' == '1' ? "TRUE": "FALSE");

	// Prepare buffer to compare
	buffer[0] = 0x31;
	buffer[1] = '2';
	buffer[2] = '3';
	buffer[3] = 't';
	buffer[4] = 'o';
	buffer[5] = 't';
	buffer[6] = 'o';
	buffer[7] = 0x00;

	// Test1
	rmc = memcmp(buffer, STRING1, 7);
	rsc = strncmp(buffer, STRING1, 7);
	printf("1st test - rmc: %d - rsc: %d - buffer: %s - STRING1: %s\n", rmc, rsc, buffer, STRING1);

	// Test2
	rmc = memcmp(buffer, STRING2, 7);
	rsc = strncmp(buffer, STRING2, 7);
	printf("2nd test - rmc: %d - rsc: %d - buffer: %s - STRING2: %s\n", rmc, rsc, buffer, STRING2);

	// Test3
	rmc = memcmp(buffer, STRING3, 7);
	rsc = strncmp(buffer, STRING3, 7);
	printf("3rd test - rmc: %d - rsc: %d - buffer: %s - STRING3: %s\n", rmc, rsc, buffer, STRING3);

	// Test4 - Ultimate
	rmc = memcmp(buffer, ultimate, 7);
	rsc = strncmp(buffer, ultimate, 7);
	printf("4rd test - rmc: %d - rsc: %d - buffer: %s - ultimate: %s\n", rmc, rsc, buffer, ultimate);

	return(0);
}
