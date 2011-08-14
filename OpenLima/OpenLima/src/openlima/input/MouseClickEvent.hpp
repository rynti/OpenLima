#ifndef OPENLIMA_INPUT_MOUSECLICKEVENT_HPP
#define OPENLIMA_INPUT_MOUSECLICKEVENT_HPP

#include "..\util\macros.hpp"
#include "..\util\Vector2i.hpp"
#include "MouseButton.hpp"
#include "MouseButtonState.hpp"


namespace openlima {
	namespace input {

		/**
		 * A event argument that will be given to events that are raised on mouse clicks.
		 */
		class MouseClickEvent {
		private:

			/* The mouse position. */
			openlima::util::Vector2i position;

			/* The affected mouse button. */
			MouseButton button;

			/* The state of the affected mouse button. */
			MouseButtonState state;

		public:

			/**
			 * Constructor.
			 *
			 * @param	position	The mouse position.
			 * @param	button  	The affected mouse button.
			 * @param	state   	The state of the affected mouse button.
			 */
			L_DLL MouseClickEvent(openlima::util::Vector2i position, MouseButton button, MouseButtonState state);


			/**
			 * Returns the mouse position.
			 *
			 * @return	The mouse position.
			 */
			L_DLL openlima::util::Vector2i getPosition();

			/**
			 * Returns the affected mouse button.
			 *
			 * @return	The affected mouse button.
			 */
			L_DLL MouseButton getButton();

			/**
			 * Returns the state of the affected mouse button.
			 *
			 * @return	The state of the affected mouse button.
			 */
			L_DLL MouseButtonState getState();

		};

	}
}

#endif /* OPENLIMA_INPUT_MOUSECLICKEVENT_HPP */