/*
The MIT License (MIT)

Copyright (c) James Ramm 2015

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef CSVPARSER_H
#define CSVPARSER_H

#include <stdio.h>
#include<stdbool.h>

typedef struct CsvRow {
    char **fields_;
    int numOfFields_;
} CsvRow;

typedef struct CsvParser {
    char *filePath_;
    char delimiter_;
    int firstLineIsHeader_;
    char *errMsg_;
    CsvRow *header_;
    FILE *fileHandler_;
	int fromString_;
	char *csvString_;
	int csvStringIter_;
} CsvParser;

CsvParser *CsvParser_new(const char *filePath, const char *delimiter, bool firstLineIsHeader);
void CsvParser_destroy(CsvParser *csvParser);
void CsvParser_destroy_row(CsvRow *csvRow);
CsvRow *CsvParser_getHeader(CsvParser *csvParser);
CsvRow *CsvParser_getRow(CsvParser *csvParser);
int CsvParser_getNumFields(CsvRow *csvRow);
char **CsvParser_getFields(CsvRow *csvRow);
const char* CsvParser_getErrorMessage(CsvParser *csvParser);

#endif
