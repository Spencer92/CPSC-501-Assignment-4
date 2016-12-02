#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

#define BYTE 16
#define NEGATIVE_FLOAT 32768
#define POSITIVE_FLOAT 32767
#define CHAR 256

int main(int argc, char** argv) {

/*    int input;
    unsigned short thing = numeric_limits<unsigned short>::max();
    cout << sizeof(char) << endl;
    cout << sizeof(short) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(long) << endl;
    cout << numeric_limits<char>::max() << endl;
    cout << numeric_limits<unsigned short>::max() << endl;
    cout << numeric_limits<int>::max() << endl;
    cout << thing/256 << endl;
    cout << thing/(256 * 256) << endl;*/

    ifstream audioFile;
    int fileLength = 0;
    unsigned short digit;
    unsigned char part_of_digit;

    audioFile.open("END.wav");

    while(!audioFile.eof())
    {
        fileLength++;
    }
    audioFile.close();
    audioFile.open("FluteDry.wav");
    float newValues[fileLength];
    int index = 0;
    while(!audioFile.eof())
    {
        part_of_digit = audioFile.get();
        digit = (unsigned short) part_of_digit * CHAR;
        if(!audioFile.eof())
        {
            part_of_digit = audioFile.get();
            digit += (unsigned short) part_of_digit;
        }

        if(index < fileLength)
        {
            newValues[index] = (float) digit/NEGATIVE_FLOAT;
            index++;
        }

    }

    std::cout << "Hello, World!" << std::endl;

    return 0;
}