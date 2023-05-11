//==================//
//                  //
//  Keaton Reece    //
//  CPTR 142        //
//  Project 3       //
//  Decompression   //
//  Stops Code      //
//  3/9/2023        //
//                  //
//==================//

// Calculate decompression stops from depth and time data

// Current iteration up to 45 foot depth completed

// Assumptions for calculations:
// Air mix
// 75 FPM descent rate
// 30 FPM ascent rate
// Stop times include travel time
// All depths are in feet
// All times are in minutes

#include <istream>
#include <vector>

// Function will return a 2-D vector to allow easy access of correlated stop
// time and depth
std::vector<std::vector<int>> calculateStops(int time, int depth) {

  // Initialize 2-D Vector
  // Row 1, depth of stop
  // Row 2, time at stop
  // Columns are number of stops
  int rows = 2;
  int cols = 0;
  std::vector<std::vector<int>> stops(rows, std::vector<int>(cols));

  // Determine depth case, from lower limit of 30 to upper limit of 300
  // Default case is less than 25 feet in which case no stops are required for
  // any practical length of time
  switch (depth) {
  case 26 ... 30:
    // Use the 30 table
    if (time > 660) {
      // Use 720 time section
      stops[0].push_back(20);
      stops[1].push_back(158);
    } else if (time > 600) {
      // Use 660 time section
      stops[0].push_back(20);
      stops[1].push_back(120);
    } else if (time > 540) {
      // Use 600 time section
      stops[0].push_back(20);
      stops[1].push_back(92);
    } else if (time > 480) {
      // Use 540 time section
      stops[0].push_back(20);
      stops[1].push_back(71);
    } else if (time > 420) {
      // Use 480 time section
      stops[0].push_back(20);
      stops[1].push_back(42);
    } else if (time > 380) {
      // Use 420 time section
      stops[0].push_back(20);
      stops[1].push_back(22);
    } else if (time > 371) {
      // Use 380 time section
      stops[0].push_back(20);
      stops[1].push_back(5);
    } else {
      // Use 371 time section
      // No stops needed
    }
    break;
  // Visual separation of cases //
  // ========================== //
  case 31 ... 35:
    // Following cases uses same logic as previous case
    if (time > 660) {
      stops[0].push_back(20);
      stops[1].push_back(342);
    } else if (time > 600) {
      stops[0].push_back(20);
      stops[1].push_back(314);
    } else if (time > 540) {
      stops[0].push_back(20);
      stops[1].push_back(277);
    } else if (time > 480) {
      stops[0].push_back(20);
      stops[1].push_back(228);
    } else if (time > 420) {
      stops[0].push_back(20);
      stops[1].push_back(173);
    } else if (time > 360) {
      stops[0].push_back(20);
      stops[1].push_back(134);
    } else if (time > 330) {
      stops[0].push_back(20);
      stops[1].push_back(88);
    } else if (time > 300) {
      stops[0].push_back(20);
      stops[1].push_back(71);
    } else if (time > 270) {
      stops[0].push_back(20);
      stops[1].push_back(53);
    } else if (time > 240) {
      stops[0].push_back(20);
      stops[1].push_back(28);
    } else if (time > 232) {
      stops[0].push_back(20);
      stops[1].push_back(4);
    } else {
      // No stops needed
    }
    break;
  // ========================== //
  case 36 ... 40:
    if (time > 660) {
      stops[0].push_back(20);
      stops[1].push_back(461);
    } else if (time > 600) {
      stops[0].push_back(20);
      stops[1].push_back(439);
    } else if (time > 540) {
      stops[0].push_back(20);
      stops[1].push_back(410);
    } else if (time > 480) {
      stops[0].push_back(20);
      stops[1].push_back(372);
    } else if (time > 420) {
      stops[0].push_back(20);
      stops[1].push_back(321);
    } else if (time > 360) {
      stops[0].push_back(20);
      stops[1].push_back(248);
    } else if (time > 330) {
      stops[0].push_back(20);
      stops[1].push_back(184);
    } else if (time > 300) {
      stops[0].push_back(20);
      stops[1].push_back(160);
    } else if (time > 270) {
      stops[0].push_back(20);
      stops[1].push_back(128);
    } else if (time > 240) {
      stops[0].push_back(20);
      stops[1].push_back(101);
    } else if (time > 230) {
      stops[0].push_back(20);
      stops[1].push_back(75);
    } else if (time > 220) {
      stops[0].push_back(20);
      stops[1].push_back(64);
    } else if (time > 210) {
      stops[0].push_back(20);
      stops[1].push_back(52);
    } else if (time > 200) {
      stops[0].push_back(20);
      stops[1].push_back(39);
    } else if (time > 190) {
      stops[0].push_back(20);
      stops[1].push_back(27);
    } else if (time > 180) {
      stops[0].push_back(20);
      stops[1].push_back(21);
    } else if (time > 170) {
      stops[0].push_back(20);
      stops[1].push_back(14);
    } else if (time > 163) {
      stops[0].push_back(20);
      stops[1].push_back(6);
    } else {
      // Not stops needed
    }
    break;
  // ========================== //
  case 41 ... 45:
    if (time > 480) {
      stops[0].push_back(20);
      stops[1].push_back(473);
    } else if (time > 420) {
      stops[0].push_back(20);
      stops[1].push_back(431);
    } else if (time > 360) {
      stops[0].push_back(20);
      stops[1].push_back(373);
    } else if (time > 330) {
      stops[0].push_back(20);
      stops[1].push_back(288);
    } else if (time > 300) {
      stops[0].push_back(20);
      stops[1].push_back(243);
    } else if (time > 270) {
      stops[0].push_back(20);
      stops[1].push_back(206);
    } else if (time > 240) {
      stops[0].push_back(20);
      stops[1].push_back(173);
    } else if (time > 230) {
      stops[0].push_back(20);
      stops[1].push_back(130);
    } else if (time > 220) {
      stops[0].push_back(20);
      stops[1].push_back(121);
    } else if (time > 210) {
      stops[0].push_back(20);
      stops[1].push_back(112);
    } else if (time > 200) {
      stops[0].push_back(20);
      stops[1].push_back(101);
    } else if (time > 190) {
      stops[0].push_back(20);
      stops[1].push_back(89);
    } else if (time > 180) {
      stops[0].push_back(20);
      stops[1].push_back(75);
    } else if (time > 170) {
      stops[0].push_back(20);
      stops[1].push_back(59);
    } else if (time > 160) {
      stops[0].push_back(20);
      stops[1].push_back(41);
    } else if (time > 150) {
      stops[0].push_back(20);
      stops[1].push_back(34);
    } else if (time > 140) {
      stops[0].push_back(20);
      stops[1].push_back(25);
    } else if (time > 130) {
      stops[0].push_back(20);
      stops[1].push_back(14);
    } else if (time > 125) {
      stops[0].push_back(20);
      stops[1].push_back(2);
    } else {
      // No stops needed
    }
    break;
  // ========================== //
  case 46 ... 50:
    break;
  // ========================== //
  case 51 ... 55:
    break;
  // ========================== //
  case 56 ... 60:
    break;
  // ========================== //
  case 61 ... 70:
    break;
  // ========================== //
  case 71 ... 80:
    break;
  // ========================== //
  case 81 ... 90:
    break;
  // ========================== //
  case 91 ... 100:
    break;
  // ========================== //
  case 101 ... 110:
    break;
  // ========================== //
  case 111 ... 120:
    break;
  // ========================== //
  case 121 ... 130:
    break;
  // ========================== //
  case 131 ... 140:
    break;
  // ========================== //
  case 141 ... 150:
    break;
  // ========================== //
  case 151 ... 160:
    break;
  // ========================== //
  case 161 ... 170:
    break;
  // ========================== //
  case 171 ... 180:
    break;
  // ========================== //
  case 181 ... 190:
    break;
  // ========================== //
  case 191 ... 200:
    break;
  // ========================== //
  case 201 ... 210:
    break;
  // ========================== //
  case 211 ... 220:
    break;
  // ========================== //
  case 221 ... 250:
    break;
  // ========================== //
  case 251 ... 300:
    break;
  // ========================== //
  default:
    // less than 25 feet, no stops required
    break;
    // ========================== //
  }
  return stops;
}