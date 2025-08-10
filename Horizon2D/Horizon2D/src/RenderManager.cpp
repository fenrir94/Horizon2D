#include "RenderManager.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


void RenderManager::Initialize()
{
	m_MeshManager.Initialize();
	m_ShaderManager.Initialize();
}

void RenderManager::DrawRectangle(float x, float y, float width, float height, float r, float g, float b, float alpha)
{
	auto mesh = m_MeshManager.LoadRectangle("Rectangle");
	auto shader = m_ShaderManager.LoadShader("Basic", "shader.vert", "shader.frag");

	shader->Use();
	
	glm::mat4 projection = glm::ortho(0.0f, 800.f, 0.f, 600.0f, -1.f, 1.f);

	glm::mat4 view = glm::mat4(1.0f);
	
	glm::mat4 model = glm::translate(glm::mat4(1.f), glm::vec3(x, y, 0.f));
	model = glm::scale(model, glm::vec3(width, height, 1.0f));
	shader->SetUniform("u_Model", model);
	shader->SetUniform("u_View", view);
	shader->SetUniform("u_Projection", projection);
	shader->SetUniform("u_Color", glm::vec4(r, g, b, alpha));

	mesh->Draw();
}

void RenderManager::DrawObjects(std::vector<Object>& objs)
{
	for (auto obj : objs)
	{
		DrawRectangle(obj->GetPosition().x, obj->GetPosition().y, obj->GetSize().x, obj->GetSize().y, 0.f, 0.f, 1.f, 1.f);
	}
}
