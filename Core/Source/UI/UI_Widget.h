#pragma once
#include <string>

class UI_Widget
{
protected:
    virtual void Update() {}
    virtual void Start() {}
public:
    std::string Title = "Default Name";
    bool Active = false;
    void Internal_Update();
    void Internal_Start();

    virtual ~UI_Widget() = default;
};
