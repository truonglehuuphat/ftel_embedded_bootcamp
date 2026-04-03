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

// typedef struct {
// 	const int8_t* cmd;
// 	pf_cmd_func func;
// 	const int8_t* info;
// } cmd_line_t;

cmd_line_t cmd_table[] = {
    {(uint8_t*)"help", mock_func,(const char*) "HELP"},
    {(uint8_t*)"led", mock_func,(const char*) "LED"},
    {(uint8_t*)"uart", mock_func, (const char*) "UART"},
    {0, 0}
};

typedef struct {
    const char * name_test,
	pf_cmd_func func,
    const int8_t* cmd,
    int8_t expected_result
}test_case_t;

test_case_t test_case[] = {
    {"Call Function CMD_SUCCESS", mock_func,(uint8_t*)"help", CMD_SUCCESS},
    {"Call Function CMD_TBL_NOT_FOUND", (cmd_line_t*)0, (uint8_t*)"help",CMD_TBL_NOT_FOUND},
    {"Call Function CMD_TOO_LONG", mock_func, (uint8_t*)"help help help help",CMD_TOO_LONG},
    {"Call Function CMD_NOT_FOUND", mock_func, (uint8_t*)"led On",CMD_NOT_FOUND}
};

void run_test(test_case_t *tc){
    cmd_line_t * test_data = malloc(size(cmd_line_parser));
    test_data->func = tc->func;
    test_data->cmd = tc->cmd;

    int ret = cmd_line_parser(test_data,tc->cmd);

    if(ret != tc->expected_result){
        printf("[FAIL]: %s: expected: %d actual: %d", tc->name_test, tc->expected_result, ret);
    }

    if(ret == tc->expected_result){
        printf("[PASS]: %s  expected: %d actual: %d", tc->name_test, tc->expected_result, ret);
    }

    return;
}


void main(){
    int total_testcase = sizeof(test_case)/ sizeof(test_case_t);
    printf("Runing test all test case: %d\n", total_testcase);
    for(int i = 0 ; i < total_testcase; i++){
        printf("Runing test %d test case:\n", i);
        run_test(test_case[i]);
    }

    return;
}