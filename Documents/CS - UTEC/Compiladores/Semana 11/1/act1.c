/*

num-base→0 num | num 
num→num digito | digito
digito→0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9

*/

typedef enum {num-base,num} nodekind;
typedef enum {octal,decimal} typekind; 
typedef struct treeNode
{	nodekind kind;
	struct treeNode * lchild, * rchild, * sibling;
	typekind base;
	int * digito;
} * SyntaxTree;

void evalBase (SyntaxTree t) 
{ 	if (t->kind == num-base)
	{	SyntaxTree p = t->lchild; 
		p->base = t->rchild->base; 
		while (p->sibling != NULL)
		{ 	p->sibling->base = p->base; 
			p = p->sibling;
		}
	} 
} 
