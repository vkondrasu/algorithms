/*
  This file contains the code for creating an expression tree from the given string expression.
  TO-DO: presently we have to insert paranthesis around the expression before passing the string to parse() method,
         write a method that encloses the expression in paranthesis before passing it to parse().
*/
#include <iostream>
#include <string.h>
#include <stack>
#include <stdlib.h>

using namespace std;

struct ExprTreeNode
{
  ExprTreeNode *left, *right;
  bool is_leaf;
  int value;
  char op;
};

class ExpressionTree
{
  public:
  ExprTreeNode* get_new_ExprTreeNode();
  ExprTreeNode* parse(string);
  int getValue(string);
  int findRightParanthesis(string,int);
  int findLeftParanthesis(string,int);
  int compute(ExprTreeNode*);
};

ExprTreeNode* ExpressionTree::get_new_ExprTreeNode()
{
  ExprTreeNode* temp = (ExprTreeNode*)malloc(sizeof(ExprTreeNode));
  memset(temp, 0, sizeof(ExprTreeNode));
  return temp;
}

ExprTreeNode* ExpressionTree::parse(string expression)
{
  ExprTreeNode* root = get_new_ExprTreeNode();
  int m = findRightParanthesis(expression, 1);
  string leftExpr = expression.substr(1, m);
  
  if(m == expression.length() - 1)
  {
    string operand = expression.substr(1, expression.length() - 1);
    root->is_leaf = true;
    root->value = getValue(operand);
    return root;
  }

  int n = findLeftParanthesis(expression, expression.length() - 2);
  string rightExpr = expression.substr(n, expression.length() - n - 1);

  root->left = parse(leftExpr);
  root->right = parse(rightExpr);
  root->is_leaf = false;
  root->op = expression[m+1];

  return root;
}

int ExpressionTree::getValue(string operand)
{
  return atoi(operand.c_str());
}

int ExpressionTree::findRightParanthesis(string expression, int leftposition)
{
  stack<char> stchar;
  stchar.push(expression[leftposition]);
  int i;
  for(i=leftposition+1; i < expression.length()-1; i++)
  {
    if(expression[i] == '(')
      stchar.push('(');
    else if(expression[i] == ')')
    {
      stchar.pop();
      if(stchar.empty())
        return i;
    }
  }
  return i;
}


int ExpressionTree::findLeftParanthesis(string expression, int rightposition)
{
  stack<char> stchar;
  stchar.push(expression[rightposition]);
  int i;
  for(i=rightposition-1; i >= 0; i--)
  {
    if(expression[i] == ')')
      stchar.push(')');
    else if(expression[i] == '(')
    {
      stchar.pop();
      if(stchar.empty())
        return i;
    }
  }
  return i;
}

void printTree(ExprTreeNode* root)
{
  if(root->right != NULL)
    printTree(root->right);
  if(root->left != NULL)
    printTree(root->left);
  if(root->value != 0)
    cout<< root->value << " ";
  else
    cout<< root->op <<" ";
}

int ExpressionTree::compute(ExprTreeNode * root)
{
  if(root->is_leaf)
    return root->value;
  int leftvalue = compute(root->left);
  int rightvalue = compute(root->right);
  
  switch(root->op)
  {
    case '+':
      return leftvalue + rightvalue;
    case '-':
      return leftvalue - rightvalue;
    case '*':
      return leftvalue * rightvalue;
    case '/':
      return leftvalue / rightvalue;
  }
}
//driver method

int main()
{
  ExpressionTree e;
  ExprTreeNode *root = e.parse("(((35)-((3)*((3)+(2))))/(4))");
  printTree(root);
  cout<<endl;
  cout<< e.compute(root)<<endl;
  return 0;
}
