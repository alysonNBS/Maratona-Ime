/*
Platform: Windows
Languages: C, C++
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <dirent.h>

char *strscat(int n, ...);
int compile(char *code, char *language);
void analyse_result();

int main(int argc, char** argv) {
    char *code = "C:\\Users\\alyso\\Maratona Ime\\2016\\Primeira Fase\\Competicao\\L.cpp";
    char *language = "C++";
    char *path_input = "C:\\Users\\alyso\\Maratona Ime\\2016\\Primeira Fase\\Competicao\\L\\input";
    char *path_output = "C:\\Users\\alyso\\Maratona Ime\\2016\\Primeira Fase\\Competicao\\L\\output";

    struct dirent *input;
    struct dirent *output;
    DIR *dir_input = opendir(path_input);
    DIR *dir_output = opendir(path_output);


    if ( compile(code, language) ) {
        printf("Could not compile current file code");
        exit(1);
    }
    if ( dir_input == NULL || dir_output == NULL ) {
        printf("Could not open input or outup directory");
        exit(2);
    }

    while ( (input = readdir(dir_input)) != NULL && (output = readdir(dir_output)) != NULL ) {
        if( strcmp(input->d_name, ".") && strcmp(input->d_name, "..") ) {
            system( strscat( 5, "executable_of_code_test.exe < \"", path_input, "\\", input->d_name, "\" > code_test_output") );
            system( strscat( 5, "fc \"", path_output, "\\", output->d_name, "\" code_test_output > result_fc") );
            analyse_result();
        }
    }

    closedir(dir_input);
    closedir(dir_output);
    system("del /f executable_of_code_test.exe");
    system("del /f code_test_output");
    system("del /f result_fc");

    return 0;
}

int compile(char *code, char *language) {
    if ( !strcmp(language, "CPP") || !strcmp(language, "cpp") || !strcmp(language, "C++") || !strcmp(language, "c++") )
        return system( strscat( 3, "g++ \"", code, "\" -o executable_of_code_test.exe") );
    if ( !strcmp(language, "C") || !strcmp(language, "c") )
        return system( strscat( 3, "gcc \"", code, "\" -o executable_of_code_test.exe") );
    return -1;
}

char *strscat(int n, ...) {
    char *str;
    str = (char *) malloc(sizeof(char) * 1000);
    str[0] = 0;

    va_list strs;
    va_start(strs, n);
    for(int i=0; i<n; i++)
        strcat(str, va_arg(strs, char *));
    va_end(strs);

    return str;
}

void analyse_result() {
    FILE *f;
    f = fopen("result_fc", "r");

    while(!feof(f)) {
        char c;
        fscanf(f, "%c", &c);

        if(c == '*') {
            fclose(f);

            f = fopen("result_fc", "r");

            while(!feof(f)) {
                char c;
                fscanf(f, "%c", &c);
                printf("%c", c);
            }
        }
    }

    fclose(f);
}