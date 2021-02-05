         /* simple lex program which removes comments from a source program
            The main key is that a variable "comment" is set when the start of a comment
            is seen and then unset when the ending set is seen.  It is possible to have
            two starts closed by on end.

            Shaun Cooper
            January 2015
 
         */
        int comment = 0;
        int debug   = 0;  /* prints out debug statements if desired */
        int lineno  = 1;  // keeps track of line number

        /* When we find an opening comment symbol we flip 'comment' indicating that
        We are now in the comment. Now if we see another opening comment before
        the current one terminates we will know that there is an error and we can
        indicate that. Then when we find the terminating comment symbol we flip
        comment again setting it to false.

        In order to count lines we setup a rule for the newline character that
        will increment lineno each time we find a newline. 
        We then use the same logic we used for other characters to print out the
        newlines in comments. 
        */
%%
"/*"	{
	if (comment && debug) fprintf(stderr,
		" >>>>>>>> line %d: Possible Nested comment <<<<<<<<<<\n", lineno);
	comment = 1;
	}

"*/"	{
          if (!comment) printf("%s",yytext); /*print out if it is not in a comment */
  	  comment = 0;
	}
.       { if (!comment) printf("%s",yytext);}
\n {
        
        lineno++;
        if (!comment) printf("%s",yytext);
}

%%

int yywrap(void)
{ return 1;
}

int main()
{
  yylex();
  
}
