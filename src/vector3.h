//
// Created by Nick Bedford on 9/12/21.
//

#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>
#include <string>
#include <sstream>

namespace math
{
	/**
	 * Represents a 3D vector.
	 * @tparam T
	 */
	template <class T>
	class vector3
	{
	public:
		// The X component of the vector.
		T x;

		// The Y component of the vector.
		T y;

		// The Z component of the vector.
		T z;

		// Defines a reference to a 3D vector.
		typedef const vector3<T> &ref;

		// Defines the vector's own type.
		typedef vector3<T> self;

		/**
		 * Initialises a vector with X, Y and Z coordinates defaulting to zero.
		 * @param x The X component of the vector.
		 * @param y The Y component of the vector.
		 * @param z The Z component of the vector.
		 */
		explicit vector3(T x = 0, T y = 0, T z = 0)
			: x(x), y(y), z(z)
		{
		}

		/**
		 * Initialises a vector from another vector.
		 * @param vector
		 */
		vector3(ref vector)
			: x(vector.x), y(vector.y), z(vector.z)
		{
		}

		/**
		 * Gets the length of the vector.
		 * @return
		 */
		T length() const
		{
			return std::sqrt(length_squared());
		}

		/**
		 * Gets the squared length of the vector.
		 * @return
		 */
		T length_squared() const
		{
			return x * x + y * y + z * z;
		}

		/**
		 * Gets the dot product of this and another vector.
		 * @param other
		 * @return
		 */
		T dot(ref other) const
		{
			return x * other.x + y * other.y + z * other.z;
		}

		/**
		 * Gets the cross product of this and another vector.
		 * @param other
		 * @return
		 */
		self cross(ref other) const
		{
			auto bx = other.x;
			auto by = other.y;
			auto bz = other.z;
			return self(
				y * bz - z * by,
				z * bx - x * bz,
				x * by - y * bx);
		}

		/**
		 * Gets the normalised unit vector from this vector.
		 * @return
		 */
		self unit() const
		{
			auto l = length();
			if (l == 0)
				return self();
			return *this / l;
		}

		/**
		 * Gets the reflection of the vector off a normal.
		 * @param normal
		 * @return
		 */
		self reflect(ref normal) const
		{
			return *this - normal * (2 * this->dot(normal));
		}

		/**
		 * Gets the sum of the two vectors.
		 * @param rhs
		 * @return
		 */
		self operator +(ref rhs) const
		{
			return self(x + rhs.x, y + rhs.y, z + rhs.z);
		}

		/**
		 * Gets the difference of the two vectors.
		 * @param rhs
		 * @return
		 */
		self operator -(ref rhs) const
		{
			return self(x - rhs.x, y - rhs.y, z - rhs.z);
		}

		/**
		 * Gets the vector multiplied by a scalar.
		 * @param rhs
		 * @return
		 */
		self operator *(T rhs) const
		{
			return self(x * rhs, y * rhs, z * rhs);
		}

		/**
		 * Gets the vector divided by a scalar.
		 * @param rhs
		 * @return
		 */
		self operator /(T rhs) const
		{
			return self(x / rhs, y / rhs, z / rhs);
		}

		/**
		 * Gets the cross product of this and another vector.
		 * @param rhs
		 * @return
		 */
		self operator *(ref rhs) const
		{
			return cross(rhs);
		}

		/**
		 * Gets the string representation of the vector to a specified precision.
		 * @return
		 */
		[[nodiscard]] std::string to_string(const std::streamsize precision = 6) const
		{
			std::stringstream out;
			out.precision(precision);
			out << x << ", " << y << ", " << z;
			return out.str();
		}
	};

	// Defines a 3D vector with single 32-bit floating point precision.
	typedef vector3<float> vector3f;

	// Defines a 3D vector with double 64-bit floating point precision.
	typedef vector3<double> vector3d;
}

#endif