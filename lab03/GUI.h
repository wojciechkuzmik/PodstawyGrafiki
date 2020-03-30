///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/scrolbar.h>
#include <wx/gauge.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////
#include <wx/colordlg.h>

///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
	private:
		
	protected:
		wxPanel* m_panel;
		wxButton* m_button_write;
		wxCheckBox* m_checkBox_banan;
		wxScrollBar* m_scrollBar;
		wxGauge* m_gauge;
		wxButton* m_button_color;
		wxTextCtrl* m_textCtrl;
		wxChoice* m_choice;
		wxBitmap MyBitmap;
		wxImage MyImage;
		wxColourDialog colorDlg;
		// Virtual event handlers, overide them in your derived class
		virtual void m_panelOnUpdateUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void m_button_writeOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBox_bananOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_button_colorOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlOnText( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choiceOnChoice( wxCommandEvent& event ) { event.Skip(); }

	public:

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Lab 03"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame1();

};

