#include "Method.h"
#include <stdio.h>


Boolean palindromeR(char s[], int from, int to)
{
if(from==to) return TRUE;

if(s[from]==s[to]) return TRUE;
else if (s[from]!=s[to]) return FALSE;

if(!palindromeR(s, from+1, to-1)) return FALSE;

}

Boolean nonrecursive(char s[], int from, int to)
{
while(s[from++]==s[to--])
{
if(from==to) return TRUE;
}
return FALSE;
}