#include "Mesh.h"
#include "Utility//ShaderProgram.h"


fw::Mesh::Mesh(std::vector<fw::VertexFormat>& format, PrimitiveTypes type) :
    m_type(type)
{

    glGenBuffers(1, &m_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(VertexFormat), &format[0], GL_STATIC_DRAW);

    m_format = format;
}

fw::Mesh::~Mesh()
{

}


void fw::Mesh::draw(Vector2 scale, float angle, Vector2 position, ShaderProgram* shader)
{

    glUseProgram(shader->GetProgram());

    // Program our uniforms.
    GLint u_Scale = glGetUniformLocation(shader->GetProgram(), "u_Scale");
    glUniform2f(u_Scale, scale.x, scale.y);

    GLint u_Offset = glGetUniformLocation(shader->GetProgram(), "u_Offset");
    glUniform2f(u_Offset, position.x, position.y);

    GLint u_Rotation = glGetUniformLocation(shader->GetProgram(), "u_Offset");
    glUniform1f(u_Rotation, angle);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    GLint a_position = glGetAttribLocation(shader->GetProgram(), "a_Position");
    glEnableVertexAttribArray(a_position);
    glVertexAttribPointer(a_position, 2, GL_FLOAT, false, sizeof(fw::VertexFormat), (void*)0);

    GLint a_Color = glGetAttribLocation(shader->GetProgram(), "a_Color");
    glEnableVertexAttribArray(a_Color);
    glVertexAttribPointer(a_Color, 4, GL_UNSIGNED_BYTE, true, sizeof(fw::VertexFormat), (void*)8);


    // Draw our mesh.
    //glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

    if (m_type == PrimitiveTypes::TRIANGLES)
    {
        glDrawArrays(GL_TRIANGLES, 0, m_format.size());
    }
    else if (m_type == PrimitiveTypes::LINES)
    {

        glDrawArrays(GL_LINE_LOOP, 0, m_format.size());
    }
    else if (m_type == PrimitiveTypes::POINTS)
    {

        glDrawArrays(GL_POINTS, 0, m_format.size());
    }

}

