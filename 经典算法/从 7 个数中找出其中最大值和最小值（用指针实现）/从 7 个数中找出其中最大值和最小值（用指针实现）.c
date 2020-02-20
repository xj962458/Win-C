int	max,min ;
void max_min_value 
(
	int array[ ],int n)
	{
	int *p,*array_end; 
	array_end=array+n; 
	max=min=*array;
	for(p=array+1;p<array_end;p++) 
		if (*p>max)	
			max =*p ;
		else    
			if( *p < min )	
				min = *p	;
}
void main()
{
	int i,number[7] ;
	printf ("enter 7 data\n"); 
	for( i=0; i<7; i++ )
		scanf("%d",&number[i]) ;
	max_min_value( number, 7 ) ;
	printf ("\n max=%d,min=%d\n",max,min) ;
}
