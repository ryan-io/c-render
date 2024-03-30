#include "obj.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

Model::Obj::Obj(const char* fileName) :
	m_verts(std::vector<Geometry::v3_f>{}),
	m_faces(std::vector<std::vector<int>>{})
{
	std::ifstream inStream{};

	inStream.open(fileName, std::ifstream::in);

	if (!inStream)
	{
		std::cerr << "Could not fine the file with name " << fileName;
	}

	std::string input{};

	// line-based parsing: https://stackoverflow.com/questions/7868936/read-file-line-by-line-using-ifstream-in-c
	// while could also be while(getline(inststream, input))
	while (!inStream.eof())
	{
		getline(inStream, input);
		// we can stream inStream lines placed in input
		std::istringstream s_stream{input};

		//obj lines are either:
		//	v 0.608654 -0.568839 -0.416318					- signifies a vertex
		//	f 1193/1240/1193 1180/1227/1180 1179/1226/1179	- signifies a face
		std::string removed{};

		// check if vertex
		if (!input.compare(0, 2, "v ")) // checks if start of line is "v ", should return '0'
		{
			s_stream >> removed; // discards 'v'; stops at ' ' delimiter
			Geometry::v3_f v;

			for (int i = 0; i < 3; ++i)
			{
				s_stream >> v.raw[i];
			}

			m_verts.push_back(v); // insert at the end of vertices vector
		}
		// check if face
		else if (!input.compare(0, 2, "f ")) // checks if start of line is "f ", should return '0'
		{
			std::vector<int> f;
			int index;
			s_stream >> removed;
			//>> removed >> itrash >> removed >> itrash

			// extracts first number, removes remaining, removes set of 3, removes another set of 3
			for (int i = 0; i < 3; i++)
			{
				s_stream >> index >> removed;
				index--; // in wavefront obj all indices start at 1, not zero
				f.push_back(index);
			}
			m_faces.push_back(f);

			//s_stream >> removed; // discards 'f'; stops at ' ' delimiter

			//// now dealing with following format: 1193/1240/1193 1180/1227/1180 1179/1226/1179
			//std::vector<std::vector<int>> faces{};
			//s_stream >> removed; // discard "f "

			//std::vector<int> alloc{};
			//for (int i = 0; i < 3; ++i)
			//{
			//	for (int j = 0; j < 2; ++j)
			//	{
			//		std::getline(s_stream, removed, '/');
			//		int removedInt{ stoi(removed) - 1};
			//		faces[i].push_back(removedInt);
			//	}

			//	int removedInt{ stoi(removed) - 1 };
			//	std::getline(s_stream, removed, ' ');
			//	alloc.push_back(removedInt);
			//}

			//faces.push_back(alloc);
		}
	}

	std::cerr << "# v# " << m_verts.size() << " f# " << m_faces.size() << std::endl;
}

Model::Obj::~Obj() = default;

int Model::Obj::numVerts()
{
	return static_cast<int>(m_verts.size());
}

int Model::Obj::numFaces()
{
	return static_cast<int>(m_faces.size());
}

Geometry::v3_f Model::Obj::vert(const int index)
{
	return m_verts[index];
}

std::vector<int> Model::Obj::face(const int index)
{
	return m_faces[index];
}
