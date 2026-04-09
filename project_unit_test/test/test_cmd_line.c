#include <stdio.h>
#include <string.h> 
#include "unity.h" 
#include "cmd_line.h"
/* ================= MOCK ================= */
static int func_called; 
static char last_cmd[100];
void mock_func(uint8_t *cmd) {
    func_called++;
    strcpy(last_cmd, (char*)cmd);
}

cmd_line_t cmd_table[] = {
    {(uint8_t*)"help", mock_func,(const char*) "HELP"},
    {(uint8_t*)"led", mock_func,(const char*) "LED"},
    {(uint8_t*)"uart", mock_func, (const char*) "UART"},
    {(uint8_t*)"null", (cmd_line_t*)0, (const char*) "UART"},
    {0,0,0}
};

typedef struct {
    char * name_test;
    cmd_line_t *data;
    uint8_t* command;
    int8_t expected_result;
}test_case_t;

test_case_t test_case[] = {
    {"Call Function CMD_SUCCESS",cmd_table, (uint8_t*)"help" , CMD_SUCCESS},
    {"Call Function CMD_TBL_NOT_FOUND",(cmd_line_t*)0,"help",CMD_TBL_NOT_FOUND},
    {"Call Function CMD_TOO_LONG",cmd_table,(uint8_t*)"aaaaaaaaaaaaaaaaaaaaaaaaaaaaa",CMD_TOO_LONG},
    {"Call Function CMD_NOT_FOUND",cmd_table,(uint8_t*)"uart2",CMD_NOT_FOUND}
};

void run_test(test_case_t tc){
    func_called =0;

    uint8_t ret = cmd_line_parser(tc.data,tc.command);

    if(ret != tc.expected_result){
        printf("[FAIL]: %s: expected: %d actual: %d\n", tc.name_test, tc.expected_result, ret);
    }

    if(ret == tc.expected_result){
        printf("[PASS]: %s  expected: %d actual: %d\n", tc.name_test, tc.expected_result, ret);
    }
    printf("\n");
}


int main(){
    int total_testcase = sizeof(test_case)/ sizeof(test_case[0]);
    printf("Runing test all test case: %d\n", total_testcase);
    for(int i = 1 ; i <= total_testcase; i++){
        printf("Runing test %d test case:\n", i);
        run_test(test_case[i-1]);
    }
    printf("Done\n");
    return 0;
}
