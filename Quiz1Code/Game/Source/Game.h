#pragma once

#include "DataTypes.h"

class VirtualController;

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

    vec2 m_Pos;
    float m_Color[4] = { 1, 1, 1, 1 };
};
