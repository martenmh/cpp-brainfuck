#include <string.h>
#include <fstream>
#include <iostream>

int main(int argc, char* argv[]){
    int memory[30000];
    int* ptr = memory;
    // Just take the first input as the brainfuck filename
    std::ifstream infile(argv[1]);

    std::string line;
    while (std::getline(infile, line))
    {
        for(int i = 0; i < line.length(); ++i){   //loop over the characters

            switch(line[i]){
                case '>':
                    ptr++;
                    break;
                case '<':
                    ptr--;
                    break;
                case '+':
                    *ptr += 1;
                    break;
                case '-':
                    *ptr -= 1;
                    break;
                case '.':
                    std::cout << (char)*ptr;
                    break;
                case ',':
                    *ptr = putchar(line[i]);
                    break;
                case '[':
                    if(*ptr == 0){ // jump past ]
                        do{
                            i++;
                        }while(line[i] != ']');
                        i++;
                    }
                    break;
                case ']':
                    if(*ptr != 0){ //jump back to [
                        do{
                            i--;
                        }while(line[i] != '[');
                    } 
                    break;
                default:
                        //do nothing
                        break;
            }
        }
    }
}
