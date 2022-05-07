#include "geometry.h"

//Point methods
Point::Point() : x(0), y(0) {}

Point::Point(int x_, int y_) : x(x_), y(y_) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point& Point::operator=(const Point& other) {
    x = other.x;
    y = other.y;
}

std::ostream& operator<<(std::ostream &os, const Point& object) {
    os << "("<< object.x << ";" << object.y << ")";
    return os;
}

int Point::abscissa() const {
    return x;
}
int Point::ordinate() const{
    return y;
}

double Point::length(const Point &other) {
    return sqrt(pow(other.x - this->x, 2) + pow(other.y - this->y, 2));
}

std::vector<Point> Point::push(std::vector<Point> &vector_) {
    vector_.push_back(*this);
    return vector_;
}

//---------------------------------------------
//Polyline methods
Polyline::Polyline() {}
Polyline::Polyline(std::initializer_list<Point> points) : polyline(points) {}
Polyline::Polyline(const Polyline& other) : polyline(other.polyline) {}
Polyline& Polyline::operator=(const Polyline& other) {
    polyline = other.polyline;
}
Point Polyline::operator[](size_t i) {
    return polyline[i];
}
const Point& Polyline::operator[](size_t i) const {
    return polyline[i];
}
std::ostream& operator<<(std::ostream &os, const Polyline& object) {
    for (size_t i = 0; i < object.polyline.size(); ++i){
        os << object[i];
    }
    return os;
}

double Polyline::perimeter() {
    int perimeter_ = 0;
    for (int i = 1; i < polyline.size(); ++i)
        perimeter_ += polyline[i].length(polyline[i - 1]);
    return perimeter_;
}

//---------------------------------------------
//Closed_polyline methods
Closed_polyline::Closed_polyline() {}

Closed_polyline::Closed_polyline(std::initializer_list<Point> points) : Polyline(points) {}

Closed_polyline::Closed_polyline(const Closed_polyline& other) : Polyline(other) {}

Closed_polyline& Closed_polyline::operator=(const Closed_polyline& other) {
    polyline = other.polyline;
}

double Closed_polyline::perimeter() {
    int perimeter_ = 0;
    for (int i = 1; i < polyline.size(); ++i)
        perimeter_ += polyline[i].length(polyline[i - 1]);
    return perimeter_ + polyline[0].length(polyline[polyline.size() - 1]);
}

//---------------------------------------------
//Polygon methods
Polygon::Polygon() {}

Polygon::Polygon(std::initializer_list<Point> points) : polygon(points), angles(points.size()), sides(points.size()) {
    count_sides();
    count_vectors();
    count_angles();
}

Polygon::Polygon(const Polygon& other) : polygon(other.polygon), vectors(other.vectors), angles(other.angles), sides(other.sides) {}

Polygon& Polygon::operator=(const Polygon& other) {
    polygon = other.polygon;
    vectors = other.vectors;
    angles = other.angles;
    sides = other.sides;
}

Point Polygon::operator[](size_t i) {
    return polygon[i];
}
const Point& Polygon::operator[](size_t i) const {
    return polygon[i];
}

std::ostream& operator<<(std::ostream &os, const Polygon& object) {
    os << "Points: ";
    for (size_t i = 0; i < object.polygon.size(); ++i) {
        os << object[i] << " ";
    }
    os << "\nSides: ";
    for (size_t i = 0; i < object.polygon.size(); ++i) {
        os << object.sides[i] << " ";
    }
    os << "\nVectors: ";
    for (size_t i = 0; i < object.polygon.size(); ++i) {
        os << object.vectors[i] << " ";
    }
    os << "\nAngles: ";
    for (size_t i = 0; i < object.polygon.size(); ++i) {
        os << object.angles[i] << " ";
    }
    return os;
}

double Polygon::perimeter() {
    int perimeter_ = 0;
    for (int i = 1; i < polygon.size(); ++i)
        perimeter_ += polygon[i].length(polygon[i - 1]);
    return perimeter_ + polygon[0].length(polygon[polygon.size() - 1]);
}

double Polygon::area() {
    double area_ = 0;
    size_t j = polygon.size() - 1;
    for (size_t i = 0; i < polygon.size(); ++i) {
        area_ += ((polygon[j].abscissa() + polygon[i].abscissa()) * (polygon[j].ordinate() - polygon[i].ordinate()));
        j = i;
    }
    return std::abs(area_ / 2);
}

//---------------------------------------------
//Triangle methods
Triangle::Triangle() {}

Triangle::Triangle(std::initializer_list<Point> points) : Polygon(points) {
        if (!is_triangle())
            throw std::invalid_argument("Too many points in triangle");
}

Triangle::Triangle(const Triangle& other) : Polygon(other) {}

Triangle& Triangle::operator=(const Triangle& other) {
    polygon = other.polygon;
}

//---------------------------------------------
//Trapezoid methods
Trapezoid::Trapezoid() {}

Trapezoid::Trapezoid(std::initializer_list<Point> points) : Polygon(points) {
    if (!is_trapezoid()){
        throw std::invalid_argument("This polygon is not trapezoid");
    }
}

Trapezoid::Trapezoid(const Trapezoid& other) : Polygon(other) {}

Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
    polygon = other.polygon;
}

//---------------------------------------------
//Regular polygon methods
Regular_polygon::Regular_polygon() {}

Regular_polygon::Regular_polygon(std::initializer_list<Point> points) : Polygon(points) {
    if (!is_regular())
        throw std::invalid_argument("This polygon is not regular");
}

Regular_polygon::Regular_polygon(const Regular_polygon& other) : Polygon(other) {}

Regular_polygon& Regular_polygon::operator=(const Regular_polygon& other) {
    polygon = other.polygon;
}

double Regular_polygon::perimeter() {
    return sides[0] * sides.size();
}