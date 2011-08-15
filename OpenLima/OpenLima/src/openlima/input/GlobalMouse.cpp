// Copyright (C) 2011 Robert B�hm
// This file is part of OpenLima.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with OpenLima. If not, see: <http://www.gnu.org/licenses/>.

#include <GL/freeglut_std.h>
#include "GlobalMouse.hpp"

using namespace openlima::util;


namespace openlima {
	namespace input {
		
		GlobalMouse::GlobalMouse() {
			glutMotionFunc(GlobalMouse::globalMouseMove);
			glutPassiveMotionFunc(GlobalMouse::globalMouseMove);
			glutMouseFunc(GlobalMouse::globalMouseClick);
		}

		void GlobalMouse::globalMouseMove(int x, int y) {
			GlobalMouse::getInstance().delta = Vector2i(x - GlobalMouse::getInstance().position.x,
				y - GlobalMouse::getInstance().position.y);

			GlobalMouse::getInstance().position = Vector2i(x, y);

			GlobalMouse::getInstance().onMouseMove(
				GlobalMouse::getInstance(),
				MouseMoveEvent(GlobalMouse::getInstance().getPosition(),
					GlobalMouse::getInstance().getDelta()));
			
			if(GlobalMouse::getInstance().sticky && (GlobalMouse::getInstance().delta.x != 0 ||
				GlobalMouse::getInstance().delta.y != 0)) {
				GlobalMouse::getInstance().setPosition(Vector2i(400, 300));
			}
		}

		void GlobalMouse::globalMouseClick(int button, int state, int x, int y) {
			MouseButtonState mouseButtonState = (state == GLUT_UP) ?
				MouseButtonStateType::RELEASED : MouseButtonStateType::PRESSED;
			MouseClickEvent* eventArgs;

			if(button == GLUT_LEFT_BUTTON) {
				eventArgs = new MouseClickEvent(Vector2i(x, y), MouseButtonType::LEFT,
					mouseButtonState);
			} else if(button == GLUT_MIDDLE_BUTTON) {
				eventArgs = new MouseClickEvent(Vector2i(x, y), MouseButtonType::MIDDLE,
					mouseButtonState);
			} else if(button == GLUT_RIGHT_BUTTON) {
				eventArgs = new MouseClickEvent(Vector2i(x, y), MouseButtonType::RIGHT,
					mouseButtonState);
			} else {
				return;
			}

			if(mouseButtonState == MouseButtonStateType::RELEASED) {
				GlobalMouse::getInstance().mouseButtonStates &= ~(1 << (int)eventArgs->getButton());
			} else {
				GlobalMouse::getInstance().mouseButtonStates |= (1 << (int)eventArgs->getButton());
			}

			GlobalMouse::getInstance().onMouseClick(GlobalMouse::getInstance(), *eventArgs);
			delete eventArgs;
		}

		void GlobalMouse::setPosition(Vector2i position) {
			glutWarpPointer(position.x, position.y);
		}

		GlobalMouse& GlobalMouse::getInstance() {
			static GlobalMouse instance;
			return instance;
		}

	}
}