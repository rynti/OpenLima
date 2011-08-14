#include "MouseMoveEvent.hpp"

using namespace openlima::util;


namespace openlima {
	namespace input {

		MouseMoveEvent::MouseMoveEvent(Vector2i position, Vector2i delta) {
			this->position = position;
			this->delta = delta;
		}

		Vector2i MouseMoveEvent::getPosition() {
			return this->position;
		}

		Vector2i MouseMoveEvent::getDelta() {
			return this->delta;
		}

	}
}