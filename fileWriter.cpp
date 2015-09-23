/*
  File:        fileWriter.cpp
  Description: C++ class to easily write file
  Author:      Axel BORJA
  mail:        axel.borja.pro@gmail.com
*/

#ifndef _FILEWRITER_H_
#define _FILEWRITER_H_

#include <fstream>
#include <string>

//
// File writing class
// Provide file write functions
//
class cFileWriter
{
public:
    // Constructor
    // Open file here
    cFileWriter(const char * iFilename)
    {
        _outputFileStream.open(iFilename);
    }

    // Destructor
    // Close file here (guarantee file closing)
    ~cFileWriter()
    {
        _outputFileStream.close();
    }

    // Check is file stream is open
    inline bool is_open() const
    {
        return _outputFileStream.is_open();
    }

    // Put a new line of data
    // Return false if something went wrong
    inline bool putLine(const std::string& iLine)
    {
        _outputFileStream.write(iLine.c_str(), iLine.size());
        _outputFileStream.put('\n');
        return _outputFileStream.good();
    }

    // Move output file stream to position 0 (begin of the file)
    inline void goToBeginningOfFile()
    {
        _outputFileStream.seekp(0);
    }

private:
    std::ofstream _outputFileStream;
};


#endif // _FILEWRITER_H_
