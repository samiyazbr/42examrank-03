#include "get_next_line.h"

char *get_next_line(int fd)
{
    int i = 0;
    int rd = 0;
    char ch;
    char *line;

    line = malloc(1000000);
    if (BUFFER_SIZE <= 0 || fd < 0)
        return (NULL);
    rd = read(fd, &ch, BUFFER_SIZE - BUFFER_SIZE + 1);
    while (rd > 0)
    {
        line[i++] = ch;
        if (ch == '\n')
            break;
        rd = read(fd, &ch, BUFFER_SIZE - BUFFER_SIZE + 1);
    }
    line[i] = '\0';
    if (rd == -1 || i == 0 || (!line[i - 1] && !rd))
    {
        free(line);
        return (NULL);
    }
    return (line);
}

int main (int ac, char **av)
{
	int fd;
	char *line;
	
	if(ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		line = get_next_line(fd);
		while(line)
		{
			printf("%s\n", line);
			line = get_next_line(fd);
		}
	}
	return (0);
}