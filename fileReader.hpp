/*
  File:        fileReader.hpp
  Description: C++ class to easily read file
  Author:      Axel BORJA
  mail:        axel.borja.pro@gmail.com
*/


#ifndef _FILEREADER_H_
#define _FILEREADER_H_

#include <fstream>
#include <string>

//
// File reading class
// Provide file reading functions
//
class cFileReader
{
public:
    // Constructor
    // Open file here
    cFileReader(const char * iFilename)
    {
        _inputFileStream.open(iFilename);
    }

    // Destructor
    // Close file here (guarantee file closing)
    ~cFileReader()
    {
        _inputFileStream.close();
    }

    // Check is file stream is open
    inline bool is_open() const
    {
        return _inputFileStream.is_open();
    }

    // Get a new line
    // Return false if something went wrong or if it is the end of the file
    inline bool getLine(std::string& oLine)
    {
        std::getline(_inputFileStream, oLine);
        return _inputFileStream.good();
    }

    // Move input file stream to position 0 (begin of the file)
    inline void goToBeginningOfFile()
    {
        _inputFileStream.seekg(0);
    }

private:
    std::ifstream _inputFileStream;
};


#endif // _FILEREADER_H_
