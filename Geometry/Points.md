```cpp
/*
Vector = Direction + Magnitude
Two vectors are perpendicular if and only if their angle is a right angle
Set of vectors is orthogonal if and only if they are pairwise perpendicular
The normal vector to a surface is a vector which is perpendicular to the surface at a given point
*/
/*
Dot Product : Algebraically, sum of the products of the corresponding entries
Geometrically, the product of the Euclidean magnitudes of the two vectors
and the cosine of the angle between them. A . B = |A| |B| cos(O) = x1*x2 + y1*y2
*/
// conj(a) ==> 2 + 3i ==> 2 - 3i flip sign of image
/*
The cross product, a X b, is a vector that is perpendicular
to both a and b and therefore normal to the plane containing them.
A x B = |A| |B| sin(O) = A.x * B.y - B.x * A.y 
*/
#define PI acos(-1.0)
#define EPS 1e-9
int dcmp(double x,double y){return fabs(x - y) <= EPS ? 0 : x > y ? 1 : -1;}
#define point complex<double>
#define X real()
#define Y imag()
#define vec(a,b) ((b) - (a))
#define length(a) abs(a)
#define dot(a,b) (conj(a)*(b)).real()
#define cross(a,b) (conj(a)*(b)).imag()
#define norm(a) dot((a),(a))
#define dist(a,b) length(vec((a),(b)))
#define angle(a) arg(a)
#define scale(a,s) (a) * (s)
#define dot_angle(a,b) acos(dot(a,b)/(abs(a) * abs(b)))
#define cross_3d(a,b) point(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x)
#define rotate_counterclockwise(a,ang) a * polar(1.0,ang) // rotate around origin
#define rotate_clockwise(a,ang) a * polar(1.0, -ang)
#define rotate_around_b(a,b,ang) (a - b) * polar(1.0, ang) + b  // rotate point a around point b
#define refelct(v,m) conj(v/m) * m
```