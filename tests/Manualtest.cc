#include "gtest/gtest.h"
#include "vector3.h"
#include "drone.h"
#include "entityFactory.h"


class ManualTest : public ::testing::Test {
public:
  void SetUp() { 
  DroneFactory* factory = new DroneFactory();
  Drone* testdrone = factory->CreateEntity();
  }
protected:
  Drone drone;
};

//--INTEGRATION--

TEST_F(ManualTest, dronename) {
  DroneFactory* factory = new DroneFactory();
  Drone* testdrone = factory->CreateEntity();
  const std::string& dronename = testdrone->GetName();
  const std::string& actualname = "drone";
  EXPECT_EQ(dronename, actualname);
}

TEST_F(ManualTest, setjoystick) {
  DroneFactory* factory = new DroneFactory();
  Drone* testdrone = factory->CreateEntity();
  testdrone->SetJoystick(1,0,0,0);
  double actual = testdrone->dir[0];
  double expect = 1;
  EXPECT_EQ(actual,expect);
}

TEST_F(ManualTest, GetPosition) {
  DroneFactory* factory = new DroneFactory();
  Drone* testdrone = factory->CreateEntity();
  double* position = testdrone->GetPosition();
  double actual = position[0];
  double expect = 0;
  EXPECT_EQ(actual,expect);
}

TEST_F(ManualTest, SetVelocity) {
  DroneFactory* factory = new DroneFactory();
  Drone* testdrone = factory->CreateEntity();
  double* velo[0] = (20.0);
  testdrone->SetVelocity(velo[0]);
  double actual = testdrone->velocity[0];
  double expect = 20;
  EXPECT_EQ(actual,expect);
}




//--UNIT--








// TEST_F(PatrolTest, DroneAtFirstCorner) { //drone at first corner should take a turn therefore change next pos
//   SetUp();
//   double pos[] = {-101,2.5,60}; //current pos of drone (at corner)
//   double* new_pos = patrol.NextPos(pos);
//   double actual_new_pos[] = {-100,2.5,40}; //should take left and go to this pos

//   EXPECT_EQ(new_pos[2], actual_new_pos[2]) << "drone new pos is not the correct pos";
// }

// TEST_F(PatrolTest, DroneAtSecondCorner) {
//   SetUp();
//   double pos[] = {109,2.5,19}; //current pos of drone (at corner)
//   double* new_pos = patrol.NextPos(pos);
//   double actual_new_pos[] = {-101,2.5,19}; //should take left and go to this pos

//   EXPECT_EQ(new_pos[2], actual_new_pos[2]) << "drone new pos is not the correct pos";
// }