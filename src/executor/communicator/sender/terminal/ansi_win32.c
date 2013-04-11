#include <windows.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <regex.h>
#include <stdlib.h>

void *getConsoleFunction(char *name) {
   static HMODULE kernel32=(HMODULE)0xffffffff;
   if(kernel32==0)
      return NULL;
   if(kernel32==(HMODULE)0xffffffff) {
      kernel32=LoadLibrary("kernel32.dll");
      if(kernel32==0)
         return 0; 
   }
   return GetProcAddress(kernel32,name);
}

BOOL (WINAPI *doSetConsoleTextAttribute)(HANDLE hConsoleOutput, WORD attr);

int eval_regex(char* regularExpression, char* sourceString)
{
  regex_t regex;
  int wasCompiledSuccessfully;
  int resultOfRegexEval;
  char messagebuffer[100];

  /* Compile regular expression */
  wasCompiledSuccessfully = regcomp(&regex, regularExpression, 0);
  if( wasCompiledSuccessfully )
  {
//    printf("%s", "Could not compile regex\n");
    resultOfRegexEval = -1;
  }

  /* Execute regular expression --> abc is the source string */
  wasCompiledSuccessfully = regexec(&regex, sourceString, 0, NULL, 0);
  if( !wasCompiledSuccessfully )
  {
//    printf("%s\n", "Match");
    resultOfRegexEval = 1;
  }
  else if( wasCompiledSuccessfully == REG_NOMATCH )
  {
//    printf("%s\n", "No Match");
    resultOfRegexEval = 0;
  }
  else
  {
    regerror(wasCompiledSuccessfully, &regex, messagebuffer, sizeof(messagebuffer));
//    printf("Regex match failed: %s\n", messagebuffer);
    resultOfRegexEval = -2;
  }

  /* Free compiled regular expression if you want to use the regex_t again */
  regfree(&regex);
  return resultOfRegexEval;
}

size_t explode(const char *delim, const char *str, char **pointers_out, char *bytes_out)
{
    size_t delim_length = strlen(delim);
    char **pointers_out_start = pointers_out;

    assert(delim_length > 0);

    for (;;) {
        const char *delim_pos = strstr(str, delim);
        *pointers_out++ = bytes_out;

        if (delim_pos == NULL) {
            strcpy(bytes_out, str);
            return pointers_out - pointers_out_start;
        } else {
            while (str < delim_pos)
                *bytes_out++ = *str++;

            *bytes_out++ = '\0';

            str += delim_length;
        }
    }
}

void printansi(FILE *stream, char *str)
{

    HANDLE hCon;
    int i, j;

    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
          
    doSetConsoleTextAttribute = getConsoleFunction("SetConsoleTextAttribute");

    // if SetConsoleTextAttribute is not supported then output the ansi escape sequence 
    if (doSetConsoleTextAttribute == NULL) {
        fprintf(stream, "\033[%s", str);
        return;
    }

    // translate the ansi escape sequences
    if (eval_regex("2J", str) == 1)
        system("cls");
//    if (eval_regex("([0-9]*;)*[0-9]+m", str) == 1)
    if (eval_regex("34m", str) == 1)
    {
        (*doSetConsoleTextAttribute)(hCon, (0*16)+4); // back black / fore red normal
    }

    // print the remaining string
    fprintf(stream, "%s", str);
}

int cfwprintf(FILE *stream, const char *format, ...)
{
    va_list args;
    char buffer[1024];

    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer)-1, format,args);
    va_end(args);

    char *items[1024];
    char item_bytes[1024];
    size_t i;
    size_t count;

    // split the string on every ansi escape sequence("\033[")
    count = explode("\033[", buffer, items, item_bytes);

    if (count > 0)
    {
        // first item never contains an ansi escape sequences
        // if a string begins with a ansi escape sequence then thew first string is empty
        fprintf(stream, "%s", items[0]);

        for (i = 1; i < count; i++)
            printansi(stream, items[i]);
    }

    return 0;
}