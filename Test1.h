#pragma once
#include "gtest/gtest.h"
#include "Patient.h"

class PatientTest : public ::testing::Test {
protected:
    Patient patient;
};

TEST_F(PatientTest, DefaultConstructor) {
    Patient defaultPatient;
    EXPECT_EQ("", defaultPatient.getName());
    EXPECT_EQ("", defaultPatient.getGender());
    EXPECT_EQ("", defaultPatient.getAddress());
    EXPECT_EQ("", defaultPatient.getInsurance());
    EXPECT_EQ(0, defaultPatient.getYearOfBirth());
}

TEST_F(PatientTest, ParameterizedConstructor) {
    Patient paramPatient("John Doe", "Male", "123 Main St", "1234567890", 1980);
    EXPECT_EQ("John Doe", paramPatient.getName());
    EXPECT_EQ("Male", paramPatient.getGender());
    EXPECT_EQ("123 Main St", paramPatient.getAddress());
    EXPECT_EQ("1234567890", paramPatient.getInsurance());
    EXPECT_EQ(1980, paramPatient.getYearOfBirth());
}

TEST_F(PatientTest, SetName) {
    patient.setName("Jane Doe");
    EXPECT_EQ("Jane Doe", patient.getName());
}

TEST_F(PatientTest, SetGender) {
    patient.setGender("Female");
    EXPECT_EQ("Female", patient.getGender());
}

TEST_F(PatientTest, SetAddress) {
    patient.setAddress("456 Elm St");
    EXPECT_EQ("456 Elm St", patient.getAddress());
}

TEST_F(PatientTest, SetInsurance) {
    patient.setInsurance("9876543210");
    EXPECT_EQ("9876543210", patient.getInsurance());
}

TEST_F(PatientTest, SetYearOfBirth) {
    patient.setYearOfBirth(1990);
    EXPECT_EQ(1990, patient.getYearOfBirth());
}

TEST_F(PatientTest, AlternativeConstructor) {
    Patient altPatient("Jane Smith", "321 Oak St", 1995, "0987654321");
    EXPECT_EQ("Jane Smith", altPatient.getName());
    EXPECT_EQ("", altPatient.getGender());
    EXPECT_EQ("321 Oak St", altPatient.getAddress());
    EXPECT_EQ("0987654321", altPatient.getInsurance());
    EXPECT_EQ(1995, altPatient.getYearOfBirth());
}
#endif