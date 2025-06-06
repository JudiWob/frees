#include "free_header.h"


char *get_next_line(int fd)
{
	char		*buffer;
	static char *rest;
	char		*line;
	char 		*temp;
	int			bytes_read;
	int 		i;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if(rest)
		{
			free(rest);
			rest = NULL;
		}
		return (NULL);
	}
	if(rest)
	{
		line = ft_strdup(rest);
		if (!line)
		{
			return (NULL);
		}
		free(rest);
		rest = NULL;
	}
	else
	{
		line = ft_strdup("");
		if (!line)
		{
			return (NULL);
		}
	}
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!buffer)
		return(NULL);
	while(nl_check(line) == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if(bytes_read < 0)
			return (NULL);
		if(bytes_read == 0)
		{
			free(buffer);
			if(line[0] == '\0')
			{
				printf("HERE");
				free(line);
				return(NULL);
			}
			return(line);
		}
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(line, buffer);
		if(!temp)
			return(NULL);
		free(line);
		line = temp;
	}
	i = 0;
	while(line[i] && line[i] != '\n')
		i++;
	rest = ft_strdup(&line[i+1]);
	line[i+1] = '\0';
	free(buffer);
	return(line);

}

int main()
{
	int fd;
	char *line;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}

	line = get_next_line(fd);
	if (line)
	{
		printf("%s", line);
		free(line);
	}
	line = get_next_line(fd);
	if (line)
	{
		printf("%s", line);
		free(line);
	}
		line = get_next_line(fd);
	if (line)
	{
		printf("%s", line);
		free(line);
	}

	close(fd);
	return (0);
}

int nl_check(char *s)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s)
{
	size_t	len;
	size_t	i;
	char	*db;

	len = ft_strlen(s);
	i = 0;
	db = (char *)malloc((len + 1) * sizeof(char));
	if (db == NULL)
		return (NULL);
	while (s[i])
	{
		db[i] = s[i];
		i++;
	}
	db[i] = '\0';
	return (db);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;
	char	*new;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	j = 0;
	new = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

