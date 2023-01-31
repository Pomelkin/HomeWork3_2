#include <windows.h>
#include <fstream>
#pragma hdrstop
#include "pt4.h"
using namespace std;

void play(PNode ptr1, bool& output)
{
	if (ptr1 != NULL)
	{
		play(ptr1->Left, output);
		play(ptr1->Right, output);
		int count_l = 0; int count_r = 0;
		if (ptr1->Left) count_l = ptr1->Left->Data;
		if (ptr1->Right) count_r = ptr1->Right->Data;
		ptr1->Data = count_l + count_r + 1;
		if (abs(count_l - count_r) > 1) output = false;
	}
}

void include(PNode& Tree, int x)
{
	if (Tree == NULL)
	{
		Tree = new TNode;
		Tree->Data = x;
		Tree->Left = NULL;
		Tree->Right = NULL;
	}
	else
		if (x < Tree->Data) include(Tree->Left, x);
		else
			if (x > Tree->Data) include(Tree->Right, x);
}

void create(PNode& Tree, fstream& FILE)
{
	int x;
	while (FILE.peek() != EOF)
	{
		FILE >> x;
		include(Tree, x);
	}
}

void RL(PNode& Tree)
{
	PNode z = Tree->Right->Left;
	Tree->Right->Left = z->Right;
	z->Right = Tree->Right;
	Tree->Right = z->Left;
	z->Left = Tree;
	Tree = z;
}


void Solve()
{
    Task("TreeWork67");
	fstream FILE;
	string name;
	bool q = true;
	pt >> name;
	FILE.open(name.c_str());
	PNode Tree = NULL;
	create(Tree, FILE);
	play(Tree, q);
	if (!q) RL(Tree);
	FILE.close();
	pt << Tree;
}
