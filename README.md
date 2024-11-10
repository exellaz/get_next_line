# get_next_line

<p align="center">
	<img src="https://github.com/exellaz/get_next_line/blob/master/gnl_badge.png"/>
</p>

The goal of this project is to create a function that reads from a file descriptor line by line and returns its contents. The bonus portion will require the function to manage multiple file descriptors simultaneously without losing the reading thread of each file descriptor. This function will be added into libft and will be used as the main way to read from file descriptors in future projects.

## Status
Finished: 2023-11-20. Grade: 112/125.

## Usage
Example ``main.c``:
```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(int ac, char *av[])
{
	int		fd;
	char	*line;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	close(fd);
	return (0);
}
```
Compile using:
```bash
gcc main.c get_next_line.c get_next_line_utils.c
```
``BUFFER_SIZE`` can also be specified at compilation to override the default of 1024
```bash
gcc -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
```
Execute using:
```bash
./a.out [file]
```
This should print out the contents of the given file.
