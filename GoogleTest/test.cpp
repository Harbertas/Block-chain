#include "pch.h"
#include "../hash v0.1/input.h"
#include "../hash v0.1/input.cpp"

//TEST(TestCaseName, TestName) {
//  EXPECT_EQ(1, 1);
//  EXPECT_TRUE(true);
//}

TEST(testHash, hashSize) {
	Input data;
	data.hashRow("hubertas");
	ASSERT_EQ(data.getHashedRow().size(), 64);
}

TEST(testHash, hashDifference) {
	Input data;
	Input data2;
	data.hashRow("hubertas");
	data2.hashRow("Hubertas");
	ASSERT_NE(data.getHashedRow(), data2.getHashedRow());
}


















/*TEST(TestCaseName1, checkConstructor) {
	duomenys pirmas({0,0,0},3,4,6,"jonas","jonaitis");
	ASSERT_EQ(pirmas.vardas(), "antanas");
}
TEST(TestCaseName2, CheckSetterAndAssignment) {
	duomenys pirmas, antras;
	pirmas.setEgz(3);
	antras = pirmas;
	ASSERT_EQ(pirmas.egz(), 3);
}
TEST(TestCaseName3, CheckMarksQuantity) {
	duomenys pirmas;
	pirmas.setPaz(3);
	pirmas.setPaz(4);
	pirmas.setPaz(5);
	ASSERT_EQ(3, pirmas.kiekPaz());
}*/
