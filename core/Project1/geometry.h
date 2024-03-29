#pragma once
#include <ostream>

namespace Geometry
{
	template <class T>
	struct Vector2
	{
		union
		{
			struct
			{
				T u, v;
			};

			struct
			{
				T x, y;
			};
		};

		T raw[2];

		Vector2() : u(0), v(0)
		{
		}

		Vector2(T _u, T _v) : u(_u), v(_v)
		{
		}

		Vector2<T> operator+(const Vector2<T>& v) const
		{
			return Vector2<T>{this->u + v.u, this->v + v.v};
		}

		Vector2<T> operator-(const Vector2<T>& v) const
		{
			return Vector2<T>{this->u + v.u, this->v + v.v};
		}

		Vector2<T> operator*(const Vector2<T>& v) const
		{
			return Vector2<T>{this->u * v.u, this->v * v.v};
		}

		template <class>
		friend std::ostream& operator <<(std::ostream& s, Vector2<T>& v);
	};

	template <class T>
	struct Vector3
	{
		union 
		{
			struct
			{
				T u, v, w;
			};

			struct
			{
				T x, y, z;
			};

			T raw[2];
		};

		Vector3(): u(0), v(0), w(0)
		{
		}


		Vector3(const T _u, const T _v, const T _w) : u(_u), v(_v), w(_w)
		{
		}

		Vector3<T> operator+(const Vector3<T>& v) const
		{
			return Vector3<T>{this->u + v.u, this->v + v.v, this->w + v.w};
		}

		Vector3<T> operator-(const Vector3<T>& v) const
		{
			return Vector3<T>{this->u + v.u, this->v + v.v, this->w - v.w};
		}

		Vector3<T> operator*(const Vector3<T>& v) const
		{
			return Vector3<T>{this->u * v.u, this->v * v.v, this->w * v.w};
		}

		template <class>
		friend std::ostream& operator <<(std::ostream& s, Vector3<T>& v);
	};

	template<class T>
	std::ostream& operator<<(std::ostream& s, const Vector2<T>& v)
	{
		s << "(" << v.u << ", " << v.v << ")";
		return s;
	}

	template<class T>
	std::ostream& operator<<(std::ostream& s, const Vector3<T>& v)
	{
		s << "(" << v.u << ", " << v.v << ", "<<v.w<<")";
		return s;
	}

	typedef Vector2<int> v2_i;
	typedef Vector2<float> v2_f;
	typedef Vector3<int> v3_i;
	typedef Vector3<float> v3_f;
}