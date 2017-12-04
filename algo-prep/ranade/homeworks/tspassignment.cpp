#include <simplecpp>
#include <string>
#include <map>
#include <sstream>

const int npoints = 10;
vector<Circle*> points;
vector<vector<double> > wt(npoints, vector<double>(npoints));

int main(){
  initCanvas();

  repeat(npoints){        // click points on the screen
    int pos = getClick();
    points.push_back(new Circle(pos/65536, pos%65536, 5));
  }
  
  // Generate the distance matrix, wt.
  for(size_t i=0; i<points.size(); i++){
    for(size_t j=0; j<points.size(); j++){
      wt[i][j] = sqrt(pow(points[i]->getOrigin().getX()-
			  points[j]->getOrigin().getX(),2) + 
		      pow(points[i]->getOrigin().getY()-
			  points[j]->getOrigin().getY(),2));
    }
  }


  // your tsp code here

  // sample code to show the tsp.  This code just connects points in
  // the order they were given.
  for(int i=0; i<npoints-1; i++)
    Line(points[i]->getOrigin().getX(), points[i]->getOrigin().getY(),
	 points[i+1]->getOrigin().getX(), points[i+1]->getOrigin().getY()).imprint();
  getClick();


}
