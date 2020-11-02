# include <stdio.h>

// 统计用户输入的小写字母字符串中各字母出现的次数
void main()
{
	char s[100]="", *p;
	int i, a[26];
	gets(s);
	// 将a中26个计数器变量a[0]~a[25]赋值为0
	for(i=0; i<26; i++)
	{
		a[i] = 0;
	}
	p = s;
	while(*p)
	{
		a[*p - 'a']++;	// *p-'a'正好是各字母对应的计数器的下标
		p++;
	}
	for(i=0; i<26; i++)
	{
		printf("%d  ", a[i]);
	}
}
