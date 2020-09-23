// Copyright [2020] <LeeYesung>
#include <string>

struct CarState {
  bool door_locked_state[4];
  bool doors_opened_state[4];
  int current_speed;
};

class Door {
 public:
  Door() : locked_(false), opened_(false) {}
  bool locked() {
    return locked_;
  }
  bool opened() {
    return opened_;
  }
  void Unlock() {
    locked_ = false;
  }
  void Lock() {
    // If door is open it will not lock.
    if (!opened_) {
      locked_ = true;
    }
  }
  void Open() {
    // If door is locked it will not open.
    if (!locked_) {
      locked_ = true;
    }
    opened_ = true;
  }
  void Close() {
    opened_ = false;
  }

 private:
  bool locked_;
  bool opened_;
};

class Pedal {
 public:
  // If car is purchased after 2010 base power is 3.
  explicit Pedal(int purchase_year) :
  base_power_((purchase_year > 2010) ? 3 : 0) {}
  int Push(int power) {
    return power+base_power_;
  }
 private:
  const int base_power_;
};


class Car {
 public:
  Car(std::string name, int purchase_year) :
  name_(name),
  purchase_year_(purchase_year),
  accel_(purchase_year),
  brake_(purchase_year),
  current_speed_(0) {}
  std::string name() {
    return name_;
  }
  int purchase_year() {
    return purchase_year_;
  }
  CarState GetCarState() {
    CarState car_state;
    car_state.current_speed = current_speed_;
    // Copy the value of door states.
    for (int i = 0; i < 4; i++) {
      car_state.door_locked_state[i] = doors_[i].locked();
      car_state.doors_opened_state[i] = doors_[i].opened();
    }
    return car_state;
  }
  void UnlockDoor() {
    for (int i = 0; i < 4; i++) {
      doors_[i].Unlock();
    }
  }
  void UnlockDoor(int target_door) {
    doors_[target_door].Unlock();
  }
  void LockDoor() {
    for (int i = 0; i < 4; i++) {
      doors_[i].Lock();
    }
  }
  void LockDoor(int target_door) {
    doors_[target_door].Lock();
  }
  void OpenDoor(int target_door) {
    doors_[target_door].Open();
  }
  void CloseDoor(int target_door) {
    doors_[target_door].Close();
  }
  // If current speed after pushing accel pedal is over 100, make it 100.
  void PushAccel() {
    current_speed_ += accel_.Push(1);
    if (current_speed_ > 100) {
      current_speed_ = 100;
    }
  }
  void PushAccel(int power) {
    current_speed_ += accel_.Push(power);
    if (current_speed_ > 100) {
      current_speed_ = 100;
    }
  }
  // If current speed after pushing brake pedal is under 0, make it 0.
  void PushBreke() {
    current_speed_ -= brake_.Push(1);
    if (current_speed_ < 0) {
      current_speed_ = 0;
    }
  }
  void PushBrake(int power) {
    current_speed_ -= brake_.Push(power);
    if (current_speed_ < 0) {
      current_speed_ = 0;
    }
  }

 private:
  const std::string name_;
  const int purchase_year_;
  Door doors_[4];
  Pedal accel_;
  Pedal brake_;
  int current_speed_;
};
