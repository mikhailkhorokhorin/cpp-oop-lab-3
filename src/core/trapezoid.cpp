#include "../include/trapezoid.h"

Trapezoid::Trapezoid() {
    size_ = 4;
    points_ = new Point[size_];
}

Trapezoid::Trapezoid(const Point& point1, const Point& point2, const Point& point3,
                     const Point& point4) {
    size_ = 4;
    points_ = new Point[size_]{point1, point2, point3, point4};
}

Trapezoid::Trapezoid(const Trapezoid& other) {
    size_ = other.size_;
    points_ = new Point[size_];

    for (size_t i = 0; i < size_; ++i)
        points_[i] = other.points_[i];
}

Point Trapezoid::getCenter() const {
    double cx = 0, cy = 0;

    for (size_t i = 0; i < size_; ++i) {
        cx += points_[i].x;
        cy += points_[i].y;
    }

    return Point{cx / size_, cy / size_};
}

double Trapezoid::getArea() const {
    double a = std::sqrt(std::pow(points_[1].x - points_[0].x, 2) +
                         std::pow(points_[1].y - points_[0].y, 2));
    double b = std::sqrt(std::pow(points_[3].x - points_[2].x, 2) +
                         std::pow(points_[3].y - points_[2].y, 2));

    double h = std::abs(points_[0].y - points_[2].y);
    return (a + b) / 2.0 * h;
}

void Trapezoid::print(std::ostream& os) const {
    for (size_t i = 0; i < size_; ++i)
        os << "(" << points_[i].x << "," << points_[i].y << ") ";
}

void Trapezoid::read(std::istream& is) {
    if (points_)
        delete[] points_;

    size_ = 4;
    points_ = new Point[size_];

    for (size_t i = 0; i < size_; ++i)
        is >> points_[i].x >> points_[i].y;
}

Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
    if (this == &other)
        return *this;

    Figure::operator=(other);
    return *this;
}

Trapezoid& Trapezoid::operator=(Trapezoid&& other) noexcept {
    if (this == &other)
        return *this;

    Figure::operator=(std::move(other));
    return *this;
}

bool Trapezoid::operator==(const Figure& other) const {
    if (const Trapezoid* r = dynamic_cast<const Trapezoid*>(&other)) {
        for (size_t i = 0; i < size_; ++i) {
            if (std::abs(points_[i].x - r->points_[i].x) > 1e-9 ||
                std::abs(points_[i].y - r->points_[i].y) > 1e-9)
                return false;
        }
        return true;
    }
    return false;
}

std::unique_ptr<Figure> Trapezoid::clone() const {
    return std::unique_ptr<Figure>(new Trapezoid(*this));
}