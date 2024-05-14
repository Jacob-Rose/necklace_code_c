// Copyright 2024 | Jake Rose 
//
// This file is part of project necklace_code_c
// See readme.md for full license details.
#include "state_emote_heart.h"

#include "../../lib/j/jmath.h"
#include "../../gm.h"

#include "../../imgs/kirby.h"

State_Emote_Heart::State_Emote_Heart(const char* InStateName) : State(InStateName)
{
    heartSaw.speed = 100.0f;
    heartSaw.width = 4.0f;
    //heartSaw.gapWidth = 3.0f;
}

void State_Emote_Heart::onStateBegin()
{
    State::onStateBegin();

    GameManager& GM = GameManager::get();

    GM.ScreenDrawer.setScreenGif((uint8_t *)kirby, sizeof(kirby));
}

void State_Emote_Heart::tick()
{
    State::tick();

    GameManager& GM = GameManager::get();
    float deltaTime = GetLastFrameDelta().count();

    heartSaw.tick(deltaTime);

    float pulseTime = heartSaw.evaluate(0.0f);

    pulseTime *= 200;

    int pulseTimeByte = std::floor(pulseTime);
    
    for(int ledIdx = 0; ledIdx < RING_LED_LENGTH; ++ledIdx)
    {
        GM.RingLEDs->setHSV(ledIdx, 0xf812, 200, pulseTimeByte);
    }

    for(int ledIdx = 0; ledIdx < OUTFIT_LED_LENGTH; ++ledIdx)
    {
        GM.OutfitLEDs->setHSV(ledIdx, 0xf812, 200, pulseTimeByte);
    }


    GM.BoardLED->setHSV(0,0xf812, 200,pulseTimeByte);
}