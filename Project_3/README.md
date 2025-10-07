Grant Tatge
ID: 008653704
Github: https://github.com/GrantTatge/CS315/tree/main/Project_3
## Project 3 - Part 1 Overview
All of the code in this project was written by me. I spent an afternoon collaborating with Burke N, working through setting up the project and figuring out what our methods should do. Ultimately my readWord() ended up very similar to his, though I did write it without looking at what he wrote beforehand. As per usual, I did not use AI for this assignment.

The vast majority of my time on this project was spent figuring out how to implement a solution based on the code given. Despite rereading main.cpp and Scanner.hpp many times, it took me several hours to realize that all I had to do is make sure each word was being written into the vector words. My initial implementation of tokenize() both read the .txt and wrote the vector into the .tokens file, which lead to a lot of confusion until I reread what writeVectorToFile() actually does. The current implementation calls tokenize() with the words vector, which itself calls a private overloaded tokenize() that takes an input path (this is what the main.cpp given did, and I'm under the impression that we're not supposed to alter it). Something I might change is that since the input path is defined in the constructor, the overload is technically unnecessary right now since the private inputPath_ variable could just be accessed directly, but for the moment I feel that this implementation is a bit safer and ultimately is harmless, plus allows for altered inputs. In the initial tokenize(), since the input file (x.txt) given is actually the output file (x.tokens), the first thing that's done is a .txt is built from the input .tokens; this new .txt file is given as an input to the overloaded tokenize() to read from. The file is read by calling readWord() until the end of the document is hit, returning no error if successful.

Also, obviously I decided to actually figure out how to write in markdown, so I'm using that instead of .txt files now.

### Scanner::Scanner(std::filesystem::path inputPath)
Constructor, simply sets the private variable inputPath_ to inputPath

### error_type Scanner::tokenize(std::vector<std::string>& words)
Constructs an input text file from _inputPath (since the input file in main.cpp is a tokens file, which is what we're outputting tokens to), and calls the overloaded tokenize with the new text file path.

### error_type Scanner::tokenize(std::vector<std::string> &words, const std::filesystem::path &inputFile)
Does exactly as described in the paragraph above: inputFile is read word by word via readWord(), which handles both reading words and progressing through the input file stream. If the return value of readWord() is not an empty string, it is pushed to the back of words. Once the end of the file is reached, the input file stream is closed and NO_ERROR is returned. Since words is being dereferenced, it does not have to be returned. If the input file cannot be opened, the relevant error is returned instead.

### static std::string Scanner::readWord(std::istream &in)
Appends each character of the current word to a return string, out. curr represents the current character being observed. Any invalid characters are skipped over until a valid character is reached, in which each character is appended to out until an invalid character is found. out is then returned. The method is static to ensure that it doesn't "lose its place."

### Testing
I tested my code on both my laptop and on the Blue server. I ended up running the bash files with every given input file, and I had no differences in any of them. For the_call_of_the_wild.tokens, I checked the number of lines in both my output file and in the .tokens file to compare against, and both sat at 35484 lines. 