
#line 1 "scanner.re"

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "scanner.h"
#include "parser.h"
#include "y.tab.h"

extern YYSTYPE yylval;

#ifndef MAX
#define MAX(a,b) (((a)>(b))?(a):(b))
#endif

#define	BSIZE	8192

#define	YYCTYPE		char
#define	YYCURSOR	cursor
#define	YYLIMIT		lim
#define	YYMARKER	ptr
#define	YYFILL(n)	{cursor = fill(cursor);}

#define	RETURN(i)	{cur = cursor; return i;}


Scanner::Scanner(std::istream& i) : in(i),
	bot(NULL), tok(NULL), ptr(NULL), cur(NULL), pos(NULL), lim(NULL),
	top(NULL), eof(NULL), tchar(0), tline(0), cline(1) {
    ;
}

char *Scanner::fill(char *cursor){
    if(!eof){
	uint cnt = tok - bot;
	if(cnt){
	    memcpy(bot, tok, lim - tok);
	    tok = bot;
	    ptr -= cnt;
	    cursor -= cnt;
	    pos -= cnt;
	    lim -= cnt;
	}
	if((top - lim) < BSIZE){
	    char *buf = new char[(lim - bot) + BSIZE];
	    memcpy(buf, tok, lim - tok);
	    tok = buf;
	    ptr = &buf[ptr - bot];
	    cursor = &buf[cursor - bot];
	    pos = &buf[pos - bot];
	    lim = &buf[lim - bot];
	    top = &lim[BSIZE];
	    delete [] bot;
	    bot = buf;
	}
	if((cnt = in.rdbuf()->sgetn((char*) lim, BSIZE)) != BSIZE){
	    eof = &lim[cnt]; *eof++ = '\n';
	}
	lim += cnt;
    }
    return cursor;
}

#line 72 "scanner.re"


int Scanner::echo(std::ostream &out){
    char *cursor = cur;

    // Catch EOF
    if (eof && cursor == eof)
    	return 0;

    tok = cursor;
echo:

#line 7 "<stdout>"
{
	YYCTYPE yych;
	unsigned int yyaccept;
	goto yy0;
	++YYCURSOR;
yy0:
	if((YYLIMIT - YYCURSOR) < 7) YYFILL(7);
	yych = *YYCURSOR;
	switch(yych){
	case 0x0A:	goto yy4;
	case '/':	goto yy2;
	default:	goto yy6;
	}
yy2:	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	switch(yych){
	case '*':	goto yy7;
	default:	goto yy3;
	}
yy3:
#line 91 "scanner.re"
{ goto echo; }
#line 30 "<stdout>"
yy4:	++YYCURSOR;
	goto yy5;
yy5:
#line 87 "scanner.re"
{ if(cursor == eof) RETURN(0);
				  out.write((const char*)(tok), (const char*)(cursor) - (const char*)(tok));
				  tok = pos = cursor; cline++;
				  goto echo; }
#line 39 "<stdout>"
yy6:	yych = *++YYCURSOR;
	goto yy3;
yy7:	yych = *++YYCURSOR;
	switch(yych){
	case '!':	goto yy9;
	default:	goto yy8;
	}
yy8:	YYCURSOR = YYMARKER;
	switch(yyaccept){
	case 0:	goto yy3;
	}
yy9:	yych = *++YYCURSOR;
	switch(yych){
	case 'r':	goto yy10;
	default:	goto yy8;
	}
yy10:	yych = *++YYCURSOR;
	switch(yych){
	case 'e':	goto yy11;
	default:	goto yy8;
	}
yy11:	yych = *++YYCURSOR;
	switch(yych){
	case '2':	goto yy12;
	default:	goto yy8;
	}
yy12:	yych = *++YYCURSOR;
	switch(yych){
	case 'c':	goto yy13;
	default:	goto yy8;
	}
yy13:	++YYCURSOR;
	goto yy14;
yy14:
#line 84 "scanner.re"
{ out.write((const char*)(tok), (const char*)(&cursor[-7]) - (const char*)(tok));
				  tok = cursor;
				  RETURN(1); }
#line 78 "<stdout>"
}
#line 92 "scanner.re"

}


int Scanner::scan(){
    char *cursor = cur;
    uint depth;

scan:
    tchar = cursor - pos;
    tline = cline;
    tok = cursor;

#line 82 "<stdout>"
{
	YYCTYPE yych;
	unsigned int yyaccept;
	goto yy15;
	++YYCURSOR;
yy15:
	if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	switch(yych){
	case 0x09:	case ' ':	goto yy33;
	case 0x0A:	goto yy35;
	case '"':	goto yy23;
	case '\'':	goto yy25;
	case '(':
	case ')':	case ';':	case '=':	case '\\':	case '|':	goto yy29;
	case '*':	goto yy21;
	case '+':	case '?':	goto yy30;
	case '/':	goto yy19;
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy31;
	case '[':	goto yy27;
	case '{':	goto yy17;
	default:	goto yy37;
	}
yy17:	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	switch(yych){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy63;
	default:	goto yy18;
	}
yy18:
#line 105 "scanner.re"
{ depth = 1;
				  goto code;
				}
#line 176 "<stdout>"
yy19:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '*':	goto yy61;
	default:	goto yy20;
	}
yy20:
#line 131 "scanner.re"
{ RETURN(*tok); }
#line 185 "<stdout>"
yy21:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '/':	goto yy59;
	default:	goto yy22;
	}
yy22:
#line 133 "scanner.re"
{ yylval.op = *tok;
				  RETURN(CLOSE); }
#line 195 "<stdout>"
yy23:	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	switch(yych){
	case 0x0A:	goto yy24;
	default:	goto yy55;
	}
yy24:
#line 122 "scanner.re"
{ fatal("unterminated string constant (missing \")"); }
#line 205 "<stdout>"
yy25:	yyaccept = 2;
	yych = *(YYMARKER = ++YYCURSOR);
	switch(yych){
	case 0x0A:	goto yy26;
	default:	goto yy50;
	}
yy26:
#line 123 "scanner.re"
{ fatal("unterminated string constant (missing ')"); }
#line 215 "<stdout>"
yy27:	yyaccept = 3;
	yych = *(YYMARKER = ++YYCURSOR);
	switch(yych){
	case 0x0A:	goto yy28;
	default:	goto yy44;
	}
yy28:
#line 129 "scanner.re"
{ fatal("unterminated range (missing ])"); }
#line 225 "<stdout>"
yy29:	yych = *++YYCURSOR;
	goto yy20;
yy30:	yych = *++YYCURSOR;
	goto yy22;
yy31:	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy42;
yy32:
#line 148 "scanner.re"
{ cur = cursor;
				  yylval.symbol = Symbol::find(token());
				  return ID; }
#line 237 "<stdout>"
yy33:	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy40;
yy34:
#line 152 "scanner.re"
{ goto scan; }
#line 243 "<stdout>"
yy35:	++YYCURSOR;
	goto yy36;
yy36:
#line 154 "scanner.re"
{ if(cursor == eof) RETURN(0);
				  pos = cursor; cline++;
				  goto scan;
	    			}
#line 252 "<stdout>"
yy37:	++YYCURSOR;
	goto yy38;
yy38:
#line 159 "scanner.re"
{ std::cerr << "unexpected character: " << *tok << std::endl;
				  goto scan;
				}
#line 260 "<stdout>"
yy39:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy40;
yy40:	switch(yych){
	case 0x09:	case ' ':	goto yy39;
	default:	goto yy34;
	}
yy41:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy42;
yy42:	switch(yych){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy41;
	default:	goto yy32;
	}
yy43:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy44;
yy44:	switch(yych){
	case 0x0A:	goto yy45;
	case '\\':	goto yy46;
	case ']':	goto yy47;
	default:	goto yy43;
	}
yy45:	YYCURSOR = YYMARKER;
	switch(yyaccept){
	case 0:	goto yy18;
	case 1:	goto yy24;
	case 2:	goto yy26;
	case 3:	goto yy28;
	}
yy46:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch(yych){
	case 0x0A:	goto yy45;
	default:	goto yy43;
	}
yy47:	++YYCURSOR;
	goto yy48;
yy48:
#line 125 "scanner.re"
{ cur = cursor;
				  yylval.regexp = ranToRE(token());
				  return RANGE; }
#line 371 "<stdout>"
yy49:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy50;
yy50:	switch(yych){
	case 0x0A:	goto yy45;
	case '\'':	goto yy52;
	case '\\':	goto yy51;
	default:	goto yy49;
	}
yy51:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch(yych){
	case 0x0A:	goto yy45;
	default:	goto yy49;
	}
yy52:	++YYCURSOR;
	goto yy53;
yy53:
#line 118 "scanner.re"
{ cur = cursor;
				  yylval.regexp = strToCaseInsensitiveRE(token());
				  return STRING; }
#line 398 "<stdout>"
yy54:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy55;
yy55:	switch(yych){
	case 0x0A:	goto yy45;
	case '"':	goto yy57;
	case '\\':	goto yy56;
	default:	goto yy54;
	}
yy56:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch(yych){
	case 0x0A:	goto yy45;
	default:	goto yy54;
	}
yy57:	++YYCURSOR;
	goto yy58;
yy58:
#line 114 "scanner.re"
{ cur = cursor;
				  yylval.regexp = strToRE(token());
				  return STRING; }
#line 425 "<stdout>"
yy59:	++YYCURSOR;
	goto yy60;
yy60:
#line 111 "scanner.re"
{ tok = cursor;
				  RETURN(0); }
#line 432 "<stdout>"
yy61:	++YYCURSOR;
	goto yy62;
yy62:
#line 108 "scanner.re"
{ depth = 1;
				  goto comment; }
#line 439 "<stdout>"
yy63:	++YYCURSOR;
	if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	goto yy64;
yy64:	switch(yych){
	case ',':	goto yy67;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy63;
	case '}':	goto yy65;
	default:	goto yy45;
	}
yy65:	++YYCURSOR;
	goto yy66;
yy66:
#line 136 "scanner.re"
{ yylval.extop.minsize = atoi((char *)tok+1);
				  yylval.extop.maxsize = atoi((char *)tok+1);
				  RETURN(CLOSESIZE); }
#line 467 "<stdout>"
yy67:	yych = *++YYCURSOR;
	switch(yych){
	case '}':	goto yy68;
	default:	goto yy71;
	}
yy68:	++YYCURSOR;
	goto yy69;
yy69:
#line 144 "scanner.re"
{ yylval.extop.minsize = atoi((char *)tok+1);
				  yylval.extop.maxsize = -1;
				  RETURN(CLOSESIZE); }
#line 480 "<stdout>"
yy70:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy71;
yy71:	switch(yych){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy70;
	case '}':	goto yy72;
	default:	goto yy45;
	}
yy72:	++YYCURSOR;
	goto yy73;
yy73:
#line 140 "scanner.re"
{ yylval.extop.minsize = atoi((char *)tok+1);
				  yylval.extop.maxsize = MAX(yylval.extop.minsize,atoi(strchr((char *)tok, ',')+1));
				  RETURN(CLOSESIZE); }
#line 507 "<stdout>"
}
#line 162 "scanner.re"


code:

#line 511 "<stdout>"
{
	YYCTYPE yych;
	unsigned int yyaccept;
	goto yy74;
	++YYCURSOR;
yy74:
	if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	switch(yych){
	case 0x0A:	goto yy80;
	case '"':	goto yy84;
	case '\'':	goto yy85;
	case '{':	goto yy78;
	case '}':	goto yy76;
	default:	goto yy82;
	}
yy76:	++YYCURSOR;
	goto yy77;
yy77:
#line 166 "scanner.re"
{ if(--depth == 0){
					cur = cursor;
					yylval.token = new Token(token(), tline);
					return CODE;
				  }
				  goto code; }
#line 538 "<stdout>"
yy78:	++YYCURSOR;
	goto yy79;
yy79:
#line 172 "scanner.re"
{ ++depth;
				  goto code; }
#line 545 "<stdout>"
yy80:	++YYCURSOR;
	goto yy81;
yy81:
#line 174 "scanner.re"
{ if(cursor == eof) fatal("missing '}'");
				  pos = cursor; cline++;
				  goto code;
				}
#line 554 "<stdout>"
yy82:	++YYCURSOR;
	goto yy83;
yy83:
#line 178 "scanner.re"
{ goto code; }
#line 560 "<stdout>"
yy84:	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	switch(yych){
	case 0x0A:	goto yy83;
	default:	goto yy91;
	}
yy85:	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	switch(yych){
	case 0x0A:	goto yy83;
	default:	goto yy87;
	}
yy86:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy87;
yy87:	switch(yych){
	case 0x0A:	goto yy88;
	case '\'':	goto yy82;
	case '\\':	goto yy89;
	default:	goto yy86;
	}
yy88:	YYCURSOR = YYMARKER;
	switch(yyaccept){
	case 0:	goto yy83;
	}
yy89:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch(yych){
	case 0x0A:	goto yy88;
	default:	goto yy86;
	}
yy90:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy91;
yy91:	switch(yych){
	case 0x0A:	goto yy88;
	case '"':	goto yy82;
	case '\\':	goto yy92;
	default:	goto yy90;
	}
yy92:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch(yych){
	case 0x0A:	goto yy88;
	default:	goto yy90;
	}
}
#line 179 "scanner.re"


comment:

#line 618 "<stdout>"
{
	YYCTYPE yych;
	unsigned int yyaccept;
	goto yy93;
	++YYCURSOR;
yy93:
	if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	switch(yych){
	case 0x0A:	goto yy98;
	case '*':	goto yy95;
	case '/':	goto yy97;
	default:	goto yy100;
	}
yy95:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '/':	goto yy103;
	default:	goto yy96;
	}
yy96:
#line 193 "scanner.re"
{ goto comment; }
#line 641 "<stdout>"
yy97:	yych = *++YYCURSOR;
	switch(yych){
	case '*':	goto yy101;
	default:	goto yy96;
	}
yy98:	++YYCURSOR;
	goto yy99;
yy99:
#line 189 "scanner.re"
{ if(cursor == eof) RETURN(0);
				  tok = pos = cursor; cline++;
				  goto comment;
				}
#line 655 "<stdout>"
yy100:	yych = *++YYCURSOR;
	goto yy96;
yy101:	++YYCURSOR;
	goto yy102;
yy102:
#line 187 "scanner.re"
{ ++depth;
				  goto comment; }
#line 664 "<stdout>"
yy103:	++YYCURSOR;
	goto yy104;
yy104:
#line 183 "scanner.re"
{ if(--depth == 0)
					goto scan;
				    else
					goto comment; }
#line 673 "<stdout>"
}
#line 194 "scanner.re"

}

void Scanner::fatal(char *msg){
    std::cerr << "line " << tline << ", column " << (tchar + 1) << ": "
	<< msg << std::endl;
    exit(1);
}