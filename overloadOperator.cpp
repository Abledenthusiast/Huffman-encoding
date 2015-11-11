#include <cmath> /** sqrt **/
#include <queue> /** priority_queue **/
#include <iostream> /** cout **/
using namespace std;
/**
 * @author Gary Lewandowski
 *
 * example of overloading the < operator in a class
 **/

/**
 * we'll make a class that stores a point, and use distance to (0,0)
 * as our < operator 
 */
class APoint
{
private:
  int x, y;

public:
  void setX(int value) { x = value;}
  void setY(int value) { y = value;}

  int getX() const { return x; }
  int getY() const { return y; }

  bool operator<(const APoint &rightHandArgument) const
  {
    /** the values of x and y in this object instantiation are the
	left hand argument of the <
    **/
    double myDistanceToOrigin = sqrt(x*x + y*y);
    int rhsX = rightHandArgument.getX();
    int rhsY = rightHandArgument.getY();
    double rhsDistanceToOrigin= sqrt(rhsX * rhsX + rhsY * rhsY);

    return (myDistanceToOrigin < rhsDistanceToOrigin);
  }

};

/** and now, here's an example using APoint on a heap! **/

int main()
{
  priority_queue<APoint> myHeap;

  APoint insertVal;

  insertVal.setX(0);
  insertVal.setY(5);
  myHeap.push(insertVal);

  insertVal.setX(1);
  insertVal.setY(1);
  myHeap.push(insertVal);

  insertVal.setX(1);
  insertVal.setY(10);
  myHeap.push(insertVal);

  insertVal.setX(1);
  insertVal.setY(0);
  myHeap.push(insertVal);
  
  while (!myHeap.empty())
    {
      APoint p = myHeap.top();
      myHeap.pop();
      cout << p.getX() << "," << p.getY() << endl;
    }
  
}
