void string_copy(char *str_from, char *str_to)
{	
	int i=0;
	for(;(*(str_to+i)=*(str_from+i))!='\0'; i++) ;	/*ѭ����Ϊ�����*/
}
void main()
{
	static char array_str1[20]="I am a teacher."; 
	char array_str2[20];
	string_copy(array_str1, array_str2);/*��������ʵ��*/ 
	printf("array_str2=%s\n", array_str2);
}
/*string_copy()����������һ���ַ���*/
/*�βΣ��ַ�ָ�� str_from ����Դ�����ַ�ָ�� str_to �洢Ŀ�괮 */
