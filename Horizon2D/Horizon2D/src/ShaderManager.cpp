#include "ShaderManager.h"

std::shared_ptr<Shader> ShaderManager::LoadShader(const std::string& name, const std::string& vertPath, const std::string& fragPath)
{
	auto iShader = m_Shaders.find(name);
	if (iShader != m_Shaders.end()) return iShader->second;

	auto shader = std::make_shared<Shader>(vertPath, fragPath);
	m_Shaders[name] = shader;
	return shader;
}

std::shared_ptr<Shader> ShaderManager::GetShader(const std::string& name)
{
	return m_Shaders[name];
}
