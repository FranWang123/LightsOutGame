#ifndef _GRAPHICSDISPLAY_H_
#define _GRAPHICSDISPLAY_H_
#include "observer.h"
#include "window.h"

class GraphicsDisplay: public Observer {
  Xwindow &w; // has a Xwindow
  int gridSize;
  public:
  GraphicsDisplay(Xwindow &w);
  void init(int size);
  void notify(Subject &whoNotified) override;
  SubscriptionType subType() const override;
  ~GraphicsDisplay();
};

#endif

