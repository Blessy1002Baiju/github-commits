#include <stdio.h>

#pragma warning(disable : 4996)

int getNum(FILE** file, const char* filename, const char* mode) 
{
    *file = fopen(filename, mode);
    if (*file == NULL) 
    {
        printf("Error opening the file: %s\n", filename);
        return 0;
    }
    return 1;
}

int main() 
{
  // Make file references
    FILE* textFile;
    FILE* binaryFile;

    
    if (!getNum(&textFile, "myTextFile.txt", "w"))  // Use getNum to access the text file
    {  
        return 1; 
        // If fopen fails, end the program


    }

    fprintf(textFile, "This is line 1.\n"); // Add information to the text file
    fprintf(textFile, "This is line 2.\n");

    // Close the text file
    fclose(textFile);


    if (textFile != NULL)  // Check to see if the text file was produced
    {
        printf("Text file created successfully.\n");
    }
    else 
    {
        printf("Error creating text file.\n");
        return 1; 
        // If the file creation fails, exit the application
    }

    if (!getNum(&binaryFile, "myEvenDataList.data", "wb")) // To access the binary file, use getNum
    {
        return 1; // If fopen fails, exit the application
    }

    // To write, define binary data.
    const unsigned short kBinaryData[] = { 26946, 24942, 31090, 25632, 29793, 8289, 28518, 8306, 28537, 33141, 39308 };

    // Write content to the binary file
    fwrite(kBinaryData, sizeof(unsigned short), sizeof(kBinaryData) / sizeof(unsigned short), binaryFile);

    
    fclose(binaryFile);  // End the binary file
    
    // Check to see if the binary file was produced
    if (binaryFile != NULL) {
        printf("Binary file created successfully.\n");
    }
    else {
        printf("Error creating binary file.\n");
        return 1;
       
        // Close the program if the attempt to create the file fails.

    }

    return 0;
}
