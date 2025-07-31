#pragma once
#include <memory>
#include "Mesh.h"
#include "Shader.h"
#include "MeshManager.h"
#include "ShaderManager.h"

class RenderManager
{
public:

    void Initialize();

	void DrawRectangle(float x, float y, float width, float height, float r, float g, float b, float alpha);

private:
    MeshManager m_MeshManager;
    ShaderManager m_ShaderManager;
};

