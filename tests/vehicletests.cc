#include <functions/vehiclearg.h>
#include <gtest/gtest.h>
using namespace vehicle;
using namespace std;

TEST(RailCalcTests, Test) {
	auto v1 = Vehicle(VehicleType::RAILWAY, "Ласточка", 1000);
	auto T1 = v1.calc(100, 5);

	EXPECT_EQ(T1, 500000);
}

TEST(WaterCalcTests, Test) {
	auto v2 = Vehicle(VehicleType::WATER, "Черная Жемчужина", 1000, 0.9);
	auto T2 = v2.calc(100, 5000);

	EXPECT_EQ(T2, 450000000);
}

TEST(AirCalcTests, Test) {
	auto v3 = Vehicle(VehicleType::AIR, "Боинг", 1000, EngineType::TURB);
	auto v4 = Vehicle(VehicleType::AIR, "Ту-134", 1000, EngineType::REACT);
	auto T3 = v3.calc(100, 5);
	auto T4 = v4.calc(100, 5);

	EXPECT_EQ(T3, 250000);
	EXPECT_EQ(T4, 750000);
}

TEST(MinimTest, Test) {
	VehicleList vehicles;
	auto v1 = Vehicle(VehicleType::RAILWAY, "Ласточка", 1000);
	auto v2 = Vehicle(VehicleType::RAILWAY, "Ласточка", 100);
	auto v3 = Vehicle(VehicleType::WATER, "Черная Жемчужина", 1000, 0.9);
	auto v4 = Vehicle(VehicleType::AIR, "Боинг", 1000, EngineType::TURB);
	auto v5 = Vehicle(VehicleType::AIR, "Ту-134", 1000, EngineType::REACT);
	vehicles.insert(v1, 0);
	vehicles.insert(v2, 1);
	vehicles.insert(v3, 2);
	vehicles.insert(v4, 3);
	vehicles.insert(v5, 4);
	auto minim = min(vehicles, 100, 5);

	EXPECT_EQ(minim, 1);
	EXPECT_ANY_THROW(vehicles.insert(v1, 11););
}
TEST(SizeTest, Test) {
	VehicleList vehicles;
	auto v1 = Vehicle(VehicleType::RAILWAY, "Ласточка", 1000);
	auto v2 = Vehicle(VehicleType::RAILWAY, "Ласточка", 100);
	auto v3 = Vehicle(VehicleType::WATER, "Черная Жемчужина", 1000, 0.9);
	auto v4 = Vehicle(VehicleType::AIR, "Боинг", 1000, EngineType::TURB);
	auto v5 = Vehicle(VehicleType::AIR, "Ту-134", 1000, EngineType::REACT);
	vehicles.insert(v1, 0);
	vehicles.insert(v2, 1);
	vehicles.insert(v3, 2);
	vehicles.insert(v4, 3);
	vehicles.insert(v5, 4);
	auto s = vehicles.size();

	EXPECT_EQ(s, 5);
}
TEST(RemoveTest, Test) {
	VehicleList vehicles;
	auto v1 = Vehicle(VehicleType::RAILWAY, "Ласточка", 1000);
	auto v2 = Vehicle(VehicleType::RAILWAY, "Ласточка", 100);
	auto v3 = Vehicle(VehicleType::WATER, "Черная Жемчужина", 1000, 0.9);
	auto v4 = Vehicle(VehicleType::AIR, "Боинг", 1000, EngineType::TURB);
	auto v5 = Vehicle(VehicleType::AIR, "Ту-134", 1000, EngineType::REACT);
	vehicles.add(v1);
	vehicles.add(v2);
	vehicles.add(v3);
	vehicles.add(v4);
	vehicles.add(v5);
	auto sb = vehicles.size();
	vehicles.remove(1);
	vehicles.remove(3);
	auto sa = vehicles.size();
	auto minim = min(vehicles, 100, 5000);

	EXPECT_EQ(minim, 1);
	EXPECT_EQ(sb, 5);
	EXPECT_EQ(sa, 3);
}
TEST(OperatorTest, Test) {
	VehicleList vehicles;
	auto v1 = Vehicle(VehicleType::RAILWAY, "Ласточка", 1000);
	auto v2 = Vehicle(VehicleType::RAILWAY, "Ласточка", 100);
	auto v3 = Vehicle(VehicleType::WATER, "Черная Жемчужина", 1000, 0.9);
	auto v4 = Vehicle(VehicleType::AIR, "Боинг", 1000, EngineType::TURB);
	auto v5 = Vehicle(VehicleType::AIR, "", 1000, EngineType::REACT);
	vehicles.insert(v1, 0);
	vehicles.insert(v2, 1);
	vehicles.insert(v3, 2);
	vehicles.insert(v4, 3);
	vehicles.insert(v5, 4);

	EXPECT_ANY_THROW(vehicles.operator[](5));
}
TEST(GetTest, Test) {
	VehicleList vehicles;
	auto v1 = Vehicle(VehicleType::RAILWAY, "Ласточка", 1000);
	auto v2 = Vehicle(VehicleType::WATER, "Черная Жемчужина", 1000, 0.9);
	auto v3 = Vehicle(VehicleType::AIR, "Боинг", 1000, EngineType::TURB);
	vehicles.add(v1);
	vehicles.add(v2);
	vehicles.add(v3);
	EXPECT_EQ(vehicles[0].get_model(), RAILWAY);
	EXPECT_EQ(vehicles[0].get_name(), "Ласточка");
	EXPECT_EQ(vehicles[0].get_k(), 1000);
	EXPECT_EQ(vehicles[1].get_a(), float(0.9));
	EXPECT_EQ(vehicles[2].get_engine(), TURB);
}
