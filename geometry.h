#ifndef INC_1CPP_LAB_GEOMETRY_H
#define INC_1CPP_LAB_GEOMETRY_H
#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory>
#include <initializer_list>
#include <exception>
#include <cmath>
#include <limits>

class Double_compare {
    friend bool double_equal (double x , double y);
};

class Point{
public:
    Point();
    Point(double x, double y);
    Point(const Point& other);
    Point& operator=(const Point& other);
    friend std::ostream& operator<<(std::ostream &os, const Point& object);

    double length(const Point& other);
    double abscissa() const;
    double ordinate() const;
    std::vector<Point> push(std::vector<Point>& vector_);

private:
    double x;
    double y;
};
//---------------------------------------------
class Polyline{
public:
    Polyline();
    Polyline(std::initializer_list<Point> points);
    Polyline(const Polyline& other);
    Polyline& operator=(const Polyline& other);
    friend std::ostream& operator<<(std::ostream &os, const Polyline& object);
    Point operator[](size_t i);
    const Point& operator[](size_t i) const;
    virtual double perimeter();

protected:
    std::vector<Point> polyline;
};

//---------------------------------------------
class Closed_polyline : public Polyline {
public:
    Closed_polyline();
    Closed_polyline(std::initializer_list<Point> points);
    Closed_polyline(const Closed_polyline& other);
    Closed_polyline& operator=(const Closed_polyline& other);
    double perimeter() override;
};

//---------------------------------------------
class Polygon {
public:
    Polygon();
    Polygon(std::initializer_list<Point> points);
    Polygon(const Polygon& other);
    Polygon& operator=(const Polygon& other);
    friend std::ostream& operator<<(std::ostream &os, const Polygon& object);
    Point operator[](size_t i);
    const Point& operator[](size_t i) const;

    virtual double perimeter();
    double area();

protected:
    std::vector<Point> polygon;
    std::vector<Point> vectors;
    std::vector<double> angles;
    std::vector<double> sides;
    void count_sides();
    void count_vectors();
    void count_angles();
};

//---------------------------------------------
class Triangle : public Polygon {
public:
    Triangle();
    Triangle(std::initializer_list<Point> points);
    Triangle(const Triangle& other);
    Triangle& operator=(const Triangle& other);

private:
    bool is_triangle();
};

//---------------------------------------------
class Trapezoid : public Polygon {
public:
    Trapezoid();
    Trapezoid(std::initializer_list<Point> points);
    Trapezoid(const Trapezoid& other);
    Trapezoid& operator=(const Trapezoid& other);

private:
    bool is_trapezoid();
};

//---------------------------------------------
class Regular_polygon : public Polygon {
public:
    Regular_polygon();
    Regular_polygon(std::initializer_list<Point> points);
    Regular_polygon(const Regular_polygon& other);
    Regular_polygon& operator=(const Regular_polygon& other);
    double perimeter() override;

private:
    bool is_regular();
};


#endif //INC_1CPP_LAB_GEOMETRY_H
