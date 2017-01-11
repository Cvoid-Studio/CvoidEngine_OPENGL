
#include "GLBase.hpp"
#include <iostream>

HDC	g_HDC;

void SetupPixelFormat(HDC hDC);
LRESULT	CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wp, LPARAM lp);


int WINAPI WinMain(HINSTANCE Hinst, HINSTANCE PreHinst, LPSTR lpCmdline, int nShowCmd)
{
	WNDCLASSEX	winClass;
	HWND		hwnd;
	MSG			msg;
	bool		QUIT;
	//-------------------------------------------------------//
	winClass.cbSize = sizeof(WNDCLASSEX);
	winClass.style = CS_HREDRAW | CS_VREDRAW;
	winClass.lpfnWndProc = WndProc;
	winClass.cbClsExtra = 0;
	winClass.cbWndExtra = 0;
	winClass.hInstance = Hinst;
	winClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winClass.hbrBackground = NULL;
	winClass.lpszMenuName = NULL;
	//-------------------------------------------------------//
	winClass.lpszClassName = "Cvoid_Demo 1";
	winClass.hIconSm = LoadIcon(NULL, IDI_WINLOGO);
	//-------------------------------------------------------//
	//-------------------------------------------------------//
	if (!RegisterClassEx(&winClass))
	{
		return 0;
	}

	hwnd = CreateWindowEx(NULL,
		"Cvoid_Demo 1",
		"Cvoid_Demo Proj1",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_SYSMENU
		| WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
		100, 100,
		1000, 600,
		NULL,
		NULL,
		Hinst,
		NULL);

	if (!hwnd)
		return 0;

	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);

	QUIT = false;
	GLBase GLGame;
	// ================= MSG LOOP ================== //
	while (!QUIT)
	{
		PeekMessage(&msg, hwnd, NULL, NULL, PM_REMOVE);

		if (msg.message == WM_QUIT)
			QUIT = true;
		else
		{
			GLGame.RenderScene();		//--> Main Rendering Work
			SwapBuffers(g_HDC);
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		
	}
	std::cout << sizeof(short);
	std::cin.get();
	return msg.wParam;
}

LRESULT	CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wp, LPARAM lp)
{
	static HGLRC hRC;
	static HDC hDC;
	int width, height;

	switch (message)
	{
	case WM_CREATE:
		hDC = GetDC(hwnd);
		g_HDC = hDC;
		SetupPixelFormat(hDC);

		hRC = wglCreateContext(hDC);
		wglMakeCurrent(hDC, hRC);

		return 0;
		break;

	case WM_CLOSE:
		wglMakeCurrent(hDC, NULL);
		wglDeleteContext(hRC);

		PostQuitMessage(0);

		return 0;
		break;

	case WM_SIZE:
		height = HIWORD(lp);
		width = LOWORD(lp);

		if (height == 0)
			height = 1;

		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 1.0f, 1000.0f);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		return 0;
		break;

	default:
		break;
	}

	return (DefWindowProc(hwnd, message, wp, lp));
}

void SetupPixelFormat(HDC hDC)
{
	int nPixelFormat;

	static PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW |
		PFD_SUPPORT_OPENGL |
		PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		32,
		0,0,0,0,0,0,
		0,
		0,
		0,
		0,0,0,0,
		16,
		0,
		0,
		PFD_MAIN_PLANE,
		0,
		0,0,0
	};
	nPixelFormat = ChoosePixelFormat(hDC, &pfd);

	SetPixelFormat(hDC, nPixelFormat, &pfd);
}
