#pragma once
#include <vector>

#include "geometry.h"


namespace Model
{
	class Obj
	{
	public:
		explicit Obj(const char* fileName);
		~Obj();
		[[nodiscard]] int numVerts();
		[[nodiscard]] int numFaces();
		Geometry::v3_f vert(int index);
		std::vector<int> face(int index) ;

	private:
		std::vector<Geometry::v3_f> m_verts {};
		std::vector<std::vector<int>> m_faces {};
	};
}
