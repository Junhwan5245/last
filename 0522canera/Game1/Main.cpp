#include "stdafx.h"
#include "Bullet.h"
#include "Player.h"
#include "Main.h"

Main::Main()
{
	pl[0] = new Player;
	
    for (int i = 0; i < StarMax; i++)
    {
        bg[i] = new ObStar();
        bg[i]->SetWorldPosX(RANDOM->Float(-800.0f, 800.0f));
        bg[i]->SetWorldPosY(RANDOM->Float(-600.0f, 600.0f));
        bg[i]->scale.x = 15.0f;
        bg[i]->scale.y = 15.0f;
        bg[i]->color = Color(1, 1, 0)* RANDOM->Float();
        //bg[i]->space = SPACE::SCREEN;
    }
    
}

Main::~Main()
{
}

void Main::Init()
{

	pl[0]->Init(Vector2(0, 0), false);
    pl[0]->isFilled = true;
    pl[0]->color = Color(1, 0.5, 0);
	
	turn = 0;

}

void Main::Release()
{
   
}

void Main::Update()
{
    ImGui::Text("FPS : %d", (int)TIMER->GetFramePerSecond());
    ImGui::ColorEdit3("color", (float*)&pl[0]->color);

    
	pl[turn]->Control();

	pl[0]->Update();
	

    for (int i = 0; i < StarMax; i++)
    {
        bg[i]->Update();
    }
}

void Main::LateUpdate()
{
    //for (int i = 0; i < 30; i++)
    //{

    //    if (not pl[turn]->GetBullet(i)->GetIsFire())continue;

    //    if (pl[turn]->GetBullet(i)->GetWorldPos().x < -400.0f + 10.0f)
    //    {
    //        pl[turn]->GetBullet(i)->SetWorldPosX(-400.0f + 10.0f);
    //        pl[turn]->GetBullet(i)->ReflectionY();
    //        pl[turn]->GetBullet(i)->Update();
    //    }
    //    else if (pl[turn]->GetBullet(i)->GetWorldPos().x > 400.0f - 10.0f)
    //    {
    //        pl[turn]->GetBullet(i)->SetWorldPosX(400.0f - 10.0f);
    //        pl[turn]->GetBullet(i)->ReflectionY();
    //        pl[turn]->GetBullet(i)->Update();
    //    }
    //    if (pl[turn]->GetBullet(i)->GetWorldPos().y < -300.0f - 10.0f)
    //    {
    //        pl[turn]->GetBullet(i)->Release();
    //        turn = not turn;
    //        damage = 0;
    //        damageTime = 0.0f;
    //    }

    //    if (pl[turn]->GetBullet(i)->Touch(pl[not turn]))
    //    {
    //        //pl[not turn]->
    //        //pl[not turn]->Damage(10.0f);
    //        //pl[turn]->GetBullet(i)->Release();
    //        //turn = not turn;
    //        damage = 1;
    //        releasebullet = i;
    //    }
    //}

    //if (damage)
    //{
    //    if (TIMER->GetTick(damageTime, 0.02f))
    //    {
    //        pl[not turn]->Damage(5.0f);
    //        damage++;
    //    }

    //    if (damage >= 5)
    //    {
    //        pl[turn]->GetBullet(releasebullet)->Release();
    //        turn = not turn;
    //        damage = 0;
    //        damageTime = 0.0f;
    //    }
    //}

}

void Main::Render()
{
    for (int i = 0; i < StarMax; i++)
    {
        bg[i]->Render();
    }

    pl[0]->Render();
   


}

void Main::ResizeScreen()
{
}

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE prevInstance, LPWSTR param, int command)
{
    app.SetAppName(L"Game1");
    app.SetInstance(instance);
	app.InitWidthHeight(800.0f,600.0f);
    app.background = Color(0, 0, 0);
	WIN->Create();
	Main* main = new Main();
	int wParam = (int)WIN->Run(main);
	SafeDelete(main);
	WIN->Destroy();
	WIN->DeleteSingleton();
	
	return wParam;
}