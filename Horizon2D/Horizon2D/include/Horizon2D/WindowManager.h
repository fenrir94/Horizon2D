#pragma once

class WindowManager
{
public:
	WindowManager();
	~WindowManager();

	void Initialize();
	void ClearWindow();

private:
	unsigned int m_width;
	unsigned int m_heigth;
};

