/*�����ַ����������г�����֤�������ȱ���С��lens��*/
void stringinput(char *t,int lens,char *notice){
	char n[255];
	do{
		printf(notice);			/*��ʾ��ʾ��Ϣ*/
		scanf("%s",n);		/*�����ַ���*/
		if (strlen(n)>lens)
		{
			/* code */
			printf("\n exceed the required length!\n");/*����У�飬����lensֵ��������*/
		}
	}while(strlen(n)>lens);
	strcpy(t,n);		/*�������ַ������Ƶ��ַ���t��*/
}
 
/*������ֵ������������ֵ����󷵻ظ�ֵ����ֵ������ڵ���0*/
float numberinput(char *notice){
	float t=0.00;
	do{
			printf(notice);/*��ʾ��ʾ��Ϣ*/
			scanf("%f",&t);
			if (t<0)
			{
				/* code */
				printf("\n score must>=0!\n");/*������ֵУ��*/
			}
	}while(t<0);
	return t;
}