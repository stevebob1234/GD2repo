#pragma once

class VirtualController;
class fw::Mesh;
class GameObject;
class Game : public fw::GameCore
{
public:
    Game(fw::FWCore& core);
    virtual ~Game();

    virtual void StartFrame(float deltaTime) override;
    virtual void Game::OnEvent(fw::Event* pEvent) override;
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;

protected:
    fw::FWCore& m_Framework;
    fw::ImGuiManager* m_pImGuiManager = nullptr;

    GLuint m_VBO = 0;

    fw::ShaderProgram* m_pBasicShader = nullptr;

    VirtualController* m_pControllers[4] = { nullptr };

    float m_PosX = 0.0f;
    float m_Color[4] = { 1, 1, 1, 1 };
    fw::Mesh* m_playerMesh;
    std::vector<GameObject*> m_gameObjs;

    fw::Mesh* m_enemyMesh;

};
