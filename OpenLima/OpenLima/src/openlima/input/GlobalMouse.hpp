// Copyright (C) 2011 Robert B�hm
// This file is part of OpenLima.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with OpenLima. If not, see: <http://www.gnu.org/licenses/>.

#ifndef OPENLIMA_INPUT_GLOBALMOUSE_HPP
#define OPENLIMA_INPUT_GLOBALMOUSE_HPP

#include "Mouse.hpp"


namespace openlima {
	namespace input {

		class GlobalMouse : public Mouse {
		private:

			/**
			 * Initializes the mouse and registers the global events to it.
			 *
			 * @author	Robert B�hm (rynti)
			 */
			GlobalMouse();


			/**
			 * The event that will be called when the global mouse was moved.
			 *
			 * @author	Robert B�hm (rynti)
			 *
			 * @param	x	The x coordinate of the mouse.
			 * @param	y	The y coordinate of the mouse.
			 */
			static void globalMouseMove(int x, int y);

			/**
			 * The event that will be called when the global mouse was clicked.
			 *
			 * @author	Robert B�hm (rynti)
			 */
			static void globalMouseClick(int button, int state, int x, int y);

		public:

			/**
			 * Returns the global mouse.
			 *
			 * @author	Robert B�hm (rynti)
			 *
			 * @return	The global mouse.
			 */
			OPENLIMA_DLL static GlobalMouse& getInstance();

			/**
			 * Sets the position of this mouse.
			 *
			 * @param	position	The position, relative to the window.
			 */
			OPENLIMA_DLL void setPosition(openlima::util::Vector2i position);

		};

	}
}

#endif /* OPENLIMA_INPUT_GLOBALMOUSE_HPP */