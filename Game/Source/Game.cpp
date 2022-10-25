#include "Framework.h"
#include "Game.h"
#include "VirtualController.h"
#include "GameObject.h"


Game::Game(fw::FWCore& core) : m_Framework(core)
{
    m_pImGuiManager = new fw::ImGuiManager(&core);

    // Initialize our mesh.
    std::vector<fw::VertexFormat> values = {
        { -0.5f, -0.5f, 255, 0, 0, 255 },
        {  0.5f, -0.5f, 0, 255, 0, 255 },
        {  0.0f,  0.5f, 0, 0, 255, 255 },
    };

    glGenBuffers( 1, &m_VBO );
    glBindBuffer( GL_ARRAY_BUFFER, m_VBO );
    glBufferData( GL_ARRAY_BUFFER, 3 * sizeof(fw::VertexFormat), &values[0], GL_STATIC_DRAW );

    // Load the basic shader.
    m_pBasicShader = new fw::ShaderProgram( "Data/Shaders/Basic.vert", "Data/Shaders/Basic.frag" );

    std::vector<fw::VertexFormat> enemy = {


        {2.0f,0.0f, 255, 255, 255, 255}, 
        {-1.0f,1.0f, 255, 255, 255, 255}, 
        {-2.0f, 0.0f, 255, 255, 255, 255},
        {-4.0f,-2.5f, 135, 255, 245, 205},
        {-2.0f,-1.0f, 135, 255, 245, 205},
    };

    m_playerMesh = new fw::Mesh(values, fw::PrimitiveTypes::TRIANGLES);

    m_enemyMesh = new fw::Mesh(enemy, fw::PrimitiveTypes::LINES);

    for (int i = 0; i < 3; i++)
    {
        m_gameObjs.push_back(new GameObject(m_enemyMesh, fw::Vector2{ 1.5f * (i + 1), 1.5f + (i + 1) }, 0.0f, fw::Vector2{1.0f, 1.0f}));

    }

    m_gameObjs.push_back(new GameObject(m_playerMesh, fw::Vector2 {0.0f,0.0f}, 0.0f, fw::Vector2{1.0f,1.0f}));

    for( int i=0; i<4; i++ )
    {
        m_pControllers[i] = new VirtualController();
    }
}

Game::~Game()
{
    for( int i=0; i<4; i++ )
    {
        delete m_pControllers[i];
    }

    delete m_pBasicShader;

    delete m_pImGuiManager;

    delete m_enemyMesh;
    delete m_playerMesh;

    for (auto Objects : m_gameObjs)
    {
        delete Objects;
    }
}

void Game::StartFrame(float deltaTime)
{
    m_pImGuiManager->StartFrame( deltaTime );
    ImGui::ShowDemoWindow();

    m_pEventManager->ProcessEvents();
}

void Game::OnEvent(fw::Event* pEvent)
{
    m_pControllers[0]->OnEvent( pEvent );
}

void Game::Update(float deltaTime)
{
    if (ImGui::TreeNode("This is a tree node"))
    {
        ImGui::DragFloat("Position X", &m_PosX, 0.01f);

        if (ImGui::Button("Reset"))
        {
            m_PosX = 0.0f;
        }

        ImGui::ColorEdit3("Color", &m_Color[0]);
        
        ImGui::TreePop();
    }

    if( m_pControllers[0]->IsHeld(VirtualController::Action::Left) )
    {
        m_PosX -= deltaTime;
    }

    if( m_pControllers[0]->IsHeld(VirtualController::Action::Right) )
    {
        m_PosX += deltaTime;
    }
}

void Game::Draw()
{
    glPointSize( 20 );
    glClearColor( 0, 0, 0.2f, 1 );
    glClear( GL_COLOR_BUFFER_BIT );

    for (auto obj : m_gameObjs)
    {

        obj->draw();

    }


    m_pImGuiManager->EndFrame();
}
