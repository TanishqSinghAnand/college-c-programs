    #include <stdio.h>
#include <string.h>

// Program demonstrating all major string functions
// Author: Tanishq (teach your friends with this)

int main() {

    char s1[100] = "Hello";
    char s2[100] = "World";
    char s3[100];

    printf("===== STRING FUNCTIONS DEMO =====\n\n");

    // -----------------------------------------------------------
    // 1. strlen() - length of string
    // -----------------------------------------------------------
    printf("1. strlen():\n");
    printf("Length of '%s' = %lu\n\n", s1, strlen(s1));

    // -----------------------------------------------------------
    // 2. strcpy() - copy string
    // -----------------------------------------------------------
    printf("2. strcpy():\n");
    strcpy(s3, s1);  // s3 = "Hello"
    printf("Copy '%s' into s3 → %s\n\n", s1, s3);

    // -----------------------------------------------------------
    // 3. strncpy() - copy first n chars
    // -----------------------------------------------------------
    printf("3. strncpy():\n");
    strncpy(s3, s2, 3);  // s3 = "Wor"
    s3[3] = '\0';  // add null terminator
    printf("Copy first 3 letters of '%s' → %s\n\n", s2, s3);

    // -----------------------------------------------------------
    // 4. strcat() - concatenate
    // -----------------------------------------------------------
    printf("4. strcat():\n");
    char a[100] = "Hello ";
    char b[100] = "Students";
    strcat(a, b);
    printf("After concat: %s\n\n", a);

    // -----------------------------------------------------------
    // 5. strncat() - concatenate first n chars
    // -----------------------------------------------------------
    printf("5. strncat():\n");
    char x[100] = "Good ";
    char y[100] = "Morning";
    strncat(x, y, 4);   // adds "Morn"
    printf("After strncat: %s\n\n", x);

    // -----------------------------------------------------------
    // 6. strcmp() - compare strings
    // -----------------------------------------------------------
    printf("6. strcmp():\n");
    printf("Compare 'Hello' and 'World' → %d\n", strcmp("Hello", "World"));
    printf("Compare 'Hello' and 'Hello' → %d\n\n", strcmp("Hello", "Hello"));

    // -----------------------------------------------------------
    // 7. strncmp() - compare first n chars
    // -----------------------------------------------------------
    printf("7. strncmp():\n");
    printf("Compare first 3 letters: 'Hello' vs 'Helium' → %d\n\n",
           strncmp("Hello", "Helium", 3));

    // -----------------------------------------------------------
    // 8. strchr() - find first occurrence of a character
    // -----------------------------------------------------------
    printf("8. strchr():\n");
    char name[] = "Tanishq Singh";
    char *p = strchr(name, 'i');
    if(p)
        printf("First 'i' in '%s' found at position: %ld\n\n",
               name, p - name);
    else
        printf("Not found\n\n");

    // -----------------------------------------------------------
    // 9. strrchr() - find last occurrence of a char
    // -----------------------------------------------------------
    printf("9. strrchr():\n");
    p = strrchr(name, 'i');
    if(p)
        printf("Last 'i' found at position: %ld\n\n", p - name);
    else
        printf("Not found\n\n");

    // -----------------------------------------------------------
    // 10. strstr() - find substring
    // -----------------------------------------------------------
    printf("10. strstr():\n");
    char sentence[] = "I love programming in C language";
    char *q = strstr(sentence, "programming");
    if(q)
        printf("Found 'programming' at: %s\n\n", q);
    else
        printf("Not found\n\n");

    // -----------------------------------------------------------
    // 11. strtok() - split string by delimiter
    // -----------------------------------------------------------
    printf("11. strtok():\n");
    char regi[] = "apple,mango,banana,orange";
    char *token = strtok(regi, ",");

    printf("Tokens:\n");
    while(token != NULL){
        printf("%s\n", token);
        token = strtok(NULL, ",");
    }
    printf("\n");

    // -----------------------------------------------------------
    // Extra 1: Reverse string manually
    // -----------------------------------------------------------
    printf("EXTRA 1: Reverse string manually\n");
    char rev[] = "College";
    int len = strlen(rev);
    for(int i = 0; i < len/2; i++){
        char temp = rev[i];
        rev[i] = rev[len - i - 1];
        rev[len - i - 1] = temp;
    }
    printf("Reversed: %s\n\n", rev);

    // -----------------------------------------------------------
    // Extra 2: Count vowels
    // -----------------------------------------------------------
    printf("EXTRA 2: Count vowels\n");
    char line[] = "This is a nice day";
    int count = 0;
    for(int i = 0; line[i] != '\0'; i++){
        char c = line[i];
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
           c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
            count++;
        }
    }
    printf("Vowels in \"%s\" = %d\n\n", line, count);

    // -----------------------------------------------------------
    // Extra 3: Count words
    // -----------------------------------------------------------
    printf("EXTRA 3: Count words\n");
    char text[] = "Hello this is Tanishq teaching string functions";
    int words = 1;
    for(int i = 0; text[i] != '\0'; i++){
        if(text[i] == ' ')
            words++;
    }
    printf("Words = %d\n\n", words);

    printf("===== END OF STRING FUNCTIONS DEMO =====\n");

    return 0;
}
