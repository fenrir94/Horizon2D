#pragma once
#include "Mesh.h"
#include <unordered_map>
#include <memory>
#include <string>

class MeshManager
{
public:
	void Initialize();

	std::shared_ptr<Mesh> LoadRectangle(const std::string& name);
	std::shared_ptr<Mesh> Get(const std::string& name);

private:
	std::unordered_map<std::string, std::shared_ptr<Mesh>> m_Meshes;
};

