     /*  This lex routine uses a counting array to match alphabeticstrings 
         and make a frequency count.
  
         The real item to notice is that yywrap() is called at EOF and then is run
         to do what we need to do.   yywrap() returns true when we have a successful 
         end to the program.  We may want to return false (0) if we want to lexing process 
         to fail 

        Shaun Cooper
        January 2015
   */
	int lgths[100];
	int cnt = 0;
%%
[a-zA-Z]+	lgths[yyleng]++;
[0-9]+          cnt++;
.	|
\n	;
%%

int yywrap()
{
	int i;
	printf("Length  No. words\n");
	for (i=1; i<100; i++) {
		if (lgths[i] > 0) {
			printf("%5d%10d\n",i,lgths[i]);
		}
	}
	printf("\n\n\n-------------\n");
	printf("There are %d numbers\n", cnt);
	return(1);
}

int main()
{  yylex();

}
