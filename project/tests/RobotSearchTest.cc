// #include "gtest/gtest.h"
// #include "apply_rgb.h"
// #include "image.h"
// #include <vector>

// class RobotSearchTest : public ::testing::Test {
// public:
//   void SetUp() { 
//     robot = Image("robot.jpg");
//     no_robot = Image("no_robot.jpg");
//   }
// protected:
//   Image robot;
//   Image no_robot;
// };

// TEST_F(RobotSearchTest, RobotInPicture) {
//   SetUp();
//   ApplyRGB apply;
//   int found_notfound = apply.ApplyFilter(&robot); 

//   EXPECT_EQ(found_notfound, 0) << "Didn't find robot when robot is in pic";
// }

// TEST_F(RobotSearchTest, RobotNotInPicture) {  
//   SetUp();
//   ApplyRGB apply;
//   int found_notfound = apply.ApplyFilter(&no_robot); 

//   EXPECT_EQ(found_notfound, -1) << "Found robot when robot is not in pic";
// }
