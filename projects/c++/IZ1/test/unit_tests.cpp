#include <gtest/gtest.h>
#include <cstdlib>

extern "C" char* to_rom_num(size_t*, unsigned);

TEST(RomanNumeralsTest, ChecksZeroCase) {
    size_t size = 0;
    char *res = to_rom_num(&size, 0);

    EXPECT_EQ(res, nullptr);
    EXPECT_EQ(size, 0);
    free(res);
}

TEST(RomanNumeralsTest, ChecksICase) {
    size_t size = 0;
    char *res = to_rom_num(&size, 1);

    EXPECT_STREQ(res, "I");
    EXPECT_EQ(size, 2);
    free(res);
}

TEST(RomanNumeralsTest, ChecksVCase) {
    size_t size = 0;
    char *res = to_rom_num(&size, 5);

    EXPECT_STREQ(res, "V");
    EXPECT_EQ(size, 2);
    free(res);
}

TEST(RomanNumeralsTest, ChecksXCase) {
    size_t size = 0;
    char *res = to_rom_num(&size, 10);

    EXPECT_STREQ(res, "X");
    EXPECT_EQ(size, 2);
    free(res);
}

TEST(RomanNumeralsTest, ChecksLCase) {
    size_t size = 0;
    char *res = to_rom_num(&size, 50);

    EXPECT_STREQ(res, "L");
    EXPECT_EQ(size, 2);
    free(res);
}

TEST(RomanNumeralsTest, ChecksCCase) {
    size_t size = 0;
    char *res = to_rom_num(&size, 100);

    EXPECT_STREQ(res, "C");
    EXPECT_EQ(size, 2);
    free(res);
}

TEST(RomanNumeralsTest, ChecksDCase) {
    size_t size = 0;
    char *res = to_rom_num(&size, 500);

    EXPECT_STREQ(res, "D");
    EXPECT_EQ(size, 2);
    free(res);
}

TEST(RomanNumeralsTest, ChecksMCase) {
    size_t size = 0;
    char *res = to_rom_num(&size, 1000);

    EXPECT_STREQ(res, "M");
    EXPECT_EQ(size, 2);
    free(res);
}

TEST(RomanNumeralsTest, CaseMixed) {
    size_t size = 0;
    char *res = to_rom_num(&size, 1359);

    EXPECT_STREQ(res, "MCCCLIX");
    EXPECT_EQ(size, 8);
    free(res);
}

TEST(RomanNumeralsTest, CaseMixedWithEight) {
    size_t size = 0;
    char *res = to_rom_num(&size, 1888);

    EXPECT_STREQ(res, "MDCCCLXXXVIII");
    EXPECT_EQ(size, 14);
    free(res);
}

TEST(RomanNumeralsTest, CaseMixedWithNine) {
    size_t size = 0;
    char *res = to_rom_num(&size, 1999);

    EXPECT_STREQ(res, "MCMXCIX");
    EXPECT_EQ(size, 8);
    free(res);
}

TEST(RomanNumeralsTest, CaseMixedWithSeven) {
    size_t size = 0;
    char *res = to_rom_num(&size, 1777);

    EXPECT_STREQ(res, "MDCCLXXVII");
    EXPECT_EQ(size, 11);
    free(res);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}