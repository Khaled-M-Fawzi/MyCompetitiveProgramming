```
/*
Polar system , Cartesian
x = r * cos(O)
y = r * sin(O)
r = sqrt(x^2 + y^2)
O = atan2(y,x)

Radians: 0 - 2 π
Degrees: 0 - 360
Right angle 90 degree or π/2 radians
370 Degree = 10 Degree = 370 % 360
*/
#define PI acos(-1.0)
double toRadians(double degree) 
{
    return (degree * PI) / 180.0;
}
double toDegree(double radian)
{
    if(radian<0)
        radian += 2*PI;
    return (radian * 180.0 / PI);
}
// Convert degrees, minutes, seconds(d° m' s") to decimal degrees d°
double to_degree(double degrees, double minutes, double seconds)
{
    return degrees + (minutes/60) + (seconds/60*60);
}
```
