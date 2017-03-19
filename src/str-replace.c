#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// assume old is in src
char* str_replace(const char* src, const char* old, const char* new)
{
    int output_len = strlen(src) - strlen(old) + strlen(new);
    char* output = malloc(output_len * sizeof(char));

    char* found = strstr(src, old);
    int begin_len = found - src; //pointer arithmetic
    strncpy(output, src, begin_len);
    strcpy(&output[begin_len], new);
    strcpy(&output[begin_len + strlen(new)], &src[begin_len + strlen(old)]);

    return output;
}

int main()
{

    char* out = str_replace("Hi Dan", "Dan", "Kellie");
    printf("out: '%s'\n", out);
    char* out2 = str_replace("Hi Dude", "Dan", "Kellie");
    printf("out: '%s'\n", out2);
    return 0;
}
