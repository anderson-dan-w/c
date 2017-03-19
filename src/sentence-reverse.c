#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char my_string[] = "hello world of strings\0";
    char* walker = strdup(my_string);
    printf("my_string: %s\n", my_string);
    const char delim[] = " \0";

    long sentence_len = strlen(walker);
    //char *reversed = malloc(sentence_len * sizeof(char));
    // calloc to clear contents to help with reversal
    char *reversed = calloc(sentence_len, sizeof(char));
    char* rev_offset = reversed + sentence_len;
    char* token;
    
    while(1)
    {
        token = strsep(&walker, delim);
        if (token == NULL)
        {
            printf("token is null\n");
            break;
        }
        long word_len = strlen(token);
        rev_offset -= word_len;
        strcpy(rev_offset, token);
        if (sentence_len > (rev_offset + word_len - reversed)) {
            printf("space");
            rev_offset[word_len] = ' ';
        }
        rev_offset--;
    }
    printf("my_string: %s\n", my_string);
    printf("walker: %s\n", walker);
    printf("reversed: %s\n", reversed);

    for (int i=0; i<sentence_len; ++i) {
        printf("%c", reversed[i]);
    }
    printf("\n");
    return 0;
}
