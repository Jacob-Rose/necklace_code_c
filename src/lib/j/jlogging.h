// Copyright 2024 | Jake Rose 
//
// This file is part of project necklace_code_c
// See readme.md for full license details.

#pragma once

#include <stdio.h>
#include "pico/stdlib.h"

#include <Arduino.h>

#include <string>

#define LOGGING_ENABLED 1

enum class Verbosity : uint8_t
{
    TickSpam, // goes off every tick
    VeryVerbose,
    Verbose,
    Display,
    Warning,
    Error
};

enum class Category : uint8_t
{
    None        = 0b00000000,
    OnTick      = 0b00000001,
    StateInfo   = 0b00000010,
};

Category operator|(Category lhs, Category rhs);

Category operator&(Category lhs, Category rhs);

constexpr Verbosity ProjectVerbosity { 
    Verbosity::VeryVerbose
};
constexpr Category ProjectHideCategories { 
    //Category::OnTick
};

namespace jlog
{
    void print(const char *msg, Verbosity Verbosity = Verbosity::Display, Category HideCategories = Category::None);
    void print(std::string msg, Verbosity Verbosity = Verbosity::Display, Category HideCategories = Category::None);
    void print(String msg, Verbosity Verbosity = Verbosity::Display, Category HideCategories = Category::None);
}
