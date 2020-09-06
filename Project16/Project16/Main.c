#include <stdio.h>
#include "Method.h"

int main()
{
	char word[20] = "madAM";
	Boolean isPalindrome = palindromeR(word, 0, 4);
	if(isPalindrome)printf("TRUE");
	isPalindrome = nonrecursive(word, 0, 4);
	if (isPalindrome)printf("TRUE");

}
