#include "graphicsdisplay.h"
#include <iostream>
#include "cell.h"
#include "info.h"

GraphicsDisplay::GraphicsDisplay(Xwindow &w): w{w}, gridSize{0} {}

void GraphicsDisplay::init(int size){
  gridSize = size;
  w.fillRectangle(0, 0, 500, 500, Xwindow::Black); // every lights is off when the window is initilized
}

void GraphicsDisplay::notify(Subject &whoNotified) {
  int width = 500 / gridSize;
  int height = 500 / gridSize;
  int x = whoNotified.getInfo().row * width;
  int y = whoNotified.getInfo().col * height;
  bool State = whoNotified.getInfo().state;
  w.fillRectangle(x, y, width, height, State ? Xwindow::White : Xwindow::Black);
}

SubscriptionType GraphicsDisplay::subType() const {
  return SubscriptionType::All;
}

GraphicsDisplay::~GraphicsDisplay() {}


  
