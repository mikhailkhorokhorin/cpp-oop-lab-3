#include "../include/rectangle.h"

Rectangle::Rectangle() {
    size_ = 4;
    points_ = new Point[size_];
}

Rectangle::Rectangle(const Point& point1, const Point& point2, const Point& point3,
                     const Point& point4) {
    size_ = 4;
    points_ = new Point[size_]{point1, point2, point3, point4};
}

Rectangle::Rectangle(const Rectangle& other) {
    size_ = other.size_;
    points_ = new Point[size_];

    for (size_t i = 0; i < size_; ++i)
        points_[i] = other.points_[i];
}

Point Rectangle::getCenter() const {
    double cx = 0, cy = 0;

    for (size_t i = 0; i < size_; ++i) {
        cx += points_[i].x;
        cy += points_[i].y;
    }

    return Point{cx / size_, cy / size_};
}

double Rectangle::getArea() const {
    double width = std::sqrt(std::pow(points_[1].x - points_[0].x, 2) +
                             std::pow(points_[1].y - points_[0].y, 2));
    double height = std::sqrt(std::pow(points_[3].x - points_[0].x, 2) +
                              std::pow(points_[3].y - points_[0].y, 2));
    return width * height;
}

void Rectangle::print(std::ostream& os) const {
    for (size_t i = 0; i < size_; ++i)
        os << "(" << points_[i].x << "," << points_[i].y << ") ";
}

void Rectangle::read(std::istream& is) {
    if (points_)
        delete[] points_;

    size_ = 4;
    points_ = new Point[size_];

    for (size_t i = 0; i < size_; ++i)
        is >> points_[i].x >> points_[i].y;
}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this == &other)
        return *this;

    Figure::operator=(other);
    return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
    if (this == &other)
        return *this;

    Figure::operator=(std::move(other));
    return *this;
}

bool Rectangle::operator==(const Figure& other) const {
    if (const Rectangle* r = dynamic_cast<const Rectangle*>(&other)) {
        for (size_t i = 0; i < size_; ++i) {
            if (std::abs(points_[i].x - r->points_[i].x) > 1e-9 ||
                std::abs(points_[i].y - r->points_[i].y) > 1e-9)
                return false;
        }
        return true;
    }
    return false;
}

std::unique_ptr<Figure> Rectangle::clone() const {
    return std::unique_ptr<Figure>(new Rectangle(*this));
}