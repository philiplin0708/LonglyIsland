#include "GamePCH.h"

Scene_Hud::Scene_Hud(Game* pGame, ResourceManager* pResources, TextRenderer* pTextRenderer)
    : Scene(pGame, pResources, pTextRenderer)
{
    m_bOpacity = false;
    m_ShouldDrawText = false;
    m_Hour = 0;
    m_Hunger = 0;
    LoadContent();
}

Scene_Hud::~Scene_Hud()
{
}

void Scene_Hud::LoadContent()
{
    // Camera
    m_pGameObjects["Camera"] = new CameraObject(this, "Camera", vec3(0, 0, -4), vec3(0, 0, 0), vec3(1, 1, 1));
    static_cast<CameraObject*>(m_pGameObjects["Camera"])->SetUseOrthoProj(true);

    //Hud Object
    m_pGameObjects["Hud_Time"] = new GameObject(this, "Hud_Time", vec3(-4.3f, 4, 0), vec3(0, 0, 0), vec3(0.8f, 1, 1), "Box", "Hud_Time");
    m_pGameObjects["Hud_Hunger"] = new GameObject(this, "Hud_Hunger", vec3(-4.3f, 2.8f, 0), vec3(0, 0, 0), vec3(0.8f, 1, 1), "Box", "Hud_Hunger");
}

bool Scene_Hud::OnEvent(Event* pEvent)
{
    Scene::OnEvent(pEvent);
    return false;
}

void Scene_Hud::Update(float deltatime)
{
    Scene::Update(deltatime);

    if (m_pPlayer)
    {
        m_Hour = m_pPlayer->m_Survived;
    }
}

void Scene_Hud::Draw()
{
    Scene::Draw();
}

void Scene_Hud::DrawTexts()
{
    float charheight = m_pTextRenderer->GetCharacterHeight();
    std::string time = std::to_string(m_Hour) + " Hours";
    m_pTextRenderer->printText2D(time.c_str(), 16, 10, 16, 20, 0);
}


