#include<string.h>
#include<stdio.h>

int main()
{
	char s[4];

	int i;

	for(i=0;i<3;i++)
		s[i] = 'a';
	s[i] = '\0';
	printf("%d\n",(int)strlen(s));
}