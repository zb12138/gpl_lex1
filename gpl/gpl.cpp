
/*  A Bison parser, made from gpl.y
	by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	FUNC	257
#define	PRINT	258
#define	RETURN	259
#define	CONTINUE	260
#define	IF	261
#define	THEN	262
#define	ELSE	263
#define	FI	264
#define	WHILE	265
#define	DO	266
#define	DONE	267
#define	INT	268
#define	EQ	269
#define	NE	270
#define	LT	271
#define	LE	272
#define	GT	273
#define	GE	274
#define	UMINUS	275
#define	INTEGER	276
#define	IDENTIFIER	277
#define	TEXT	278

//#line 1 "gpl.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <Map>
#include <algorithm>
#include <string>


	/* constant */
#define LAB_MIN 1
#define MODIFIED 1
#define UNMODIFIED 0

/* symbol */
#define SYM_UNDEF 0
#define SYM_VAR 1
#define SYM_FUNC 2
#define SYM_TEXT 3
#define SYM_INT 4
#define SYM_LABEL 5

/* tac */
#define TAC_UNDEF 0 /* undefine */
#define TAC_ADD 1 /* a=b+c */
#define TAC_SUB 2 /* a=b-c */
#define TAC_MUL 3 /* a=b*c */
#define TAC_DIV 4 /* a=b/c */
#define TAC_EQ 5 /* a=(b==c) */
#define TAC_NE 6 /* a=(b!=c) */
#define TAC_LT 7 /* a=(b<c) */
#define TAC_LE 8 /* a=(b<=c) */
#define TAC_GT 9 /* a=(b>c) */
#define TAC_GE 10 /* a=(b>=c) */
#define TAC_NEG 11 /* a=-b */
#define TAC_COPY 12 /* a=b */
#define TAC_GOTO 13 /* goto a */
#define TAC_IFZ 14 /* ifz b goto a */
#define TAC_BEGINFUNC 15 /* function begin */
#define TAC_ENDFUNC 16 /* function end */
#define TAC_LABEL 17 /* label a */
#define TAC_VAR 18 /* int a */
#define TAC_FORMAL 19 /* formal a */
#define TAC_ACTUAL 20 /* actual a */
#define TAC_CALL 21 /* a=call b */
#define TAC_RETURN 22 /* return a */

/* register */
#define R_UNDEF -1
#define R_FLAG 0
#define R_IP 1
#define R_BP 2
#define R_JP 3
#define R_TP 4
#define R_GEN 5
#define R_NUM 16

/* frame */
#define FORMAL_OFF -4 	/* first formal parameter */
#define OBP_OFF 0 		/* dynamic chain */
#define RET_OFF 4 		/* ret address */
#define LOCAL_OFF 8 		/* local var */

typedef struct symb
{
	/*
		type:SYM_VAR name:abc value:98 offset:-1
		type:SYM_VAR name:bcd value:99 offset:4
		type:SYM_LABEL name:L1/max
		type:SYM_INT value:1
		type:SYM_FUNC name:max address:1234
		type:SYM_TEXT name:"hello" lable:10
	*/
	int type;
	int store; /* 0:global, 1:local */
	char *name;
	int offset;
	int value;
	int lable;
	struct tac *address; /* SYM_FUNC */
	struct symb *next;
} SYMB;

typedef struct tac /* TAC instruction node */
{
	struct tac  *next; /* Next instruction */
	struct tac  *prev; /* Previous instruction */
	int op; /* TAC instruction */
	SYMB *a;
	SYMB *b;
	SYMB *c;
} TAC;

typedef struct enode /* Parser expression */
{
	struct enode *next; /* For argument lists */
	TAC *tac; /* The code */
	SYMB *ret; /* Where the result is */
} ENODE;

typedef struct keyw
{
	int id;
	char name[100];
} KEYW;

typedef struct regdesc /* Reg descriptor */
{
	struct symb *name; /* Thing in reg */
	int modified; /* If needs spilling */
} REGDESC;


//#line 116 "gpl.y"
typedef union
{
	char character;
	char *string;
	SYMB *symb;
	TAC *tac;
	ENODE	*enode;
} YYSTYPE;
//#line 180 "gpl.y"
int yylex();
int yyerror(char *str);
int main(int argc, char *argv[]);
SYMB *mkconst(int n);
char *mklstr(int i);
SYMB *mklabel(char *name);
SYMB *get_symb(void);
void free_symb(SYMB *s);
ENODE *get_enode(void);
void free_enode(ENODE *e);
void *safe_malloc(int n);
TAC *mktac(int op, SYMB *a, SYMB *b, SYMB *c);
TAC *join_tac(TAC *c1, TAC *c2);
void insert(SYMB **symbtab, SYMB *sym);
SYMB *lookup(SYMB *symbtab, char *name);
SYMB *getvar(char *name);
TAC *do_func(SYMB *name, TAC *args, TAC *code);
TAC *declare_var(char *name);
TAC *declare_para(char *name);
SYMB *declare_func(char *name);
TAC *do_assign(SYMB *var, ENODE *expr);
ENODE *do_bin(int binop, ENODE *expr1, ENODE *expr2);
ENODE *do_cmp(int binop, ENODE *expr1, ENODE *expr2);
ENODE *do_un(int unop, ENODE *expr);
ENODE *do_call_ret(char *name, ENODE *arglist);
TAC *do_call(char *name, ENODE *arglist);
TAC *do_lib(char *name, SYMB *arg);
TAC *do_if(ENODE *expr, TAC *stmt);
TAC *do_test(ENODE *expr, TAC *stmt1, TAC *stmt2);
TAC *do_while(ENODE *expr, TAC *stmt);
SYMB *mktext(char *text);
SYMB *mktmp(void);
SYMB *mkvar(char *name);
ENODE *mkenode(ENODE *next, SYMB *ret, TAC *code);
void tac_print(TAC *i);
char *ts(SYMB *s, char *str);
void error(char *str);
void cg();
void cg_init();
void cg_code(TAC *c);
void cg_bin(char *op, SYMB *a, SYMB *b, SYMB *c);
void cg_cmp(int op, SYMB *a, SYMB *b, SYMB *c);
void cg_copy(SYMB *a, SYMB *b);
void cg_cond(char *op, SYMB *a, char *l);
void cg_return(SYMB *a);
void cg_data(void);
void cg_str(SYMB *s);
void flush_all(void);
void spill_all(void);
void spill_one(int r);
void load_reg(int r, SYMB *n);
void clear_desc(int r);
void insert_desc(int r, SYMB *n, int mod);
int get_rreg(SYMB *c);
int get_areg(SYMB *b, int cr);
void cg_head();
void cg_lib();

int mode;
TAC *tac_first, *tac_last;
int LocalScope, scope;
SYMB *GlobalSymbolTable, *LocalSymbolTable;
int next_tmp;
int next_label;
SYMB *symb_list;
ENODE *enode_list;
int line;
char character;
char token[1000];
REGDESC rdesc[R_NUM];
int tos; /* top of static */
int tof; /* top of frame */
int oof; /* offset of formal */
int oon; /* offset of next frame */
KEYW keywords[100] =
{
	{INT,"int"},
	{PRINT,"print"},
	{RETURN,"return"},
	{CONTINUE,"continue"},
	{IF,"if"},
	{THEN,"then"},
	{ELSE,"else"},
	{FI,"fi"},
	{WHILE,"while"},
	{DO,"do"},
	{DONE,"done"},
	{0,""}
};

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		111
#define	YYFLAG		-32768
#define	YYNTBASE	36

#define YYTRANSLATE(x) ((unsigned)(x) <= 278 ? yytranslate[x] : 61)

static const char yytranslate[] = { 0,
	 2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	 2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	 2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	 2,     2,     2,     2,     2,     2,     2,     2,     2,    31,
	32,    27,    25,    30,    26,     2,    28,     2,     2,     2,
	 2,     2,     2,     2,     2,     2,     2,     2,    29,     2,
	35,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	 2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	 2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	 2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	 2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	 2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	 2,     2,    33,     2,    34,     2,     2,     2,     2,     2,
	 2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	 2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	 2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	 2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	 2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	 2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	 2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	 2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	 2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	 2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	 2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	 2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	 2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
	 7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
	17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG != 0
static const short yyprhs[] = { 0,
	 0,     2,     4,     7,     9,    11,    15,    17,    21,    27,
	29,    31,    33,    37,    38,    41,    44,    47,    50,    53,
	55,    57,    59,    61,    66,    67,    70,    72,    75,    79,
	83,    87,    91,    95,    98,   102,   106,   110,   114,   118,
   122,   126,   128,   130,   132,   134,   135,   137,   139,   143,
   148,   150,   154,   156,   158,   161,   163,   169,   177,   183,
   188
};

static const short yyrhs[] = { 37,
	 0,    38,     0,    37,    38,     0,    41,     0,    39,     0,
	14,    40,    29,     0,    23,     0,    40,    30,    23,     0,
	42,    31,    43,    32,    45,     0,     1,     0,    23,     0,
	23,     0,    43,    30,    23,     0,     0,    48,    29,     0,
	59,    29,     0,    55,    29,     0,    52,    29,     0,    56,
	29,     0,    57,     0,    58,     0,    45,     0,     1,     0,
	33,    46,    47,    34,     0,     0,    46,    39,     0,    44,
	 0,    47,    44,     0,    23,    35,    49,     0,    49,    25,
	49,     0,    49,    26,    49,     0,    49,    27,    49,     0,
	49,    28,    49,     0,    26,    49,     0,    49,    15,    49,
	 0,    49,    16,    49,     0,    49,    17,    49,     0,    49,
	18,    49,     0,    49,    19,    49,     0,    49,    20,    49,
	 0,    31,    49,    32,     0,    22,     0,    23,     0,    60,
	 0,     1,     0,     0,    51,     0,    49,     0,    51,    30,
	49,     0,     4,    31,    53,    32,     0,    54,     0,    53,
	30,    54,     0,    49,     0,    24,     0,     5,    49,     0,
	 6,     0,     7,    31,    49,    32,    45,     0,     7,    31,
	49,    32,    45,     9,    45,     0,    11,    31,    49,    32,
	45,     0,    23,    31,    50,    32,     0,    23,    31,    50,
	32,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   273,   279,   280,   286,   287,   290,   296,   300,   306,   312,
   319,   327,   331,   335,   341,   342,   343,   344,   345,   346,
   347,   348,   349,   356,   362,   366,   372,   373,   379,   385,
   389,   393,   397,   401,   405,   409,   413,   417,   421,   425,
   429,   433,   437,   441,   445,   452,   456,   459,   460,   467,
   473,   474,   480,   485,   491,   500,   506,   510,   516,   522,
   528
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = { "$","error","$undefined.","FUNC","PRINT",
"RETURN","CONTINUE","IF","THEN","ELSE","FI","WHILE","DO","DONE","INT","EQ","NE",
"LT","LE","GT","GE","UMINUS","INTEGER","IDENTIFIER","TEXT","'+'","'-'","'*'",
"'/'","';'","','","'('","')'","'{'","'}'","'='","program","function_declaration_list",
"function_declaration","declaration","variable_list","function","function_head",
"parameter_list","statement","block","declaration_list","statement_list","assignment_statement",
"expression","argument_list","expression_list","print_statement","print_list",
"print_item","return_statement","null_statement","if_statement","while_statement",
"call_statement","call_expression", NULL
};
#endif

static const short yyr1[] = { 0,
	36,    37,    37,    38,    38,    39,    40,    40,    41,    41,
	42,    43,    43,    43,    44,    44,    44,    44,    44,    44,
	44,    44,    44,    45,    46,    46,    47,    47,    48,    49,
	49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
	49,    49,    49,    49,    49,    50,    50,    51,    51,    52,
	53,    53,    54,    54,    55,    56,    57,    57,    58,    59,
	60
};

static const short yyr2[] = { 0,
	 1,     1,     2,     1,     1,     3,     1,     3,     5,     1,
	 1,     1,     3,     0,     2,     2,     2,     2,     2,     1,
	 1,     1,     1,     4,     0,     2,     1,     2,     3,     3,
	 3,     3,     3,     2,     3,     3,     3,     3,     3,     3,
	 3,     1,     1,     1,     1,     0,     1,     1,     3,     4,
	 1,     3,     1,     1,     2,     1,     5,     7,     5,     4,
	 4
};

static const short yydefact[] = { 0,
	10,     0,    11,     0,     2,     5,     4,     0,     7,     0,
	 3,    14,     6,     0,    12,     0,     8,     0,     0,    13,
	25,     9,     0,    23,     0,     0,    56,     0,     0,     0,
	26,    27,    22,     0,     0,     0,     0,     0,    20,    21,
	 0,     0,    45,    42,    43,     0,     0,    55,    44,     0,
	 0,     0,     0,    24,    28,    15,    18,    17,    19,    16,
	54,    53,     0,    51,     0,    34,     0,     0,     0,     0,
	 0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
	 0,    47,    29,     0,    50,     0,    41,    35,    36,    37,
	38,    39,    40,    30,    31,    32,    33,     0,     0,    60,
	 0,    52,    61,    57,    59,    49,     0,    58,     0,     0,
	 0
};

static const short yydefgoto[] = { 109,
	 4,     5,     6,    10,     7,     8,    16,    32,    33,    23,
	34,    35,    62,    81,    82,    36,    63,    64,    37,    38,
	39,    40,    41,    49
};

static const short yypact[] = { 16,
-32768,    13,-32768,    61,-32768,-32768,-32768,     7,-32768,   -26,
-32768,    30,-32768,    33,-32768,   -21,-32768,    34,    26,-32768,
-32768,-32768,     9,-32768,    38,    69,-32768,    41,    42,     6,
-32768,-32768,-32768,     1,    45,    48,    49,    57,-32768,-32768,
	58,    59,-32768,-32768,    62,    69,    69,   140,-32768,    69,
	69,    32,    69,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   140,    -1,-32768,    32,-32768,    86,    69,    69,    69,
	69,    69,    69,    69,    69,    69,    69,   104,   122,   140,
	39,    64,   140,    59,-32768,    65,-32768,    40,    40,    40,
	40,    40,    40,    -9,    -9,-32768,-32768,    26,    26,-32768,
	69,-32768,-32768,    80,-32768,   140,    26,-32768,    96,    98,
-32768
};

static const short yypgoto[] = { -32768,
-32768,    95,    84,-32768,-32768,-32768,-32768,    74,   -19,-32768,
-32768,-32768,   -25,    44,-32768,-32768,-32768,    31,-32768,-32768,
-32768,-32768,-32768,-32768
};


#define	YYLAST		168


static const short yytable[] = { 22,
	48,    24,    13,    14,    25,    26,    27,    28,    18,    24,
	19,    29,    25,    26,    27,    28,     1,    76,    77,    29,
	66,    67,     2,    30,    78,    79,    80,    83,    84,     2,
	85,    30,    43,    21,    54,     9,    52,    12,     3,    80,
	53,    21,    88,    89,    90,    91,    92,    93,    94,    95,
	96,    97,    15,    44,    45,    17,    20,    46,    21,    43,
	-1,     1,    47,   -46,    74,    75,    76,    77,    42,    43,
   100,    50,    51,    56,     2,   106,    57,    58,   104,   105,
	44,    45,    61,     3,    46,    59,    60,   108,   107,    47,
	44,    45,    65,   101,    46,   110,   103,   111,    11,    47,
	68,    69,    70,    71,    72,    73,    31,    55,    86,     0,
	74,    75,    76,    77,   102,     0,     0,    87,    68,    69,
	70,    71,    72,    73,     0,     0,     0,     0,    74,    75,
	76,    77,     0,     0,     0,    98,    68,    69,    70,    71,
	72,    73,     0,     0,     0,     0,    74,    75,    76,    77,
	 0,     0,     0,    99,    68,    69,    70,    71,    72,    73,
	 0,     0,     0,     0,    74,    75,    76,    77
};

static const short yycheck[] = { 19,
	26,     1,    29,    30,     4,     5,     6,     7,    30,     1,
	32,    11,     4,     5,     6,     7,     1,    27,    28,    11,
	46,    47,    14,    23,    50,    51,    52,    53,    30,    14,
	32,    23,     1,    33,    34,    23,    31,    31,    23,    65,
	35,    33,    68,    69,    70,    71,    72,    73,    74,    75,
	76,    77,    23,    22,    23,    23,    23,    26,    33,     1,
	 0,     1,    31,    32,    25,    26,    27,    28,    31,     1,
	32,    31,    31,    29,    14,   101,    29,    29,    98,    99,
	22,    23,    24,    23,    26,    29,    29,   107,     9,    31,
	22,    23,    31,    30,    26,     0,    32,     0,     4,    31,
	15,    16,    17,    18,    19,    20,    23,    34,    65,    -1,
	25,    26,    27,    28,    84,    -1,    -1,    32,    15,    16,
	17,    18,    19,    20,    -1,    -1,    -1,    -1,    25,    26,
	27,    28,    -1,    -1,    -1,    32,    15,    16,    17,    18,
	19,    20,    -1,    -1,    -1,    -1,    25,    26,    27,    28,
	-1,    -1,    -1,    32,    15,    16,    17,    18,    19,    20,
	-1,    -1,    -1,    -1,    25,    26,    27,    28
};
/* -*-C-*-  Note some compilers choke on comments on `//#line' lines.  */
//#line 3 "/usr/local/share/bison.simple"
/* This file comes from bison-1.28.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

   /* As a special exception, when this file is copied by Bison into a
	  Bison output file, you may use that output file without restriction.
	  This special exception was added by the Free Software Foundation
	  in version 1.24 of Bison.  */

	  /* This is the parser code that is written into each bison parser
		when the %semantic_parser declaration is not specified in the grammar.
		It was written by Richard Stallman by simplifying the hairy parser
		used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
		/* We think this test detects Watcom and Microsoft C.  */
		/* This used to test MSDOS, but that is a bad idea
		   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
		   /* I don't know what this was needed for, but it pollutes the namespace.
			  So I turned it off.   rms, 2 May 1997.  */
			  /* #include <malloc.h>  */
#pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

		 /* Note: there must be only one dollar sign in this file.
			It is replaced by the list of actions, each action
			as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
			/* Like YYERROR except do call yyerror.
			   This remains here temporarily to ease the
			   transition to the new meaning of YYERROR, for GCC.
			   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

			   /* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

   /*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
	(effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

	/* Define __yy_memcpy.  Note that the size argument
	   should be passed with type unsigned int, because that is what the non-GCC
	   definitions require.  With GCC, __builtin_memcpy takes an arg
	   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

	   /* This is the most reliable way to avoid incompatibilities
		  in available built-in functions on various systems.  */
static void
__yy_memcpy(to, from, count)
char *to;
char *from;
unsigned int count;
{
	register char *f = from;
	register char *t = to;
	register int i = count;

	while (i-- > 0)
		*t++ = *f++;
}

#else /* __cplusplus */

	   /* This is the most reliable way to avoid incompatibilities
		  in available built-in functions on various systems.  */
static void
__yy_memcpy(char *to, char *from, unsigned int count)
{
	register char *t = to;
	register char *f = from;
	register int i = count;

	while (i-- > 0)
		*t++ = *f++;
}

#endif
#endif

//#line 217 "/usr/local/share/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

   /* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse(void *);
#else
int yyparse(void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
YYPARSE_PARAM_DECL
{
	register int yystate;
	register int yyn;
	register short *yyssp;
	register YYSTYPE *yyvsp;
	int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
	int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

	short	yyssa[YYINITDEPTH];	/*  the state stack			*/
	YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

	short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
	YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
	YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
	YYLTYPE *yyls = yylsa;
	YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

	int yystacksize = YYINITDEPTH;
	int yyfree_stacks = 0;

#ifdef YYPURE
	int yychar;
	YYSTYPE yylval;
	int yynerrs;
#ifdef YYLSP_NEEDED
	YYLTYPE yylloc;
#endif
#endif

	YYSTYPE yyval;		/*  the variable used to return		*/
				  /*  semantic values from the action	*/
				  /*  routines				*/

	int yylen;

#if YYDEBUG != 0
	if (yydebug)
		fprintf(stderr, "Starting parse\n");
#endif

	yystate = 0;
	yyerrstatus = 0;
	yynerrs = 0;
	yychar = YYEMPTY;		/* Cause a token to be read.  */

	/* Initialize stack pointers.
	   Waste one element of value and location stack
	   so that they stay on the same level as the state stack.
	   The wasted elements are never initialized.  */

	yyssp = yyss - 1;
	yyvsp = yyvs;
#ifdef YYLSP_NEEDED
	yylsp = yyls;
#endif

	/* Push a new state, which is found in  yystate  .  */
	/* In all cases, when you get here, the value and location stacks
	   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

	*++yyssp = yystate;

	if (yyssp >= yyss + yystacksize - 1)
	{
		/* Give user a chance to reallocate the stack */
		/* Use copies of these so that the &'s don't force the real ones into memory. */
		YYSTYPE *yyvs1 = yyvs;
		short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
		YYLTYPE *yyls1 = yyls;
#endif

		/* Get the current used size of the three stacks, in elements.  */
		int size = yyssp - yyss + 1;

#ifdef yyoverflow
		/* Each stack pointer address is followed by the size of
	   the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
	   /* This used to be a conditional around just the two extra args,
	  but that might be undefined if yyoverflow is a macro.  */
		yyoverflow("parser stack overflow",
			&yyss1, size * sizeof(*yyssp),
			&yyvs1, size * sizeof(*yyvsp),
			&yyls1, size * sizeof(*yylsp),
			&yystacksize);
#else
		yyoverflow("parser stack overflow",
			&yyss1, size * sizeof(*yyssp),
			&yyvs1, size * sizeof(*yyvsp),
			&yystacksize);
#endif

		yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
		yyls = yyls1;
#endif
#else /* no yyoverflow */
		/* Extend the stack our own way.  */
		if (yystacksize >= YYMAXDEPTH)
		{
			yyerror("parser stack overflow");
			if (yyfree_stacks)
			{
				free(yyss);
				free(yyvs);
#ifdef YYLSP_NEEDED
				free(yyls);
#endif
			}
			return 2;
		}
		yystacksize *= 2;
		if (yystacksize > YYMAXDEPTH)
			yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
		yyfree_stacks = 1;
#endif
		yyss = (short *)YYSTACK_ALLOC(yystacksize * sizeof(*yyssp));
		__yy_memcpy((char *)yyss, (char *)yyss1,
			size * (unsigned int) sizeof(*yyssp));
		yyvs = (YYSTYPE *)YYSTACK_ALLOC(yystacksize * sizeof(*yyvsp));
		__yy_memcpy((char *)yyvs, (char *)yyvs1,
			size * (unsigned int) sizeof(*yyvsp));
#ifdef YYLSP_NEEDED
		yyls = (YYLTYPE *)YYSTACK_ALLOC(yystacksize * sizeof(*yylsp));
		__yy_memcpy((char *)yyls, (char *)yyls1,
			size * (unsigned int) sizeof(*yylsp));
#endif
#endif /* no yyoverflow */

		yyssp = yyss + size - 1;
		yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
		yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
		if (yydebug)
			fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

		if (yyssp >= yyss + yystacksize - 1)
			YYABORT;
	}

#if YYDEBUG != 0
	if (yydebug)
		fprintf(stderr, "Entering state %d\n", yystate);
#endif

	goto yybackup;
yybackup:

	/* Do appropriate processing given the current state.  */
	/* Read a lookahead token if we need one and don't already have one.  */
	/* yyresume: */

	  /* First try to decide what to do without reference to lookahead token.  */

	yyn = yypact[yystate];
	if (yyn == YYFLAG)
		goto yydefault;

	/* Not known => get a lookahead token if don't already have one.  */

	/* yychar is either YYEMPTY or YYEOF
	   or a valid token in external form.  */

	if (yychar == YYEMPTY)
	{
#if YYDEBUG != 0
		if (yydebug)
			fprintf(stderr, "Reading a token: ");
#endif
		yychar = YYLEX;
	}

	/* Convert token to internal form (in yychar1) for indexing tables with */

	if (yychar <= 0)		/* This means end of input. */
	{
		yychar1 = 0;
		yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
		if (yydebug)
			fprintf(stderr, "Now at end of input.\n");
#endif
	}
	else
	{
		yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
		if (yydebug)
		{
			fprintf(stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
			/* Give the individual parser a way to print the precise meaning
			   of a token, for further debugging info.  */
#ifdef YYPRINT
			YYPRINT(stderr, yychar, yylval);
#endif
			fprintf(stderr, ")\n");
		}
#endif
	}

	yyn += yychar1;
	if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
		goto yydefault;

	yyn = yytable[yyn];

	/* yyn is what to do for this token type in this state.
	   Negative => reduce, -yyn is rule number.
	   Positive => shift, yyn is new state.
		 New state is final state => don't bother to shift,
		 just return success.
	   0, or most negative number => error.  */

	if (yyn < 0)
	{
		if (yyn == YYFLAG)
			goto yyerrlab;
		yyn = -yyn;
		goto yyreduce;
	}
	else if (yyn == 0)
		goto yyerrlab;

	if (yyn == YYFINAL)
		YYACCEPT;

	/* Shift the lookahead token.  */

#if YYDEBUG != 0
	if (yydebug)
		fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

	/* Discard the token being shifted unless it is eof.  */
	if (yychar != YYEOF)
		yychar = YYEMPTY;

	*++yyvsp = yylval;
#ifdef YYLSP_NEEDED
	*++yylsp = yylloc;
#endif

	/* count tokens shifted since error; after three, turn off error status.  */
	if (yyerrstatus) yyerrstatus--;

	yystate = yyn;
	goto yynewstate;

	/* Do the default action for the current state.  */
yydefault:

	yyn = yydefact[yystate];
	if (yyn == 0)
		goto yyerrlab;

	/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
	yylen = yyr2[yyn];
	if (yylen > 0)
		yyval = yyvsp[1 - yylen]; /* implement default value of the action */

#if YYDEBUG != 0
	if (yydebug)
	{
		int i;

		fprintf(stderr, "Reducing via rule %d (line %d), ",
			yyn, yyrline[yyn]);

		/* Print the symbols being reduced, and their result.  */
		for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
			fprintf(stderr, "%s ", yytname[yyrhs[i]]);
		fprintf(stderr, " -> %s\n", yytname[yyr1[yyn]]);
	}
#endif


	switch (yyn) {

	case 1:
//#line 274 "gpl.y"
	{
		tac_last = yyvsp[0].tac;
		;
		break; }
	case 3:
//#line 281 "gpl.y"
	{
		yyval.tac = join_tac(yyvsp[-1].tac, yyvsp[0].tac);
		;
		break; }
	case 6:
//#line 291 "gpl.y"
	{
		yyval.tac = yyvsp[-1].tac;
		;
		break; }
	case 7:
//#line 297 "gpl.y"
	{
		yyval.tac = declare_var(yyvsp[0].string);
		;
		break; }
	case 8:
//#line 301 "gpl.y"
	{
		yyval.tac = join_tac(yyvsp[-2].tac, declare_var(yyvsp[0].string));
		;
		break; }
	case 9:
//#line 307 "gpl.y"
	{
		yyval.tac = do_func(yyvsp[-4].symb, yyvsp[-2].tac, yyvsp[0].tac);
		LocalScope = 0; /* Leave local scope. */
		LocalSymbolTable = NULL; /* Clear local symbol table. */
		;
		break; }
	case 10:
//#line 313 "gpl.y"
	{
		error("Bad function syntax");
		yyval.tac = NULL;
		;
		break; }
	case 11:
//#line 320 "gpl.y"
	{
		yyval.symb = declare_func(yyvsp[0].string);
		LocalScope = 1; /* Enter local scope. */
		LocalSymbolTable = NULL; /* Init local symbol table. */
		;
		break; }
	case 12:
//#line 328 "gpl.y"
	{
		yyval.tac = declare_para(yyvsp[0].string);
		;
		break; }
	case 13:
//#line 332 "gpl.y"
	{
		yyval.tac = join_tac(yyvsp[-2].tac, declare_para(yyvsp[0].string));
		;
		break; }
	case 14:
//#line 336 "gpl.y"
	{
		yyval.tac = NULL;
		;
		break; }
	case 23:
//#line 350 "gpl.y"
	{
		error("Bad statement syntax");
		yyval.tac = NULL;
		;
		break; }
	case 24:
//#line 357 "gpl.y"
	{
		yyval.tac = join_tac(yyvsp[-2].tac, yyvsp[-1].tac);
		;
		break; }
	case 25:
//#line 363 "gpl.y"
	{
		yyval.tac = NULL;
		;
		break; }
	case 26:
//#line 367 "gpl.y"
	{
		yyval.tac = join_tac(yyvsp[-1].tac, yyvsp[0].tac);
		;
		break; }
	case 28:
//#line 374 "gpl.y"
	{
		yyval.tac = join_tac(yyvsp[-1].tac, yyvsp[0].tac);
		;
		break; }
	case 29:
//#line 380 "gpl.y"
	{
		yyval.tac = do_assign(getvar(yyvsp[-2].string), yyvsp[0].enode);
		;
		break; }
	case 30:
//#line 386 "gpl.y"
	{
		yyval.enode = do_bin(TAC_ADD, yyvsp[-2].enode, yyvsp[0].enode);
		;
		break; }
	case 31:
//#line 390 "gpl.y"
	{
		yyval.enode = do_bin(TAC_SUB, yyvsp[-2].enode, yyvsp[0].enode);
		;
		break; }
	case 32:
//#line 394 "gpl.y"
	{
		yyval.enode = do_bin(TAC_MUL, yyvsp[-2].enode, yyvsp[0].enode);
		;
		break; }
	case 33:
//#line 398 "gpl.y"
	{
		yyval.enode = do_bin(TAC_DIV, yyvsp[-2].enode, yyvsp[0].enode);
		;
		break; }
	case 34:
//#line 402 "gpl.y"
	{
		yyval.enode = do_un(TAC_NEG, yyvsp[0].enode);
		;
		break; }
	case 35:
//#line 406 "gpl.y"
	{
		yyval.enode = do_cmp(TAC_EQ, yyvsp[-2].enode, yyvsp[0].enode);
		;
		break; }
	case 36:
//#line 410 "gpl.y"
	{
		yyval.enode = do_cmp(TAC_NE, yyvsp[-2].enode, yyvsp[0].enode);
		;
		break; }
	case 37:
//#line 414 "gpl.y"
	{
		yyval.enode = do_cmp(TAC_LT, yyvsp[-2].enode, yyvsp[0].enode);
		;
		break; }
	case 38:
//#line 418 "gpl.y"
	{
		yyval.enode = do_cmp(TAC_LE, yyvsp[-2].enode, yyvsp[0].enode);
		;
		break; }
	case 39:
//#line 422 "gpl.y"
	{
		yyval.enode = do_cmp(TAC_GT, yyvsp[-2].enode, yyvsp[0].enode);
		;
		break; }
	case 40:
//#line 426 "gpl.y"
	{
		yyval.enode = do_cmp(TAC_GE, yyvsp[-2].enode, yyvsp[0].enode);
		;
		break; }
	case 41:
//#line 430 "gpl.y"
	{
		yyval.enode = yyvsp[-1].enode;
		;
		break; }
	case 42:
//#line 434 "gpl.y"
	{
		yyval.enode = mkenode(NULL, mkconst(atoi(yyvsp[0].string)), NULL);
		;
		break; }
	case 43:
//#line 438 "gpl.y"
	{
		yyval.enode = mkenode(NULL, getvar(yyvsp[0].string), NULL);
		;
		break; }
	case 44:
//#line 442 "gpl.y"
	{
		yyval.enode = yyvsp[0].enode;
		;
		break; }
	case 45:
//#line 446 "gpl.y"
	{
		error("Bad expression syntax");
		yyval.enode = mkenode(NULL, NULL, NULL);
		;
		break; }
	case 46:
//#line 453 "gpl.y"
	{
		yyval.enode = NULL;
		;
		break; }
	case 49:
//#line 461 "gpl.y"
	{
		yyvsp[0].enode->next = yyvsp[-2].enode;
		yyval.enode = yyvsp[0].enode;
		;
		break; }
	case 50:
//#line 468 "gpl.y"
	{
		yyval.tac = yyvsp[-1].tac;
		;
		break; }
	case 52:
//#line 475 "gpl.y"
	{
		yyval.tac = join_tac(yyvsp[-2].tac, yyvsp[0].tac);
		;
		break; }
	case 53:
//#line 481 "gpl.y"
	{
		yyval.tac = join_tac(yyvsp[0].enode->tac,
			do_lib("PRINTN", yyvsp[0].enode->ret));
		;
		break; }
	case 54:
//#line 486 "gpl.y"
	{
		yyval.tac = do_lib("PRINTS", mktext(yyvsp[0].string));
		;
		break; }
	case 55:
//#line 492 "gpl.y"
	{
		TAC *t = mktac(TAC_RETURN, yyvsp[0].enode->ret, NULL, NULL);
		t->prev = yyvsp[0].enode->tac;
		free_enode(yyvsp[0].enode);
		yyval.tac = t;
		;
		break; }
	case 56:
//#line 501 "gpl.y"
	{
		yyval.tac = NULL;
		;
		break; }
	case 57:
//#line 507 "gpl.y"
	{
		yyval.tac = do_if(yyvsp[-2].enode, yyvsp[0].tac);
		;
		break; }
	case 58:
//#line 511 "gpl.y"
	{
		yyval.tac = do_test(yyvsp[-4].enode, yyvsp[-2].tac, yyvsp[0].tac);
		;
		break; }
	case 59:
//#line 517 "gpl.y"
	{
		yyval.tac = do_while(yyvsp[-2].enode, yyvsp[0].tac);
		;
		break; }
	case 60:
//#line 523 "gpl.y"
	{
		yyval.tac = do_call(yyvsp[-3].string, yyvsp[-1].enode);
		;
		break; }
	case 61:
//#line 529 "gpl.y"
	{
		yyval.enode = do_call_ret(yyvsp[-3].string, yyvsp[-1].enode);
		;
		break; }
	}
	/* the action file gets copied in in place of this dollarsign */
//#line 543 "/usr/local/share/bison.simple"

	yyvsp -= yylen;
	yyssp -= yylen;
#ifdef YYLSP_NEEDED
	yylsp -= yylen;
#endif

#if YYDEBUG != 0
	if (yydebug)
	{
		short *ssp1 = yyss - 1;
		fprintf(stderr, "state stack now");
		while (ssp1 != yyssp)
			fprintf(stderr, " %d", *++ssp1);
		fprintf(stderr, "\n");
	}
#endif

	*++yyvsp = yyval;

#ifdef YYLSP_NEEDED
	yylsp++;
	if (yylen == 0)
	{
		yylsp->first_line = yylloc.first_line;
		yylsp->first_column = yylloc.first_column;
		yylsp->last_line = (yylsp - 1)->last_line;
		yylsp->last_column = (yylsp - 1)->last_column;
		yylsp->text = 0;
	}
	else
	{
		yylsp->last_line = (yylsp + yylen - 1)->last_line;
		yylsp->last_column = (yylsp + yylen - 1)->last_column;
	}
#endif

	/* Now "shift" the result of the reduction.
	   Determine what state that goes to,
	   based on the state we popped back to
	   and the rule number reduced by.  */

	yyn = yyr1[yyn];

	yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
	if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
		yystate = yytable[yystate];
	else
		yystate = yydefgoto[yyn - YYNTBASE];

	goto yynewstate;

yyerrlab:   /* here on detecting error */

	if (!yyerrstatus)
		/* If not already recovering from an error, report this error.  */
	{
		++yynerrs;

#ifdef YYERROR_VERBOSE
		yyn = yypact[yystate];

		if (yyn > YYFLAG && yyn < YYLAST)
		{
			int size = 0;
			char *msg;
			int x, count;

			count = 0;
			/* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
			for (x = (yyn < 0 ? -yyn : 0);
				x < (sizeof(yytname) / sizeof(char *)); x++)
				if (yycheck[x + yyn] == x)
					size += strlen(yytname[x]) + 15, count++;
			msg = (char *)malloc(size + 15);
			if (msg != 0)
			{
				strcpy(msg, "parse error");

				if (count < 5)
				{
					count = 0;
					for (x = (yyn < 0 ? -yyn : 0);
						x < (sizeof(yytname) / sizeof(char *)); x++)
						if (yycheck[x + yyn] == x)
						{
							strcat(msg, count == 0 ? ", expecting `" : " or `");
							strcat(msg, yytname[x]);
							strcat(msg, "'");
							count++;
						}
				}
				yyerror(msg);
				free(msg);
			}
			else
				yyerror("parse error; also virtual memory exceeded");
		}
		else
#endif /* YYERROR_VERBOSE */
			yyerror("parse error");
	}

	goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

	if (yyerrstatus == 3)
	{
		/* if just tried and failed to reuse lookahead token after an error, discard it.  */

		/* return failure if at end of input */
		if (yychar == YYEOF)
			YYABORT;

#if YYDEBUG != 0
		if (yydebug)
			fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

		yychar = YYEMPTY;
	}

	/* Else will try to reuse lookahead token
	   after shifting the error token.  */

	yyerrstatus = 3;		/* Each real token shifted decrements this */

	goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
	 should shift them.  */
	yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
	if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

	if (yyssp == yyss) YYABORT;
	yyvsp--;
	yystate = *--yyssp;
#ifdef YYLSP_NEEDED
	yylsp--;
#endif

#if YYDEBUG != 0
	if (yydebug)
	{
		short *ssp1 = yyss - 1;
		fprintf(stderr, "Error: state stack now");
		while (ssp1 != yyssp)
			fprintf(stderr, " %d", *++ssp1);
		fprintf(stderr, "\n");
	}
#endif

yyerrhandle:

	yyn = yypact[yystate];
	if (yyn == YYFLAG)
		goto yyerrdefault;

	yyn += YYTERROR;
	if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
		goto yyerrdefault;

	yyn = yytable[yyn];
	if (yyn < 0)
	{
		if (yyn == YYFLAG)
			goto yyerrpop;
		yyn = -yyn;
		goto yyreduce;
	}
	else if (yyn == 0)
		goto yyerrpop;

	if (yyn == YYFINAL)
		YYACCEPT;

#if YYDEBUG != 0
	if (yydebug)
		fprintf(stderr, "Shifting error token, ");
#endif

	*++yyvsp = yylval;
#ifdef YYLSP_NEEDED
	*++yylsp = yylloc;
#endif

	yystate = yyn;
	goto yynewstate;

yyacceptlab:
	/* YYACCEPT comes here.  */
	if (yyfree_stacks)
	{
		free(yyss);
		free(yyvs);
#ifdef YYLSP_NEEDED
		free(yyls);
#endif
	}
	return 0;

yyabortlab:
	/* YYABORT comes here.  */
	if (yyfree_stacks)
	{
		free(yyss);
		free(yyvs);
#ifdef YYLSP_NEEDED
		free(yyls);
#endif
	}
	return 1;
}
//#line 535 "gpl.y"


TAC *do_func(SYMB *func, TAC *args, TAC *code)
{
	TAC *tlist; /* The backpatch list */

	TAC *tlab; /* Label at start of function */
	TAC *tbegin; /* BEGINFUNC marker */
	TAC *tend; /* ENDFUNC marker */

	tlab = mktac(TAC_LABEL, mklabel(func->name), NULL, NULL);
	tbegin = mktac(TAC_BEGINFUNC, NULL, NULL, NULL);
	tend = mktac(TAC_ENDFUNC, NULL, NULL, NULL);

	tbegin->prev = tlab;
	code = join_tac(args, code);
	tend->prev = join_tac(tbegin, code);

	return tend;
}

SYMB *mktmp(void)
{
	SYMB *sym;
	char *name;

	name = (char*)safe_malloc(12);
	sprintf(name, "t%d", next_tmp++); /* Set up text */
	return mkvar(name);
}

SYMB *mkvar(char *name)
{
	SYMB *sym = NULL;

	if (LocalScope)
		sym = lookup(LocalSymbolTable, name);
	else
		sym = lookup(GlobalSymbolTable, name);

	/* var already declared */
	if (sym != NULL)
	{
		error("variable already declared");
		return NULL;
	}

	/* var unseen before, set up a new symbol table node, insert it into the symbol table. */
	sym = get_symb();
	sym->type = SYM_VAR;
	sym->name = name; /* ysj */
	sym->offset = -1; /* Unset address */

	if (LocalScope)
		insert(&LocalSymbolTable, sym);
	else
		insert(&GlobalSymbolTable, sym);

	return sym;
}

TAC *declare_var(char *name)
{
	return mktac(TAC_VAR, mkvar(name), NULL, NULL);
}

TAC *declare_para(char *name)
{
	return mktac(TAC_FORMAL, mkvar(name), NULL, NULL);
}

SYMB *declare_func(char *name)
{
	SYMB *sym = NULL;

	sym = lookup(GlobalSymbolTable, name);

	/* name used before declared */
	if (sym != NULL)
	{
		if (sym->type == SYM_FUNC)
		{
			error("func already declared");
			return NULL;
		}

		if (sym->type != SYM_UNDEF)
		{
			error("func name already used");
			return NULL;
		}

		return sym;
	}


	sym = get_symb();
	sym->type = SYM_FUNC;
	sym->name = name;
	sym->address = NULL;

	insert(&GlobalSymbolTable, sym);
	return sym;
}

TAC *do_assign(SYMB *var, ENODE *expr)
{
	TAC *code;

	if (var->type != SYM_VAR) error("assignment to non-variable");

	code = mktac(TAC_COPY, var, expr->ret, NULL);
	code->prev = expr->tac;
	free_enode(expr); /* Expression now finished with */

	return code;
}

ENODE *do_bin(int binop, ENODE *expr1, ENODE *expr2)
{
	TAC *temp; /* TAC code for temp symbol */
	TAC *ret; /* TAC code for result */

	if ((expr1->ret->type == SYM_INT) && (expr2->ret->type == SYM_INT))
	{
		int newval; /* The result of constant folding */

		switch (binop) /* Chose the operator */
		{
		case TAC_ADD:
			newval = expr1->ret->value + expr2->ret->value;
			break;

		case TAC_SUB:
			newval = expr1->ret->value - expr2->ret->value;
			break;

		case TAC_MUL:
			newval = expr1->ret->value * expr2->ret->value;
			break;

		case TAC_DIV:
			newval = expr1->ret->value / expr2->ret->value;
			break;
		}

		expr1->ret = mkconst(newval); /* New space for result */
		free_enode(expr2); /* Release space in expr2 */

		return expr1; /* The new expression */
	}

	temp = mktac(TAC_VAR, mktmp(), NULL, NULL);
	temp->prev = join_tac(expr1->tac, expr2->tac);
	ret = mktac(binop, temp->a, expr1->ret, expr2->ret);
	ret->prev = temp;

	expr1->ret = temp->a;
	expr1->tac = ret;
	free_enode(expr2);

	return expr1;
}

ENODE *do_cmp(int binop, ENODE *expr1, ENODE *expr2)
{
	TAC *temp; /* TAC code for temp symbol */
	TAC *ret; /* TAC code for result */

	if ((expr1->ret->type == SYM_INT) && (expr2->ret->type == SYM_INT))
	{
		int newval; /* The result of constant folding */

		switch (binop) /* Chose the operator */
		{
		case TAC_EQ:
			newval = (expr1->ret->value == expr2->ret->value);
			break;

		case TAC_NE:
			newval = (expr1->ret->value != expr2->ret->value);
			break;

		case TAC_LT:
			newval = (expr1->ret->value < expr2->ret->value);
			break;

		case TAC_LE:
			newval = (expr1->ret->value <= expr2->ret->value);
			break;

		case TAC_GT:
			newval = (expr1->ret->value > expr2->ret->value);
			break;

		case TAC_GE:
			newval = (expr1->ret->value >= expr2->ret->value);
			break;
		}

		expr1->ret = mkconst(newval); /* New space for result */
		free_enode(expr2); /* Release space in expr2 */
		return expr1; /* The new expression */
	}

	temp = mktac(TAC_VAR, mktmp(), NULL, NULL);
	temp->prev = join_tac(expr1->tac, expr2->tac);
	ret = mktac(binop, temp->a, expr1->ret, expr2->ret);
	ret->prev = temp;

	expr1->ret = temp->a;
	expr1->tac = ret;
	free_enode(expr2);

	return expr1;
}

ENODE *do_un(int unop, ENODE *expr)
{
	TAC *temp; /* TAC code for temp symbol */
	TAC *ret; /* TAC code for result */

	/* Do constant folding if possible. Calculate the constant into expr */
	if (expr->ret->type == SYM_INT)
	{
		switch (unop) /* Chose the operator */
		{
		case TAC_NEG:
			expr->ret->value = -expr->ret->value;
			break;
		}

		return expr; /* The new expression */
	}

	temp = mktac(TAC_VAR, mktmp(), NULL, NULL);
	temp->prev = expr->tac;
	ret = mktac(unop, temp->a, expr->ret, NULL);
	ret->prev = temp;

	expr->ret = temp->a;
	expr->tac = ret;

	return expr;
}

TAC *do_call(char *name, ENODE *arglist)
{
	ENODE  *alt; /* For counting args */
	TAC *code; /* Resulting code */
	TAC *temp; /* Temporary for building code */

	code = NULL;
	for (alt = arglist; alt != NULL; alt = alt->next) code = join_tac(code, alt->tac);

	while (arglist != NULL) /* Generate ARG instructions */
	{
		temp = mktac(TAC_ACTUAL, arglist->ret, NULL, NULL);
		temp->prev = code;
		code = temp;

		alt = arglist->next;
		free_enode(arglist); /* Free the space */
		arglist = alt;
	};

	temp = mktac(TAC_CALL, NULL, (SYMB *)strdup(name), NULL);
	temp->prev = code;
	code = temp;

	return code;
}

ENODE *do_call_ret(char *name, ENODE *arglist)
{
	ENODE  *alt; /* For counting args */
	SYMB *ret; /* Where function result will go */
	TAC *code; /* Resulting code */
	TAC *temp; /* Temporary for building code */

	ret = mktmp(); /* For the result */
	code = mktac(TAC_VAR, ret, NULL, NULL);

	for (alt = arglist; alt != NULL; alt = alt->next) code = join_tac(code, alt->tac);

	while (arglist != NULL) /* Generate ARG instructions */
	{
		temp = mktac(TAC_ACTUAL, arglist->ret, NULL, NULL);
		temp->prev = code;
		code = temp;

		alt = arglist->next;
		free_enode(arglist); /* Free the space */
		arglist = alt;
	};

	temp = mktac(TAC_CALL, ret, (SYMB *)strdup(name), NULL);
	temp->prev = code;
	code = temp;

	return mkenode(NULL, ret, code);
}

TAC *do_lib(char *name, SYMB *arg)
{
	TAC *a = mktac(TAC_ACTUAL, arg, NULL, NULL);
	TAC *c = mktac(TAC_CALL, NULL, (SYMB *)strdup(name), NULL);
	c->prev = a;
	return c;
}

TAC *do_if(ENODE *expr, TAC *stmt)
{
	TAC *label = mktac(TAC_LABEL, mklabel(mklstr(next_label++)), NULL, NULL);
	TAC *code = mktac(TAC_IFZ, label->a, expr->ret, NULL);

	code->prev = expr->tac;
	code = join_tac(code, stmt);
	label->prev = code;

	free_enode(expr); /* Expression finished with */

	return label;
}

TAC *do_test(ENODE *expr, TAC *stmt1, TAC *stmt2)
{
	TAC *label1 = mktac(TAC_LABEL, mklabel(mklstr(next_label++)), NULL, NULL);
	TAC *label2 = mktac(TAC_LABEL, mklabel(mklstr(next_label++)), NULL, NULL);
	TAC *code1 = mktac(TAC_IFZ, label1->a, expr->ret, NULL);
	TAC *code2 = mktac(TAC_GOTO, label2->a, NULL, NULL);

	code1->prev = expr->tac; /* Join the code */
	code1 = join_tac(code1, stmt1);
	code2->prev = code1;
	label1->prev = code2;
	label1 = join_tac(label1, stmt2);
	label2->prev = label1;

	free_enode(expr); /* Free the expression */

	return label2;
}

TAC *do_while(ENODE *expr, TAC *stmt)
{
	TAC *label = mktac(TAC_LABEL, mklabel(mklstr(next_label++)), NULL, NULL);
	TAC *code = mktac(TAC_GOTO, label->a, NULL, NULL);

	code->prev = stmt; /* Bolt on the goto */

	return join_tac(label, do_if(expr, code));
}

SYMB *getvar(char *name)
{
	SYMB *sym = NULL; /* Pointer to looked up symbol */

	if (LocalScope) sym = lookup(LocalSymbolTable, name);

	if (sym == NULL) sym = lookup(GlobalSymbolTable, name);

	if (sym == NULL)
	{
		error("name not declared as local/global variable");
		return NULL;
	}

	if (sym->type != SYM_VAR)
	{
		error("not a variable");
		return NULL;
	}

	return sym;
}

ENODE *mkenode(ENODE *next, SYMB *ret, TAC *code)
{
	ENODE *expr = get_enode();

	expr->next = next;
	expr->ret = ret;
	expr->tac = code;

	return expr;
}

SYMB *mktext(char *text)
{
	SYMB *sym = NULL; /* Pointer to looked up symbol */

	sym = lookup(GlobalSymbolTable, text);

	/* text already used */
	if (sym != NULL)
	{
		return sym;
	}

	/* text unseen before, set up a new symbol table node, insert it into the symbol table. */
	sym = get_symb();
	sym->type = SYM_TEXT;
	sym->name = text; /* ysj */
	sym->lable = next_label++; /* ysj */

	insert(&GlobalSymbolTable, sym);
	return sym;
}

SYMB *mkconst(int n)
{
	SYMB *c = get_symb(); /* Create a new node */

	c->type = SYM_INT;
	c->value = n; /* ysj */
	return c;
}

char *mklstr(int i)
{
	char lstr[100] = "L";
	sprintf(lstr, "L%d", i);
	return(strdup(lstr));
}

SYMB *mklabel(char *name)
{
	SYMB *t = get_symb();

	t->type = SYM_LABEL;
	t->name = strdup(name);

	return t;
}

SYMB *get_symb(void)
{
	SYMB *t;

	if (symb_list != NULL)
	{
		t = symb_list;
		symb_list = symb_list->next;
	}
	else t = (SYMB *)safe_malloc(sizeof(SYMB));

	return t;
}


void free_symb(SYMB *s)
{
	s->next = symb_list;
	symb_list = s;
}


ENODE *get_enode(void)
{
	if (enode_list != NULL)
	{
		ENODE *expr;
		expr = enode_list;
		enode_list = expr->next;
		return expr;
	}
	else return (ENODE *)safe_malloc(sizeof(ENODE));
}

void free_enode(ENODE *expr)
{
	expr->next = enode_list;
	enode_list = expr;
}

void *safe_malloc(int n)
{
	void *t = (void *)malloc(n);

	if (t == NULL)
	{
		/* We can't use printf to put the message out here, since it calls malloc, which will fail because that's why we're here... */
		error("malloc() failed");
		exit(0);
	}

	return t;
}

TAC *mktac(int op, SYMB *a, SYMB *b, SYMB *c)
{
	TAC *t = (TAC *)safe_malloc(sizeof(TAC));

	t->next = NULL; /* Set these for safety */
	t->prev = NULL;
	t->op = op;
	t->a = a;
	t->b = b;
	t->c = c;

	return t;
}

TAC *join_tac(TAC *c1, TAC *c2)
{
	TAC *t;

	/* If either list is NULL return the other */
	if (c1 == NULL) return c2;
	if (c2 == NULL) return c1;

	/* Run down c2, until we get to the beginning and then add c1 */
	t = c2;
	while (t->prev != NULL)
		t = t->prev;

	t->prev = c1;
	return c2;
}

void insert(SYMB **symbtab, SYMB *sym)
{
	sym->next = *symbtab; /* Insert at head */
	*symbtab = sym;
}


SYMB *lookup(SYMB *symbtab, char *name)
{
	SYMB *t = symbtab;

	while (t != NULL)
	{
		if (strcmp(t->name, name) == 0) break;
		else t = t->next;
	}

	return t; /* NULL if not found */
}

void tac_print(TAC *i)
{
	char sa[12]; /* For text of TAC args */
	char sb[12];
	char sc[12];

	switch (i->op)
	{
	case TAC_UNDEF:
		printf("undef");
		break;

	case TAC_ADD:
		printf("%s = %s + %s", ts(i->a, sa), ts(i->b, sb),
			ts(i->c, sc));
		break;

	case TAC_SUB:
		printf("%s = %s - %s", ts(i->a, sa), ts(i->b, sb),
			ts(i->c, sc));
		break;

	case TAC_MUL:
		printf("%s = %s * %s", ts(i->a, sa), ts(i->b, sb),
			ts(i->c, sc));
		break;

	case TAC_DIV:
		printf("%s = %s / %s", ts(i->a, sa), ts(i->b, sb),
			ts(i->c, sc));
		break;

	case TAC_EQ:
		printf("%s = (%s == %s)", ts(i->a, sa), ts(i->b, sb), ts(i->c, sc));
		break;

	case TAC_NE:
		printf("%s = (%s != %s)", ts(i->a, sa), ts(i->b, sb), ts(i->c, sc));
		break;

	case TAC_LT:
		printf("%s = (%s < %s)", ts(i->a, sa), ts(i->b, sb), ts(i->c, sc));
		break;

	case TAC_LE:
		printf("%s = (%s <= %s)", ts(i->a, sa), ts(i->b, sb), ts(i->c, sc));
		break;

	case TAC_GT:
		printf("%s = (%s > %s)", ts(i->a, sa), ts(i->b, sb), ts(i->c, sc));
		break;

	case TAC_GE:
		printf("%s = (%s >= %s)", ts(i->a, sa), ts(i->b, sb), ts(i->c, sc));
		break;

	case TAC_NEG:
		printf("%s = - %s", ts(i->a, sa), ts(i->b, sb));
		break;

	case TAC_COPY:
		printf("%s = %s", ts(i->a, sa), ts(i->b, sb));
		break;

	case TAC_GOTO:
		printf("goto %s", i->a->name);
		break;

	case TAC_IFZ:
		printf("ifz %s goto %s", ts(i->b, sb), i->a->name);
		break;

	case TAC_ACTUAL:
		printf("actual %s", ts(i->a, sa));
		break;

	case TAC_FORMAL:
		printf("formal %s", ts(i->a, sa));
		break;

	case TAC_CALL:
		if (i->a == NULL) printf("call %s", (char *)i->b);
		else printf("%s = call %s", ts(i->a, sa), (char *)i->b);
		break;

	case TAC_RETURN:
		printf("return %s", ts(i->a, sa));
		break;

	case TAC_LABEL:
		printf("label %s", i->a->name);
		break;

	case TAC_VAR:
		printf("var %s", ts(i->a, sa));
		break;

	case TAC_BEGINFUNC:
		printf("begin");
		break;

	case TAC_ENDFUNC:
		printf("end");
		break;

	default:
		error("unknown TAC opcode");
		break;
	}

	fflush(stdout);

}


char *ts(SYMB *s, char *str)
{
	/* Check we haven't been given NULL */
	if (s == NULL)	return "NULL";

	/* Identify the type */
	switch (s->type)
	{
	case SYM_FUNC:
	case SYM_VAR:
		/* Just return the name */
		return s->name; /* ysj */

	case SYM_TEXT:
		/* Put the address of the text */
		sprintf(str, "L%d", s->lable);
		return str;

	case SYM_INT:
		/* Convert the number to string */
		sprintf(str, "%d", s->value);
		return str;

	default:
		/* Unknown arg type */
		error("unknown TAC arg type");
		return "?";
	}
}

void error(char *str)
{
	printf("%s\n", str);
	exit(0);
}

void cg()
{
	tof = LOCAL_OFF; /* TOS allows space for link info */
	oof = FORMAL_OFF;
	oon = 0;

	int r;
	for (r = 0; r < R_NUM; r++)
		rdesc[r].name = NULL;
	insert_desc(0, mkconst(0), UNMODIFIED); /* R0 holds 0 */

	cg_head();

	TAC * cur;
	for (cur = tac_first; cur != NULL; cur = cur->next)
	{
		printf("\n	# ");
		tac_print(cur);
		printf("\n");
		cg_code(cur);
	}
	cg_lib();
	cg_data();
}

void tac_tidy()
{
	TAC *c = NULL; 		/* Current TAC */
	TAC *p = tac_last; 	/* Previous TAC */

	while (p != NULL)
	{
		p->next = c;
		c = p;
		p = p->prev;
	}

	tac_first = c;
}

void cg_code(TAC *c)
{
	int r;

	switch (c->op)
	{
	case TAC_UNDEF:
		error("cannot translate TAC_UNDEF");
		return;

	case TAC_ADD:
		cg_bin("ADD", c->a, c->b, c->c);
		return;

	case TAC_SUB:
		cg_bin("SUB", c->a, c->b, c->c);
		return;

	case TAC_MUL:
		cg_bin("MUL", c->a, c->b, c->c);
		return;

	case TAC_DIV:
		cg_bin("DIV", c->a, c->b, c->c);
		return;

	case TAC_NEG:
		cg_bin("SUB", c->a, mkconst(0), c->b);
		return;

	case TAC_EQ:
	case TAC_NE:
	case TAC_LT:
	case TAC_LE:
	case TAC_GT:
	case TAC_GE:
		cg_cmp(c->op, c->a, c->b, c->c);
		return;

	case TAC_COPY:
		cg_copy(c->a, c->b);
		return;

	case TAC_GOTO:
		cg_cond("JMP", NULL, c->a->name);
		return;

	case TAC_IFZ:
		cg_cond("JEZ", c->b, c->a->name);
		return;

	case TAC_LABEL:
		flush_all();
		printf("%s:\n", c->a->name);
		return;

	case TAC_ACTUAL:
		r = get_rreg(c->a);
		printf("	STO (R2+%d),R%u\n", tof + oon, r);
		oon += 4;
		return;

	case TAC_CALL:
		flush_all();
		printf("	STO (R2+%d),R2\n", tof + oon);	/* store old bp */
		oon += 4;
		printf("	LOD R4,R1+32\n"); 				/* return addr: 4*8=32 */
		printf("	STO (R2+%d),R4\n", tof + oon);	/* store return addr */
		oon += 4;
		printf("	LOD R2,R2+%d\n", tof + oon - 8);	/* load new bp */
		printf("	JMP %s\n", (char *)c->b);	/* jump to new func */
		if (c->a != NULL) insert_desc(R_TP, c->a, MODIFIED);
		oon = 0;
		return;

	case TAC_BEGINFUNC:
		/* We reset the top of stack, since it is currently empty apart from the link information. */
		LocalScope = 1;
		tof = LOCAL_OFF;
		oof = FORMAL_OFF;
		oon = 0;
		return;

	case TAC_FORMAL:
		c->a->store = 1; /* parameter is special local var */
		c->a->offset = oof;
		oof -= 4;
		return;

	case TAC_VAR:
		if (LocalScope)
		{
			c->a->store = 1; /* local var */
			c->a->offset = tof;
			tof += 4;
		}
		else
		{
			c->a->store = 0; /* global var */
			c->a->offset = tos;
			tos += 4;
		}
		return;

	case TAC_RETURN:
		cg_return(c->a);
		return;

	case TAC_ENDFUNC:
		cg_return(NULL);
		LocalScope = 0;
		return;

	default:
		/* Don't know what this one is */
		error("unknown TAC opcode to translate");
		return;
	}
}

void cg_bin(char *op, SYMB *a, SYMB *b, SYMB *c)
{
	int rreg = get_rreg(b); /* Result register */
	int areg = get_areg(c, rreg); /* One more register */

	printf("	%s R%u,R%u\n", op, rreg, areg);

	/* Delete c from the descriptors and insert a */
	clear_desc(rreg);
	insert_desc(rreg, a, MODIFIED);
}

void cg_cmp(int op, SYMB *a, SYMB *b, SYMB *c)
{
	int rreg = get_rreg(b); /* Result register */
	int areg = get_areg(c, rreg); /* One more register */

	printf("	SUB R%u,R%u\n", rreg, areg);
	printf("	TST R%u\n", rreg);

	switch (op)
	{
	case TAC_EQ:
		printf("	LOD R3,R1+40\n");
		printf("	JEZ R3\n");
		printf("	LOD R%u,0\n", rreg);
		printf("	LOD R3,R1+24\n");
		printf("	JMP R3\n");
		printf("	LOD R%u,1\n", rreg);
		break;

	case TAC_NE:
		printf("	LOD R3,R1+40\n");
		printf("	JEZ R3\n");
		printf("	LOD R%u,1\n", rreg);
		printf("	LOD R3,R1+24\n");
		printf("	JMP R3\n");
		printf("	LOD R%u,0\n", rreg);
		break;

	case TAC_LT:
		printf("	LOD R3,R1+40\n");
		printf("	JLZ R3\n");
		printf("	LOD R%u,0\n", rreg);
		printf("	LOD R3,R1+24\n");
		printf("	JMP R3\n");
		printf("	LOD R%u,1\n", rreg);
		break;

	case TAC_LE:
		printf("	LOD R3,R1+40\n");
		printf("	JGZ R3\n");
		printf("	LOD R%u,1\n", rreg);
		printf("	LOD R3,R1+24\n");
		printf("	JMP R3\n");
		printf("	LOD R%u,0\n", rreg);
		break;

	case TAC_GT:
		printf("	LOD R3,R1+40\n");
		printf("	JGZ R3\n");
		printf("	LOD R%u,0\n", rreg);
		printf("	LOD R3,R1+24\n");
		printf("	JMP R3\n");
		printf("	LOD R%u,1\n", rreg);
		break;

	case TAC_GE:
		printf("	LOD R3,R1+40\n");
		printf("	JLZ R3\n");
		printf("	LOD R%u,1\n", rreg);
		printf("	LOD R3,R1+24\n");
		printf("	JMP R3\n");
		printf("	LOD R%u,0\n", rreg);
		break;
	}

	/* Delete c from the descriptors and insert a */
	clear_desc(rreg);
	insert_desc(rreg, a, MODIFIED);
}

void cg_copy(SYMB *a, SYMB *b)
{
	int rreg = get_rreg(b); /* Load b into a register */
	insert_desc(rreg, a, MODIFIED); /* Indicate a is there */
}

void cg_cond(char *op, SYMB *a, char *l)
{
	spill_all();

	if (a != NULL)
	{
		int r;

		for (r = R_GEN; r < R_NUM; r++) /* Is it in reg? */
		{
			if (rdesc[r].name == a) break;
		}

		if (r < R_NUM) printf("	TST R%u\n", r);
		else printf("	TST R%u\n", get_rreg(a)); /* Load into new register */
	}

	printf("	%s %s\n", op, l);
}

void cg_return(SYMB *a)
{
	if (a != NULL)					/* return value */
	{
		spill_one(R_TP);
		load_reg(R_TP, a);
	}

	printf("	LOD R3,(R2+4)\n");	/* return address */
	printf("	LOD R2,(R2)\n");	/* restore bp */
	printf("	JMP R3\n");		/* return */
}

void cg_head()
{
	char head[] =
		"	# head\n"
		"	LOD R2,STACK\n"
		"	STO (R2),0\n"
		"	LOD R4,EXIT\n"
		"	STO (R2+4),R4";

	puts(head);
}

void cg_lib()
{
	char lib[] =
		"\nPRINTN:\n"
		"	LOD R7,(R2-4) # 789\n"
		"	LOD R15,R7 # 789 \n"
		"	DIV R7,10 # 78\n"
		"	TST R7\n"
		"	JEZ PRINTDIGIT\n"
		"	LOD R8,R7 # 78\n"
		"	MUL R8,10 # 780\n"
		"	SUB R15,R8 # 9\n"
		"	STO (R2+8),R15 # local 9 store\n"
		"\n	# out 78\n"
		"	STO (R2+12),R7 # actual 78 push\n"
		"\n	# call PRINTN\n"
		"	STO (R2+16),R2\n"
		"	LOD R4,R1+32\n"
		"	STO (R2+20),R4\n"
		"	LOD R2,R2+16\n"
		"	JMP PRINTN\n"
		"\n	# out 9\n"
		"	LOD R15,(R2+8) # local 9 \n"
		"\nPRINTDIGIT:\n"
		"	ADD  R15,48\n"
		"	OUT\n"
		"\n	# ret\n"
		"	LOD R3,(R2+4)\n"
		"	LOD R2,(R2)\n"
		"	JMP R3\n"
		"\nPRINTS:\n"
		"	LOD R7,(R2-4)\n"
		"\nPRINTC:\n"
		"	LOD R15,(R7)\n"
		"	DIV R15,16777216\n"
		"	TST R15\n"
		"	JEZ PRINTSEND\n"
		"	OUT\n"
		"	ADD R7,1\n"
		"	JMP PRINTC\n"
		"\nPRINTSEND:\n"
		"	# ret\n"
		"	LOD R3,(R2+4)\n"
		"	LOD R2,(R2)\n"
		"	JMP R3\n"

		"\n"
		"EXIT:\n"
		"	END\n";

	puts(lib);
}

void cg_data(void)
{
	int i;

	SYMB *sl;

	for (sl = GlobalSymbolTable; sl != NULL; sl = sl->next)
	{
		if (sl->type == SYM_TEXT) cg_str(sl);
	}

	printf("STATIC:\n");
	printf("	DBN 0,%u\n", tos);
	printf("STACK:\n");
}

void cg_str(SYMB *s)
{
	char *t = s->name; /* The text */
	int i;

	printf("L%u:\n", s->lable); /* Label for the string */
	printf("	DBS "); /* Label for the string */

	for (i = 1; t[i + 1] != 0; i++)
	{
		if (t[i] == '\\')
		{
			switch (t[++i])
			{
			case 'n':
				printf("%u,", '\n');
				break;

			case '\"':
				printf("%u,", '\"');
				break;
			}
		}
		else printf("%u,", t[i]);
	}

	printf("0\n"); /* End of string */
}

void flush_all(void)
{
	int r;

	spill_all();

	for (r = R_GEN; r < R_NUM; r++) clear_desc(r);

	clear_desc(R_TP); /* Clear result register */
}

void spill_all(void)
{
	int r;
	for (r = R_GEN; r < R_NUM; r++) spill_one(r);
}

void spill_one(int r)
{
	if ((rdesc[r].name != NULL) && rdesc[r].modified)
	{
		if (rdesc[r].name->store == 1) /* local var */
		{
			printf("	STO (R%u+%u),R%u\n", R_BP, rdesc[r].name->offset, r);
		}
		else /* global var */
		{
			printf("	LOD R%u,STATIC\n", R_TP);
			printf("	STO (R%u+%u),R%u\n", R_TP, rdesc[r].name->offset, r);
		}
		rdesc[r].modified = UNMODIFIED;
	}
}


void load_reg(int r, SYMB *n)
{
	int s;

	/* Look for a register */
	for (s = 0; s < R_NUM; s++)
	{
		if (rdesc[s].name == n)
		{
			printf("	LOD R%u,R%u\n", r, s);
			insert_desc(r, n, rdesc[s].modified);
			return;
		}
	}

	/* Not in a reg. Load appropriately */
	switch (n->type)
	{
	case SYM_INT:
		printf("	LOD R%u,%u\n", r, n->value);
		break;

	case SYM_VAR:
		if (n->store == 1) /* local var */
		{
			if ((n->offset) >= 0) printf("	LOD R%u,(R%u+%d)\n", r, R_BP, n->offset);
			else printf("	LOD R%u,(R%u-%d)\n", r, R_BP, -(n->offset));
		}
		else /* global var */
		{
			printf("	LOD R%u,STATIC\n", R_TP);
			printf("	LOD R%u,(R%u+%d)\n", r, R_TP, n->offset);
		}
		break;

	case SYM_TEXT:
		printf("	LOD R%u,L%u\n", r, n->lable);
		break;
	}

	insert_desc(r, n, UNMODIFIED);
}

void clear_desc(int r)
{
	rdesc[r].name = NULL;
}

void insert_desc(int r, SYMB *n, int mod)
{
	int or ; /* Old register counter */

	/* Search through each register in turn looking for "n". There should be at most one of these. */
	for (or = R_GEN; or < R_NUM; or ++)
	{
		if (rdesc[or ].name == n)
		{
			/* Found it, clear it and break out of the loop. */

			clear_desc(or );
			break;
		}
	}

	/* We should not find any duplicates, but check, just in case. */

	for (or ++; or < R_NUM; or ++)

		if (rdesc[or ].name == n)
		{
			error("Duplicate slave found");
			clear_desc(or );
		}

	/* Finally insert the name in the new descriptor */

	rdesc[r].name = n;
	rdesc[r].modified = mod;
}

int get_rreg(SYMB *c)
{
	int r; /* Register for counting */

	for (r = R_GEN; r < R_NUM; r++) /* Already in a register */
	{
		if (rdesc[r].name == c)
		{
			spill_one(r);
			return r;
		}
	}

	for (r = R_GEN; r < R_NUM; r++)
	{
		if (rdesc[r].name == NULL) /* Empty register */
		{
			load_reg(r, c);
			return r;
		}

	}
	for (r = R_GEN; r < R_NUM; r++)
	{
		if (!rdesc[r].modified) /* Unmodifed register */
		{
			clear_desc(r);
			load_reg(r, c);
			return r;
		}
	}

	spill_one(R_GEN); /* Modified register */
	clear_desc(R_GEN);
	load_reg(R_GEN, c);
	return R_GEN;
}

int get_areg(SYMB *b, int cr)
{
	int r; /* Register for counting */

	for (r = R_GEN; r < R_NUM; r++)
	{
		if (rdesc[r].name == b) /* Already in register */
			return r;
	}

	for (r = R_GEN; r < R_NUM; r++)
	{
		if (rdesc[r].name == NULL) /* Empty register */
		{
			load_reg(r, b);
			return r;
		}
	}

	for (r = R_GEN; r < R_NUM; r++)
	{
		if (!rdesc[r].modified && (r != cr)) /* Unmodifed register */
		{
			clear_desc(r);
			load_reg(r, b);
			return r;
		}
	}

	for (r = R_GEN; r < R_NUM; r++)
	{
		if (r != cr) /* Modified register */
		{
			spill_one(r);
			clear_desc(r);
			load_reg(r, b);
			return r;
		}
	}
}

using namespace std;

enum sytype { unkonwPunc, invalidComb, correct };//词法状态
enum stype { sIDENTIFIER, sINTEGER, sTEXT };//符号类型
struct Syntype //词法错误信息
{
	sytype type;
	char error_info[10];
}syntype;

class SYMBOL //符号
{
public:
	stype type;	//类型
	char* lexme; //字面量
	SYMBOL() :type(sIDENTIFIER), lexme(nullptr) {}
	SYMBOL(stype t, char* lexme) :type(t), lexme(lexme) {};
	bool operator <(const SYMBOL &a)const {
		return a.type < type || (a.type == type && (strcmp(a.lexme, lexme) < 0));
	};
};
typedef map<SYMBOL, int *> SYMBOLMAP;//符号表类型，键值为地址

char punctuators[20] = {
	'(',')',
	'{','}',
	',',';','!',
	'+','-','*','/','=',
	'>','<',
	'\0'
};
char AppendInfo[1000] = { 0 };//附加信息
int Append = 0; //附加模式
int AppIp = 0; //附加信息指针
SYMBOLMAP SymbolMap;//符号表

SYMBOLMAP::iterator IdfindInMap(SYMBOLMAP &Map, SYMBOL &val)//在Map 中查找，找到返回迭代器
{
	auto it = Map.find(val);
	if (it != Map.end())//找到了
		return it;
	else
	{
		if (val.type == sINTEGER)
		{
			int *p = (int *)malloc(4);
			*p = atoi(val.lexme);
			Map[val] = (int *)p;
		}
		if (val.type == sTEXT || val.type == sIDENTIFIER)
		{
			Map[val] = (int *)val.lexme;
		}
	}
	return  it;
}

int main(int argc, char *argv[])
{

	int i; /* General counter */
	char *ifile;
	char *ofile;
	if (argc == 2)
	{
		mode = 0;
	}
	else if (argc == 3)
	{
		if (!strcmp(argv[2], "-lex"))
			mode = 1;
		else if (!strcmp(argv[2], "-syn"))
			mode = 2;
		else if (!strcmp(argv[2], "-tac"))
			mode = 3;
		else if (!strcmp(argv[2], "-sym"))
		{
			mode = 1;
			Append = 1;
		}
		else
		{
			printf("error: argument %s\n", argv[2]);
			exit(0);
		}
	}
	else
	{
		printf("usage: %s name [-lex/-syn/-tac/-sym]\n", argv[0]);
		exit(0);
	}

	ifile = (char *)malloc(strlen(argv[1]) + 10);
	strcpy(ifile, argv[1]);
	strcat(ifile, ".gpl");

	if (freopen(ifile, "r", stdin) == NULL)
	{
		printf("error: open %s failed\n", ifile);
		exit(0);
	}

	ofile = (char *)malloc(strlen(argv[1]) + 10);
	strcpy(ofile, argv[1]);

	if (mode == 1)
		strcat(ofile, ".lex");
	else if (mode == 2)
		strcat(ofile, ".syn");
	else if (mode == 3)
		strcat(ofile, ".tac");
	else
		strcat(ofile, ".gal");

	if (freopen(ofile, "w", stdout) == NULL)
	{
		printf("error: open %s failed\n", ofile);
		exit(0);
	}

	/* Give values to global variables */
	line = 1;
	character = 0;
	token[0] = 0;
	LocalScope = 0;
	GlobalSymbolTable = NULL;
	LocalSymbolTable = NULL;
	tos = 0;
	symb_list = NULL; /* Freelists */
	enode_list = NULL;
	next_tmp = 0; /* No temporaries used */
	next_label = LAB_MIN;
	syntype.type = correct;
	memset(syntype.error_info, 0, sizeof(syntype.error_info));
	/* parse */
	yyparse();

	/* tac */
	tac_tidy();
	if (mode == 3)
	{
		TAC * cur;
		for (cur = tac_first; cur != NULL; cur = cur->next)
		{
			tac_print(cur);
			printf("\n");
		}
		exit(0);
	}

	/* code generate */
	cg();

	if (Append == 1)
	{
		freopen("CON", "w", stdout);
		printf("%s", AppendInfo);	//二元式

		for (auto vi : SymbolMap) //符号表
		{
			if (vi.first.type == sINTEGER)
			{
				printf("%p,%d\n", vi.second, *(vi.second));
			}
			if (vi.first.type == sTEXT || vi.first.type == sIDENTIFIER)
			{
				printf("%p,%s\n", vi.second, (char *)vi.second);
			}
		}
	}
	return 0;
}


int yyerror(char *str)
{
	if (syntype.type == unkonwPunc)
	{
		fprintf(stderr, "Undefined character '%c' at line %d\n", syntype.error_info[0], line);
	}
	else if (syntype.type == invalidComb)
	{
		fprintf(stderr, "Invalid combination \"%s\" at line %d\n", syntype.error_info, line);
	}
	else
		fprintf(stderr, "yyerror: %s at line %d\n", str, line);
	return 0;
}

void getch()
{
	character = getchar();
	if (character == '#')
	{
		while (1)
		{
			character = getchar();
			if (character == '\n' || character == EOF) break;
		}
	}
	if (character == '\n') line++;
}

void getnbc()
{
	while ((character == ' ') || (character == '\t') || (character == '\r') || (character == '\n'))
		character = getchar();
}

void concat()
{
	int len = strlen(token);
	token[len] = character;
	token[len + 1] = '\0';
}

int letter()
{
	if (((character >= 'a') && (character <= 'z')) || ((character >= 'A') && (character <= 'Z')))
		return 1;
	else
		return 0;
}

int digit()
{
	if ((character >= '0') && (character <= '9'))
		return 1;
	else
		return 0;
}

void retract()
{
	ungetc(character, stdin);
	character = '\0';
}

int keyword()
{
	int i = 0;
	while (strcmp(keywords[i].name, ""))
	{
		if (!strcmp(keywords[i].name, token))
			return keywords[i].id;
		i++;
	}
	return 0;
}

int punctuator()
{
	int i = 0;
	for (; punctuators[i]; i++)
	{
		if (character == punctuators[i])
			break;
	}
	//非法标点符
	if (punctuators[i] == 0)
		return 0;

	//合法标点符
	if (character == '=')
	{
		concat();
		getch();
		if (character == '=')
		{
			concat();
			return EQ;
		}
		else
		{
			retract();
			return '=';
		}
	}

	if (character == '!')
	{
		concat();
		getch();
		if (character == '=')
		{
			concat();
			return NE;
		}
		else
		{
			syntype.error_info[0] = '!';
			syntype.error_info[1] = character;
			syntype.type = invalidComb;
			retract();
			return '!';
		}
	}

	if (character == '<')
	{
		concat();
		getch();
		if (character == '=')
		{
			concat();
			return LE;
		}
		else
		{
			retract();
			return LT;
		}
	}

	if (character == '>')
	{
		concat();
		getch();
		if (character == '=')
		{
			concat();
			return GE;
		}
		else
		{
			retract();
			return GT;
		}
	}
	return character;//界符
}

int yylex()
{
	int num;
	char *lexeme;
	strcpy(token, "");
	getch();
	getnbc();

	if (letter())
	{
		while (letter() || digit())
		{
			concat();
			getch();
		}
		retract();
		num = keyword();
		if (num != 0)
		{
			if (Append)
			{
				AppIp += sprintf(&AppendInfo[AppIp], "(%d,-)\n", num);
			}
			return num; // return keyword
		}
		else
		{
			lexeme = (char*)malloc(strlen(token + 1));
			strcpy(lexeme, token);
			yylval.string = lexeme;
			if (Append)
			{
				SYMBOL S(sIDENTIFIER, lexeme);
				IdfindInMap(SymbolMap, S);
				AppIp += sprintf(&AppendInfo[AppIp], "(%d,%p)\n", IDENTIFIER, SymbolMap[S]);
			}
			return IDENTIFIER;//标识符
		}
	}

	if (digit())
	{
		while (digit())
		{
			concat();
			getch();
		}
		retract();
		lexeme = (char *)malloc(strlen(token + 1));
		strcpy(lexeme, token);
		yylval.string = lexeme;
		if (Append) {
			SYMBOL S(sINTEGER, lexeme);
			IdfindInMap(SymbolMap, S);
			AppIp += sprintf(&AppendInfo[AppIp], "(%d,%p)\n", INTEGER, SymbolMap[S]);
		}
		return INTEGER;//整数
	}

	if (character == '"')
	{
		concat();
		getch();
		while (character != '"' && character != EOF)
		{
			concat();
			getch();
		}
		if (character == EOF)
		{
			printf("lex error: \" expected\n");
			exit(1);
		}
		concat();
		lexeme = (char *)malloc(strlen(token + 1));
		strcpy(lexeme, token);
		yylval.string = lexeme;
		if (Append)
		{
			SYMBOL S(sTEXT, lexeme);
			IdfindInMap(SymbolMap, S);
			AppIp += sprintf(&AppendInfo[AppIp], "(%d,%p)\n", TEXT, SymbolMap[S]);
		}
		return TEXT;
	}

	num = punctuator();
	if (num)//操作符,界符
	{
		if (AppIp)
			AppIp += sprintf(&AppendInfo[AppIp], "(%d,-)\n", num);
		return num;
	}
	syntype.type = unkonwPunc;
	syntype.error_info[0] = character;
	return character;
}
