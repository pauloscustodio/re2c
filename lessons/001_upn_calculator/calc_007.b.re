/* re2c lesson_001, calc_006, (c) M. Boerger 2006 */
/*!ignore:re2c

- optimizing the generated code by using -b command line switch of re2c
  . This tells re2c to generate code that uses a decision table. The -b switch
    also contains the -s behavior. 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DEBUG(stmt) stmt

int  stack[4];
int  depth = 0;

int push_num(const char *t, const char *l, int radix)
{
	int num = 0;
	
	if (depth >= sizeof(stack))
	{
		return 3;
	}

	--t;
	while(++t < l)
	{
		num = num * radix + (*t - '0');
	}
	DEBUG(printf("Num: %d\n", num));

	stack[depth++] = num;
	return 0;
}

int stack_add()
{
	if (depth < 2) return 4;
	
	--depth;
	stack[depth-1] = stack[depth-1] + stack[depth];
	return 0;
}

int stack_sub()
{
	if (depth < 2) return 4;

	--depth;
	stack[depth-1] = stack[depth-1] - stack[depth];
	return 0;
}

int scan(char *s, int l)
{
	char *p = s;
	char *t;
	int res = 0;
	
	#define YYCTYPE         char
	#define YYCURSOR        p
	
    if (l > 1 && s[l-2] == '0' && s[l-1] >= '0' && s[l-1] <= '9') return 2;

	while(!res)
	{
		t = p;
/*!re2c
	re2c:indent:top    = 2;
	re2c:yyfill:enable = 0;

	DIGIT	= [0-9] ;
	OCT		= "0" DIGIT+ ;
	INT		= "0" | ( [1-9] DIGIT* ) ;
	WS		= [ \t]+ ;

	WS		{ continue; }
	OCT		{ res = push_num(t, p, 8);	continue; }
	INT		{ res = push_num(t, p, 10); continue; }
	"+"		{ res = stack_add();		continue; }
	"-"		{ res = stack_sub();		continue; }
	"\000"  { res = depth == 1 ? 0 : 2;	continue; }
	[^]		{ res = 1; 					continue; }
*/
	}
	return res;
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		char *inp;
		int res = 0, argp = 0, len;
		
		while(!res && ++argp < argc)
		{
			inp = argv[argp];
			len = strlen(inp);
			if (inp[0] == '\"' && inp[len-1] == '\"')
			{
				++inp;
				len -=2;
			}
			res = scan(inp, len);
		}
		switch(res)
		{
		case 0:
			printf("Result: %d\n", stack[0]);
			return 0;
		case 1:
			fprintf(stderr, "Illegal character in input.\n");
			return 1;
		case 2:
			fprintf(stderr, "Premature end of input.\n");
			return 2;
		case 3:
			fprintf(stderr, "Stack overflow.\n");
			return 3;
		case 4:
			fprintf(stderr, "Stack underflow.\n");
			return 4;
		}
	}
	else
	{
		fprintf(stderr, "%s <expr>\n", argv[0]);
		return 0;
	}
}
