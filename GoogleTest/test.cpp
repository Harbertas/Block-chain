#include "pch.h"
#include "../hash v0.1/input.h"
#include "../hash v0.1/input.cpp"


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
