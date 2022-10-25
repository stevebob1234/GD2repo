#pragma once
#include "CoreHeaders.h"

namespace fw {

	enum class PrimitiveTypes
	{
		POINTS,
		LINES,
		TRIANGLES
	};


	struct VertexFormat
	{
		fw::Vector2 position;
		unsigned char r, g, b, a;
	};

	class ShaderProgram;

	class Mesh
	{
	public:
		Mesh(std::vector<fw::VertexFormat>& format, PrimitiveTypes type);
		~Mesh();
		void draw(Vector2 scale, float angle, Vector2 position, ShaderProgram* shader);


	private:
		GLuint m_VBO;
		std::vector<VertexFormat> m_format;
		PrimitiveTypes m_type;



	};

}