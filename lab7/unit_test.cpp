#include "factory.hpp"
#include "base.hpp"

#include "gtest/gtest.h"

TEST(factory_test, no_args) {
    char** test_val = new char* [1]; test_val[0] = "./calculator";
    Factory* my_factory = new Factory();
    Base* result_num = my_factory->parse(1, test_val);
    EXPECT_EQ(result_num, nullptr);
}

TEST(factory_test, invalid_ampersand) {
    char** test_val = new char* [2]; test_val[0] = "./calculator"; test_val[1] = "&";
    Factory* my_factory = new Factory();
    Base* result_num = my_factory->parse(2, test_val);
    EXPECT_EQ(result_num, nullptr);
}

TEST(factory_test, invalid_minus) {
    char** test_val = new char* [2]; test_val[0] = "./calculator"; test_val[1] = "-";
    Factory* my_factory = new Factory();
    Base* result_num = my_factory->parse(2, test_val);
    EXPECT_EQ(result_num, nullptr);
}

TEST(factory_test, invalid_decimal) {
    char** test_val = new char* [2]; test_val[0] = "./calculator"; test_val[1] = ".";
    Factory* my_factory = new Factory();
    Base* result_num = my_factory->parse(2, test_val);
    EXPECT_EQ(result_num, nullptr);
}

TEST(factory_test, one_operand_arg) {
    char** test_val = new char* [2]; test_val[0] = "./calculator"; test_val[1] = "0";
    Factory* my_factory = new Factory();
    Base* result_num = my_factory->parse(2, test_val);
    ASSERT_NE(result_num, nullptr);
    EXPECT_EQ( result_num->evaluate(), 0);
    EXPECT_EQ( result_num->stringify(), "0.000000");
}

TEST(factory_test, sub_two_ops) {
    char** test_val = new char* [4]; test_val[0] = "./calculator"; test_val[1] = "2"; test_val[2] = "-"; test_val[3] = "1";
    Factory* my_factory = new Factory();
    Base* result_num = my_factory->parse(4, test_val);
    ASSERT_NE(result_num, nullptr);   
    EXPECT_EQ(result_num->stringify(), "2.000000 - 1.000000");
    EXPECT_EQ(result_num->evaluate(), 1);
}

TEST(factory_test, add_two_negs) {
    char** test_val = new char* [4]; test_val[0] = "./calculator"; test_val[1] = "-4"; test_val[2] = "+"; test_val[3] = "-3";
    Factory* my_factory = new Factory();
    Base* result_num = my_factory->parse(4, test_val);
    ASSERT_NE(result_num, nullptr);
    EXPECT_EQ(result_num->stringify(), "-4.000000 + -3.000000");
    EXPECT_EQ(result_num->evaluate(), -7);
}


TEST(factory_test, add_two_ops) {
    char** test_val = new char* [4]; test_val[0] = "./calculator"; test_val[1] = "2"; test_val[2] = "+"; test_val[3] = "1";
    Factory* my_factory = new Factory();
    Base* result_num = my_factory->parse(4, test_val);
    ASSERT_NE(result_num, nullptr);   
    EXPECT_EQ(result_num->stringify(), "2.000000 + 1.000000");
    EXPECT_EQ(result_num->evaluate(), 3);
}

TEST(factory_test, pow_two_ops) {
    char** test_val = new char* [4]; test_val[0] = "./calculator"; test_val[1] = "3"; test_val[2] = "**"; test_val[3] = "4";
    Factory* my_factory = new Factory();
    Base* result_num = my_factory->parse(4, test_val);
    ASSERT_NE(result_num, nullptr);
    EXPECT_EQ(result_num->stringify(), "3.000000 ** 4.000000");
    EXPECT_EQ(result_num->evaluate(), 81);
}

TEST(factory_test, pow_two_ops_neg_base) {
    char** test_val = new char* [4]; test_val[0] = "./calculator"; test_val[1] = "-3"; test_val[2] = "**"; test_val[3] = "5";
    Factory* my_factory = new Factory();
    Base* result_num = my_factory->parse(4, test_val);
    ASSERT_NE(result_num, nullptr);
    EXPECT_EQ(result_num->stringify(), "-3.000000 ** 5.000000");
    EXPECT_EQ(result_num->evaluate(), -243);
}

TEST(factory_test, div_two_ops) {
    char** test_val = new char* [4]; test_val[0] = "./calculator"; test_val[1] = "9"; test_val[2] = "/"; test_val[3] = "3";
    Factory* my_factory = new Factory();
    Base* result_num = my_factory->parse(4, test_val);
    ASSERT_NE(result_num, nullptr);
    EXPECT_EQ(result_num->stringify(), "9.000000 / 3.000000");
    EXPECT_EQ(result_num->evaluate(), 3);
}

TEST(factory_test, div_two_ops_one_neg) {
    char** test_val = new char* [4]; test_val[0] = "./calculator"; test_val[1] = "9"; test_val[2] = "/"; test_val[3] = "-2";
    Factory* my_factory = new Factory();
    Base* result_num = my_factory->parse(4, test_val);
    ASSERT_NE(result_num, nullptr);
    EXPECT_EQ(result_num->stringify(), "9.000000 / -2.000000");
    EXPECT_EQ(result_num->evaluate(), -4.5);
}

TEST(factory_test, mult_two_ops) {
    char** test_val = new char* [4]; test_val[0] = "./calculator"; test_val[1] = "9"; test_val[2] = "*"; test_val[3] = "3";
    Factory* my_factory = new Factory();
    Base* result_num = my_factory->parse(4, test_val);
    ASSERT_NE(result_num, nullptr);
    EXPECT_EQ(result_num->stringify(), "9.000000 * 3.000000");
    EXPECT_EQ(result_num->evaluate(), 27);
}

TEST(factory_test, mult_two_ops_one_neg) {
    char** test_val = new char* [4]; test_val[0] = "./calculator"; test_val[1] = "-8.5"; test_val[2] = "*"; test_val[3] = "3";
    Factory* my_factory = new Factory();
    Base* result_num = my_factory->parse(4, test_val);
    ASSERT_NE(result_num, nullptr);
    EXPECT_EQ(result_num->stringify(), "-8.500000 * 3.000000");
    EXPECT_EQ(result_num->evaluate(), -25.5);
}

TEST(factory_test, use_all_operations_1) {
    char** test_val = new char* [12]; 
    test_val[0] = "./calculator"; 
    test_val[1] = "-5"; 
    test_val[2] = "*"; 
    test_val[3] = "3";
    test_val[4] = "-"; 
    test_val[5] = "1"; 
    test_val[6] = "/";
    test_val[7] = "2";
    test_val[8] = "+";
    test_val[9] = "4";
    test_val[10] = "**";
    test_val[11] = "2";
    Factory* my_factory = new Factory();
    Base* result_num = my_factory->parse(12, test_val);
    ASSERT_NE(result_num, nullptr);
    EXPECT_EQ(result_num->stringify(), "-5.000000 * 3.000000 - 1.000000 / 2.000000 + 4.000000 ** 2.000000");
    EXPECT_EQ(result_num->evaluate(), 16);
}

TEST(factory_test, use_all_operations_2) {
    char** test_val = new char* [12];
    test_val[0] = "./calculator";
    test_val[1] = "-5.1";
    test_val[2] = "*";
    test_val[3] = "2";
    test_val[4] = "-";
    test_val[5] = "-0.2";
    test_val[6] = "/";
    test_val[7] = "2";
    test_val[8] = "+";
    test_val[9] = "4";
    test_val[10] = "**";
    test_val[11] = "2";
    Factory* my_factory = new Factory();
    Base* result_num = my_factory->parse(12, test_val);
    ASSERT_NE(result_num, nullptr);
    EXPECT_EQ(result_num->stringify(), "-5.100000 * 2.000000 - -0.200000 / 2.000000 + 4.000000 ** 2.000000");
    EXPECT_EQ(result_num->evaluate(), 1);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
