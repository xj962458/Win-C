#include <stdio.h>
#include <stdio.h> 
void main()
{
	int i=0;
	char s[]=" A123 B56C78D0X";
	char szc[15], zfc[15],*s1=szc,*s2=zfc;
	while(s[i]!='\0')
	{
		if (s[i]>='0'&&s[i]<='9') 
			*s1++=s[i];
		else
			*s2++=s[i];
		i++;
	}
	*s1='\0',*s2='\0';
	printf("Êý×Ö´®=%s,×Ö·û´®=%s\n",szc,zfc);
}
