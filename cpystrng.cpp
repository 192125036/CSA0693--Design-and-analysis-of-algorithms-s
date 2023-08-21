#include <stdio.h>
#include <string.h>

void stringCopy(char dest[], const char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // Add null-terminator to the destination string
}

int main() {
    char source[100];
    char destination[100];

    printf("Enter a string: ");
    scanf("%s", source);

    stringCopy(destination, source);

    printf("Source string: %s\n", source);
    printf("Copied string: %s\n", destination);

    return 0;
}
