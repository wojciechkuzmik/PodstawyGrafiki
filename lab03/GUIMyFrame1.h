#ifndef __GUIMyFrame1__
#define __GUIMyFrame1__

/**
@file
Subclass of MyFrame1, which is generated by wxFormBuilder.
*/

#include "GUI.h"

//// end generated include
#include <wx/dcclient.h>


/** Implementing MyFrame1 */
class GUIMyFrame1 : public MyFrame1
{
	protected:
		// Handlers for MyFrame1 events.
		void m_panelOnUpdateUI( wxUpdateUIEvent& event );
		void m_button_writeOnButtonClick( wxCommandEvent& event );
		void m_checkBox_bananOnCheckBox( wxCommandEvent& event );
		void m_scrollBarOnScroll(wxScrollEvent& event);
		void m_button_colorOnButtonClick( wxCommandEvent& event );
		void m_textCtrlOnText( wxCommandEvent& event );
		void m_choiceOnChoice( wxCommandEvent& event );
	public:
		/** Constructor */
		GUIMyFrame1( wxWindow* parent );
	//// end generated class members
		void Repaint();



};

#endif // __GUIMyFrame1__
