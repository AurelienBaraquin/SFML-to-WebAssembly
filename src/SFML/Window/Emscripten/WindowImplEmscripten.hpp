////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2013 Jonathan De Wachter (dewachter.jonathan@gmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef SFML_WINDOWEMSCRIPTEN_HPP
#define SFML_WINDOWEMSCRIPTEN_HPP

#include <SFML/Window/Event.hpp>
#include <SFML/Window/WindowImpl.hpp>
#include <SFML/Window/EglContext.hpp>

namespace sf
{
namespace priv
{

class WindowImplEmscripten : public WindowImpl
{
    WindowImplEmscripten(WindowHandle handle) {(void)handle;};

    virtual ~WindowImplEmscripten() {};

    virtual WindowHandle getSystemHandle() const { return 0; };

    virtual Vector2u getSize() const { return Vector2u(0, 0); };

    virtual void setSize(const Vector2u& size) {(void)size;};

    virtual void setTitle(const String& title) {(void)title;};

    virtual void setVisible(bool visible) {};

    virtual void setMouseCursorVisible(bool visible) {(void)visible;};

    virtual void setMouseCursorGrabbed(bool grabbed) {(void)grabbed;};

    virtual void setMouseCursor(const CursorImpl* cursor) {(void)cursor;};

    virtual void setKeyRepeatEnabled(bool enabled) {(void)enabled;};

    virtual void requestFocus() {};

    virtual bool hasFocus() const { return false; };

    virtual void display() {};

    virtual void processEvents() {};

    virtual void setJoystickThreshold(float threshold) {(void)threshold;};

    virtual bool popEvent(Event& event) {(void)event; return false;};

    virtual void setFramerateLimit(unsigned int limit) {(void)limit;};

    virtual void setJoystickMapping(unsigned int joystickId, Joystick::Identification mapping) {(void)joystickId; (void)mapping;};

    virtual void setIcon(unsigned int width, unsigned int height, const Uint8* pixels) {(void)width; (void)height; (void)pixels;};
};

} // namespace priv

} // namespace sf

#endif // SFML_WINDOWEMSCRIPTEN_HPP
