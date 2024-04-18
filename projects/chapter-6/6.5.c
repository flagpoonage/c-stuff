#include <stdio.h>;
#include <ctype.h>;
#include <string.h>;

#define MAXWORD 100

struct tnode
{
  char *word;
  int count;
  struct tnode *left;
  struct tnode *right;
};

struct tnode *talloc(void);

void treeprint(struct tnode *);

int main()
{
  struct tnode *root;
  char word[MAXWORD];

  root = NULL;
  while (getword(word, MAXWORD) != EOF)
  {
    if (isalpha(word[0]))
    {
      root = addtree(root, word);
    }
  }

  treeprint(root);
  return 0;
}

struct tnode *
addtree(struct tnode *p, char *w)
{
  int cond;

  if (p == NULL)
  {
    p = talloc();
    p->word = strdup(w);
  }
}

int getword(char *word, int lim)
{
  int c, getch(void);
  void ungetch(int);
  char *w = word;

  while (isspace(c = getch()))
  {
    ;
  }

  if (c != EOF)
  {
    *w++ = c;
  }

  if (!isalpha(c))
  {
    *w = '\0';
    return c;
  }

  for (; --lim > 0; w++)
  {
    if (!isalnum(*w = getch()))
    {
      ungetch(*w);
      break;
    }
  }

  *w = '\0';
  return word[0];
}