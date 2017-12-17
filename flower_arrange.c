#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int length;
	char *row = malloc(sizeof(char));
	int i;

	scanf("%d",&length);

	scanf("%s",row);

	char str[4];

	int count=0,j,k;

	for(i=0;;i++)
	{
		for(j=i,k=0;k<3;j++,k++)
			str[k] = row[j];
		str[k] = '\0';

		if(strcmp(str,"aba")==0)
		{
			*(row+i+2) = 'b';
			count++;
		}

		if(j==length)
			break;
	}
	printf("%d\n",count);

	return 0;
}