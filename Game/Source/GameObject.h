#pragma once


class GameObject
{
public:
    GameObject(fw::Mesh* m, fw::Vector2 p, float a, fw::Vector2 s);
    ~GameObject();

    void update(float delta);
    void draw();


protected:
    fw::Vector2 m_scale = { 1.0f,1.0f };
    float m_angle = 1.0f;
    fw::Vector2 m_position = { 0.0f,0.0f };
    fw::Mesh* m_mesh;
    fw::ShaderProgram* m_shader;
};
