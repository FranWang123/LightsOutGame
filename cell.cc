#include <utility>
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "subscriptions.h"
#include "info.h"

Cell::Cell() {}

bool Cell::getState() const { return isOn; }

Info Cell::getInfo() const {
  return Info{r, c, isOn};
}



void Cell::setOn() {
  isOn = true;
  notifyObservers(SubscriptionType::All); // to notify the textdisplay
}

void Cell::toggle() {
  isOn = !isOn;
   notifyObservers(SubscriptionType::SwitchOnly); // to notify its neighbours
  notifyObservers(SubscriptionType::All); // to notify the textdiplay
}

void Cell::setCoords(int r, int c) { this->r = r; this->c = c; }

void Cell::notify(Subject &) {
  isOn = !isOn; // switch its isOn
  notifyObservers(SubscriptionType::All); // notify its textdisplay
}

SubscriptionType Cell::subType() const {
  return SubscriptionType::SwitchOnly;
}
