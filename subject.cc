#include "subject.h"
#include "observer.h"
#include "subscriptions.h"

void Subject::attach(Observer *o) {
  if (o != nullptr){
    observers.push_back(o);
  }
}

void Subject::notifyObservers(SubscriptionType t) {
  for(auto i : observers) {
    if(t == i->subType()){ // to determine whether to notify its neighbours or textdisplay
      i->notify(*this);
    }
  }
}

Subject::~Subject() {}
      

