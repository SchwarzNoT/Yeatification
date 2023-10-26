// YEATIFICATION.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <Windows.h>

const int BUFFER_SIZE = 1000000;

void convertChars(char* buffer, size_t size) {
    for (int i = 0; i < size; i++) {
        switch (buffer[i]) {
        case 'A': buffer[i] = 'Ä'; break;
        case 'a': buffer[i] = 'ä'; break;
        case 'E': buffer[i] = 'Ë'; break;
        case 'e': buffer[i] = 'ë'; break;
        case 'I': buffer[i] = 'Ï'; break;
        case 'i': buffer[i] = 'ï'; break;
        case 'O': buffer[i] = 'Ö'; break;
        case 'o': buffer[i] = 'ö'; break;
        case 'U': buffer[i] = 'Ü'; break;
        case 'u': buffer[i] = 'ü'; break;
        }
    }
}
bool readText(char* filePath, char* buffer, int BUFFER_MAX_SIZE, size_t* size) {

    std::ifstream fin;

    fin.open(filePath, std::ios::binary | std::ios::in);

    if (!fin.is_open()) {

        printf("Failed To Locate The Input File\nCreate New Input File?\nY | N\n");

        char answer;

        scanf_s("%c", &answer);

        if (answer == 'Y' || answer == 'y') {

            std::ofstream fout;
            fout.open(filePath, std::ios::binary | std::ios::out);
            fout.close();

        }
        else {

            return false;
        }

    }
    
    fin.read(buffer, BUFFER_MAX_SIZE);

    printf("Successfully Copied From File\n");

    *size = fin.gcount();

    fin.close();
    
    return true;
}
void writeText(char* filePath, char* buffer, size_t size) {

    std::ofstream fout;

    fout.open(filePath, std::ios::binary | std::ios::out);
    
    fout.write(buffer, size);

    fout.close();

    printf("Finished Execution, Please Check The Output File\nIf There Are Errors Please Make Sure Your Input Was in Default ASCII Character Set (Look Mainly at Quote Marks)\n ");

}

int main()
{
    char buffer[BUFFER_SIZE];

    size_t size{};

    readText((char*)"input.txt", buffer, sizeof(buffer), &size);

    printf("Char count: %d\n", size);

    convertChars(buffer, size);

    writeText((char*)"output.txt", buffer, size);

    Sleep(5000);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
