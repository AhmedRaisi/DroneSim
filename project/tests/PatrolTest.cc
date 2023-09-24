#include "gtest/gtest.h"
#include "patrol.h"
#include "drone.h"

class PatrolTest : public ::testing::Test {
public:
  void SetUp() { 
    // drone = Drone("test drone");
  }
protected:
  Patrol patrol;
  Drone drone;
};

//--UNIT--

TEST_F(PatrolTest, DroneAtStart) {
  SetUp();
  double pos[] = {110,2.5,60}; //drone always starts at this pos
  double* new_pos = patrol.NextPos(pos);
  double actual_new_pos[] = {-100,2.5,60};

  EXPECT_EQ(new_pos[0], actual_new_pos[0]) << "drone new pos is not the correct pos";
}

TEST_F(PatrolTest, DroneAtFirstCorner) { //drone at first corner should take a turn therefore change next pos
  SetUp();
  double pos[] = {-101,2.5,60}; //current pos of drone (at corner)
  double* new_pos = patrol.NextPos(pos);
  double actual_new_pos[] = {-100,2.5,40}; //should take left and go to this pos

  EXPECT_EQ(new_pos[2], actual_new_pos[2]) << "drone new pos is not the correct pos";
}

TEST_F(PatrolTest, DroneAtSecondCorner) {
  SetUp();
  double pos[] = {109,2.5,19}; //current pos of drone (at corner)
  double* new_pos = patrol.NextPos(pos);
  double actual_new_pos[] = {-101,2.5,19}; //should take left and go to this pos

  EXPECT_EQ(new_pos[2], actual_new_pos[2]) << "drone new pos is not the correct pos";
}

//--INTEGRATION--

// TEST_F(PatrolTest, StopDrone) { //stop drone when it reached end
//   SetUp();

//   double pos[] = {-103,2.5,-61}; //pos at end of map
//   drone.SetPosition(pos);
//   double* new_pos = patrol.NextPos(drone.GetPosition());
//   double actual_new_pos[] = {-103,-1,-61}; //pos[1] = -1 is only used for stopping the drone

//   EXPECT_EQ(new_pos[1], actual_new_pos[1]) << "drone new pos is not the correct pos";
// }