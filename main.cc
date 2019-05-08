#include <iostream>
#include <string>
#include "grid.h"
using namespace std;

int main() {
  cin.exceptions(ios::eofbit|ios::failbit);
  Xwindow w;
  string cmd, aux;
  Grid g(w);
  int moves = 0;

  // You will need to make changes to this code.

  try {
    while (true) {
      cin >> cmd;
      if (cmd == "new") { // initialize a grid
        int n;
        cin >> n;
	g.init(n);
      }
      else if (cmd == "init") {
	int r, c;
	while(true) {
	  cin >> r;	  cin >> c;
	  if (r == -1 && c == -1) break;
	  g.init(r, c); // initialize a cell and turn to on
	}
        cout << g;
      }
      else if (cmd == "game") {
        cin >> moves;
	cout << moves << " moves left" << endl;
      }
      else if (cmd == "switch") {
	moves -= 1;
          int r = 0, c = 0;
          cin >> r >> c;
	  g.toggle(r, c); // to toggle a cell
	  cout << g;
          if (moves == 1) {
	  cout << moves << " move left" << endl;
          } else {
	  cout << moves << " moves left" << endl;
         }
	  if(g.isWon()) {
	    cout << "Won" << endl;
	    return 0;
	  }
       if(moves == 0 && !g.isWon()) {
	  cout << "Lost" << endl;
          return 0;
        }
     }
	
    }
  }
  catch (ios::failure &) {
    if (cin.eof());
    return 0;
  }
}
