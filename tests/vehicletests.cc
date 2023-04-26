/*
#include <gtest/gtest.h>
using namespace vehicle;
using namespace std;

TEST(RailCalcTests, Test) {
	auto v1 = Vehicle(VehicleType::RAILWAY, "��������");
	auto T1 = v1.calc(100, 5);

	EXPECT_EQ(T1, 500000);
}

TEST(WaterCalcTests, Test) {
	auto v1 = Vehicle(VehicleType::WATER, "������ ���������");
	auto T1 = v1.calc(100, 5000);

	EXPECT_EQ(T1, 450000000);
}

TEST(AirCalcTests, Test) {
	auto v1 = Vehicle(VehicleType::AIR, "�����", EngineType::TURB);
	auto v2 = Vehicle(VehicleType::AIR, "��-134", EngineType::REACT);
	auto T1 = v1.calc(100, 5);
	auto T2 = v2.calc(100, 5);

	EXPECT_EQ(T1, 250000);
	EXPECT_EQ(T2, 750000);
}

TEST(MinimTest, Test) {
	VehicleList vehicles;
	auto v1 = Vehicle(VehicleType::RAILWAY, "��������");
	auto v2 = Vehicle(VehicleType::RAILWAY, "��������");
	auto v3 = Vehicle(VehicleType::WATER, "������ ���������");
	auto v4 = Vehicle(VehicleType::AIR, "�����", EngineType::TURB);
	auto v5 = Vehicle(VehicleType::AIR, "��-134", EngineType::REACT);
	vehicles.insert(v1, 0);
	vehicles.insert(v2, 1);
	vehicles.insert(v3, 2);
	vehicles.insert(v4, 3);
	vehicles.insert(v5, 4);
	auto minim = min(vehicles, 100, 5);

	EXPECT_EQ(minim, 1);
	EXPECT_ANY_THROW(vehicles.insert(v1, 11));
}
TEST(SizeTest, Test) {
	VehicleList vehicles;
	auto v1 = Vehicle(VehicleType::RAILWAY, "��������");
	auto v2 = Vehicle(VehicleType::RAILWAY, "��������");
	auto v3 = Vehicle(VehicleType::WATER, "������ ���������");
	auto v4 = Vehicle(VehicleType::AIR, "�����", EngineType::TURB);
	auto v5 = Vehicle(VehicleType::AIR, "��-134", EngineType::REACT);
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
	auto v1 = Vehicle(VehicleType::RAILWAY, "��������");
	auto v2 = Vehicle(VehicleType::RAILWAY, "��������");
	auto v3 = Vehicle(VehicleType::WATER, "������ ���������");
	auto v4 = Vehicle(VehicleType::AIR, "�����", EngineType::TURB);
	auto v5 = Vehicle(VehicleType::AIR, "��-134", EngineType::REACT);
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
	auto v1 = Vehicle(VehicleType::RAILWAY, "��������");
	auto v2 = Vehicle(VehicleType::RAILWAY, "��������");
	auto v3 = Vehicle(VehicleType::WATER, "������ ���������");
	auto v4 = Vehicle(VehicleType::AIR, "�����", EngineType::TURB);
	auto v5 = Vehicle(VehicleType::AIR, "��-134", EngineType::REACT);
	vehicles.insert(v1, 0);
	vehicles.insert(v2, 1);
	vehicles.insert(v3, 2);
	vehicles.insert(v4, 3);
	vehicles.insert(v5, 4);

	EXPECT_ANY_THROW(vehicles.operator[](5));
}
TEST(GetTest, Test) {
	VehicleList vehicles;
	auto v1 = Vehicle(VehicleType::RAILWAY, "��������");
	auto v2 = Vehicle(VehicleType::WATER, "������ ���������");
	auto v3 = Vehicle(VehicleType::AIR, "�����", EngineType::TURB);
	vehicles.add(v1);
	vehicles.add(v2);
	vehicles.add(v3);

	EXPECT_EQ(vehicles[0].get_model(), RAILWAY);
	EXPECT_EQ(vehicles[0].get_name(), "��������");
	EXPECT_EQ(vehicles[0].get_k(), 1000);
	EXPECT_EQ(vehicles[1].get_a(), float(0.9));
	EXPECT_EQ(vehicles[2].get_engine(), TURB);
}
TEST(OperatorTest1, Test) {
	VehicleList vehicles;
	auto v1 = Vehicle(VehicleType::RAILWAY, "��������");
	auto v2 = Vehicle(VehicleType::WATER, "������ ���������");
	auto v3 = Vehicle(VehicleType::AIR, "�����", EngineType::TURB);
	vehicles.add(v1);
	vehicles.add(v2);

	EXPECT_EQ(vehicles[0].get_model(), RAILWAY);
	EXPECT_EQ(vehicles[0].get_name(), "��������");
	vehicles[0] = v3;

	EXPECT_EQ(vehicles[0].get_model(), AIR);
	EXPECT_EQ(vehicles[0].get_name(), "�����");
}
TEST(AddErrorTest, Test) {
	VehicleList vehicles;
	auto v1 = Vehicle(VehicleType::RAILWAY, "��������");
	vehicles.add(v1);
	vehicles.add(v1);
	vehicles.add(v1);
	vehicles.add(v1);
	vehicles.add(v1);
	vehicles.add(v1);
	vehicles.add(v1);
	vehicles.add(v1);
	vehicles.add(v1);
	vehicles.add(v1);

	EXPECT_ANY_THROW(vehicles.add(v1));
}*/