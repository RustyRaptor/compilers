     /*  This lex routine uses a counting array to match alphabeticstrings 
         and make a frequency count.
  
         The real item to notice is that yywrap() is called at EOF and then is run
         to do what we need to do.   yywrap() returns true when we have a successful 
         end to the program.  We may want to return false (0) if we want to lexing process 
         to fail 

        Shaun Cooper
        January 2015
   */
	/* Stores an array where the index corresponds to the
	 length of the word and the value is the number of 
	 instances of words of that length
	*/
	int lgths[100];

	/* Stores the count of number groupings we find */
	int cnt = 0;

	/* The first rule looks for groupings of only letters then 
	increments lgths based on yyleng which stores the length
	of the regex found
	
	The second rule looks for groupings of 1 or more digits
	then increment cnt by one
	The remaining lines will just skip over anything else found or newlines
	*/
%%
[a-zA-Z]+	lgths[yyleng]++;
[0-9]+          cnt++;
.	|
\n	;
%%

// our yywrap will print our values when we finish reading all inputs
int yywrap()
{
	int i;
	// print a table showing number of letters and instances
	// skips over entries where we found no words of that length
	printf("Length  No. words\n");
	for (i=1; i<100; i++) {
		if (lgths[i] > 0) {
			printf("%5d%10d\n",i,lgths[i]);
		}
	}
	// print a pretty separator and then just print the count of numbers we found
	printf("\n\n\n-------------\n");
	printf("There are %d numbers\n", cnt);
	return(1);
}

// This executes the entry point for lex
int main()
{  yylex();

}
