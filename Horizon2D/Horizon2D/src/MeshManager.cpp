#include "MeshManager.h"

void MeshManager::Initialize()
{
    LoadRectangle("Rectangle");
}

std::shared_ptr<Mesh> MeshManager::LoadRectangle(const std::string& name)
{
    if (m_Meshes.count(name)) return m_Meshes[name];

    std::vector<float> vertices = {
        -0.5f, -0.5f,
         0.5f, -0.5f,
        -0.5f,  0.5f,
         0.5f,  0.5f
    };

    auto mesh = std::make_shared<Mesh>(vertices);
    m_Meshes[name] = mesh;
    return mesh;
}

std::shared_ptr<Mesh> MeshManager::Get(const std::string& name)
{
    return m_Meshes[name];
}
