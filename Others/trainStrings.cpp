/*Strings. Basic operations.
 Working with memory.

***************
 String length, String copy, String compare, String duplication
 Count the words in a text
 Extract all the words from a text
****************/

#include <iostream>
using namespace std;

// Find the lenght of a string.
size_t strlen(const char* text)
{
    size_t length = 0;

    while (text[length]) ++length;

    return length;
}

// Make a copy of a string - from src to dest with indexes
void strcpy(char* copy, const char* src)
{
    int index = 0;

    while(src[index]) 
    {
        copy[index] = src[index];
        ++index;
    }

    copy[index] = '\0';
}

// Make a copy of a string - from src to dest with pointers
void strcpyPtr(char* dest, const char* src)
{
    while (*dest++ = *src++) ;
}

// Compares two strings in lexicographic order
// The result is 0 if the strings are equal,
// negative, if the first is before the second
// and positive in the other case.
int strcmp(const char* text1, const char* text2)
{
    while (*text1 && *text1 == *text2) 
    {
        ++text1;
        ++text2;
    }

    return *text1 - *text2;
}

// Creates a duplicate of a string, using dynamic memory
char* strdup(const char* text)
{
    char* newtext = new(nothrow) char[strlen(text) + 1];

    if(newtext) 
    {
        strcpy(newtext, text);
    }

    return newtext;
}

// Check if a letter is part of a word
bool isWordLetter(char c)
{
    return (c >= 'A' && c <= 'Z') ||
           (c >= 'a' && c <= 'z') ||
           (c >= '0' && c <= '9') ||
           c == '_';
}

// Counts the words in a text.
int wordCount(const char* text)
{
    int counter = 0;

    while (*text) 
    {
        while (*text && !isWordLetter(*text)) 
        {  
            ++text; // skip letters to the beginning of a word
        }
        if (*text) 
        {
            ++counter; // if there is a word, count it   
        }
        while (isWordLetter(*text)) 
        {           
            ++text;  // skip to the end of the word
        }
    }

    return counter;
}

// Check if a string is part of another string.
// Return a pointer to the first occurrence or NULL
// A naive algorithm.
const char* strstr(const char* where, const char* what)
{
    size_t whatLen = strlen(what), index;
    const char* whereEnd = where + strlen(where);

    while (where + whatLen <= whereEnd) 
    { 
        for (index = 0; index < whatLen; ++index) 
        {
            if (where[index] != what[index]) 
            {
                break;
            }
        }
        if (!what[index]) return where;
        ++where;
    }
    return nullptr;
}

/**********************************************************/
// Extract all the words from a text in a new array
// Allocates memory for that array and for each word
// Returns the count of extracted words
int extractWords(const char* text, char *** wordsPtr)
{
    int count = wordCount(text);  // found the count of the words
    *wordsPtr = new(nothrow) char*[count];  // allocate memory for the index array
    if (!*wordsPtr) return 0;

    for (int i = 0; i < count; ++i)
    {          
        // for each word go to the beginning of the word
        while (*text && !isWordLetter(*text)) ++text;

        if (*text) 
        {     
            // and if there is any
            const char* start = text;
            while (isWordLetter(*text)) ++text; // go to the end

            int len = text - start;         // and calculate the length of that word
            (*wordsPtr)[i] = new(nothrow) char[len + 1];   // allocate memory for the word

            if (!(*wordsPtr)[i]) 
            {    
                // If the allocation fails
                cout << "No memory for word " << i;
                return i;       // Return the number of successfully allocated words
                /*
                // Alternative approach - clear all the memory
                for (--i; i >= 0; --i)
                    delete[](*wordsPtr)[i];
                delete[] (*wordsPtr);
                *wordsPtr = NULL;
                return 0;
                */
            }

            for (int pos = 0; pos < len; ++pos)    // copy the word
                (*wordsPtr)[i][pos] = start[pos];
            (*wordsPtr)[i][len] = '\0';            // put a terminal symbol at the end
        }
    }

    return count;
}

// A method to test the above function
void wordTest(const char* text)
{
    char ** words;
    int count = extractWords(text, &words);
    int properCnt = wordCount(text);

    if (!words) 
    {
        cout << "Memory problem!" << endl;
        return;
    }
    if (count != properCnt) 
    {
        cout << "Memory problem - not all words extracted!";
    }

    cout << count << endl;
    for (int i = 0; i < count; ++i)
        cout << words[i] << endl;

    for (int i = 0; i < count; ++i)
        delete[] words[i];
    delete[] words;
}

int main()
{
    const char* text = "C++ is cool and pointers are cool too!";

    char* copy = strdup(text);
    cout << text;
    delete[] copy;

/*
    size_t len = strlen(text);
    cout << len << endl;

    char* buff = new(nothrow) char[len+1];
    if (!buff) {
        cout << "memory problem!" << endl;
        return 1;
    }

    strcpyPtr(buff, text);
    cout << buff << endl;
    cout << strcmp(buff, text) << endl;
    buff[len-1] = '.';
    cout << strcmp(buff, text) << endl;

    delete[] buff;
*/

//    cout << strstr(text, "too!") << endl;

//    wordTest(text);
    return 0;
}