// You have a set of cars and parking lots.

// You know the distances from each car to each parking lot and the parking lot capacities.

// How would you make sure each car gets to a parking lot with a vacancy so that all cars travel the least amount of total distance possible?

// A small data set example might be:

// distance_car1_to_lot1 = 1
// distance_car1_to_lot2 = 10
// distance_car2_to_lot1 = 2
// distance_car2_to_lot2 = 100
// lot1_capacity = 1
// lot2_capacity = 1

// You can see here that if you were to take car1 and put it into lot1 and car2 into lot2, the distance traveled of all cars would be 101.

// Rather than doing that, taking car1 to lot2 and car2 to lot1 would result in a total travel distance of 12. Which would be the correct answer in this small data set.

// How might you solve this, assuming there could a wide number of cars, parking lots and varying distances than listed above.