```cpp
// Sine Role : sin(A)/a = sin(B)/b = sin(C)/c
// Cosine Role : a^2 = b^2 + c^2 - 2*b*c*cos(A)
// sin(A + B) = sin(A) cos(B) + sin(B) cos(A)
// sin(A - B) = sin(A) cos(B) - sin(B) cos(A)
// cos(A + B) = cos(A) cos(B) - sin(A) sin(B)
// cos(A - B) = cos(A) cos(B) + sin(A) sin(B)
// tan(A + B) = (tan A + tan B)/(1 - tan A tan B)
// tan(A - B) = (tan A - tan B)/(1 + tan A tan B)
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double getSide_a_bAB(double b, double A, double B) 
{
	return (sin(A) * b) / sin(B);
}
double getAngle_A_abB(double a, double b, double B) 
{
	return asin(fixAngle((a * sin(b)) / b));
}
double getAngle_A_abc(double a, double b, double c)
{
	return acos(fixAngle((b * b + c * c - a * a) / (2 * b * c)));
}
double perimeter_triangle(double a, double b, double c) 
{
	return a + b + c;
}
// a, b, c are sides of triangle
double area_triangle(double a, double b, double c) 
{
	double s = 0.5 * perimeter_triangle(a, b, c);
	return sqrt(s * (s - a) * (s - b) * (s - c));// Heron’s formula
}
// a, b, c are medians of triangle
double area_triangle(double a, double b, double c) 
{
	double s = 0.5 * perimeter_triangle(a, b, c);
	return (4.0/3.0) * sqrt(s * (s - a) * (s - b) * (s - c));
}
// a, b, c are coordinate points
double area_triangle(point a,point b,point c) 
{ 
        return 0.5 * cross(vec(a,b),vec(a,c));
} 
// Check whether point X lies inside the triangle abc
bool isInside(point a,point b,point c,point x) 
{    
        double A  = area_triangle(a,b,c); 
        double A1 = area_triangle(x,a,b); 
        double A2 = area_triangle(x,b,c); 
        double A3 = area_triangle(x,a,c); 
        return (A == A1 + A2 + A3);    
	// if X lies on boundaries return 0;
	// return (A == A1 + A2 + A3 && A1 && A2 && A3);  
}
double rInCircle(double ab, double bc, double ca)
{
    double k = area_triangle(ab, bc, ca) / (0.5 * perimeter_triangle(ab, bc, ca));
    return isnan(k)? 0 : k;
}
double rInCircle(point a, point b, point c)
{
    double k = rInCircle(dist(a - b), dist(b - c), dist(c - a));
    return isnan(k)? 0 : k;
}
double rCircumCircle(double ab, double bc, double ca)
{
    double k = ab * bc * ca / (4.0 * area_triangle(ab, bc, ca));
    return isnan(k)? 0 : k;
}
double rCircumCircle(point a, point b, point c)
{
    double k = rCircumCircle(dist(a - b), dist(b - c), dist(c - a));
    return isnan(k)? 0 : k;
}
// Get radius and point of circle that inscribed with triangle
bool inCircle(point p1, point p2, point p3, point& ctr, double& r)
{
    r = rInCircle(p1, p2, p3);
    if (fabs(r) < EPS)
        return 0; // no inCircle center
    line l1, l2; // compute these two angle bisectors
    double ratio = dist(p1 - p2) / dist(p1 - p3);
    point p = translate(p2, scale(vec(p2, p3), ratio / (1 + ratio)));
    pointsToLine(p1, p, l1);
    ratio = dist(p2 - p1) / dist(p2 - p3);
    p = translate(p1, scale(vec(p1, p3), ratio / (1 + ratio)));
    pointsToLine(p2, p, l2);
    areIntersect(l1, l2, ctr); // get their intersection point
    return 1;
}
```
