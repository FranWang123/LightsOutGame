#include <iostream>
#include <utility>
#include "textdisplay.h"
#include "cell.h"
#include "info.h"
using namespace std;

TextDisplay::TextDisplay(int n): gridSize{n}{
  for(int r = 0; r < n; ++r) {
    vector<char> row;
    theDisplay.emplace_back(row);
    for(int c = 0; c < n; ++c) {
      theDisplay[r].emplace_back('_');
    }
  }
}

void TextDisplay::notify(Subject &whoNotified) {
  int row = whoNotified.getInfo().row;
  int col = whoNotified.getInfo().col;
  theDisplay[row][col] = whoNotified.getInfo().state ? 'X' : '_';
}

TextDisplay::~TextDisplay() {}

SubscriptionType TextDisplay::subType() const {
  return SubscriptionType::All;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
  for(int r = 0; r < td.gridSize; ++r) {
    for(int c = 0; c < td.gridSize; ++ c) {
      out << td.theDisplay[r][c];
    }
    out << endl;
  }
  return out;
}
