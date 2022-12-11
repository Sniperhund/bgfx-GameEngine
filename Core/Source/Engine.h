#pragma once
#include <vector>

#include "UI/UI_Widget.h"

class Engine
{
private:
    static std::vector<UI_Widget*> m_UI_Widgets;
public:
    static void Start();
    static void Update();
    static void AddUIWidget(UI_Widget* widget);
};
