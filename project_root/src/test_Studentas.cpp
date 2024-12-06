#include <gtest/gtest.h>
#include "Vec_funkcijos.h"

// Test default constructor
TEST(StudentasTest, DefaultConstructor) {
    Studentas student;
    EXPECT_EQ(student.getVardas(), "");   // Default name
    EXPECT_EQ(student.getPavarde(), ""); // Default surname
    EXPECT_EQ(student.getEgzaminoPazymys(), 0); // Default grade
}

// Test parameterized constructor
TEST(StudentasTest, ParameterizedConstructor) {
    std::vector<int> grades = {10, 9, 8};
    Studentas student("Jonas", "Jonaitis", grades, 10);
    EXPECT_EQ(student.getVardas(), "Jonas");
    EXPECT_EQ(student.getPavarde(), "Jonaitis");
    EXPECT_EQ(student.getEgzaminoPazymys(), 10);
}
