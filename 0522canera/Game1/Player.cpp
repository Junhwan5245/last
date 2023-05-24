#include "stdafx.h"
#include "Bullet.h"
#include "Player.h"

Player::Player()
{
  
   /* hasAxis = true;*/

    
    //
    for (int i = 0; i < 30; i++)
    {
        bullet[i] = new Bullet();
    }

    scale.x = 600.0f * 0.1f;
    scale.y = 600.0f * 0.1f;

    

    
}

Player::~Player()
{
}

void Player::Init(Vector2 spawn, bool isLeft)
{
    SetWorldPosX(spawn.x);
    SetWorldPosY(spawn.y);

    

    rotation.y = isLeft ? PI : 0.0f;


}

void Player::Control()
{
    

    //계속 누를때
    if (INPUT->KeyPress('W'))
    {
        
        //벡터의 크기는 초당 50
        //MoveWorldPos(UP * DELTA * 200);
        MoveWorldPos(UP * DELTA * 200);
        CAM->position += UP * 200.0f * DELTA;
       
        if (GetWorldPos().x > 800.0f)
            SetWorldPosX(800.0f);
        if (GetWorldPos().x < -800.0f)
            SetWorldPosX(-800.0f);
        if (GetWorldPos().y < -600.0f)
            SetWorldPosY(-600.0f);
        if (GetWorldPos().y > 600.0f)
            SetWorldPosY(600.0f);

        if (CAM->position.x < -800.0f)
            CAM->position.x = -800.0f;
        if (CAM->position.x > 800.0f)
            CAM->position.x = 800.0f;
        if (CAM->position.y < -600.0f)
            CAM->position.y = -600.0f;
        if (CAM->position.y > 600.0f)
            CAM->position.y = 600.0f;
       
        
    }
    if (INPUT->KeyPress('S'))
    {
        //MoveWorldPos(DOWN * DELTA * 200);
        MoveWorldPos(DOWN * DELTA * 200);
        CAM->position += DOWN * 200.0f * DELTA;
        
        if (GetWorldPos().x > 800.0f)
            SetWorldPosX(800.0f);
        if (GetWorldPos().x < -800.0f)
            SetWorldPosX(-800.0f);
        if (GetWorldPos().y < -600.0f)
            SetWorldPosY(-600.0f);
        if (GetWorldPos().y > 600.0f)
            SetWorldPosY(600.0f);
        
        if (CAM->position.x < -800.0f)
            CAM->position.x = -800.0f;
        if (CAM->position.x > 800.0f)
            CAM->position.x = 800.0f;
        if (CAM->position.y < -600.0f)
            CAM->position.y = -600.0f;
        if (CAM->position.y > 600.0f)
            CAM->position.y = 600.0f;
       
        
    }
    if (INPUT->KeyPress('A'))
    {
        MoveWorldPos(LEFT * DELTA * 200);
        CAM->position += LEFT * 200.0f * DELTA;

        if (GetWorldPos().x > 800.0f)
            SetWorldPosX(800.0f);
        if (GetWorldPos().x < -800.0f)
            SetWorldPosX(-800.0f);
        if (GetWorldPos().y < -600.0f)
            SetWorldPosY(-600.0f);
        if (GetWorldPos().y > 600.0f)
            SetWorldPosY(600.0f);
        
        if (CAM->position.x < -800.0f)
            CAM->position.x = -800.0f;
        if (CAM->position.x > 800.0f)
            CAM->position.x = 800.0f;
        if (CAM->position.y < -600.0f)
            CAM->position.y = -600.0f;
        if (CAM->position.y > 600.0f)
            CAM->position.y = 600.0f;
    }
    if (INPUT->KeyPress('D'))
    {
        MoveWorldPos(RIGHT * DELTA * 200);
        CAM->position += RIGHT * 200.0f * DELTA;

        if (GetWorldPos().x > 800.0f)
            SetWorldPosX(800.0f);
        if (GetWorldPos().x < -800.0f)
            SetWorldPosX(-800.0f);
        if (GetWorldPos().y < -600.0f)
            SetWorldPosY(-600.0f);
        if (GetWorldPos().y > 600.0f)
            SetWorldPosY(600.0f);
        
        if (CAM->position.x < -800.0f)
            CAM->position.x = -800.0f;
        if (CAM->position.x > 800.0f)
            CAM->position.x = 800.0f;
        if (CAM->position.y < -600.0f)
            CAM->position.y = -600.0f;
        if (CAM->position.y > 600.0f)
            CAM->position.y = 600.0f;
    }
    if (INPUT->KeyDown(VK_SPACE))
    {
        pressPower = 200.0f;
    }
    if (INPUT->KeyPress(VK_SPACE))
    {
        pressPower += 300.0f * DELTA;
        pressPower = min(pressPower, 1000.0f);
    }
    if (INPUT->KeyUp(VK_SPACE))
    {
        for (int i = 0; i < 30; i++)
        {
            if (not bullet[i]->GetIsFire())
            {
                bullet[i]->Fire(this, pressPower);
                break;
            }
        }
    }
    

    
  

}

void Player::Update()
{


    ObCircle::Update();
    for (int i = 0; i < 30; i++)
    {
        bullet[i]->Update();
    }
   
  
}

void Player::Render()
{
    ObCircle::Render();
    
    for (int i = 0; i < 30; i++)
    {
        bullet[i]->Render();
    }
}
