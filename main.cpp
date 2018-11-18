#include <iostream>
#include <fstream>

/**
 * The program reads numbers from input file and prints the Sum of them
 * Example: main.exe ./tests/input.in
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */
int main(int argc, const char* argv[])
{
    float Sum = 0;
    int Counter = 0;
    float* dynArr;
    std::string line;
    std::ifstream myReadFile;
    myReadFile.open(argv[1]);

    if (argc < 2) {
        std::cout << "Invalid amount of parameters, did you pass the file correctly?" << std::endl;
        exit(EXIT_FAILURE);
    }
    while (myReadFile >> line) {
        Counter += 1;
    }

    dynArr = new float[Counter];
    myReadFile.clear();
    myReadFile.seekg(0, myReadFile.beg);

    for (int i = 0; i < Counter; i++) {
        if (myReadFile >> dynArr[i]) {
            Sum += dynArr[i];
        }
        else {
            std::cout << "Invalid input data" << std::endl;
            delete[] dynArr;
            exit(EXIT_FAILURE);
        }
    }

    myReadFile.close();
    float average = Sum / Counter;
    float printableAverage = (float)((int)(average * 1000)) / 1000;
   
    for (int i = 0; i < Counter; i++) {
        if (dynArr[i] > average)
            std::cout << ((float)((int)(dynArr[i] * 1000)) / 1000) << " is bigger than the average which is " << printableAverage << std::endl;
    }

    delete[] dynArr;
    return 0;
}
