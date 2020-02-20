void string_copy(char *str_from, char *str_to)
{	
	int i=0;
	for(;(*(str_to+i)=*(str_from+i))!='\0'; i++) ;	/*循环体为空语句*/
}
void main()
{
	static char array_str1[20]="I am a teacher."; 
	char array_str2[20];
	string_copy(array_str1, array_str2);/*数组名作实参*/ 
	printf("array_str2=%s\n", array_str2);
}
/*string_copy()函数：复制一个字符串*/
/*形参：字符指针 str_from 接收源串，字符指针 str_to 存储目标串 */
