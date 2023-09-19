#include "main.h"
#include <unistd.h>

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @buff_ind: Index at which to add the next character, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
{
write(1, &buffer[0], *buff_ind);
*buff_ind = 0;
}
}
