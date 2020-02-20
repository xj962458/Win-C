#include<stdio.h> 
union word
{
	char ch[2]; 
	int	n;
};
void main()
{
	union word w; 
	w.n=0x1234;
	printf("the low is =%x\n",w.ch[0]); 
	printf("the high is =%x\n",w.ch[1]); 
	w.ch[0]='a';
	printf("the number is %x\n",w.n);
}
