
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdexcept>

int checkForEmptyString(const char* str) {
     if(str == NULL || str[0] == '\0')
    {
      return 1;
    }
  else return 0;
}

int isValueLessthanthousand(int value) {
  if(value < 1000){
    return value;}
  else {
    return 0;}
}

void extractDel(const char* str, char* del) {
    int i = 2, j = 0;  
    while (str[i] != '\0' && str[i] != '\n') {
        del[j++] = str[i++];
    }
    del[j] = '\0'; 
}

void findDel(const char* str, char* del) {
    if (str[0] == '/' && str[1] == '/') {
        extractDel(str, del);
    } else {
        strcpy(del, ",\n");
    }
}

void isValueNegative(int value) {
    if (value < 0) {
        throw std::runtime_error("negatives number is not allowed");
    }
}

int getSum(const char* original_str, const char* delimiter) {
    char* duplicate = strdup(original_str);
    int sum = 0;
    char* token = strtok(duplicate, delimiter);
    while (token != NULL) {
        int value = atoi(token);
        isValueNegative(value);
        sum += isValueLessthanthousand(value);
        token = strtok(NULL, delimiter);
    }
    free(duplicate);
    return sum;
}

int add(const char* str) {
    char del[];
    if (checkForEmptyString(str)) {
        return 0;
    }
    findDel(str, del);
    int sum = getSum(str, del);
    return sum;
}
