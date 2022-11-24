#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef enum {
	NONE = 0, BEGIN, END, IF, THEN, WHILE, DO, CALL, ODD, TO, CONST, BAR, PROCEDURE, PROGRAM,
	ELSE, FOR, NUMBER, IDENT, PLUS, MINUS, SLASH, TIMES, EQU, NEQ, LSS, LEQ, GTR, GEQ, LPARENT,
	RPARENT, LBRACK, RBRACK, ASSIGN, SEMICOLON, COMMA, PERIOD, PERCENT
} TokenType;

char TagToken[][10] = {"NONE", "BEGIN", "END", "IF", "THEN", "WHILE", "DO", "CALL", "ODD","TO", 
	"CONST", "BAR", "PROCEDURE", "PROGRAM", "ELSE", "FOR", "NUMBER", "IDENT", "PLUS", "MINUS", "SLASH",
	"TIMES", "EQU", "NEQ", "LSS", "LEQ", "GTR", "GEQ", "LPARENT",
	"RPARENT", "LBRACK", "RBRACK", "ASSIGN", "SEMICOLON", "COMMA", "PERIOD", "PERCENT"};

char keyword[][10] = {"BEGIN", "END", "IF", "THEN", "WHILE", "DO", "CALL", "ODD","TO", "CONST",
 "BAR", "PROCEDURE", "PROGRAM", "ELSE", "FOR", "NUMBER"};

// typedef struct dictionary{
// } DICT;


char Ch;FILE *f; char str[100]; char* result;
TokenType token; int num = 0;

char getCh()
{
	return toupper(fgetc(f));
}

TokenType getToken()
{
	while(Ch == ' ' || Ch == '\n') Ch = getCh();	
	if (isalpha(Ch)) 
	{
		strcpy(str, "");
		while(isalpha(Ch) || isdigit(Ch)) {
			strncat(str, &Ch, 1);
			Ch = getCh();
		} 
		return IDENT;
	}
	else if(isdigit(Ch))
	{	
		num = 0;
		num = 10 * num + (Ch - 48);
		Ch = getCh();
		while(isdigit(Ch))
		{
			num = 10 * num + (Ch - 48);
			Ch = getCh();	
		} 
		return NUMBER;
	} 
	else if (Ch == ';') 
	{
		Ch = getCh();
		return SEMICOLON;
	} 
	else if (Ch == '+') 
	{
		Ch = getCh();
		return PLUS;
	}
	else if (Ch == '-') 
	{
		Ch = getCh();
		return MINUS;
	}
	else if (Ch == '*') 
	{
		Ch = getCh();
		return TIMES;
	}
	else if (Ch == '/') 
	{
		Ch = getCh();
		return SLASH;
	}
	else if (Ch == '=') 
	{
		Ch = getCh();
		return EQU;
	}
	else if (Ch == '!') 
	{
		Ch = getCh();
		if (Ch == '=') 
		{
			Ch = getCh();
			return NEQ;
		} else return NONE;
	}
	else if (Ch == '<') 
	{
		Ch = getCh();
		if(Ch == '=') 
		{
			Ch = getCh();
			return LEQ;
		}
		else 
		{
			Ch = getCh();
			return LSS;
		}	
	}
	else if (Ch == '>') 
	{
		Ch = getCh();
		if(Ch == '=') 
		{
			Ch = getCh();
			return GEQ;
		}
		else 
		{
			Ch = getCh();
			return GTR;
		}	
	}
	else if (Ch == '(') 
	{
		Ch = getCh();
		return LPARENT;
	}
	else if (Ch == ')') 
	{
		Ch = getCh();
		return RPARENT;
	}
	else if (Ch == '[') 
	{
		Ch = getCh();
		return LBRACK;
	}
	else if (Ch == ']') 
	{
		Ch = getCh();
		return RBRACK;
	}
	else if (Ch == ':') 
	{
		Ch = getCh();
		if (Ch == '=') 
		{
			Ch = getCh();
			return ASSIGN;
		}
		return NONE;
	}
	else if (Ch == ',') 
	{
		Ch = getCh();
		return COMMA;
	}
	else if (Ch == '.') 
	{
		Ch = getCh();
		return PERIOD;
	}
	else if (Ch == '%') 
	{
		Ch = getCh();
		return PERCENT;
	}
	else return NONE;
	
}

char *isKeyword(char *ident) 
{
	char * result;
	for(int i = 0; i < sizeof(keyword); i++)
	{
		if(strcmp(ident, keyword[i]) == 0)
		{
			strcpy(result, keyword[i]);
			return result;
		} else 
		{
			return str;
		}
	}
}

int main() {
	f = fopen("program.txt","r");
	
	Ch = getCh();
	while(!feof(f)) 
	{
		token = getToken();
		result = TagToken[token];
		if(strcmp(result, "NUMBER") == 0) 
		{
			printf("%d\n", num);
		}
		else if(strcmp(result, "IDENT") == 0)
		{
			printf("%s\n", isKeyword(result));
		} else printf("%s\n", result);
	}
	fclose(f);
}