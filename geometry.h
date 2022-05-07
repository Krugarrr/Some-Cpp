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

class Point{
public:
    Point();
    Point(int x, int y);
    Point(const Point& other);
    Point& operator=(const Point& other);
    friend std::ostream& operator<<(std::ostream &os, const Point& object);

    double length(const Point& other);
    int abscissa() const;
    int ordinate() const;
    std::vector<Point> push(std::vector<Point>& vector_);

private:
    int x;
    int y;
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
    void count_sides() {
        size_t size_ = polygon.size() - 1;
        for (size_t i = 0; i < size_; ++i) {
            sides[i] = pow(polygon[i + 1].abscissa() - polygon[i].abscissa(), 2);
            sides[i] += pow(polygon[i + 1].ordinate() - polygon[i].ordinate(), 2);
            sides[i] = sqrt(sides[i]);
        }
        sides[size_] = pow(polygon[size_].abscissa() - polygon[0].abscissa(), 2);
        sides[size_] += pow(polygon[size_].ordinate() - polygon[0].ordinate(), 2);
        sides[size_] = sqrt(sides[size_]);
    }
    void count_vectors() {
        size_t size_ = polygon.size() - 1;
        int x_ = 0, y_ = 0;
        for (size_t i = 0; i < size_; ++i) {
            x_ = polygon[i + 1].abscissa() - polygon[i].abscissa();
            y_ = polygon[i + 1].ordinate() - polygon[i].ordinate();
            Point point_(x_, y_);
            point_.push(vectors);
        }
        x_ = polygon[0].abscissa() - polygon[size_].abscissa();
        y_ = polygon[0].ordinate() - polygon[size_].ordinate();
        Point point_(x_, y_);
        point_.push(vectors);
    }

    void count_angles() {
        size_t size_ = polygon.size() - 1;
        double first_scalar, second_scalar;
        for (size_t i = 0; i < size_; ++i) {
            angles[i] = abs(vectors[i].abscissa() * vectors[i + 1].abscissa());
            angles[i] += abs(vectors[i].ordinate() * vectors[i + 1].ordinate());
            first_scalar = pow(vectors[i].ordinate(), 2) + pow(vectors[i].abscissa(), 2);
            second_scalar = pow(vectors[i + 1].ordinate(), 2) + pow(vectors[i + 1].abscissa(), 2);
            angles[i] /= sqrt(first_scalar * second_scalar);
        }
        angles[size_] = abs(vectors[0].abscissa() * vectors[size_].abscissa());
        angles[size_] += abs(vectors[0].ordinate() * vectors[size_].ordinate());
        first_scalar = pow(vectors[0].ordinate(), 2) + pow(vectors[0].abscissa(), 2);
        second_scalar = pow(vectors[size_].ordinate(), 2) + pow(vectors[size_].abscissa(), 2);
        angles[size_] /= sqrt(first_scalar * second_scalar);
    }
};

//---------------------------------------------
class Triangle : public Polygon {
public:
    Triangle();
    Triangle(std::initializer_list<Point> points);
    Triangle(const Triangle& other);
    Triangle& operator=(const Triangle& other);

private:
    bool is_triangle() {
        if (polygon.size() > 3)
            return false;
        return true;
    }
};

//---------------------------------------------
class Trapezoid : public Polygon {
public:
    Trapezoid();
    Trapezoid(std::initializer_list<Point> points);
    Trapezoid(const Trapezoid& other);
    Trapezoid& operator=(const Trapezoid& other);

private:
    bool is_trapezoid(){
        if (polygon.size() > 4)
            return false;
        return true;
    }
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
    bool is_regular(){
        for (size_t i = 1; i < sides.size(); ++i){
            if (sides[i] != sides[i - 1] || angles[i] != angles[i - 1])
                return false;
        }
        return true;
    }
};

#endif //INC_1CPP_LAB_GEOMETRY_H
