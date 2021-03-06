```CPP
/*
// Circle
Diameter = 2 * Radius
Area of circle = PI * r^2
Circumference of a circle = 2 * PI * r
(x-h)^2 + (y-k)^2 = r^2 where (h,k) is center, (x,y) any point in circle
*/

bool is_inside_circle(point center, point b, double r)
{
    double d1 = (b.X - center.X);
    double d2 = (b.Y - center.Y);
    return (d1 * d1 + d2 * d2) <= r * r;
}
bool is_intersect_circles(double x1, double y1, double r1, double x2, double y2, double r2)
{
    double x = x1 - x2;
    double y = y1 - y2;
    double dist = sqrt(x * x + y * y);
    return dcmp(dist, (r1 + r2)) == -1 && dcmp(abs(r1 - r2), dist) == -1; 
    // if intersect on boundaries return 1, we use below code
   // return dcmp(dist, (r1 + r2)) <= 0 && dcmp(abs(r1 - r2), dist) <= 0;
}
double distance_circles(double x1, double y1, double x2, double y2)
{
    double x = (x1 - x2);
    double y = (y1 - y2);
    return (x * x) + (y * y);
}
// 2 points has infinite circles
// Find circle passes with 3 points, some times, there is no circle! (in case colinear)
// Draw two perpendicular lines and intersect them
pair<double, point> findCircle(point a, point b, point c)
{
    //create median, vector, its prependicular
    point m1 = (b + a) * 0.5, v1 = b - a, pv1 = point(v1.Y, -v1.X);
    point m2 = (b + c) * 0.5, v2 = b - c, pv2 = point(v2.Y, -v2.X);
    point end1 = m1 + pv1, end2 = m2 + pv2, center;
    intersect_line(m1, end1, m2, end2, center);
    return make_pair(length(vec(center, a)), center);
}

// If line intersect cirlce at point p, and p = p0 + t(p1-p0)
// Then (p-c)(p-c) = r^2 substitute p and rearrange
// (p1-p0)(p1-p0)t^2 + 2(p1-p0)(p0-C)t + (p0-C)(p0-C) = r*r; -> Quadratic
vector<point> intersectLineCircle(point p0, point p1, point C, double r)
{
    double a = dot(vec(p0, p1), vec(p0, p1)), b = 2 * dot(vec(p0, p1), vec(C, p0)),
           c = dot(vec(C, p0), vec(C, p0)) - r * r;
    double f = b * b - 4 * a * c;
    vector<point> v;
    if (dcmp(f, 0) >= 0)
    {
        if (dcmp(f, 0) == 0)
            f = 0;
        double t1 = (-b + sqrt(f)) / (2 * a);
        double t2 = (-b - sqrt(f)) / (2 * a);
        v.push_back(p0 + t1 * (p1 - p0));
        if (dcmp(f, 0) != 0)
            v.push_back(p0 + t2 * (p1 - p0));
    }
    return v;
}

vector<point> intersectCircleCircle(point c1, double r1, point c2, double r2)
{
    if (same(c1, c2) && dcmp(r1, r2) == 0 && dcmp(r1, 0) > 0)
        return vector<point>(3, c1);
    double ang1 = angle(vec(c1, c2)), ang2 = getAngle_A_abc(r2, r1, length(vec(c1, c2)));
   if (isnan(ang2))
      ang2 = 0;
    vector<point> v(1, polar(r1, ang1 + ang2) + c1);
    if (dcmp(dot(vec(c1, v[0]), vec(c1, v[0])), r1 * r1) != 0 ||
            dcmp(dot(vec(c2, v[0]), vec(c2, v[0])), r2 * r2) != 0)
    return vector<point>();
    v.push_back(polar(r1, ang1 - ang2) + c1);
    if (same(v[0], v[1]))
        v.pop_back();
    return v;
}
// Min enclosing circle
// get smallest radious that contatin all points
const int MAX = 100000 + 9;
point pnts[MAX], r[3], cen;
double rad;
int ps, rs;	// ps = n, rs = 0, initially
// Pre condition
// random_shuffle(pnts, pnts+ps);
void MEC()
{
    if (ps == 0 && rs == 2)
    {
        cen = (r[0] + r[1]) / 2.0;
        rad = dist(r[0] , cen);
    }
    else if (rs == 3)
    {
        pair<double, point> p = findCircle(r[0], r[1], r[2]);
        cen = p.second;
        rad = p.first;
    }
    else if (ps == 0)
    {
        cen = r[0];	
        rad = 0;
    }
    else
    {
        ps--;
        MEC();
        if (dist(pnts[ps] , cen) > rad)
        {
            r[rs++] = pnts[ps];
            MEC();
            rs--;
        }
        ps++;
    }
}
/*
// Circular Sector
Length of an Arc = (O/360) * 2 * PI * r
Sector area = (O/360) * PI * r^2
*/
double arc(double theta,double r)
{
    // IF theta is degree
    return (theta/360) * 2 * PI * r;
    // IF theta is radian
    return theta * r;
}
double area_sector(double theta,double r)
{
    return (toDegree(theta)/360) * PI * r * r;
}
/*
// Cylinder
The surface area of cylinder consists of three parts:

the area of the top base: πr^2
the area of the bottom base: πr^2
the area of the side(lateral area): 2πrh (Circumference of the bottom base * height)

The surface area of cylinder = πr^2 + 2πrh + πr^2 = 2πrh + πr^2 = 2πr(h + r)
volume = πr^2 * h (Area of the bottom base * height)
*/
```
