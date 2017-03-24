#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// assume single replace, strlen(old) == strlen(new), old at end of src
char* str_replace1(const char* src, const char* old, const char* new)
{
    char* output = malloc(sizeof(char) * (strlen(src) + 1));  //+1 = null-term
    strcpy(output, src);

    char* old_in_output = strstr(output, old);
    strcpy(old_in_output, new);

    return output;
}

// assume single replace, strlen(old) == strlen(new), old in, not ending src
char* str_replace2(const char* src, const char* old, const char* new)
{
    char* output = malloc(sizeof(char) * (strlen(src) + 1));  //+1 = null-term
    strcpy(output, src);

    char* old_in_output = strstr(output, old);
    strncpy(old_in_output, new, strlen(new));

    return output;
}

// assume single replace, strlen(old) == strlen(new), old not in src
char* str_replace3(const char* src, const char* old, const char* new)
{
    char* output = malloc(sizeof(char) * (strlen(src) + 1));  //+1 = null-term
    strcpy(output, src);

    char* old_in_output = strstr(output, old);
    if (old_in_output != NULL)
    {
        strncpy(old_in_output, new, strlen(new));
    }

    return output;
}

//assume single replace, but strlen(old) != strlen(new). (maybe old not in src)
char* str_replace4(const char* src, const char* old, const char* new)
{
    // first, determine if old is in src - if not, easy win
    char* old_in_src = strstr(src, old);
    if (old_in_src == NULL)
    {
        char* output = malloc(sizeof(char) * (strlen(src) + 1));  //+1 = null
        strcpy(output, src);
        return output;
    }

    int output_len = strlen(src) - strlen(old) + strlen(new);
    char* output = malloc(sizeof(char) * (output_len + 1));

    // find out how much to copy from src before old - pointer arithmetic
    int beginning_len = old_in_src - src;
    strncpy(output, src, beginning_len); 

    // now copy in new, starting after what we just copied:
    strcpy(&output[beginning_len], new);

    // copy remainder of src, after end of old, into output, after end of new
    // I know these are getting messy; I'll work on cleaner variable names...
    char* src_old_ending = &old_in_src[strlen(old)];
    char* output_new_ending = &output[beginning_len + strlen(new)];
    strcpy(output_new_ending, src_old_ending);

    return output;
}

int main()
{

    const char src1[] = "feed the dog";
    const char src2[] = "feed the dog please";
    const char dog[] = "dog";
    const char cat[] = "cat";
    const char pig[] = "pig";
    const char bird[] = "bird";
    const char ox[] = "ox";

    printf("\nstr_replace1\n");
    printf("rpl1, src1: '%s'\n", str_replace1(src1, dog, cat));
    printf("rpl1, src2: '%s'\n", str_replace1(src2, dog, cat));

    printf("\nstr_replace2\n");
    printf("rpl2, src1: '%s'\n", str_replace2(src1, dog, cat));
    printf("rpl2, src2: '%s'\n", str_replace2(src2, dog, cat));

    printf("\nstr_replace3\n");
    printf("rpl3, src1: '%s'\n", str_replace3(src1, dog, cat));
    printf("rpl3, src2: '%s'\n", str_replace3(src2, dog, cat));
    printf("rpl3, pig : '%s'\n", str_replace3(src2, pig, cat));

    printf("\nstr_replace4\n");
    printf("rpl4, src1: '%s'\n", str_replace4(src1, dog, cat));
    printf("rpl4, src2: '%s'\n", str_replace4(src2, dog, cat));
    printf("rpl4, pig : '%s'\n", str_replace4(src2, pig, cat));
    printf("rpl4, bird: '%s'\n", str_replace4(src2, dog, bird));
    printf("rpl4, ox  : '%s'\n", str_replace4(src2, dog, ox));

    return 0;
}
