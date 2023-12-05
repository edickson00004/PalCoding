//
// Created by Hubert Starosta on 2023-12-04.
//
#include "model.h"
#include "interface.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

typedef struct{
    long storedValue;
    char string[50];
}Node;
Node excelSheet[10][7];
//char *parser(char *text){
//
//}
long formulaEvaluator(char *text, long total){

    if (text[0] =='\0'){
        return total;
    }
    else if(text[0] == '='){
        total = formulaEvaluator((text+1), total);
        return total;
    }
    else if(text[0] == '-'){
        total -= formulaEvaluator((text+1), total);
        return total;
    }
    else if(text[0] == '+'){
        total += formulaEvaluator((text+1), total);
        return total;
    }
    else if(text[0] == '*'){
        total *= formulaEvaluator((text+1), total);
        return total;
    }
    else if(text[0] == '/'){
        total /= formulaEvaluator((text+1), total);
        return total;
    }
//    else if(64 < text[0] && text[0] < 72){
//        switch(text[0]){
//            case 65:
//                total = excelSheet[(text[1])][0].storedValue;
//                return formulaEvaluator((text+2), total);
//
//            default:
//                total = excelSheet[(text[1])][0].storedValue;
//                return formulaEvaluator((text+2), total);
//        }
//    }
    else{
        total = strtol(text, &text, 10);
        return formulaEvaluator((text), total);
//        int flag = 0;
//        for (int i = 0; i < strlen(text); i++) {
//            if (isdigit(text[i]) == 0) {
//                //excelSheet[col][row].storedValue = strtol(text, &text, 10);
//                //strcpy(excelSheet[col][row].string, text);
//                flag = 1;
//                break;
//            }
//        }
//        if (flag != 1){
//            long sum = strtol(text, &text, 10);
//            return formulaEvaluator((text+1), sum);
//        }
//        else{
//            return 0;
//        }
    }
}
int flagger(const char *text){
    int flag = 0;
    if(text[0] == '='){
        flag = 1;
    }
    return flag;
}

void model_init() {
    // TODO: implement this.

//    for (int i = 0; i < 10; i++){
//        for (int j = 0; j < 7; j++){
//            excelSheet[i][j].storedValue = NULL;
//            strcpy(excelSheet[i][j].string,);
//        }
//    }
}

void set_cell_value(ROW row, COL col, char *text) {
    // TODO: implement this.
    long total = 0;
    int setter = flagger(text);
    excelSheet[col][row].storedValue = formulaEvaluator(text, total);
    strcpy(excelSheet[col][row].string, text);
    // This just displays the text without saving it in any data structure. You will need to change this.
    if(setter == 1){
        char str[50];
        sprintf(str, "%ld", excelSheet[col][row].storedValue);
        update_cell_display(row, col, str);
    }
    else{
        //char str[50];
        //sprintf(str, "%ld", excelSheet[col][row].storedValue);
        update_cell_display(row, col, text);
    }
    free(text);

}

void clear_cell(ROW row, COL col) {
    // TODO: implement this.

    excelSheet[col][row].storedValue = 0;
    strcpy(excelSheet[col][row].string, "");
    // This just clears the display without updating any data structure. You will need to change this.
    update_cell_display(row, col, "");
}

char *get_textual_value(ROW row, COL col) {
    // TODO: implement this.
    return strdup(excelSheet[col][row].string);

}
