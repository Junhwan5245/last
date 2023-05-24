#include "stdafx.h"
#include "Main.h"

Main::Main()
{
	target = new ObCircle();
}

Main::~Main()
{
	delete target;
}
void Main::Init()
{
	target->scale.x = 100.0f;
	target->scale.y = 100.0f;

	//target->color.x = 0.8f;
	//target->color.y = 1.0f;
	//target->color.x = 0.0f;
	//target->color.z = 0.0f;
}

void Main::Release()
{
}

void Main::Update()
{
	ImGui::ColorEdit3("color", (float*)&target->color);

	target->Update();
}

void Main::LateUpdate()
{
	
}

void Main::Render()
{
	target->Render();
}

void Main::ResizeScreen()
{
}

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE prevInstance, LPWSTR param, int command)
{
	app.SetAppName(L"Game2");
	app.SetInstance(instance);
	app.InitWidthHeight(1000.0f, 800.0f);
	WIN->Create();
	Main* main = new Main();
	int wParam = (int)WIN->Run(main);
	SafeDelete(main);
	WIN->Destroy();
	WIN->DeleteSingleton();
	
	return wParam;
}