//  about printf(".*")

#include <stdio.h>

int main() {
    int precision = 8;
    int biggerPrecision = 16;
    const char *greetings = "Hello world";

    printf("|%.8s|\n", greetings);
    printf("|%.*s|\n", precision , greetings);
    printf("|%16s|\n", greetings);
    printf("|%*s|\n", biggerPrecision , greetings);

    return 0;
}