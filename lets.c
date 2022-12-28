# include <unistd.h>
2	# include <stdio.h>
3	# include <stdlib.h>
4	# include <fcntl.h>
5	# ifndef BUFFER_SIZE
6	#  define BUFFER_SIZE 100
7	# endif
8	
9	char    *get_next_line(int fd);
10	char    *gnl_strjoin(char *line, char *buffer);
11	char    *gnl_buffer_clear(char *buffer);
12	int     gnl_strlen(char *str);
13	
14	char    *get_next_line(int fd)
15	{
16	    char        *line;
17	    static char    buffer[BUFFER_SIZE + 1];
18	
19	    line = 0;
20	    while (read(fd, buffer, BUFFER_SIZE) > 0)
21	    {
22	        gnl_strjoin(line, buffer);
23	        gnl_buffer_clear(buffer);
24	    }
25	    return (line);
26	}
27	
28	char    *gnl_strjoin(char *line, char *buffer)
29	{
30	    int    il;
31	    int    ib;
32	    int    new_len;
33	
34	    il = gnl_strlen(line) - 1;
35	    ib = 0;
36	    if (!line)
37	        il = 0;
38	    new_len = il + gnl_strlen(buffer);
39	    line = (char *)malloc(sizeof(char) * (new_len + 1));
40	    if (!line)
41	        return (0);
42	    while (buffer[ib] && buffer[ib] != '\n')
43	    {
44	        line[il] = buffer[ib];
45	        il++;
46	        ib++;
47	    }
48	    return (line);
49	}
50	
51	char    *gnl_buffer_clear(char *buffer)
52	{
53	    int    i;
54	    int    ii;
55	
56	    i = 0;
57	    ii = 0;
58	    while (buffer && buffer[i] != '\n')
59	    {
60	        buffer[i] = 0;
61	        i++;
62	        if (buffer[i] == '\n')
63	        {
64	            buffer[i] = 0;
65	            i++;
66	            while (buffer && ii < i)
67	            {
68	                buffer[ii] = buffer[i];
69	                buffer[i] = 0;
70	                i++;
71	                ii++;
72	            }
73	        }
74	    }
75	    return (buffer);
76	}
77	
78	int    gnl_strlen(char *str)
79	{
80	    int    i;
81	
82	    i = 0;
83	    while (str && str[i] != '\n')
84	        i++;
85	    return (i);
86	}
87	
88	int    main(void)
89	{
90	    int        fd;
91	    char    *str;
92	
93	    fd = open("test.txt", O_RDONLY);
94	    str = get_next_line(fd);
95	    while (str)
96	    {
97	        printf("%s", str);
98	        free(str);
99	        str = get_next_line(fd);
100	    }
101	    free(str);
102	}