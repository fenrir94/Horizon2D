#pragma once
#include "Shader.h"
#include <unordered_map>
#include <memory>

class ShaderManager
{
public:
	void Initialize();

	std::shared_ptr<Shader> LoadShader(const std::string& name, const std::string& vertPath, const std::string& fragPath);
	std::shared_ptr<Shader> GetShader(const std::string& name);

private:
	std::unordered_map<std::string, std::shared_ptr<Shader>> m_Shaders;
};

