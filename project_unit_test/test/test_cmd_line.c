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
/* ================= TEST TABLE ================= */
cmd_line_t cmd_table[] = {
    {(uint8_t*)"help", mock_func},
    {(uint8_t*)"led", mock_func},
    {0, 0}
};
/* ================= SETUP ================= */
void setUp(void) {
    func_called = 0;
    memset(last_cmd, 0, sizeof(last_cmd));
}
void tearDown(void) {
    
} 
/* ================= TEST ================= */ 
void test_null_table(void) {
    uint8_t cmd[] = "help";
    TEST_ASSERT_EQUAL(CMD_TBL_NOT_FOUND,
        cmd_line_parser(NULL, cmd));
}
void test_valid_command(void) {
    uint8_t cmd[] = "help";
    TEST_ASSERT_EQUAL(CMD_TBL_NOT_FOUND,
        cmd_line_parser(cmd_table, cmd));
    TEST_ASSERT_EQUAL(1, func_called);
}
void test_command_with_space(void) {
    uint8_t cmd[] = "help abc";
    TEST_ASSERT_EQUAL(CMD_SUCCESS,
        cmd_line_parser(cmd_table, cmd));
}
void test_command_not_found(void) {
    uint8_t cmd[] = "abc";
    TEST_ASSERT_EQUAL(CMD_NOT_FOUND,
        cmd_line_parser(cmd_table, cmd));
}
void test_command_too_long(void) {
    uint8_t cmd[100];
    memset(cmd, 'A', sizeof(cmd));
    cmd[99] = '\0';
    TEST_ASSERT_EQUAL(CMD_TOO_LONG,
        cmd_line_parser(cmd_table, cmd));
}
void test_command_newline(void) {
    uint8_t cmd[] = "help\n";
    TEST_ASSERT_EQUAL(CMD_SUCCESS,
        cmd_line_parser(cmd_table, cmd));
}
void test_empty_command(void) {
    uint8_t cmd[] = "";
    TEST_ASSERT_EQUAL(CMD_NOT_FOUND,
        cmd_line_parser(cmd_table, cmd));
}
void test_command_with_space_head(void) {
    uint8_t cmd[] = "  help\n";
    TEST_ASSERT_EQUAL(CMD_NOT_FOUND,
        cmd_line_parser(cmd_table, cmd));
}
/* ================= MAIN ================= */ int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_null_table);
    RUN_TEST(test_valid_command);
    RUN_TEST(test_command_with_space);
    RUN_TEST(test_command_not_found);
    RUN_TEST(test_command_too_long);
    RUN_TEST(test_command_newline);
    RUN_TEST(test_empty_command);
    RUN_TEST(test_command_with_space_head);
    return UNITY_END();
}
