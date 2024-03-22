#include <stdio.h>

#pragma warning(disable : 4996)

int getNum(FILE** file, const char* filename, const char* mode) {
    *file = fopen(filename, mode);
    if (*file == NULL) {
        printf("Error opening the file: %s\n", filename);
        return 0;
    }
    return 1;
}

int main() {
    // Declare file pointers
    FILE* textFile;
    FILE* binaryFile;

    // Open the text file using getNum
    if (!getNum(&textFile, "myTextFile.txt", "w")) {
        return 1; // Exit the program if fopen fails
    }

    // Write content to the text file
    fprintf(textFile, "This is line 1.\n");
    fprintf(textFile, "This is line 2.\n");

    // Close the text file
    fclose(textFile);

    // Verify if the text file is created
    if (textFile != NULL) {
        printf("Text file created successfully.\n");
    }
    else {
        printf("Error creating text file.\n");
        return 1; // Exit the program if file creation fails
    }

    // Open the binary file using getNum
    if (!getNum(&binaryFile, "myEvenDataList.data", "wb")) {
        return 1; // Exit the program if fopen fails
    }

    // Define binary data to write
    const unsigned short kBinaryData[] = { 26946, 24942, 31090, 25632, 29793, 8289, 28518, 8306, 28537, 33141, 39308 };

    // Write content to the binary file
    fwrite(kBinaryData, sizeof(unsigned short), sizeof(kBinaryData) / sizeof(unsigned short), binaryFile);

    // Close the binary file
    fclose(binaryFile);

    // Verify if the binary file is created
    if (binaryFile != NULL) {
        printf("Binary file created successfully.\n");
    }
    else {
        printf("Error creating binary file.\n");
        return 1; // Exit the program if file creation fails
    }

    return 0;
}
