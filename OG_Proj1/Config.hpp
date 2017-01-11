#pragma once
#include <stdio.h>
#include <cstdlib>

class C_WndConfig
{
public:
	C_WndConfig();
	~C_WndConfig();

private:
	float	m_width;		// 0x04
	float	m_height;		// 0x14

	bool	FullScreen;

public:
	void	ReadConfig(const char* filename);
	void*	GetConfig(unsigned int index);
	void	SaveConfig(const char* filename);
};