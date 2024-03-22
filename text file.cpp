#include <stdio.h>

#pragma warning(disable : 4996)

int main() {
    // Open the file in write mode
    FILE* file = fopen("myTextFile.txt", "w");

    if (file != NULL) {
        // Write the first line
        fprintf(file, "This is line 1.\n");
        // Write the second line
        fprintf(file, "This is line 2.\n");

        // Close the file
        fclose(file);
        printf("Text file created successfully.\n");
    }
    else {
        printf("Error opening the file.\n");
    }

    return 0;
}