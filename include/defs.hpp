#pragma once

#include <cmath>

template <typename Precision> struct _Vector {
  Precision x;
  Precision y;
  Precision z;

  _Vector operator+(const _Vector &other) const {
    return {x + other.x, y + other.y, z + other.z};
  }

  _Vector operator-(const _Vector &other) const {
    return {x - other.x, y - other.y, z - other.z};
  }

  _Vector operator*(Precision scalar) const {
    return {x * scalar, y * scalar, z * scalar};
  }

  _Vector operator/(Precision scalar) const {
    return {x / scalar, y / scalar, z / scalar};
  }

  _Vector operator-() const { return {-x, -y, -z}; }

  Precision length() const { return std::sqrt(x * x + y * y + z * z); }

  _Vector normalize() const { return *this / length(); }

  Precision dot(const _Vector &other) const {
    return x * other.x + y * other.y + z * other.z;
  }

  _Vector cross(const _Vector &other) const {
    return {y * other.z - z * other.y, z * other.x - x * other.z,
            x * other.y - y * other.x};
  }
};
using Vector = _Vector<float>;

struct Plane {
  Vector normal;
  float distance;
};

struct Ray {
  Vector origin;
  Vector direction;
  float t;
};