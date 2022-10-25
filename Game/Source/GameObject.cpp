#include "Framework.h"
#include "GameObject.h"

GameObject::GameObject(fw::Mesh* m, fw::Vector2 p, float a, fw::Vector2 s) :
	m_mesh(m),
	m_position(p),
	m_angle(a),
	m_scale(s)
{

	m_shader = new fw::ShaderProgram("Data/Shaders/Basic.vert", "Data/Shaders/Basic.frag");

}

GameObject::~GameObject()
{
	delete m_shader;
}

void GameObject::update(float delta)
{
}

void GameObject::draw()
{
	m_mesh->draw(m_scale, m_angle, m_position, m_shader);


}
