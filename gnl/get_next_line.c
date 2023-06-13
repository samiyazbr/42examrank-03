#include "get_next_line.h"

char    *get_next_line(int fd)
{
        int             i;
        int             byte;
        char    *buffer;
        char    character;

        if ((fd < 0) || (BUFFER_SIZE <= 0))
                return (NULL);
        i = 0;
        byte = read(fd, &character, 1);
        buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
        while (byte > 0)
        {
                buffer[i++] = character;
                if (character == '\n')
                        break ;
                byte = read(fd, &character, 1);
        }
        if ((byte <= 0) && (i == 0))
                return (free(buffer), NULL);
        buffer[i] = '\0';
        return (buffer);
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
