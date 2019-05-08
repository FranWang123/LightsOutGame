#include <iostream>
#include "grid.h"
using namespace std;

Grid::Grid(Xwindow &w): gd(w){
  td = nullptr;
}

Grid::~Grid(){
  delete td;
}

void Grid::clearGrid() {
  theGrid.clear(); //lear the theGrid stack first
  gridSize = 0;
  if (td != nullptr){
    delete td;
    td = nullptr;
  }
}

Cell *Grid::findCell(int r, int c) { // to get the Cell at the r row and the c colnum
  if(0 <= r && r < gridSize && 0 <=c && c < gridSize) {
    return &(theGrid[r][c]);
  } else {
    return nullptr;
  }
}


bool Grid::isWon() const {
  for(int r = 0; r < gridSize; ++r) {
    for(int c = 0; c < gridSize; ++c) {
      if(theGrid[r][c].getState()){ // if there is a On cell, then go on
	return false;
	break;
      }
    }
  }
  return true;// since the loop is finished, which means there is no lights is on,
               // then the player wons
}

void Grid::init(int n) {
  clearGrid(); 
  gd.init(n);
  td = new TextDisplay(n);
  gridSize = n;
  for(int r = 0; r < n; ++r) {
    std::vector<Cell> row;
    theGrid.emplace_back(row);
    for(int c = 0; c < n; ++c) {
      theGrid[r].emplace_back(Cell());
      theGrid[r][c].setCoords(r, c);
      theGrid[r][c].attach(td);// since when the grid was initialized, every cell should attach
                               // the textdispkay
      theGrid[r][c].attach(&gd);// since when the grid was initialized, every cell should attach
                               // the graphicsdisplay
    }
  }
  for( int r= 0; r < gridSize; ++r) {  // when all cells have been initilized, attach the 4
                                       // neighbours
      for( int c =0; c < gridSize; ++c){
	theGrid[r][c].attach(findCell(r + 1, c));
	theGrid[r][c].attach(findCell(r - 1, c));
	theGrid[r][c].attach(findCell(r, c + 1));
	theGrid[r][c].attach(findCell(r, c - 1));
      }
   }// when all cells have been initilized, attach the 4
    // neighbours
}


void Grid::turnOn(int r, int c) {
  theGrid[r][c].setOn();
}

void Grid::toggle(int r, int c) {
  theGrid[r][c].toggle();
}

void Grid::init(int r, int c) {
  turnOn(r,c);
}

ostream &operator<<(ostream &out, const Grid &g) {
  out << *(g.td);
  return out;
}
