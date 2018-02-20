

#ifndef __MY_LIST_H__
#define __MY_LIST_H__

typedef struct     s_list
{
	void             *data;
	struct s_list    *next;
} t_list;

#endif
