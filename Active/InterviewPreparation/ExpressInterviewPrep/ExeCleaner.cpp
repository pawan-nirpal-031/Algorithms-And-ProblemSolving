#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main(){
    char cmd[50];
    char extension[10] = "exe";
    strcpy(cmd,"del *.");
    strcat(cmd,extension);
    system(cmd);
    return 0;
}