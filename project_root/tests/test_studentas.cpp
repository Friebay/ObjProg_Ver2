#include <gtest/gtest.h>
#include "../include/Vec_funkcijos.h"

TEST(StudentasTest, DefaultConstructor) {
    Studentas s;
    EXPECT_EQ(s.getVardas(), "");
    EXPECT_EQ(s.getPavarde(), "");
    EXPECT_TRUE(s.getPazymiai().empty());
    EXPECT_EQ(s.getEgzaminoPazymys(), 0);
}

TEST(StudentasTest, ParameterizedConstructor) {
    std::vector<int> pazymiai = {8, 9, 10};
    Studentas s("Jonas", "Jonaitis", pazymiai, 9);
    EXPECT_EQ(s.getVardas(), "Jonas");
    EXPECT_EQ(s.getPavarde(), "Jonaitis");
    EXPECT_EQ(s.getPazymiai(), pazymiai);
    EXPECT_EQ(s.getEgzaminoPazymys(), 9);
}
